//! Konata v4 view of the RTL pipeline lifecycle.
//!
//! RTL events are decoded into [`PipelineEvent`] at the module boundary. This
//! file then tracks instruction identity and state transitions; [`KonataWriter`]
//! owns the textual `I/L/S/E/W/R/C` protocol.
//!
//! ```text
//! pipeline: FQ -> DC -> IQ -> X-* -> RT
//! ROB:                  ROB-N -> ROB-D
//! tracking:             SQ-U -> SQ-R / LTQ / ATQ
//! memory:                       XLAT -> DMQ-*
//! ```

mod event;
mod writer;

use crate::ffi::NpcPipelineEvent;
use event::{
    DispatchEvent, ExecutionUnit, InstructionBits, InstructionKey, MemoryRequestKind,
    PipelineEvent, RobIndex,
};
use std::{
    collections::HashMap,
    io,
    path::{Path, PathBuf},
};
use writer::{InstructionId, KonataWriter, Lane, RetireCause, Stage};

#[derive(Debug, Clone, Copy)]
struct OpenStage {
    name: Stage,
    start_cycle: u64,
}

#[derive(Debug, Default)]
struct LaneStates {
    pipeline: Option<OpenStage>,
    rob: Option<OpenStage>,
    tracking: Option<OpenStage>,
    memory: Option<OpenStage>,
}

impl LaneStates {
    fn get(&self, lane: Lane) -> Option<OpenStage> {
        match lane {
            Lane::Pipeline => self.pipeline,
            Lane::Rob => self.rob,
            Lane::Tracking => self.tracking,
            Lane::Memory => self.memory,
        }
    }

    fn set(&mut self, lane: Lane, stage: Option<OpenStage>) {
        match lane {
            Lane::Pipeline => self.pipeline = stage,
            Lane::Rob => self.rob = stage,
            Lane::Tracking => self.tracking = stage,
            Lane::Memory => self.memory = stage,
        }
    }
}

#[derive(Debug, Clone, Copy)]
struct DeferredTransition {
    stage: Stage,
    due_cycle: u64,
}

#[derive(Debug)]
struct ActiveInstruction {
    key: InstructionKey,
    rob: Option<RobIndex>,
    is_store: bool,
    lanes: LaneStates,
    deferred_pipeline: Option<DeferredTransition>,
}

impl ActiveInstruction {
    fn new(key: InstructionKey) -> Self {
        Self {
            key,
            rob: None,
            is_store: false,
            lanes: LaneStates::default(),
            deferred_pipeline: None,
        }
    }

    fn has_zero_cycle_execution(&self, cycle: u64) -> bool {
        self.lanes
            .pipeline
            .is_some_and(|stage| stage.name.is_execution() && stage.start_cycle == cycle)
    }
}

/// Translates semantic pipeline events into a Konata instruction timeline.
pub(super) struct KanataTrace {
    path: PathBuf,
    writer: KonataWriter,
    next_instruction_id: u64,
    next_retire_id: u64,
    by_key: HashMap<InstructionKey, InstructionId>,
    by_rob: HashMap<RobIndex, InstructionId>,
    active: HashMap<InstructionId, ActiveInstruction>,
}

impl KanataTrace {
    pub(super) fn create(path: &Path) -> io::Result<Self> {
        Ok(Self {
            path: path.to_path_buf(),
            writer: KonataWriter::create(path)?,
            next_instruction_id: 0,
            next_retire_id: 0,
            by_key: HashMap::new(),
            by_rob: HashMap::new(),
            active: HashMap::new(),
        })
    }

    pub(super) fn path(&self) -> &Path {
        &self.path
    }

    pub(super) fn write_cycle(
        &mut self,
        cycle: u64,
        raw_events: &mut Vec<NpcPipelineEvent>,
    ) -> io::Result<()> {
        let has_deferred_transition = self.active.values().any(|instruction| {
            instruction
                .deferred_pipeline
                .is_some_and(|transition| transition.due_cycle <= cycle)
        });
        if raw_events.is_empty() && !has_deferred_transition {
            return Ok(());
        }

        self.writer.advance_to(cycle)?;
        self.apply_deferred_transitions(cycle)?;

        raw_events.sort_by_key(|raw| {
            (
                PipelineEvent::decode(*raw).map_or(u32::MAX, PipelineEvent::order),
                raw.slot,
            )
        });
        for event in raw_events.iter().copied().filter_map(PipelineEvent::decode) {
            self.handle_event(cycle, event)?;
        }
        Ok(())
    }

    /// The event match is the module's lifecycle index. Keep every transition
    /// visible here instead of hiding dispatch behind a table of callbacks.
    fn handle_event(&mut self, cycle: u64, event: PipelineEvent) -> io::Result<()> {
        match event {
            PipelineEvent::Fetch { key, bits } => {
                self.ensure_instruction(key, bits, Stage::FETCH_QUEUE, cycle)?;
            }
            PipelineEvent::BackendReceive { key, bits } => {
                let id = self.ensure_instruction(key, bits, Stage::DECODE, cycle)?;
                self.start_pipeline(id, Stage::DECODE, cycle)?;
            }
            PipelineEvent::Dispatch(dispatch) => self.dispatch(cycle, dispatch)?,
            PipelineEvent::Issue { rob, unit } => self.issue(cycle, rob, unit)?,
            PipelineEvent::MemoryRequest { rob, kind } => self.memory_request(cycle, rob, kind)?,
            PipelineEvent::StoreReady { rob } => self.store_ready(cycle, rob)?,
            PipelineEvent::Writeback { rob } => self.writeback(cycle, rob)?,
            PipelineEvent::Retire { rob, trapped } => self.retire(rob, trapped)?,
            PipelineEvent::Recover { boundary } => self.recover(boundary)?,
            PipelineEvent::Flush => self.flush_all()?,
        }
        Ok(())
    }

    fn ensure_instruction(
        &mut self,
        key: InstructionKey,
        bits: InstructionBits,
        initial_stage: Stage,
        cycle: u64,
    ) -> io::Result<InstructionId> {
        if let Some(&id) = self.by_key.get(&key) {
            return Ok(id);
        }

        let id = InstructionId(self.next_instruction_id);
        self.next_instruction_id += 1;
        self.by_key.insert(key, id);
        self.active.insert(id, ActiveInstruction::new(key));

        self.writer.create_instruction(id)?;
        self.writer.label(
            id,
            Lane::Pipeline,
            format_args!(
                "0x{:08x}: inst=0x{:08x} raw=0x{:08x} fetch={}:{}",
                key.pc, bits.inst, bits.raw_inst, key.epoch, key.sequence
            ),
        )?;
        self.start_pipeline(id, initial_stage, cycle)?;
        Ok(id)
    }

    fn dispatch(&mut self, cycle: u64, event: DispatchEvent) -> io::Result<()> {
        let id = self.ensure_instruction(event.key, event.bits, Stage::DECODE, cycle)?;
        self.bind_rob(id, event.rob)?;
        self.writer
            .label(id, Lane::Rob, format_args!("ROB={}", event.rob.0))?;

        if let Some(instruction) = self.active.get_mut(&id) {
            instruction.is_store = event.is_store;
        }
        self.start_pipeline(
            id,
            if event.needs_issue {
                Stage::ISSUE_QUEUE
            } else {
                Stage::READY
            },
            cycle,
        )?;
        self.start_rob(
            id,
            if event.needs_issue {
                Stage::ROB_WAITING
            } else {
                Stage::ROB_DONE
            },
            cycle,
        )?;
        if event.is_store {
            self.start_tracking(id, Stage::STORE_QUEUE_UNRESOLVED, cycle)?;
        }
        self.write_dependencies(id, event.producers)
    }

    fn issue(&mut self, cycle: u64, rob: RobIndex, unit: ExecutionUnit) -> io::Result<()> {
        let Some(&id) = self.by_rob.get(&rob) else {
            return Ok(());
        };
        self.start_pipeline(id, execution_stage(unit), cycle)?;
        if unit == ExecutionUnit::Lsu {
            self.start_memory(id, Stage::ADDRESS_TRANSLATION, cycle)?;
        }
        Ok(())
    }

    fn memory_request(
        &mut self,
        cycle: u64,
        rob: RobIndex,
        kind: MemoryRequestKind,
    ) -> io::Result<()> {
        let Some(&id) = self.by_rob.get(&rob) else {
            return Ok(());
        };
        self.start_memory(id, memory_stage(kind), cycle)?;
        match kind {
            MemoryRequestKind::Load => {
                self.start_tracking(id, Stage::LOAD_TRANSACTION_QUEUE, cycle)?;
            }
            MemoryRequestKind::AtomicRead | MemoryRequestKind::AtomicWrite => {
                self.start_tracking(id, Stage::ATOMIC_TRANSACTION_QUEUE, cycle)?;
            }
            MemoryRequestKind::PageTableWalk | MemoryRequestKind::Unknown => {}
        }
        Ok(())
    }

    fn store_ready(&mut self, cycle: u64, rob: RobIndex) -> io::Result<()> {
        let Some(&id) = self.by_rob.get(&rob) else {
            return Ok(());
        };
        self.start_tracking(id, Stage::STORE_QUEUE_READY, cycle)?;
        self.end_stage(id, Lane::Memory)
    }

    fn writeback(&mut self, cycle: u64, rob: RobIndex) -> io::Result<()> {
        let Some(&id) = self.by_rob.get(&rob) else {
            return Ok(());
        };

        // A same-cycle issue/writeback would make X-* invisible. Defer RT so
        // every execution stage occupies at least one displayed cycle.
        let zero_cycle_execution = self
            .active
            .get(&id)
            .is_some_and(|instruction| instruction.has_zero_cycle_execution(cycle));
        if zero_cycle_execution {
            if let Some(instruction) = self.active.get_mut(&id) {
                instruction.deferred_pipeline = Some(DeferredTransition {
                    stage: Stage::READY,
                    due_cycle: cycle + 1,
                });
            }
        } else {
            self.start_pipeline(id, Stage::READY, cycle)?;
        }

        self.start_rob(id, Stage::ROB_DONE, cycle)?;
        let is_store = self
            .active
            .get(&id)
            .is_some_and(|instruction| instruction.is_store);
        if !is_store {
            self.end_stage(id, Lane::Tracking)?;
        }
        self.end_stage(id, Lane::Memory)
    }

    fn retire(&mut self, rob: RobIndex, trapped: bool) -> io::Result<()> {
        let Some(&id) = self.by_rob.get(&rob) else {
            return Ok(());
        };
        self.finish_instruction(
            id,
            if trapped {
                RetireCause::Flush
            } else {
                RetireCause::Retire
            },
        )
    }

    fn bind_rob(&mut self, id: InstructionId, rob: RobIndex) -> io::Result<()> {
        if let Some(previous_id) = self.by_rob.insert(rob, id) {
            if previous_id != id {
                self.finish_instruction(previous_id, RetireCause::Flush)?;
                self.by_rob.insert(rob, id);
            }
        }
        if let Some(instruction) = self.active.get_mut(&id) {
            instruction.rob = Some(rob);
        }
        Ok(())
    }

    fn write_dependencies(
        &mut self,
        consumer: InstructionId,
        producers: [Option<RobIndex>; 2],
    ) -> io::Result<()> {
        let mut last_producer = None;
        for rob in producers.into_iter().flatten() {
            let Some(&producer) = self.by_rob.get(&rob) else {
                continue;
            };
            if producer != consumer && last_producer != Some(producer) {
                self.writer.dependency(consumer, producer)?;
                last_producer = Some(producer);
            }
        }
        Ok(())
    }

    fn apply_deferred_transitions(&mut self, cycle: u64) -> io::Result<()> {
        let due = self
            .active
            .iter()
            .filter_map(|(&id, instruction)| {
                instruction
                    .deferred_pipeline
                    .filter(|transition| transition.due_cycle <= cycle)
                    .map(|transition| (id, transition.stage))
            })
            .collect::<Vec<_>>();

        for (id, stage) in due {
            if let Some(instruction) = self.active.get_mut(&id) {
                instruction.deferred_pipeline = None;
            }
            self.start_pipeline(id, stage, cycle)?;
        }
        Ok(())
    }

    fn recover(&mut self, boundary: RobIndex) -> io::Result<()> {
        let Some(&boundary_id) = self.by_rob.get(&boundary) else {
            return self.flush_all();
        };
        let mut flushed = self
            .active
            .iter()
            .filter_map(|(&id, instruction)| {
                (instruction.rob.is_none() || id.0 > boundary_id.0).then_some(id)
            })
            .collect::<Vec<_>>();
        flushed.sort_unstable_by_key(|id| id.0);
        for id in flushed {
            self.finish_instruction(id, RetireCause::Flush)?;
        }
        Ok(())
    }

    fn flush_all(&mut self) -> io::Result<()> {
        let mut ids = self.active.keys().copied().collect::<Vec<_>>();
        ids.sort_unstable_by_key(|id| id.0);
        for id in ids {
            self.finish_instruction(id, RetireCause::Flush)?;
        }
        Ok(())
    }

    fn start_pipeline(&mut self, id: InstructionId, stage: Stage, cycle: u64) -> io::Result<()> {
        self.start_stage(id, Lane::Pipeline, stage, cycle)
    }

    fn start_rob(&mut self, id: InstructionId, stage: Stage, cycle: u64) -> io::Result<()> {
        self.start_stage(id, Lane::Rob, stage, cycle)
    }

    fn start_tracking(&mut self, id: InstructionId, stage: Stage, cycle: u64) -> io::Result<()> {
        self.start_stage(id, Lane::Tracking, stage, cycle)
    }

    fn start_memory(&mut self, id: InstructionId, stage: Stage, cycle: u64) -> io::Result<()> {
        self.start_stage(id, Lane::Memory, stage, cycle)
    }

    fn start_stage(
        &mut self,
        id: InstructionId,
        lane: Lane,
        stage: Stage,
        cycle: u64,
    ) -> io::Result<()> {
        let Some(instruction) = self.active.get_mut(&id) else {
            return Ok(());
        };
        if instruction
            .lanes
            .get(lane)
            .is_some_and(|open| open.name == stage)
        {
            return Ok(());
        }

        self.writer.start(id, lane, stage)?;
        instruction.lanes.set(
            lane,
            Some(OpenStage {
                name: stage,
                start_cycle: cycle,
            }),
        );
        Ok(())
    }

    fn end_stage(&mut self, id: InstructionId, lane: Lane) -> io::Result<()> {
        let Some(instruction) = self.active.get_mut(&id) else {
            return Ok(());
        };
        let Some(stage) = instruction.lanes.get(lane) else {
            return Ok(());
        };

        self.writer.end(id, lane, stage.name)?;
        instruction.lanes.set(lane, None);
        Ok(())
    }

    fn finish_instruction(&mut self, id: InstructionId, cause: RetireCause) -> io::Result<()> {
        let Some(instruction) = self.active.remove(&id) else {
            return Ok(());
        };

        self.writer.retire(id, self.next_retire_id, cause)?;
        if cause == RetireCause::Retire {
            self.next_retire_id += 1;
        }
        self.by_key.remove(&instruction.key);
        if let Some(rob) = instruction.rob {
            if self.by_rob.get(&rob) == Some(&id) {
                self.by_rob.remove(&rob);
            }
        }
        Ok(())
    }
}

const fn execution_stage(unit: ExecutionUnit) -> Stage {
    match unit {
        ExecutionUnit::Alu => Stage::EXEC_ALU,
        ExecutionUnit::Mul => Stage::EXEC_MUL,
        ExecutionUnit::Div => Stage::EXEC_DIV,
        ExecutionUnit::Branch => Stage::EXEC_BRANCH,
        ExecutionUnit::Jump => Stage::EXEC_JUMP,
        ExecutionUnit::Csr => Stage::EXEC_CSR,
        ExecutionUnit::Lsu => Stage::EXEC_LSU,
        ExecutionUnit::Fence => Stage::EXEC_FENCE,
        ExecutionUnit::Unknown => Stage::EXEC_UNKNOWN,
    }
}

const fn memory_stage(kind: MemoryRequestKind) -> Stage {
    match kind {
        MemoryRequestKind::Load => Stage::MEMORY_LOAD,
        MemoryRequestKind::PageTableWalk => Stage::MEMORY_PAGE_TABLE_WALK,
        MemoryRequestKind::AtomicRead => Stage::MEMORY_ATOMIC_READ,
        MemoryRequestKind::AtomicWrite => Stage::MEMORY_ATOMIC_WRITE,
        MemoryRequestKind::Unknown => Stage::MEMORY_UNKNOWN,
    }
}

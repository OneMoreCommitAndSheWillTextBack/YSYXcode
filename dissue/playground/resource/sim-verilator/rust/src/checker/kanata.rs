use crate::ffi::NpcPipelineEvent;
use std::{
    collections::HashMap,
    fs::{self, File},
    io::{self, LineWriter, Write},
    path::{Path, PathBuf},
};

const LANE_PIPELINE: u32 = 0;
const LANE_ROB: u32 = 1;
const LANE_TRACKING: u32 = 2;
const LANE_MEMORY: u32 = 3;

const FLAG_NEEDS_ISSUE: u32 = 0;
const FLAG_SRC1_DEPENDENCY: u32 = 1;
const FLAG_SRC2_DEPENDENCY: u32 = 2;
const FLAG_STORE: u32 = 4;
const FLAG_TRAP: u32 = 6;

const RESOURCE_LSU: u32 = 7;
const RESOURCE_LOAD: u32 = 9;
const RESOURCE_ATOMIC_READ: u32 = 11;
const RESOURCE_ATOMIC_WRITE: u32 = 12;

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
#[repr(u32)]
enum EventKind {
    FetchQueueEnqueue = 1,
    BackendReceive = 2,
    Dispatch = 3,
    Issue = 4,
    MemoryRequest = 5,
    StoreReady = 6,
    Writeback = 7,
    Retire = 8,
    Recover = 9,
    Flush = 10,
}

impl EventKind {
    fn from_raw(kind: u32) -> Option<Self> {
        match kind {
            1 => Some(Self::FetchQueueEnqueue),
            2 => Some(Self::BackendReceive),
            3 => Some(Self::Dispatch),
            4 => Some(Self::Issue),
            5 => Some(Self::MemoryRequest),
            6 => Some(Self::StoreReady),
            7 => Some(Self::Writeback),
            8 => Some(Self::Retire),
            9 => Some(Self::Recover),
            10 => Some(Self::Flush),
            _ => None,
        }
    }

    fn order(self) -> u32 {
        self as u32
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
struct InstructionKey {
    epoch: u32,
    sequence: u32,
    pc: u32,
}

impl From<NpcPipelineEvent> for InstructionKey {
    fn from(event: NpcPipelineEvent) -> Self {
        Self {
            epoch: event.epoch,
            sequence: event.sequence,
            pc: event.pc,
        }
    }
}

#[derive(Debug, Clone, Copy)]
struct Stage {
    name: &'static str,
    start_cycle: u64,
}

#[derive(Debug, Clone, Copy)]
struct PendingStage {
    name: &'static str,
    due_cycle: u64,
}

#[derive(Debug)]
struct ActiveInstruction {
    key: InstructionKey,
    rob_idx: Option<u32>,
    is_store: bool,
    lanes: [Option<Stage>; 4],
    pending_pipeline_stage: Option<PendingStage>,
}

impl ActiveInstruction {
    fn new(key: InstructionKey) -> Self {
        Self {
            key,
            rob_idx: None,
            is_store: false,
            lanes: [None; 4],
            pending_pipeline_stage: None,
        }
    }
}

/// Owns the complete policy for translating semantic RTL events to Kanata v4.
pub(super) struct KanataTrace {
    path: PathBuf,
    writer: LineWriter<File>,
    output_cycle: u64,
    next_instruction_id: u64,
    next_retire_id: u64,
    by_key: HashMap<InstructionKey, u64>,
    by_rob: HashMap<u32, u64>,
    active: HashMap<u64, ActiveInstruction>,
}

impl KanataTrace {
    pub(super) fn create(path: &Path) -> io::Result<Self> {
        if let Some(parent) = path
            .parent()
            .filter(|parent| !parent.as_os_str().is_empty())
        {
            fs::create_dir_all(parent)?;
        }

        let mut writer = LineWriter::new(File::create(path)?);
        writeln!(writer, "Kanata\t0004")?;

        Ok(Self {
            path: path.to_path_buf(),
            writer,
            output_cycle: 0,
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
        events: &mut Vec<NpcPipelineEvent>,
    ) -> io::Result<()> {
        let has_pending_stage = self.active.values().any(|instruction| {
            instruction
                .pending_pipeline_stage
                .is_some_and(|pending| pending.due_cycle <= cycle)
        });
        if events.is_empty() && !has_pending_stage {
            return Ok(());
        }

        self.advance_to(cycle)?;
        self.apply_pending_stages(cycle)?;
        events.sort_by_key(|event| {
            (
                EventKind::from_raw(event.kind).map_or(u32::MAX, EventKind::order),
                event.slot,
            )
        });

        for event in events.iter().copied() {
            self.handle_event(cycle, event)?;
        }
        Ok(())
    }

    fn advance_to(&mut self, cycle: u64) -> io::Result<()> {
        if cycle < self.output_cycle {
            return Err(io::Error::new(
                io::ErrorKind::InvalidData,
                format!(
                    "Kanata cycle moved backwards from {} to {cycle}",
                    self.output_cycle
                ),
            ));
        }
        if cycle > self.output_cycle {
            writeln!(self.writer, "C\t{}", cycle - self.output_cycle)?;
            self.output_cycle = cycle;
        }
        Ok(())
    }

    fn apply_pending_stages(&mut self, cycle: u64) -> io::Result<()> {
        let pending = self
            .active
            .iter()
            .filter_map(|(&id, instruction)| {
                instruction
                    .pending_pipeline_stage
                    .filter(|stage| stage.due_cycle <= cycle)
                    .map(|stage| (id, stage.name))
            })
            .collect::<Vec<_>>();

        for (id, name) in pending {
            if let Some(instruction) = self.active.get_mut(&id) {
                instruction.pending_pipeline_stage = None;
            }
            self.start_stage(id, LANE_PIPELINE, name, cycle)?;
        }
        Ok(())
    }

    fn handle_event(&mut self, cycle: u64, event: NpcPipelineEvent) -> io::Result<()> {
        let Some(kind) = EventKind::from_raw(event.kind) else {
            return Ok(());
        };

        match kind {
            EventKind::FetchQueueEnqueue => {
                self.ensure_instruction(event, "FQ", cycle)?;
            }
            EventKind::BackendReceive => {
                let id = self.ensure_instruction(event, "DC", cycle)?;
                self.start_stage(id, LANE_PIPELINE, "DC", cycle)?;
            }
            EventKind::Dispatch => self.on_dispatch(cycle, event)?,
            EventKind::Issue => self.on_issue(cycle, event)?,
            EventKind::MemoryRequest => self.on_memory_request(cycle, event)?,
            EventKind::StoreReady => self.on_store_ready(cycle, event)?,
            EventKind::Writeback => self.on_writeback(cycle, event)?,
            EventKind::Retire => self.on_retire(event)?,
            EventKind::Recover => self.on_recover(event.rob_idx)?,
            EventKind::Flush => self.flush_all()?,
        }
        Ok(())
    }

    fn ensure_instruction(
        &mut self,
        event: NpcPipelineEvent,
        initial_stage: &'static str,
        cycle: u64,
    ) -> io::Result<u64> {
        let key = InstructionKey::from(event);
        if let Some(&id) = self.by_key.get(&key) {
            return Ok(id);
        }

        let id = self.next_instruction_id;
        self.next_instruction_id += 1;
        self.by_key.insert(key, id);
        self.active.insert(id, ActiveInstruction::new(key));

        writeln!(self.writer, "I\t{id}\t{id}\t0")?;
        writeln!(
            self.writer,
            "L\t{id}\t0\t0x{:08x}: inst=0x{:08x} raw=0x{:08x} fetch={}:{}",
            event.pc, event.inst, event.raw_inst, event.epoch, event.sequence
        )?;
        self.start_stage(id, LANE_PIPELINE, initial_stage, cycle)?;
        Ok(id)
    }

    fn on_dispatch(&mut self, cycle: u64, event: NpcPipelineEvent) -> io::Result<()> {
        let id = self.ensure_instruction(event, "DC", cycle)?;
        self.bind_rob(id, event.rob_idx)?;

        let needs_issue = has_flag(event.flags, FLAG_NEEDS_ISSUE);
        let is_store = has_flag(event.flags, FLAG_STORE);
        if let Some(instruction) = self.active.get_mut(&id) {
            instruction.is_store = is_store;
        }

        writeln!(self.writer, "L\t{id}\t1\tROB={}", event.rob_idx)?;
        self.start_stage(
            id,
            LANE_PIPELINE,
            if needs_issue { "IQ" } else { "RT" },
            cycle,
        )?;
        self.start_stage(
            id,
            LANE_ROB,
            if needs_issue { "ROB-N" } else { "ROB-D" },
            cycle,
        )?;
        if is_store {
            self.start_stage(id, LANE_TRACKING, "SQ-U", cycle)?;
        }

        let mut last_producer = None;
        for (flag, rob_idx) in [
            (FLAG_SRC1_DEPENDENCY, event.producer0),
            (FLAG_SRC2_DEPENDENCY, event.producer1),
        ] {
            if !has_flag(event.flags, flag) {
                continue;
            }
            let Some(&producer_id) = self.by_rob.get(&rob_idx) else {
                continue;
            };
            if producer_id != id && last_producer != Some(producer_id) {
                writeln!(self.writer, "W\t{id}\t{producer_id}\t0")?;
                last_producer = Some(producer_id);
            }
        }
        Ok(())
    }

    fn bind_rob(&mut self, id: u64, rob_idx: u32) -> io::Result<()> {
        if let Some(previous_id) = self.by_rob.insert(rob_idx, id) {
            if previous_id != id {
                self.finish_instruction(previous_id, RetireType::Flush)?;
                self.by_rob.insert(rob_idx, id);
            }
        }
        if let Some(instruction) = self.active.get_mut(&id) {
            instruction.rob_idx = Some(rob_idx);
        }
        Ok(())
    }

    fn on_issue(&mut self, cycle: u64, event: NpcPipelineEvent) -> io::Result<()> {
        let Some(&id) = self.by_rob.get(&event.rob_idx) else {
            return Ok(());
        };
        self.start_stage(id, LANE_PIPELINE, execution_stage(event.resource), cycle)?;
        if event.resource == RESOURCE_LSU {
            self.start_stage(id, LANE_MEMORY, "XLAT", cycle)?;
        }
        Ok(())
    }

    fn on_memory_request(&mut self, cycle: u64, event: NpcPipelineEvent) -> io::Result<()> {
        let Some(&id) = self.by_rob.get(&event.rob_idx) else {
            return Ok(());
        };
        self.start_stage(id, LANE_MEMORY, memory_stage(event.resource), cycle)?;
        if event.resource == RESOURCE_LOAD {
            self.start_stage(id, LANE_TRACKING, "LTQ", cycle)?;
        } else if matches!(event.resource, RESOURCE_ATOMIC_READ | RESOURCE_ATOMIC_WRITE) {
            self.start_stage(id, LANE_TRACKING, "ATQ", cycle)?;
        }
        Ok(())
    }

    fn on_store_ready(&mut self, cycle: u64, event: NpcPipelineEvent) -> io::Result<()> {
        let Some(&id) = self.by_rob.get(&event.rob_idx) else {
            return Ok(());
        };
        self.start_stage(id, LANE_TRACKING, "SQ-R", cycle)?;
        self.end_stage(id, LANE_MEMORY)
    }

    fn on_writeback(&mut self, cycle: u64, event: NpcPipelineEvent) -> io::Result<()> {
        let Some(&id) = self.by_rob.get(&event.rob_idx) else {
            return Ok(());
        };

        let zero_length_execution = self
            .active
            .get(&id)
            .and_then(|instruction| instruction.lanes[LANE_PIPELINE as usize])
            .is_some_and(|stage| stage.name.contains('X') && stage.start_cycle == cycle);
        if zero_length_execution {
            if let Some(instruction) = self.active.get_mut(&id) {
                instruction.pending_pipeline_stage = Some(PendingStage {
                    name: "RT",
                    due_cycle: cycle + 1,
                });
            }
        } else {
            self.start_stage(id, LANE_PIPELINE, "RT", cycle)?;
        }

        self.start_stage(id, LANE_ROB, "ROB-D", cycle)?;
        let is_store = self
            .active
            .get(&id)
            .is_some_and(|instruction| instruction.is_store);
        if !is_store {
            self.end_stage(id, LANE_TRACKING)?;
        }
        self.end_stage(id, LANE_MEMORY)
    }

    fn on_retire(&mut self, event: NpcPipelineEvent) -> io::Result<()> {
        let Some(&id) = self.by_rob.get(&event.rob_idx) else {
            return Ok(());
        };
        self.finish_instruction(
            id,
            if has_flag(event.flags, FLAG_TRAP) {
                RetireType::Flush
            } else {
                RetireType::Retire
            },
        )
    }

    fn on_recover(&mut self, boundary_rob_idx: u32) -> io::Result<()> {
        let boundary_id = self.by_rob.get(&boundary_rob_idx).copied();
        let mut flushed = self
            .active
            .iter()
            .filter_map(|(&id, instruction)| {
                let younger_rob = boundary_id
                    .is_some_and(|boundary| instruction.rob_idx.is_some() && id > boundary);
                (instruction.rob_idx.is_none() || younger_rob).then_some(id)
            })
            .collect::<Vec<_>>();
        flushed.sort_unstable();
        for id in flushed {
            self.finish_instruction(id, RetireType::Flush)?;
        }
        Ok(())
    }

    fn flush_all(&mut self) -> io::Result<()> {
        let mut ids = self.active.keys().copied().collect::<Vec<_>>();
        ids.sort_unstable();
        for id in ids {
            self.finish_instruction(id, RetireType::Flush)?;
        }
        Ok(())
    }

    fn start_stage(
        &mut self,
        id: u64,
        lane: u32,
        name: &'static str,
        cycle: u64,
    ) -> io::Result<()> {
        let lane_index = lane as usize;
        let unchanged = self
            .active
            .get(&id)
            .and_then(|instruction| instruction.lanes[lane_index])
            .is_some_and(|stage| stage.name == name);
        if unchanged {
            return Ok(());
        }

        writeln!(self.writer, "S\t{id}\t{lane}\t{name}")?;
        if let Some(instruction) = self.active.get_mut(&id) {
            instruction.lanes[lane_index] = Some(Stage {
                name,
                start_cycle: cycle,
            });
        }
        Ok(())
    }

    fn end_stage(&mut self, id: u64, lane: u32) -> io::Result<()> {
        let lane_index = lane as usize;
        let Some(stage) = self
            .active
            .get(&id)
            .and_then(|instruction| instruction.lanes[lane_index])
        else {
            return Ok(());
        };

        writeln!(self.writer, "E\t{id}\t{lane}\t{}", stage.name)?;
        if let Some(instruction) = self.active.get_mut(&id) {
            instruction.lanes[lane_index] = None;
        }
        Ok(())
    }

    fn finish_instruction(&mut self, id: u64, retire_type: RetireType) -> io::Result<()> {
        let Some(instruction) = self.active.remove(&id) else {
            return Ok(());
        };

        writeln!(
            self.writer,
            "R\t{id}\t{}\t{}",
            self.next_retire_id, retire_type as u32
        )?;
        if retire_type == RetireType::Retire {
            self.next_retire_id += 1;
        }
        self.by_key.remove(&instruction.key);
        if let Some(rob_idx) = instruction.rob_idx {
            if self.by_rob.get(&rob_idx) == Some(&id) {
                self.by_rob.remove(&rob_idx);
            }
        }
        Ok(())
    }

    #[cfg(test)]
    fn flush_writer(&mut self) -> io::Result<()> {
        self.writer.flush()
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
#[repr(u32)]
enum RetireType {
    Retire = 0,
    Flush = 1,
}

fn has_flag(flags: u32, index: u32) -> bool {
    flags & (1 << index) != 0
}

fn execution_stage(resource: u32) -> &'static str {
    match resource {
        1 => "X-ALU",
        2 => "X-MUL",
        3 => "X-DIV",
        4 => "X-BRU",
        5 => "X-JMP",
        6 => "X-CSR",
        7 => "X-LSU",
        8 => "X-FENCE",
        _ => "X-UNKNOWN",
    }
}

fn memory_stage(resource: u32) -> &'static str {
    match resource {
        9 => "DMQ-LD",
        10 => "DMQ-PTW",
        11 => "DMQ-AMO-R",
        12 => "DMQ-AMO-W",
        _ => "DMQ-UNKNOWN",
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::{
        fs,
        sync::atomic::{AtomicU64, Ordering},
    };

    static NEXT_PATH_ID: AtomicU64 = AtomicU64::new(0);

    fn event(kind: EventKind, slot: u32, sequence: u32, pc: u32) -> NpcPipelineEvent {
        NpcPipelineEvent {
            kind: kind as u32,
            flags: 0,
            slot,
            rob_idx: 0,
            producer0: 0,
            producer1: 0,
            pc,
            inst: 0x0000_0013,
            raw_inst: 0x0000_0013,
            sequence,
            epoch: 1,
            resource: 0,
            txn_id: 0,
        }
    }

    fn trace_path(name: &str) -> PathBuf {
        let id = NEXT_PATH_ID.fetch_add(1, Ordering::Relaxed);
        std::env::temp_dir().join(format!("npc-kanata-{name}-{}-{id}.log", std::process::id()))
    }

    fn finish(mut trace: KanataTrace, path: &Path) -> String {
        trace.flush_writer().unwrap();
        drop(trace);
        let output = fs::read_to_string(path).unwrap();
        fs::remove_file(path).unwrap();
        output
    }

    #[test]
    fn dispatch_splits_iq_rob_and_records_same_packet_dependency() {
        let path = trace_path("dispatch");
        let mut trace = KanataTrace::create(&path).unwrap();
        let producer = event(EventKind::FetchQueueEnqueue, 0, 7, 0x8000_0000);
        let consumer = event(EventKind::FetchQueueEnqueue, 1, 7, 0x8000_0004);
        trace.write_cycle(1, &mut vec![producer, consumer]).unwrap();

        let mut producer_dispatch = event(EventKind::Dispatch, 0, 7, 0x8000_0000);
        producer_dispatch.rob_idx = 15;
        producer_dispatch.flags = 1 << FLAG_NEEDS_ISSUE;
        let mut consumer_dispatch = event(EventKind::Dispatch, 1, 7, 0x8000_0004);
        consumer_dispatch.rob_idx = 0;
        consumer_dispatch.producer0 = 15;
        consumer_dispatch.flags = (1 << FLAG_NEEDS_ISSUE) | (1 << FLAG_SRC1_DEPENDENCY);
        trace
            .write_cycle(2, &mut vec![consumer_dispatch, producer_dispatch])
            .unwrap();

        let mut recover = event(EventKind::Recover, 0, 0, 0);
        recover.rob_idx = 15;
        trace.write_cycle(3, &mut vec![recover]).unwrap();
        let output = finish(trace, &path);

        assert!(output.contains("S\t0\t0\tIQ\nS\t0\t1\tROB-N"));
        assert!(output.contains("W\t1\t0\t0"));
        assert!(output.contains("R\t1\t0\t1"));
        assert!(!output.contains("R\t0\t0\t1"));
    }

    #[test]
    fn zero_latency_execution_keeps_one_visible_x_cycle() {
        let path = trace_path("zero-latency");
        let mut trace = KanataTrace::create(&path).unwrap();
        let fetched = event(EventKind::FetchQueueEnqueue, 0, 1, 0x8000_0000);
        trace.write_cycle(1, &mut vec![fetched]).unwrap();

        let mut dispatch = event(EventKind::Dispatch, 0, 1, 0x8000_0000);
        dispatch.rob_idx = 3;
        dispatch.flags = 1 << FLAG_NEEDS_ISSUE;
        trace.write_cycle(2, &mut vec![dispatch]).unwrap();

        let mut issue = event(EventKind::Issue, 0, 0, 0);
        issue.rob_idx = 3;
        issue.resource = 1;
        let mut writeback = event(EventKind::Writeback, 0, 0, 0);
        writeback.rob_idx = 3;
        trace.write_cycle(3, &mut vec![writeback, issue]).unwrap();

        let mut retire = event(EventKind::Retire, 0, 0, 0);
        retire.rob_idx = 3;
        trace.write_cycle(4, &mut vec![retire]).unwrap();
        let output = finish(trace, &path);
        let lines = output.lines().collect::<Vec<_>>();
        let execute_line = lines
            .iter()
            .position(|line| *line == "S\t0\t0\tX-ALU")
            .unwrap();
        let retire_stage_line = lines
            .iter()
            .position(|line| *line == "S\t0\t0\tRT")
            .unwrap();

        assert!(lines[execute_line + 1..retire_stage_line]
            .iter()
            .any(|line| line.starts_with("C\t")));
    }
}

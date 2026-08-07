use super::{event::CommitGroup, itrace::write_instruction_summary, perf::PerfCounters};
use std::{
    fs::{self, File},
    io::{self, LineWriter, Write},
    path::{Path, PathBuf},
};

const FRONTEND_EVENT_NAMES: [&str; 32] = [
    "icache_request",
    "icache_hit",
    "icache_miss",
    "icache_miss_wait",
    "backend_redirect",
    "icache_invalidate",
    "frontend_empty",
    "axi_request_wait",
    "fetch_queue_empty_with_backend_ready",
    "fetch_queue_full",
    "icache_mshr_active",
    "icache_hit_under_miss",
    "icache_same_line_wait",
    "icache_queued_miss",
    "redirect_during_mshr",
    "redirect_during_mshr_target_hit",
    "stale_response_drop",
    "ras_push",
    "ras_pop",
    "ras_pop_then_push",
    "ras_use",
    "ras_hit",
    "ras_miss",
    "ras_underflow",
    "ras_overflow",
    "ras_checkpoint_restore",
    "ras_recovery_discard",
    "tage_tagged_provider",
    "tage_alternate_disagree",
    "tage_allocation",
    "tage_usefulness_aging",
    "late_override",
];

const MEMORY_EVENT_NAMES: [&str; 21] = [
    "dcache_access",
    "dcache_hit",
    "dcache_miss",
    "dcache_bypass",
    "mshr_alloc",
    "mshr_merge",
    "mshr_full_stall",
    "hit_under_miss",
    "queued_miss",
    "refill_start",
    "refill_complete",
    "refill_fault",
    "load_txn_full_stall",
    "store_queue_alloc",
    "store_queue_full_stall",
    "forward_full",
    "forward_partial",
    "forward_unresolved_stall",
    "store_drain",
    "store_commit",
    "store_response",
];

/// Raw performance callbacks observed during one post-reset driver step.
#[derive(Debug, Default)]
pub(super) struct CycleSample {
    frontend: Option<FrontendSample>,
    issue_queue: Option<IssueQueueSample>,
    memory: Option<MemorySample>,
    div_completions: Vec<DivCompletion>,
    bpu_predictions: Vec<bool>,
}

#[derive(Debug, Clone, Copy)]
struct FrontendSample {
    events: u32,
    fetch_queue_occupancy: u32,
    fetch_queue_enqueue_width: u32,
    fetch_queue_dequeue_width: u32,
}

#[derive(Debug, Clone, Copy)]
struct IssueQueueSample {
    issue_count: u8,
    occupancy: u8,
    block_ready: bool,
    block_operand: bool,
}

#[derive(Debug, Clone, Copy)]
struct MemorySample {
    events: u32,
    mshr_occupancy: u32,
    store_queue_occupancy: u32,
    load_txn_occupancy: u32,
}

#[derive(Debug, Clone, Copy)]
struct DivCompletion {
    cycles: u32,
    special: bool,
}

impl CycleSample {
    pub(super) fn clear(&mut self) {
        *self = Self::default();
    }

    pub(super) fn record_frontend(
        &mut self,
        events: u32,
        fetch_queue_occupancy: u32,
        fetch_queue_enqueue_width: u32,
        fetch_queue_dequeue_width: u32,
    ) {
        self.frontend = Some(FrontendSample {
            events,
            fetch_queue_occupancy,
            fetch_queue_enqueue_width,
            fetch_queue_dequeue_width,
        });
    }

    pub(super) fn record_issue_queue(
        &mut self,
        issue_count: u8,
        occupancy: u8,
        block_ready: bool,
        block_operand: bool,
    ) {
        self.issue_queue = Some(IssueQueueSample {
            issue_count,
            occupancy,
            block_ready,
            block_operand,
        });
    }

    pub(super) fn record_memory(
        &mut self,
        events: u32,
        mshr_occupancy: u32,
        store_queue_occupancy: u32,
        load_txn_occupancy: u32,
    ) {
        self.memory = Some(MemorySample {
            events,
            mshr_occupancy,
            store_queue_occupancy,
            load_txn_occupancy,
        });
    }

    pub(super) fn record_div_completion(&mut self, cycles: u32, special: bool) {
        self.div_completions.push(DivCompletion { cycles, special });
    }

    pub(super) fn record_bpu_prediction(&mut self, correct: bool) {
        self.bpu_predictions.push(correct);
    }
}

pub(super) struct DetailedTrace {
    path: PathBuf,
    writer: LineWriter<File>,
}

impl DetailedTrace {
    pub(super) fn create(path: &Path) -> io::Result<Self> {
        if let Some(parent) = path
            .parent()
            .filter(|parent| !parent.as_os_str().is_empty())
        {
            fs::create_dir_all(parent)?;
        }

        let mut writer = LineWriter::new(File::create(path)?);
        writeln!(
            writer,
            "# one post-reset cycle per line; commits is the architectural retire count"
        )?;

        Ok(Self {
            path: path.to_path_buf(),
            writer,
        })
    }

    pub(super) fn path(&self) -> &Path {
        &self.path
    }

    pub(super) fn write_cycle(
        &mut self,
        cycle: u64,
        commits: u64,
        groups: &[CommitGroup],
        sample: &CycleSample,
    ) -> io::Result<()> {
        write!(self.writer, "cycle={cycle:012} commits={commits} ")?;
        self.write_slots(groups)?;
        write!(self.writer, " frontend=")?;
        write_frontend(&mut self.writer, sample.frontend)?;
        write!(self.writer, " iq=")?;
        write_issue_queue(&mut self.writer, sample.issue_queue)?;
        write!(self.writer, " memory=")?;
        write_memory(&mut self.writer, sample.memory)?;
        write!(self.writer, " div=")?;
        write_div_completions(&mut self.writer, &sample.div_completions)?;
        write!(self.writer, " bpu=")?;
        write_bpu_predictions(&mut self.writer, &sample.bpu_predictions)?;
        write!(self.writer, " interrupts=")?;
        write_interrupts(&mut self.writer, groups)?;
        writeln!(self.writer)
    }

    fn write_slots(&mut self, groups: &[CommitGroup]) -> io::Result<()> {
        write!(self.writer, "slots=[")?;
        let mut has_slot = false;

        for (group_index, group) in groups.iter().copied().enumerate() {
            for (lane_index, entry) in group.trace_lanes() {
                if has_slot {
                    write!(self.writer, ",")?;
                }
                write!(self.writer, "g{group_index}.s{lane_index}:{{")?;
                write_instruction_summary(&mut self.writer, entry)?;
                if entry.finish {
                    write!(self.writer, " finish")?;
                }
                write!(self.writer, "}}")?;
                has_slot = true;
            }
        }

        write!(self.writer, "]")
    }
}

fn write_frontend<W: Write>(writer: &mut W, sample: Option<FrontendSample>) -> io::Result<()> {
    let Some(sample) = sample else {
        return write!(writer, "-");
    };

    write!(writer, "{{events=")?;
    write_event_list(writer, sample.events, &FRONTEND_EVENT_NAMES)?;
    write!(
        writer,
        ",fetch_queue={{occupancy={},accepted_enqueue_width={},dequeue_width={},miss_start_occupancy=",
        sample.fetch_queue_occupancy,
        sample.fetch_queue_enqueue_width,
        sample.fetch_queue_dequeue_width
    )?;
    if (sample.events & (1_u32 << PerfCounters::ICACHE_MISS)) != 0 {
        write!(writer, "{}", sample.fetch_queue_occupancy)?;
    } else {
        write!(writer, "-")?;
    }

    write!(writer, "}}}}")
}

fn write_event_list<W: Write>(writer: &mut W, events: u32, names: &[&str]) -> io::Result<()> {
    write!(writer, "[")?;
    let mut need_separator = false;
    let mut known_mask = 0_u32;

    for (index, name) in names.iter().enumerate() {
        let mask = 1_u32 << index;
        known_mask |= mask;
        if events & mask == 0 {
            continue;
        }
        if need_separator {
            write!(writer, ",")?;
        }
        write!(writer, "{name}")?;
        need_separator = true;
    }

    let unknown = events & !known_mask;
    if unknown != 0 {
        if need_separator {
            write!(writer, ",")?;
        }
        write!(writer, "unknown=0x{unknown:08x}")?;
    }

    write!(writer, "]")
}

fn write_issue_queue<W: Write>(writer: &mut W, sample: Option<IssueQueueSample>) -> io::Result<()> {
    match sample {
        Some(sample) => write!(
            writer,
            "{{issue={},occ={},block_ready={},block_operand={}}}",
            sample.issue_count, sample.occupancy, sample.block_ready, sample.block_operand
        ),
        None => write!(writer, "-"),
    }
}

fn write_memory<W: Write>(writer: &mut W, sample: Option<MemorySample>) -> io::Result<()> {
    let Some(sample) = sample else {
        return write!(writer, "-");
    };

    write!(writer, "{{events=")?;
    write_event_list(writer, sample.events, &MEMORY_EVENT_NAMES)?;
    write!(
        writer,
        ",mshr={},store_queue={},load_txn={}}}",
        sample.mshr_occupancy, sample.store_queue_occupancy, sample.load_txn_occupancy
    )
}

fn write_div_completions<W: Write>(
    writer: &mut W,
    completions: &[DivCompletion],
) -> io::Result<()> {
    write!(writer, "[")?;
    for (index, completion) in completions.iter().enumerate() {
        if index != 0 {
            write!(writer, ",")?;
        }
        write!(
            writer,
            "{{cycles={},special={}}}",
            completion.cycles, completion.special
        )?;
    }
    write!(writer, "]")
}

fn write_bpu_predictions<W: Write>(writer: &mut W, predictions: &[bool]) -> io::Result<()> {
    write!(writer, "[")?;
    for (index, correct) in predictions.iter().enumerate() {
        if index != 0 {
            write!(writer, ",")?;
        }
        write!(writer, "{}", if *correct { "correct" } else { "incorrect" })?;
    }
    write!(writer, "]")
}

fn write_interrupts<W: Write>(writer: &mut W, groups: &[CommitGroup]) -> io::Result<()> {
    write!(writer, "[")?;
    let mut need_separator = false;

    for group in groups {
        let Some(interrupt) = (*group).async_interrupt() else {
            continue;
        };
        if need_separator {
            write!(writer, ",")?;
        }
        write!(
            writer,
            "{{cause=0x{:08x},epc=0x{:08x}}}",
            interrupt.cause(),
            interrupt.epc()
        )?;
        need_separator = true;
    }

    write!(writer, "]")
}

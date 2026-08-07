use std::{
    fmt,
    fs::{self, File},
    io::{self, LineWriter, Write},
    path::Path,
};

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub(super) struct InstructionId(pub(super) u64);

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub(super) struct Stage(pub(super) &'static str);

impl Stage {
    pub(super) const FETCH_QUEUE: Self = Self("FQ");
    pub(super) const DECODE: Self = Self("DC");
    pub(super) const ISSUE_QUEUE: Self = Self("IQ");
    pub(super) const READY: Self = Self("RT");

    pub(super) const EXEC_ALU: Self = Self("X-ALU");
    pub(super) const EXEC_MUL: Self = Self("X-MUL");
    pub(super) const EXEC_DIV: Self = Self("X-DIV");
    pub(super) const EXEC_BRANCH: Self = Self("X-BRU");
    pub(super) const EXEC_JUMP: Self = Self("X-JMP");
    pub(super) const EXEC_CSR: Self = Self("X-CSR");
    pub(super) const EXEC_LSU: Self = Self("X-LSU");
    pub(super) const EXEC_FENCE: Self = Self("X-FENCE");
    pub(super) const EXEC_UNKNOWN: Self = Self("X-UNKNOWN");

    pub(super) const ROB_WAITING: Self = Self("ROB-N");
    pub(super) const ROB_DONE: Self = Self("ROB-D");
    pub(super) const STORE_QUEUE_UNRESOLVED: Self = Self("SQ-U");
    pub(super) const STORE_QUEUE_READY: Self = Self("SQ-R");
    pub(super) const STORE_QUEUE_COMMITTED: Self = Self("SQ-C");
    pub(super) const STORE_QUEUE_ISSUED: Self = Self("SQ-I");
    pub(super) const LOAD_TRANSACTION_QUEUE: Self = Self("LTQ");
    pub(super) const ATOMIC_TRANSACTION_QUEUE: Self = Self("ATQ");
    pub(super) const ADDRESS_TRANSLATION: Self = Self("XLAT");
    pub(super) const MEMORY_LOAD: Self = Self("DMQ-LD");
    pub(super) const MEMORY_PAGE_TABLE_WALK: Self = Self("DMQ-PTW");
    pub(super) const MEMORY_ATOMIC_READ: Self = Self("DMQ-AMO-R");
    pub(super) const MEMORY_ATOMIC_WRITE: Self = Self("DMQ-AMO-W");
    pub(super) const MEMORY_STORE: Self = Self("DMQ-ST");
    pub(super) const MEMORY_UNKNOWN: Self = Self("DMQ-UNKNOWN");

    pub(super) fn is_execution(self) -> bool {
        self.0.starts_with("X-")
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
#[repr(u32)]
pub(super) enum Lane {
    Pipeline = 0,
    Rob = 1,
    Tracking = 2,
    Memory = 3,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
#[repr(u32)]
pub(super) enum RetireCause {
    Retire = 0,
    Flush = 1,
}

pub(super) struct KonataWriter {
    output: LineWriter<File>,
    cycle: u64,
}

impl KonataWriter {
    pub(super) fn create(path: &Path) -> io::Result<Self> {
        if let Some(parent) = path.parent().filter(|path| !path.as_os_str().is_empty()) {
            fs::create_dir_all(parent)?;
        }

        let mut output = LineWriter::new(File::create(path)?);
        writeln!(output, "Kanata\t0004")?;
        Ok(Self { output, cycle: 0 })
    }

    pub(super) fn advance_to(&mut self, cycle: u64) -> io::Result<()> {
        if cycle < self.cycle {
            return Err(io::Error::new(
                io::ErrorKind::InvalidData,
                format!(
                    "Kanata cycle moved backwards from {} to {cycle}",
                    self.cycle
                ),
            ));
        }
        if cycle > self.cycle {
            writeln!(self.output, "C\t{}", cycle - self.cycle)?;
            self.cycle = cycle;
        }
        Ok(())
    }

    pub(super) fn create_instruction(&mut self, id: InstructionId) -> io::Result<()> {
        writeln!(self.output, "I\t{}\t{}\t0", id.0, id.0)
    }

    pub(super) fn create_store_transaction(
        &mut self,
        id: InstructionId,
        transaction_id: u64,
    ) -> io::Result<()> {
        writeln!(self.output, "I\t{}\t{}\t1", id.0, transaction_id)
    }

    pub(super) fn label(
        &mut self,
        id: InstructionId,
        lane: Lane,
        label: fmt::Arguments<'_>,
    ) -> io::Result<()> {
        writeln!(self.output, "L\t{}\t{}\t{label}", id.0, lane as u32)
    }

    pub(super) fn start(&mut self, id: InstructionId, lane: Lane, stage: Stage) -> io::Result<()> {
        writeln!(self.output, "S\t{}\t{}\t{}", id.0, lane as u32, stage.0)
    }

    pub(super) fn end(&mut self, id: InstructionId, lane: Lane, stage: Stage) -> io::Result<()> {
        writeln!(self.output, "E\t{}\t{}\t{}", id.0, lane as u32, stage.0)
    }

    pub(super) fn dependency(
        &mut self,
        consumer: InstructionId,
        producer: InstructionId,
    ) -> io::Result<()> {
        writeln!(self.output, "W\t{}\t{}\t0", consumer.0, producer.0)
    }

    pub(super) fn retire(
        &mut self,
        id: InstructionId,
        retire_id: u64,
        cause: RetireCause,
    ) -> io::Result<()> {
        writeln!(self.output, "R\t{}\t{retire_id}\t{}", id.0, cause as u32)
    }
}

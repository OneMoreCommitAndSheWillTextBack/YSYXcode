use super::{event::CommitTraceEntry, CommitGroup};
use std::{
    fs::{self, File},
    io::{self, LineWriter, Write},
    path::{Path, PathBuf},
};

#[derive(Debug)]
pub struct Itrace {
    path: PathBuf,
    writer: LineWriter<File>,
    seq: u64,
}

impl Itrace {
    pub fn create(path: &Path) -> io::Result<Self> {
        if let Some(parent) = path
            .parent()
            .filter(|parent| !parent.as_os_str().is_empty())
        {
            fs::create_dir_all(parent)?;
        }

        Ok(Self {
            path: path.to_path_buf(),
            writer: LineWriter::new(File::create(path)?),
            seq: 0,
        })
    }

    pub fn path(&self) -> &Path {
        &self.path
    }

    pub fn write_commit_group(&mut self, event: &CommitGroup) -> io::Result<()> {
        for entry in event.trace_entries() {
            self.write_entry(entry)?;
        }

        Ok(())
    }

    fn write_entry(&mut self, entry: CommitTraceEntry) -> io::Result<()> {
        let seq = self.seq;
        self.seq = self.seq.wrapping_add(1);

        write!(
            self.writer,
            "{seq:016} 0x{pc:08x}: {raw} -> 0x{next_pc:08x}",
            pc = entry.pc,
            raw = raw_inst_text(entry),
            next_pc = entry.next_pc,
        )?;

        if entry.raw_inst != entry.inst {
            write!(self.writer, " inst=0x{:08x}", entry.inst)?;
        }

        if let Some(flow) = control_flow_text(entry) {
            write!(self.writer, " flow={flow}")?;
        }

        if entry.mem_valid {
            let op = if entry.mem_write { 'W' } else { 'R' };
            write!(
                self.writer,
                " mem={op}[0x{addr:08x},{}]",
                mem_access_len(entry.mem_size),
                addr = entry.mem_addr,
            )?;
        }

        writeln!(self.writer)
    }
}

fn raw_inst_text(entry: CommitTraceEntry) -> String {
    if entry.inst_len == 2 {
        format!("0x{:04x}", entry.raw_inst & 0xffff)
    } else {
        format!("0x{:08x}", entry.raw_inst)
    }
}

fn control_flow_text(entry: CommitTraceEntry) -> Option<&'static str> {
    let sequential_next = entry.pc.wrapping_add(inst_len(entry));
    let opcode = entry.inst & 0x7f;
    let kind = match opcode {
        0x63 => Some("branch"),
        0x6f => Some("jal"),
        0x67 => Some("jalr"),
        0x73 => system_flow(entry.inst),
        _ => None,
    };

    kind.or_else(|| (entry.next_pc != sequential_next).then_some("redirect"))
}

fn system_flow(inst: u32) -> Option<&'static str> {
    match inst {
        0x0000_0073 => Some("ecall"),
        0x0010_0073 => Some("ebreak"),
        0x1020_0073 => Some("sret"),
        0x3020_0073 => Some("mret"),
        _ => None,
    }
}

fn inst_len(entry: CommitTraceEntry) -> u32 {
    match entry.inst_len {
        2 | 4 => entry.inst_len,
        _ if entry.raw_inst & 0x3 != 0x3 => 2,
        _ => 4,
    }
}

fn mem_access_len(size: u32) -> u32 {
    match size {
        0 => 1,
        1 => 2,
        _ => 4,
    }
}

use crate::ffi::NpcPipelineEvent;

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub(super) struct RobIndex(pub(super) u32);

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub(super) struct InstructionKey {
    pub(super) epoch: u32,
    pub(super) sequence: u32,
    pub(super) pc: u32,
}

#[derive(Debug, Clone, Copy)]
pub(super) struct InstructionBits {
    pub(super) inst: u32,
    pub(super) raw_inst: u32,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub(super) enum ExecutionUnit {
    Alu,
    Mul,
    Div,
    Branch,
    Jump,
    Csr,
    Lsu,
    Fence,
    Unknown,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub(super) enum MemoryRequestKind {
    Load,
    PageTableWalk,
    AtomicRead,
    AtomicWrite,
    Unknown,
}

#[derive(Debug, Clone, Copy)]
pub(super) struct DispatchEvent {
    pub(super) key: InstructionKey,
    pub(super) bits: InstructionBits,
    pub(super) rob: RobIndex,
    pub(super) needs_issue: bool,
    pub(super) is_store: bool,
    pub(super) producers: [Option<RobIndex>; 2],
}

#[derive(Debug, Clone, Copy)]
pub(super) enum PipelineEvent {
    Fetch {
        key: InstructionKey,
        bits: InstructionBits,
    },
    BackendReceive {
        key: InstructionKey,
        bits: InstructionBits,
    },
    Dispatch(DispatchEvent),
    Issue {
        rob: RobIndex,
        unit: ExecutionUnit,
    },
    MemoryRequest {
        rob: RobIndex,
        kind: MemoryRequestKind,
    },
    StoreReady {
        rob: RobIndex,
    },
    Writeback {
        rob: RobIndex,
    },
    Retire {
        rob: RobIndex,
        trapped: bool,
    },
    Recover {
        boundary: RobIndex,
    },
    Flush,
}

impl PipelineEvent {
    pub(super) fn decode(raw: NpcPipelineEvent) -> Option<Self> {
        let key = InstructionKey {
            epoch: raw.epoch,
            sequence: raw.sequence,
            pc: raw.pc,
        };
        let bits = InstructionBits {
            inst: raw.inst,
            raw_inst: raw.raw_inst,
        };

        Some(match raw.kind {
            kind::FETCH => Self::Fetch { key, bits },
            kind::BACKEND_RECEIVE => Self::BackendReceive { key, bits },
            kind::DISPATCH => Self::Dispatch(DispatchEvent {
                key,
                bits,
                rob: RobIndex(raw.rob_idx),
                needs_issue: flag(raw.flags, flag::NEEDS_ISSUE),
                is_store: flag(raw.flags, flag::STORE),
                producers: [
                    flag(raw.flags, flag::SRC1_DEPENDENCY).then_some(RobIndex(raw.producer0)),
                    flag(raw.flags, flag::SRC2_DEPENDENCY).then_some(RobIndex(raw.producer1)),
                ],
            }),
            kind::ISSUE => Self::Issue {
                rob: RobIndex(raw.rob_idx),
                unit: ExecutionUnit::decode(raw.resource),
            },
            kind::MEMORY_REQUEST => Self::MemoryRequest {
                rob: RobIndex(raw.rob_idx),
                kind: MemoryRequestKind::decode(raw.resource),
            },
            kind::STORE_READY => Self::StoreReady {
                rob: RobIndex(raw.rob_idx),
            },
            kind::WRITEBACK => Self::Writeback {
                rob: RobIndex(raw.rob_idx),
            },
            kind::RETIRE => Self::Retire {
                rob: RobIndex(raw.rob_idx),
                trapped: flag(raw.flags, flag::TRAP),
            },
            kind::RECOVER => Self::Recover {
                boundary: RobIndex(raw.rob_idx),
            },
            kind::FLUSH => Self::Flush,
            _ => return None,
        })
    }

    pub(super) const fn order(self) -> u32 {
        match self {
            Self::Fetch { .. } => kind::FETCH,
            Self::BackendReceive { .. } => kind::BACKEND_RECEIVE,
            Self::Dispatch(_) => kind::DISPATCH,
            Self::Issue { .. } => kind::ISSUE,
            Self::MemoryRequest { .. } => kind::MEMORY_REQUEST,
            Self::StoreReady { .. } => kind::STORE_READY,
            Self::Writeback { .. } => kind::WRITEBACK,
            Self::Retire { .. } => kind::RETIRE,
            Self::Recover { .. } => kind::RECOVER,
            Self::Flush => kind::FLUSH,
        }
    }
}

impl ExecutionUnit {
    const fn decode(raw: u32) -> Self {
        match raw {
            resource::ALU => Self::Alu,
            resource::MUL => Self::Mul,
            resource::DIV => Self::Div,
            resource::BRANCH => Self::Branch,
            resource::JUMP => Self::Jump,
            resource::CSR => Self::Csr,
            resource::LSU => Self::Lsu,
            resource::FENCE => Self::Fence,
            _ => Self::Unknown,
        }
    }
}

impl MemoryRequestKind {
    const fn decode(raw: u32) -> Self {
        match raw {
            resource::LOAD => Self::Load,
            resource::PAGE_TABLE_WALK => Self::PageTableWalk,
            resource::ATOMIC_READ => Self::AtomicRead,
            resource::ATOMIC_WRITE => Self::AtomicWrite,
            _ => Self::Unknown,
        }
    }
}

const fn flag(flags: u32, index: u32) -> bool {
    flags & (1 << index) != 0
}

// Numeric ABI shared with PipelineTrace.scala.
mod kind {
    pub(super) const FETCH: u32 = 1;
    pub(super) const BACKEND_RECEIVE: u32 = 2;
    pub(super) const DISPATCH: u32 = 3;
    pub(super) const ISSUE: u32 = 4;
    pub(super) const MEMORY_REQUEST: u32 = 5;
    pub(super) const STORE_READY: u32 = 6;
    pub(super) const WRITEBACK: u32 = 7;
    pub(super) const RETIRE: u32 = 8;
    pub(super) const RECOVER: u32 = 9;
    pub(super) const FLUSH: u32 = 10;
}

mod flag {
    pub(super) const NEEDS_ISSUE: u32 = 0;
    pub(super) const SRC1_DEPENDENCY: u32 = 1;
    pub(super) const SRC2_DEPENDENCY: u32 = 2;
    pub(super) const STORE: u32 = 4;
    pub(super) const TRAP: u32 = 6;
}

mod resource {
    pub(super) const ALU: u32 = 1;
    pub(super) const MUL: u32 = 2;
    pub(super) const DIV: u32 = 3;
    pub(super) const BRANCH: u32 = 4;
    pub(super) const JUMP: u32 = 5;
    pub(super) const CSR: u32 = 6;
    pub(super) const LSU: u32 = 7;
    pub(super) const FENCE: u32 = 8;
    pub(super) const LOAD: u32 = 9;
    pub(super) const PAGE_TABLE_WALK: u32 = 10;
    pub(super) const ATOMIC_READ: u32 = 11;
    pub(super) const ATOMIC_WRITE: u32 = 12;
}

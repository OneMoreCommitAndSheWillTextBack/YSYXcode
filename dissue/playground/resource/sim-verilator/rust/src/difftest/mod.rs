mod abi;
mod backend;
mod compare;
mod csr;

pub use compare::DifftestMismatch;
pub(crate) use csr::CSR_DIFF_SPECS;

use crate::{config::DifftestRef, cpu::CpuContext};
use backend::RefBackend;
use compare::compare_contexts;
use std::{mem, os::raw::c_int, path::PathBuf};

const DEFAULT_DIFFTEST_PORT: c_int = 1234;

#[derive(Debug)]
pub enum DifftestError {
    ReferenceNotLoaded,
    InvalidReferencePath {
        path: PathBuf,
    },
    LoadFailed {
        path: PathBuf,
        message: String,
    },
    MissingSymbol {
        path: PathBuf,
        symbol: &'static str,
        message: String,
    },
    Mismatch {
        pc: u32,
        mismatch: DifftestMismatch,
        dut: CpuContext,
        reference: CpuContext,
    },
}

pub type DifftestResult<T> = Result<T, DifftestError>;

#[derive(Debug)]
pub struct DiffTest {
    state: DifftestState,
}

#[derive(Debug)]
enum DifftestState {
    Disabled,
    Detached(RefBackend),
    Attached(RefBackend),
}

impl DiffTest {
    pub fn new(reference: Option<DifftestRef>) -> DifftestResult<Self> {
        let state = match reference {
            Some(reference) => {
                DifftestState::Detached(RefBackend::load(&reference.path(), DEFAULT_DIFFTEST_PORT)?)
            }
            None => DifftestState::Disabled,
        };

        Ok(Self { state })
    }

    pub(crate) fn needs_attach_context(&self) -> bool {
        !matches!(self.state, DifftestState::Disabled)
    }

    pub(crate) fn needs_check_context(&self) -> bool {
        matches!(self.state, DifftestState::Attached(_))
    }

    pub fn sync_memory(&mut self, addr: u32, data: &[u8]) -> DifftestResult<()> {
        match &mut self.state {
            DifftestState::Disabled => Ok(()),
            DifftestState::Detached(backend) | DifftestState::Attached(backend) => {
                backend.copy_memory_to_ref(addr, data);
                Ok(())
            }
        }
    }

    pub fn attach(&mut self, context: &CpuContext) -> DifftestResult<()> {
        self.state = match mem::replace(&mut self.state, DifftestState::Disabled) {
            DifftestState::Disabled => DifftestState::Disabled,
            DifftestState::Detached(mut backend) | DifftestState::Attached(mut backend) => {
                backend.copy_context_to_ref(context);
                DifftestState::Attached(backend)
            }
        };

        Ok(())
    }

    pub fn detach(&mut self) {
        self.state = match mem::replace(&mut self.state, DifftestState::Disabled) {
            DifftestState::Attached(backend) => DifftestState::Detached(backend),
            state => state,
        };
    }

    pub fn step_and_sync(&mut self, steps: u64, context: &CpuContext) -> DifftestResult<()> {
        match &mut self.state {
            DifftestState::Disabled => {}
            DifftestState::Detached(backend) => {
                backend.copy_context_to_ref(context);
            }
            DifftestState::Attached(backend) => {
                if steps > 0 {
                    backend.exec(steps);
                }
                backend.copy_context_to_ref(context);
            }
        }

        Ok(())
    }

    pub fn step_and_check(&mut self, steps: u64, context: &CpuContext) -> DifftestResult<()> {
        let DifftestState::Attached(backend) = &mut self.state else {
            return Ok(());
        };

        if steps == 0 {
            return Ok(());
        }

        backend.exec(steps);
        let reference = backend.copy_context_from_ref();
        compare_contexts(context, &reference)
    }
}

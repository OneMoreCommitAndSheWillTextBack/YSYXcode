mod abi;
mod backend;
mod compare;
mod csr;

pub use compare::DifftestMismatch;
pub(crate) use csr::CSR_DIFF_SPECS;

use crate::{config::DifftestRef, cpu::CpuContext};
use backend::RefBackend;
use compare::{compare_contexts, compare_contexts_except_gprs};
use std::{fmt, mem, os::raw::c_int, path::PathBuf};

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
    InterruptEpcMismatch {
        cause: u32,
        expected_epc: u32,
        reference_pc: u32,
    },
    Mismatch {
        pc: u32,
        mismatch: DifftestMismatch,
        dut: CpuContext,
        reference: CpuContext,
    },
}

impl fmt::Display for DifftestError {
    fn fmt(&self, formatter: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Self::ReferenceNotLoaded => write!(formatter, "difftest reference is not loaded"),
            Self::InvalidReferencePath { path } => {
                write!(formatter, "invalid difftest reference path `{}`", path.display())
            }
            Self::LoadFailed { path, message } => write!(
                formatter,
                "failed to load difftest reference `{}`: {message}",
                path.display()
            ),
            Self::MissingSymbol {
                path,
                symbol,
                message,
            } => write!(
                formatter,
                "difftest reference `{}` is missing symbol `{symbol}`: {message}",
                path.display()
            ),
            Self::InterruptEpcMismatch {
                cause,
                expected_epc,
                reference_pc,
            } => write!(
                formatter,
                "interrupt 0x{cause:08x} expected EPC 0x{expected_epc:08x}, reference PC is 0x{reference_pc:08x}"
            ),
            Self::Mismatch { pc, mismatch, .. } => {
                write!(formatter, "difftest mismatch at PC 0x{pc:08x}: {mismatch}")
            }
        }
    }
}

impl std::error::Error for DifftestError {}

pub type DifftestResult<T> = Result<T, DifftestError>;

#[derive(Debug, Clone, Copy)]
struct InterruptInjection {
    cause: u32,
    expected_epc: u32,
}

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
        self.step_interrupt_and_check(steps, None, context, 0, false)
    }

    pub fn step_raise_interrupt_and_check(
        &mut self,
        steps: u64,
        cause: u32,
        expected_epc: u32,
        context: &CpuContext,
    ) -> DifftestResult<()> {
        let interrupt = InterruptInjection {
            cause,
            expected_epc,
        };
        self.step_interrupt_and_check(steps, Some(interrupt), context, 0, false)
    }

    pub fn step_and_check_except_gprs_and_sync(
        &mut self,
        steps: u64,
        context: &CpuContext,
        ignored_gpr_mask: u32,
    ) -> DifftestResult<()> {
        self.step_interrupt_and_check(steps, None, context, ignored_gpr_mask, true)
    }

    pub fn step_raise_interrupt_and_check_except_gprs_and_sync(
        &mut self,
        steps: u64,
        cause: u32,
        expected_epc: u32,
        context: &CpuContext,
        ignored_gpr_mask: u32,
    ) -> DifftestResult<()> {
        let interrupt = InterruptInjection {
            cause,
            expected_epc,
        };
        self.step_interrupt_and_check(steps, Some(interrupt), context, ignored_gpr_mask, true)
    }

    fn step_interrupt_and_check(
        &mut self,
        steps: u64,
        interrupt: Option<InterruptInjection>,
        context: &CpuContext,
        ignored_gpr_mask: u32,
        sync_context: bool,
    ) -> DifftestResult<()> {
        let DifftestState::Attached(backend) = &mut self.state else {
            return Ok(());
        };

        if steps > 0 {
            backend.exec(steps);
        }

        if let Some(interrupt) = interrupt {
            let reference_pc = backend.copy_context_from_ref().pc;
            if reference_pc != interrupt.expected_epc {
                return Err(DifftestError::InterruptEpcMismatch {
                    cause: interrupt.cause,
                    expected_epc: interrupt.expected_epc,
                    reference_pc,
                });
            }
            backend.raise_interrupt(interrupt.cause);
        } else if steps == 0 {
            return Ok(());
        }

        let reference = backend.copy_context_from_ref();
        if ignored_gpr_mask == 0 {
            compare_contexts(context, &reference)?;
        } else {
            compare_contexts_except_gprs(context, &reference, ignored_gpr_mask)?;
        }

        if sync_context {
            backend.copy_context_to_ref(context);
        }

        Ok(())
    }
}

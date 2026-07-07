use super::{DifftestError, DifftestResult, CSR_DIFF_SPECS};
use crate::cpu::{CpuContext, PrivMode};

#[derive(Debug, Clone, PartialEq, Eq)]
pub enum DifftestMismatch {
    Pc {
        dut: u32,
        reference: u32,
    },
    Gpr {
        index: usize,
        dut: u32,
        reference: u32,
    },
    Priv {
        dut: PrivMode,
        reference: PrivMode,
    },
    Csr {
        name: &'static str,
        dut: u32,
        reference: u32,
    },
}

pub(super) fn compare_contexts(dut: &CpuContext, reference: &CpuContext) -> DifftestResult<()> {
    compare_contexts_raw(dut, reference).map_err(|mismatch| DifftestError::Mismatch {
        pc: dut.pc,
        mismatch,
        dut: *dut,
        reference: *reference,
    })
}

fn compare_contexts_raw(dut: &CpuContext, reference: &CpuContext) -> Result<(), DifftestMismatch> {
    if dut.pc != reference.pc {
        return Err(DifftestMismatch::Pc {
            dut: dut.pc,
            reference: reference.pc,
        });
    }

    for (index, (&dut_value, &ref_value)) in dut.gpr.iter().zip(reference.gpr.iter()).enumerate() {
        if dut_value != ref_value {
            return Err(DifftestMismatch::Gpr {
                index,
                dut: dut_value,
                reference: ref_value,
            });
        }
    }

    for spec in CSR_DIFF_SPECS {
        if spec.diff_enabled() {
            compare_csr(spec.name(), spec.read(&dut.csr), spec.read(&reference.csr))?;
        }
    }

    if dut.priv_mode != reference.priv_mode {
        return Err(DifftestMismatch::Priv {
            dut: dut.priv_mode,
            reference: reference.priv_mode,
        });
    }

    Ok(())
}

fn compare_csr(name: &'static str, dut: u32, reference: u32) -> Result<(), DifftestMismatch> {
    if dut == reference {
        return Ok(());
    }

    Err(DifftestMismatch::Csr {
        name,
        dut,
        reference,
    })
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::cpu::{CpuContext, PrivMode};

    fn context_with_pc(pc: u32) -> CpuContext {
        CpuContext {
            pc,
            priv_mode: PrivMode::Machine,
            ..CpuContext::default()
        }
    }

    #[test]
    fn compare_reports_gpr_mismatch() {
        let dut = context_with_pc(0x8000_0000);
        let mut reference = dut;
        reference.gpr.as_mut_slice()[10] = 1;

        let mismatch = compare_contexts_raw(&dut, &reference).unwrap_err();
        assert!(matches!(mismatch, DifftestMismatch::Gpr { index: 10, .. }));
    }

    #[test]
    fn compare_ignores_counter_csrs() {
        let mut dut = context_with_pc(0x8000_0000);
        let mut reference = dut;
        dut.csr.mcycle = 16;
        dut.csr.minstret = 2;
        reference.csr.mcycle = 0;
        reference.csr.minstret = 0;

        compare_contexts_raw(&dut, &reference).unwrap();
    }
}

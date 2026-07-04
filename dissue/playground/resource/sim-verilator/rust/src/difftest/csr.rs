use crate::cpu::CsrContext;

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
enum DifftestCsr {
    Mstatus,
    Mtvec,
    Mepc,
    Mcause,
    Mtval,
    Mie,
    Mip,
    Mscratch,
    Mcycle,
    Minstret,
}

impl DifftestCsr {
    fn name(self) -> &'static str {
        match self {
            Self::Mstatus => "mstatus",
            Self::Mtvec => "mtvec",
            Self::Mepc => "mepc",
            Self::Mcause => "mcause",
            Self::Mtval => "mtval",
            Self::Mie => "mie",
            Self::Mip => "mip",
            Self::Mscratch => "mscratch",
            Self::Mcycle => "mcycle",
            Self::Minstret => "minstret",
        }
    }

    fn read(self, csr: &CsrContext) -> u32 {
        match self {
            Self::Mstatus => csr.mstatus,
            Self::Mtvec => csr.mtvec,
            Self::Mepc => csr.mepc,
            Self::Mcause => csr.mcause,
            Self::Mtval => csr.mtval,
            Self::Mie => csr.mie,
            Self::Mip => csr.mip,
            Self::Mscratch => csr.mscratch,
            Self::Mcycle => csr.mcycle,
            Self::Minstret => csr.minstret,
        }
    }
}

#[derive(Debug, Clone, Copy)]
pub(crate) struct CsrDiffSpec {
    csr: DifftestCsr,
    diff: bool,
}

impl CsrDiffSpec {
    pub(crate) fn name(self) -> &'static str {
        self.csr.name()
    }

    pub(crate) fn read(self, context: &CsrContext) -> u32 {
        self.csr.read(context)
    }

    pub(crate) fn diff_enabled(self) -> bool {
        self.diff
    }
}

pub(crate) const CSR_DIFF_SPECS: [CsrDiffSpec; 10] = [
    CsrDiffSpec {
        csr: DifftestCsr::Mstatus,
        diff: true,
    },
    CsrDiffSpec {
        csr: DifftestCsr::Mtvec,
        diff: true,
    },
    CsrDiffSpec {
        csr: DifftestCsr::Mepc,
        diff: true,
    },
    CsrDiffSpec {
        csr: DifftestCsr::Mcause,
        diff: true,
    },
    CsrDiffSpec {
        csr: DifftestCsr::Mtval,
        diff: true,
    },
    CsrDiffSpec {
        csr: DifftestCsr::Mie,
        diff: false,
    },
    CsrDiffSpec {
        csr: DifftestCsr::Mip,
        diff: false,
    },
    CsrDiffSpec {
        csr: DifftestCsr::Mscratch,
        diff: false,
    },
    CsrDiffSpec {
        csr: DifftestCsr::Mcycle,
        diff: false,
    },
    CsrDiffSpec {
        csr: DifftestCsr::Minstret,
        diff: false,
    },
];

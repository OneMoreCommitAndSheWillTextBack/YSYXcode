use crate::common::CsrContext;

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
    Medeleg,
    Mideleg,
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
            Self::Medeleg => "medeleg",
            Self::Mideleg => "mideleg",
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
            Self::Medeleg => csr.medeleg,
            Self::Mideleg => csr.mideleg,
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

pub(crate) const CSR_DIFF_SPECS: [CsrDiffSpec; 12] = [
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
        diff: true,
    },
    CsrDiffSpec {
        csr: DifftestCsr::Mip,
        // The reference has no CLINT/PLIC; accesses synchronize the full DUT context instead.
        diff: false,
    },
    CsrDiffSpec {
        csr: DifftestCsr::Mscratch,
        diff: true,
    },
    CsrDiffSpec {
        csr: DifftestCsr::Medeleg,
        diff: true,
    },
    CsrDiffSpec {
        csr: DifftestCsr::Mideleg,
        diff: true,
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

use super::SimulatorError;
use crate::{
    cpu::CpuContext,
    difftest::{DifftestError, DifftestMismatch},
};

const REG_NAMES: [&str; 32] = [
    "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2", "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
    "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7", "s8", "s9", "s10", "s11", "t3", "t4", "t5",
    "t6",
];

const C_RESET: &str = "\x1b[0m";
const C_HDR: &str = "\x1b[36m";
const C_NAME: &str = "\x1b[33m";
const C_VAL: &str = "\x1b[32m";
const C_DIFF: &str = "\x1b[31m";

pub(super) fn print_difftest_report(error: &SimulatorError) {
    let SimulatorError::Difftest(DifftestError::Mismatch {
        pc,
        mismatch,
        dut,
        reference,
    }) = error
    else {
        return;
    };

    eprintln!("{C_HDR}[difftest] context mismatch after DUT pc 0x{pc:08x}{C_RESET}");
    print_mismatch_summary(mismatch);
    print_pc_summary(dut, reference);
    print_gpr_table(dut, reference);
}

fn print_mismatch_summary(mismatch: &DifftestMismatch) {
    match mismatch {
        DifftestMismatch::Pc { dut, reference } => {
            eprintln!(
                "{C_DIFF}[difftest] pc differs: DUT=0x{dut:08x}, REF=0x{reference:08x}{C_RESET}"
            );
        }
        DifftestMismatch::Gpr {
            index,
            dut,
            reference,
        } => {
            let name = REG_NAMES.get(*index).copied().unwrap_or("x?");
            eprintln!(
                "{C_DIFF}[difftest] gpr {name} differs: DUT=0x{dut:08x}, REF=0x{reference:08x}{C_RESET}"
            );
        }
        DifftestMismatch::Priv { dut, reference } => {
            eprintln!("{C_DIFF}[difftest] priv differs: DUT={dut:?}, REF={reference:?}{C_RESET}");
        }
        DifftestMismatch::Csr {
            name,
            dut,
            reference,
        } => {
            eprintln!(
                "{C_DIFF}[difftest] csr {name} differs: DUT=0x{dut:08x}, REF=0x{reference:08x}{C_RESET}"
            );
        }
    }
}

fn print_pc_summary(dut: &CpuContext, reference: &CpuContext) {
    let color = color_for(dut.pc, reference.pc);
    let diff = signed_delta(dut.pc, reference.pc);

    eprintln!(
        "  {C_NAME}{:<8}{C_RESET} {color}0x{:08x}{C_RESET}   {color}0x{:08x}{C_RESET}   {color}{:<8}{C_RESET}",
        "pc", dut.pc, reference.pc, diff
    );
}

fn print_gpr_table(dut: &CpuContext, reference: &CpuContext) {
    eprintln!(
        "{C_HDR}  {:<8} {:<12} {:<12} {:<8}{C_RESET}",
        "reg", "DUT", "REF", "diff"
    );
    eprintln!(
        "  {C_HDR}{:<8} {:<12} {:<12} {:<8}{C_RESET}",
        "========", "============", "============", "========"
    );

    for (index, name) in REG_NAMES.iter().enumerate() {
        let dut_value = dut.gpr[index];
        let ref_value = reference.gpr[index];
        let color = color_for(dut_value, ref_value);
        let diff = signed_delta(dut_value, ref_value);

        eprintln!(
            "  {C_NAME}{:<8}{C_RESET} {color}0x{:08x}{C_RESET}   {color}0x{:08x}{C_RESET}   {color}{:<8}{C_RESET}",
            name, dut_value, ref_value, diff
        );
    }
}

fn color_for(dut: u32, reference: u32) -> &'static str {
    if dut == reference {
        C_VAL
    } else {
        C_DIFF
    }
}

fn signed_delta(dut: u32, reference: u32) -> i64 {
    i64::from(dut as i32) - i64::from(reference as i32)
}

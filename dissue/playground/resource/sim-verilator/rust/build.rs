use std::{
    env,
    path::{Path, PathBuf},
    process::{Command, ExitStatus},
};

fn main() {
    println!("cargo:rerun-if-env-changed=NPC_LINK_VERILATOR");
    println!("cargo:rerun-if-env-changed=NPC_VERILATOR_TOP");
    println!("cargo:rerun-if-env-changed=NPC_VERILATOR_OBJ_DIR");
    println!("cargo:rerun-if-env-changed=NPC_SIM_NATIVE_LIB");

    if env::var_os("NPC_LINK_VERILATOR").is_none() {
        return;
    }

    let manifest_dir = PathBuf::from(env::var_os("CARGO_MANIFEST_DIR").unwrap());
    let top = env::var("NPC_VERILATOR_TOP").unwrap_or_else(|_| "npc".to_string());
    let obj_dir = env_path("NPC_VERILATOR_OBJ_DIR").unwrap_or_else(|| {
        manifest_dir
            .join("../../../..")
            .join("build/verilator/obj_dir")
    });
    let native_lib = env_path("NPC_SIM_NATIVE_LIB").unwrap_or_else(|| {
        obj_dir
            .parent()
            .map(|dir| dir.join("libnpc_sim_native.a"))
            .unwrap_or_else(|| {
                manifest_dir
                    .join("../../../..")
                    .join("build/verilator/libnpc_sim_native.a")
            })
    });

    let model_mk = obj_dir.join(format!("V{top}.mk"));
    if !model_mk.exists() {
        panic!(
            "missing {}; run `make verilator` before linking Rust simulator",
            model_mk.display()
        );
    }
    println!("cargo:rerun-if-changed={}", model_mk.display());
    println!(
        "cargo:rerun-if-changed={}",
        obj_dir.join(format!("V{top}.h")).display()
    );
    println!(
        "cargo:rerun-if-changed={}",
        obj_dir.join(format!("V{top}__ALL.cpp")).display()
    );

    build_verilated_model(&obj_dir, &top);

    println!("cargo:rerun-if-changed={}", native_lib.display());
    if !native_lib.exists() {
        panic!(
            "missing native simulator archive {}; run `make verilator-exec` first",
            native_lib.display()
        );
    }

    let model_lib = obj_dir.join(format!("V{top}__ALL.a"));
    if !model_lib.exists() {
        panic!("missing Verilator model archive {}", model_lib.display());
    }

    println!("cargo:rustc-link-arg=-Wl,--start-group");
    println!("cargo:rustc-link-arg={}", native_lib.display());
    println!("cargo:rustc-link-arg={}", model_lib.display());
    println!("cargo:rustc-link-arg=-Wl,--end-group");
    println!("cargo:rustc-link-arg=-lstdc++");
    println!("cargo:rustc-link-arg=-lpthread");
    println!("cargo:rustc-link-arg=-ldl");
    println!("cargo:rustc-link-arg=-lm");
}

fn build_verilated_model(obj_dir: &Path, top: &str) {
    let make = env::var_os("MAKE").unwrap_or_else(|| "make".into());
    let makefile = format!("V{top}.mk");
    let archive = format!("V{top}__ALL.a");

    run(Command::new(make)
        .arg("-C")
        .arg(obj_dir)
        .arg("-f")
        .arg(&makefile)
        .arg(&archive));
}

fn env_path(key: &str) -> Option<PathBuf> {
    env::var_os(key)
        .map(PathBuf::from)
        .filter(|path| !path.as_os_str().is_empty())
}

fn run(command: &mut Command) {
    let program = command.get_program().to_string_lossy().into_owned();
    let args = command
        .get_args()
        .map(|arg| arg.to_string_lossy().into_owned())
        .collect::<Vec<_>>()
        .join(" ");

    let status = command
        .status()
        .unwrap_or_else(|error| panic!("failed to run `{program} {args}`: {error}"));

    if !status.success() {
        panic_status(&format!("{program} {args}"), status);
    }
}

fn panic_status(command: &str, status: ExitStatus) -> ! {
    panic!("command `{command}` failed with status {status}");
}

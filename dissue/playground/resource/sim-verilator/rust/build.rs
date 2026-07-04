use std::{
    env,
    ffi::OsStr,
    fs,
    path::{Path, PathBuf},
    process::{Command, ExitStatus},
};

fn main() {
    println!("cargo:rerun-if-env-changed=NPC_LINK_VERILATOR");
    println!("cargo:rerun-if-env-changed=NPC_VERILATOR_TOP");
    println!("cargo:rerun-if-env-changed=NPC_VERILATOR_OBJ_DIR");
    println!("cargo:rerun-if-env-changed=NPC_SIM_CPP_DIR");
    println!("cargo:rerun-if-env-changed=VERILATOR_ROOT");

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
    let cpp_dir = env_path("NPC_SIM_CPP_DIR").unwrap_or_else(|| manifest_dir.join("../cpp"));
    let verilator_root = env_path("VERILATOR_ROOT").unwrap_or_else(detect_verilator_root);
    let out_dir = PathBuf::from(env::var_os("OUT_DIR").unwrap());

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

    let native_lib = build_native_lib(&out_dir, &cpp_dir, &obj_dir, &verilator_root);
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

fn build_native_lib(
    out_dir: &Path,
    cpp_dir: &Path,
    obj_dir: &Path,
    verilator_root: &Path,
) -> PathBuf {
    fs::create_dir_all(out_dir).unwrap();

    let include_dir = cpp_dir.join("include");
    let verilator_include = verilator_root.join("include");
    let verilator_vltstd = verilator_include.join("vltstd");
    let includes = [
        include_dir,
        obj_dir.to_path_buf(),
        verilator_include.clone(),
        verilator_vltstd,
    ];

    let mut objects = Vec::new();
    for source in [
        cpp_dir.join("src/npc_cpu.cpp"),
        cpp_dir.join("src/npc_dpi.cpp"),
        cpp_dir.join("src/npc_host_bridge.cpp"),
        cpp_dir.join("src/npc_sim.cpp"),
        cpp_dir.join("src/npc_sim_shim.cpp"),
        cpp_dir.join("src/npc_wave.cpp"),
        verilator_include.join("verilated.cpp"),
        verilator_include.join("verilated_dpi.cpp"),
        verilator_include.join("verilated_threads.cpp"),
        verilator_include.join("verilated_vcd_c.cpp"),
    ] {
        println!("cargo:rerun-if-changed={}", source.display());
        let object = compile_cpp(&source, out_dir, &includes);
        objects.push(object);
    }

    let native_lib = out_dir.join("libnpc_sim_native.a");
    let ar = env::var_os("AR").unwrap_or_else(|| "ar".into());
    let mut command = Command::new(ar);
    command.arg("crs").arg(&native_lib);
    for object in &objects {
        command.arg(object);
    }
    run(&mut command);

    native_lib
}

fn compile_cpp(source: &Path, out_dir: &Path, includes: &[PathBuf]) -> PathBuf {
    if !source.exists() {
        panic!("missing C++ source {}", source.display());
    }

    let stem = source
        .file_stem()
        .and_then(OsStr::to_str)
        .unwrap_or("object");
    let object = out_dir.join(format!("{stem}.o"));
    let cxx = env::var_os("CXX").unwrap_or_else(|| "c++".into());
    let mut command = Command::new(cxx);

    command
        .arg("-std=c++17")
        .arg("-O2")
        .arg("-fPIC")
        .arg("-DVM_TRACE=1")
        .arg("-DVM_TRACE_VCD=1")
        .arg("-DVM_TRACE_FST=0")
        .arg("-DVM_COVERAGE=0")
        .arg("-DVM_SC=0")
        .arg("-DVL_DEBUG=0");

    for include in includes {
        command.arg("-I").arg(include);
    }

    command.arg("-c").arg(source).arg("-o").arg(&object);
    run(&mut command);
    object
}

fn detect_verilator_root() -> PathBuf {
    let output = Command::new("verilator")
        .arg("--getenv")
        .arg("VERILATOR_ROOT")
        .output()
        .unwrap_or_else(|error| panic!("failed to run verilator: {error}"));

    if !output.status.success() {
        panic_status("verilator --getenv VERILATOR_ROOT", output.status);
    }

    let root = String::from_utf8(output.stdout)
        .unwrap_or_else(|error| panic!("invalid verilator root output: {error}"));
    PathBuf::from(root.trim())
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

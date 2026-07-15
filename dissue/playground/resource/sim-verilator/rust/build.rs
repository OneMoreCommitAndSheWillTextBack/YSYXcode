use std::{env, path::PathBuf};

fn main() {
    let model_lib = required_archive("NPC_MODEL_ARCHIVE");
    let native_lib = required_archive("NPC_NATIVE_ARCHIVE");

    println!("cargo:rerun-if-env-changed=NPC_MODEL_ARCHIVE");
    println!("cargo:rerun-if-env-changed=NPC_NATIVE_ARCHIVE");
    println!("cargo:rerun-if-changed={}", model_lib.display());
    println!("cargo:rerun-if-changed={}", native_lib.display());

    println!("cargo:rustc-link-arg=-Wl,--start-group");
    println!("cargo:rustc-link-arg={}", native_lib.display());
    println!("cargo:rustc-link-arg={}", model_lib.display());
    println!("cargo:rustc-link-arg=-Wl,--end-group");
    println!("cargo:rustc-link-arg=-lstdc++");
    println!("cargo:rustc-link-arg=-lpthread");
    println!("cargo:rustc-link-arg=-ldl");
    println!("cargo:rustc-link-arg=-lm");
}

fn required_archive(key: &str) -> PathBuf {
    let path = env::var_os(key)
        .map(PathBuf::from)
        .filter(|path| !path.as_os_str().is_empty())
        .unwrap_or_else(|| {
            panic!("{key} is required; build the simulator through the top-level Makefile")
        });

    if !path.is_file() {
        panic!("{key} does not name an archive: {}", path.display());
    }

    path
}

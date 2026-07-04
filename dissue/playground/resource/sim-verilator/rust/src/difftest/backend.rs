use super::{abi::RiscvDifftestContext, DifftestError, DifftestResult};
use crate::cpu::CpuContext;
use std::{
    ffi::{CStr, CString},
    fmt,
    os::{
        raw::{c_char, c_int, c_void},
        unix::ffi::OsStrExt,
    },
    path::{Path, PathBuf},
    ptr::NonNull,
};

const DIFFTEST_TO_DUT: c_int = 0;
const DIFFTEST_TO_REF: c_int = 1;
const RTLD_LAZY: c_int = 0x00001;

pub(super) struct RefBackend {
    handle: NonNull<c_void>,
    path: PathBuf,
    port: c_int,
    memcpy: DifftestMemcpy,
    regcpy: DifftestRegcpy,
    exec: DifftestExec,
}

impl RefBackend {
    pub(super) fn load(path: &Path, port: c_int) -> DifftestResult<Self> {
        let c_path = CString::new(path.as_os_str().as_bytes()).map_err(|_| {
            DifftestError::InvalidReferencePath {
                path: path.to_path_buf(),
            }
        })?;

        let handle = unsafe { dlopen(c_path.as_ptr(), RTLD_LAZY) };
        let handle = NonNull::new(handle).ok_or_else(|| DifftestError::LoadFailed {
            path: path.to_path_buf(),
            message: dlerror_message(),
        })?;

        let backend = unsafe {
            Self {
                handle,
                path: path.to_path_buf(),
                port,
                memcpy: load_symbol(handle, path, b"difftest_memcpy\0")?,
                regcpy: load_symbol(handle, path, b"difftest_regcpy\0")?,
                exec: load_symbol(handle, path, b"difftest_exec\0")?,
            }
        };

        let init: DifftestInit = unsafe { load_symbol(handle, path, b"difftest_init\0")? };
        unsafe {
            init(port);
            fflush(std::ptr::null_mut());
        };

        Ok(backend)
    }

    pub(super) fn copy_memory_to_ref(&mut self, addr: u32, data: &[u8]) {
        unsafe {
            (self.memcpy)(
                addr,
                data.as_ptr() as *mut c_void,
                data.len(),
                DIFFTEST_TO_REF,
            )
        };
    }

    pub(super) fn copy_context_to_ref(&mut self, context: &CpuContext) {
        let mut raw = RiscvDifftestContext::from(context);
        unsafe {
            (self.regcpy)(
                &mut raw as *mut RiscvDifftestContext as *mut c_void,
                DIFFTEST_TO_REF,
            )
        };
    }

    pub(super) fn copy_context_from_ref(&mut self) -> CpuContext {
        let mut raw = RiscvDifftestContext::default();
        unsafe {
            (self.regcpy)(
                &mut raw as *mut RiscvDifftestContext as *mut c_void,
                DIFFTEST_TO_DUT,
            )
        };
        raw.into()
    }

    pub(super) fn exec(&mut self, n: u64) {
        unsafe { (self.exec)(n) };
    }
}

impl fmt::Debug for RefBackend {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        f.debug_struct("RefBackend")
            .field("path", &self.path)
            .field("port", &self.port)
            .finish_non_exhaustive()
    }
}

impl Drop for RefBackend {
    fn drop(&mut self) {
        unsafe {
            dlclose(self.handle.as_ptr());
        }
    }
}

type DifftestMemcpy = unsafe extern "C" fn(addr: u32, buf: *mut c_void, n: usize, direction: c_int);
type DifftestRegcpy = unsafe extern "C" fn(dut: *mut c_void, direction: c_int);
type DifftestExec = unsafe extern "C" fn(n: u64);
type DifftestInit = unsafe extern "C" fn(port: c_int);

unsafe fn load_symbol<T: Copy>(
    handle: NonNull<c_void>,
    path: &Path,
    symbol: &'static [u8],
) -> DifftestResult<T> {
    let ptr = dlsym(handle.as_ptr(), symbol.as_ptr() as *const c_char);
    if ptr.is_null() {
        return Err(DifftestError::MissingSymbol {
            path: path.to_path_buf(),
            symbol: symbol_name(symbol),
            message: dlerror_message(),
        });
    }

    Ok(std::mem::transmute_copy(&ptr))
}

fn symbol_name(symbol: &'static [u8]) -> &'static str {
    CStr::from_bytes_with_nul(symbol)
        .ok()
        .and_then(|name| name.to_str().ok())
        .unwrap_or("<invalid symbol>")
}

fn dlerror_message() -> String {
    let error = unsafe { dlerror() };
    if error.is_null() {
        return "unknown dlopen/dlsym error".to_string();
    }

    unsafe { CStr::from_ptr(error) }
        .to_string_lossy()
        .into_owned()
}

#[link(name = "dl")]
unsafe extern "C" {
    fn dlopen(filename: *const c_char, flags: c_int) -> *mut c_void;
    fn dlsym(handle: *mut c_void, symbol: *const c_char) -> *mut c_void;
    fn dlclose(handle: *mut c_void) -> c_int;
    fn dlerror() -> *const c_char;
    fn fflush(stream: *mut c_void) -> c_int;
}

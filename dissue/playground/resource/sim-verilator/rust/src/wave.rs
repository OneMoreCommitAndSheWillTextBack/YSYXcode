//! Session-level waveform policy and LightSSS checkpoint lifecycle.

use crate::{config::TraceMode, driver::NpcDriver};
use std::{
    collections::VecDeque,
    io,
    os::fd::{AsRawFd, FromRawFd, OwnedFd, RawFd},
};

const START_COMMAND: u8 = 1;
const DEV_NULL_PATH: &[u8] = b"/dev/null\0";

/// Decides when the driver should trace and owns fork-based checkpoints.
pub(crate) struct WaveController {
    mode: TraceMode,
    lightsss: LightsssController,
}

impl WaveController {
    pub(crate) fn new(mode: TraceMode) -> Self {
        let mut lightsss = LightsssController::new();
        if let TraceMode::Lightsss {
            max_checkpoints, ..
        } = mode
        {
            lightsss.set_max_checkpoints(max_checkpoints);
        }
        Self { mode, lightsss }
    }

    pub(crate) fn initialize(&mut self, driver: &mut NpcDriver) {
        if matches!(self.mode, TraceMode::Immediate) {
            driver.enable_trace();
        }
    }

    /// Runs after a completed driver evaluation, never from a DPI callback.
    pub(crate) fn after_cycle(&mut self, driver: &mut NpcDriver, cycle: u64) {
        if driver.trace_enabled() {
            return;
        }

        match self.mode {
            TraceMode::After { cycle: after } if cycle > after => driver.enable_trace(),
            TraceMode::Lightsss { gap, .. } if cycle != 0 && cycle % gap == 0 => {
                match self.lightsss.add_checkpoint(cycle) {
                    Ok(CheckpointRole::Parent) => {}
                    Ok(CheckpointRole::RecoveryChild) => driver.enable_trace(),
                    Err(error) => crate::LogError!(
                        "failed to create LightSSS checkpoint at cycle {cycle}: {error}"
                    ),
                }
            }
            TraceMode::Disabled
            | TraceMode::Immediate
            | TraceMode::After { .. }
            | TraceMode::Lightsss { .. } => {}
        }
    }

    pub(crate) fn terminal(&mut self, driver: &mut NpcDriver) {
        if matches!(self.mode, TraceMode::Lightsss { .. }) {
            match self.lightsss.wake() {
                Ok(true) => {
                    crate::Log!("Wake up LightSSS checkpoint");
                    driver.abandon_trace();
                    return;
                }
                Ok(false) => {}
                Err(error) => crate::LogError!("failed to wake LightSSS checkpoint: {error}"),
            }
        }

        self.shutdown();
        driver.close_trace();
    }

    pub(crate) fn shutdown(&mut self) {
        if let Err(error) = self.lightsss.shutdown() {
            crate::LogError!("failed to shut down LightSSS checkpoints: {error}");
        }
    }
}

struct Checkpoint {
    pid: libc::pid_t,
    start_tx: OwnedFd,
}

enum CheckpointRole {
    Parent,
    RecoveryChild,
}

struct LightsssController {
    max_checkpoints: usize,
    checkpoints: VecDeque<Checkpoint>,
}

impl LightsssController {
    fn new() -> Self {
        Self {
            max_checkpoints: 0,
            checkpoints: VecDeque::new(),
        }
    }

    fn set_max_checkpoints(&mut self, max_checkpoints: usize) {
        self.max_checkpoints = max_checkpoints;
    }

    fn add_checkpoint(&mut self, cycle: u64) -> io::Result<CheckpointRole> {
        let (start_rx, start_tx) = create_pipe()?;

        match unsafe { libc::fork() } {
            -1 => Err(io::Error::last_os_error()),
            0 => self.wait_for_start(start_rx, start_tx),
            pid => {
                drop(start_rx);
                self.checkpoints.push_front(Checkpoint { pid, start_tx });
                self.discard_excess_checkpoints()?;
                // crate::Log!("created LightSSS checkpoint at cycle {cycle}");
                Ok(CheckpointRole::Parent)
            }
        }
    }

    fn wake(&mut self) -> io::Result<bool> {
        let Some(checkpoint) = self.checkpoints.pop_front() else {
            return Ok(false);
        };

        if let Err(error) = self.discard_all_checkpoints() {
            let _ = terminate_checkpoint(checkpoint);
            return Err(error);
        }

        start_checkpoint(checkpoint)?;
        Ok(true)
    }

    fn shutdown(&mut self) -> io::Result<()> {
        self.discard_all_checkpoints()
    }

    fn wait_for_start(
        &mut self,
        start_rx: OwnedFd,
        start_tx: OwnedFd,
    ) -> io::Result<CheckpointRole> {
        drop(start_tx);
        self.checkpoints.clear();

        if redirect_standard_streams_to_null().is_err() {
            unsafe { libc::_exit(1) };
        }

        match wait_for_start_command(start_rx.as_raw_fd()) {
            Ok(true) => {
                drop(start_rx);
                Ok(CheckpointRole::RecoveryChild)
            }
            Ok(false) => unsafe { libc::_exit(0) },
            Err(_) => unsafe { libc::_exit(1) },
        }
    }

    fn discard_excess_checkpoints(&mut self) -> io::Result<()> {
        while self.checkpoints.len() > self.max_checkpoints {
            let checkpoint = self
                .checkpoints
                .pop_back()
                .expect("checkpoint queue length was checked");
            terminate_checkpoint(checkpoint)?;
        }
        Ok(())
    }

    fn discard_all_checkpoints(&mut self) -> io::Result<()> {
        let mut first_error = None;
        while let Some(checkpoint) = self.checkpoints.pop_front() {
            if let Err(error) = terminate_checkpoint(checkpoint) {
                first_error.get_or_insert(error);
            }
        }
        first_error.map_or(Ok(()), Err)
    }
}

impl Drop for LightsssController {
    fn drop(&mut self) {
        let _ = self.shutdown();
    }
}

fn create_pipe() -> io::Result<(OwnedFd, OwnedFd)> {
    let mut fds = [-1; 2];
    if unsafe { libc::pipe2(fds.as_mut_ptr(), libc::O_CLOEXEC) } == -1 {
        return Err(io::Error::last_os_error());
    }
    Ok(unsafe { (OwnedFd::from_raw_fd(fds[0]), OwnedFd::from_raw_fd(fds[1])) })
}

fn redirect_standard_streams_to_null() -> io::Result<()> {
    let null_fd = unsafe {
        libc::open(
            DEV_NULL_PATH.as_ptr().cast(),
            libc::O_WRONLY | libc::O_CLOEXEC,
        )
    };
    if null_fd == -1 {
        return Err(io::Error::last_os_error());
    }

    for target_fd in [libc::STDOUT_FILENO, libc::STDERR_FILENO] {
        if unsafe { libc::dup2(null_fd, target_fd) } == -1 {
            let error = io::Error::last_os_error();
            unsafe { libc::close(null_fd) };
            return Err(error);
        }
    }
    if null_fd != libc::STDOUT_FILENO && null_fd != libc::STDERR_FILENO {
        if unsafe { libc::close(null_fd) } == -1 {
            return Err(io::Error::last_os_error());
        }
    }
    Ok(())
}

fn wait_for_start_command(start_rx: RawFd) -> io::Result<bool> {
    let mut command = 0_u8;
    loop {
        let read_len = unsafe {
            libc::read(
                start_rx,
                (&mut command as *mut u8).cast(),
                std::mem::size_of_val(&command),
            )
        };
        match read_len {
            1 if command == START_COMMAND => return Ok(true),
            1 => {
                return Err(io::Error::new(
                    io::ErrorKind::InvalidData,
                    "invalid LightSSS start command",
                ))
            }
            0 => return Ok(false),
            -1 if io::Error::last_os_error().kind() == io::ErrorKind::Interrupted => continue,
            -1 => return Err(io::Error::last_os_error()),
            _ => unreachable!("read was limited to one byte"),
        }
    }
}

fn start_checkpoint(checkpoint: Checkpoint) -> io::Result<()> {
    if let Err(error) = write_start_command(checkpoint.start_tx.as_raw_fd()) {
        let _ = terminate_checkpoint(checkpoint);
        return Err(error);
    }
    drop(checkpoint.start_tx);
    Ok(())
}

fn write_start_command(start_tx: RawFd) -> io::Result<()> {
    let previous_handler = unsafe { libc::signal(libc::SIGPIPE, libc::SIG_IGN) };
    if previous_handler == libc::SIG_ERR {
        return Err(io::Error::last_os_error());
    }

    let result = write_start_byte(start_tx);
    if unsafe { libc::signal(libc::SIGPIPE, previous_handler) } == libc::SIG_ERR {
        return Err(io::Error::last_os_error());
    }
    result
}

fn write_start_byte(start_tx: RawFd) -> io::Result<()> {
    let command = [START_COMMAND];
    loop {
        let write_len = unsafe { libc::write(start_tx, command.as_ptr().cast(), command.len()) };
        match write_len {
            1 => return Ok(()),
            0 => return Err(io::Error::from(io::ErrorKind::WriteZero)),
            -1 if io::Error::last_os_error().kind() == io::ErrorKind::Interrupted => continue,
            -1 => return Err(io::Error::last_os_error()),
            _ => unreachable!("write was limited to one byte"),
        }
    }
}

fn terminate_checkpoint(checkpoint: Checkpoint) -> io::Result<()> {
    let kill_result = unsafe { libc::kill(checkpoint.pid, libc::SIGKILL) };
    if kill_result == -1 {
        let error = io::Error::last_os_error();
        if error.raw_os_error() != Some(libc::ESRCH) {
            return Err(error);
        }
    }
    wait_for_child(checkpoint.pid)
}

fn wait_for_child(pid: libc::pid_t) -> io::Result<()> {
    let mut status = 0;
    loop {
        let waited_pid = unsafe { libc::waitpid(pid, &mut status, 0) };
        if waited_pid == pid {
            return Ok(());
        }
        if waited_pid == -1 && io::Error::last_os_error().kind() == io::ErrorKind::Interrupted {
            continue;
        }
        return Err(io::Error::last_os_error());
    }
}

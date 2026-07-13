use std::{
    collections::VecDeque,
    io,
    os::fd::{AsRawFd, FromRawFd, OwnedFd, RawFd},
};

const START_COMMAND: u8 = 1;
const DEV_NULL_PATH: &[u8] = b"/dev/null\0";

struct Checkpoint {
    pid: libc::pid_t,
    cycle: u64,
    start_tx: OwnedFd,
    result_rx: OwnedFd,
}

pub(super) enum CheckpointRole {
    Parent,
    RecoveryChild { result_tx: OwnedFd },
}

pub(super) struct RunningCheckpoint {
    pub(super) pid: libc::pid_t,
    pub(super) cycle: u64,
    pub(super) result_rx: OwnedFd,
}

pub(super) struct LightsssController {
    max_checkpoints: usize,
    checkpoints: VecDeque<Checkpoint>, // Latest checkpoint is at the front.
}

impl LightsssController {
    pub(super) fn new() -> Self {
        Self {
            max_checkpoints: 0,
            checkpoints: VecDeque::new(),
        }
    }

    pub(super) fn set_max_checkpoints(&mut self, max_checkpoints: usize) {
        self.max_checkpoints = max_checkpoints;
    }

    pub(super) fn add_checkpoints(&mut self, cycle: u64) -> io::Result<CheckpointRole> {
        let (start_rx, start_tx) = create_pipe()?;
        let (result_rx, result_tx) = create_pipe()?;

        match unsafe { libc::fork() } {
            -1 => Err(io::Error::last_os_error()),
            0 => self.wait_for_start(start_rx, start_tx, result_rx, result_tx),
            pid => {
                drop(start_rx);
                drop(result_tx);

                self.checkpoints.push_front(Checkpoint {
                    pid,
                    cycle,
                    start_tx,
                    result_rx,
                });
                self.discard_excess_checkpoints()?;
                Ok(CheckpointRole::Parent)
            }
        }
    }

    pub(super) fn wake(&mut self) -> io::Result<Option<RunningCheckpoint>> {
        let Some(checkpoint) = self.checkpoints.pop_front() else {
            return Ok(None);
        };

        if let Err(error) = self.discard_all_checkpoints() {
            let _ = terminate_checkpoint(checkpoint);
            return Err(error);
        }

        start_checkpoint(checkpoint).map(Some)
    }

    pub(super) fn shutdown(&mut self) -> io::Result<()> {
        self.discard_all_checkpoints()
    }

    fn wait_for_start(
        &mut self,
        start_rx: OwnedFd,
        start_tx: OwnedFd,
        result_rx: OwnedFd,
        result_tx: OwnedFd,
    ) -> io::Result<CheckpointRole> {
        drop(start_tx);
        drop(result_rx);
        self.checkpoints.clear();

        if redirect_standard_streams_to_null().is_err() {
            unsafe { libc::_exit(1) };
        }

        match wait_for_start_command(start_rx.as_raw_fd()) {
            Ok(true) => {
                drop(start_rx);
                Ok(CheckpointRole::RecoveryChild { result_tx })
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
                if first_error.is_none() {
                    first_error = Some(error);
                }
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

    // pipe2 initialized both descriptors on success.
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
                    "invalid lightsss start command",
                ));
            }
            0 => return Ok(false),
            -1 if io::Error::last_os_error().kind() == io::ErrorKind::Interrupted => continue,
            -1 => return Err(io::Error::last_os_error()),
            _ => unreachable!("read was limited to one byte"),
        }
    }
}

fn start_checkpoint(checkpoint: Checkpoint) -> io::Result<RunningCheckpoint> {
    if let Err(error) = write_start_command(checkpoint.start_tx.as_raw_fd()) {
        let _ = terminate_checkpoint(checkpoint);
        return Err(error);
    }

    let Checkpoint {
        pid,
        cycle,
        start_tx,
        result_rx,
    } = checkpoint;
    drop(start_tx);

    Ok(RunningCheckpoint {
        pid,
        cycle,
        result_rx,
    })
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

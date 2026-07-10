use super::{
    report, CommitGroupEvent, PendingAsyncInterrupt, Simulator, SimulatorError, SimulatorState,
    ANSI_FG_GREEN, ANSI_FG_RED, ANSI_RESET,
};
use crate::{cpu::NpcCpuContext, SimulatorResult};

impl Simulator {
    pub(super) fn process_difftest_events(&mut self) -> SimulatorResult<()> {
        let commit_count = self.pending_commit_count;
        let has_finish = self.pending_finish;
        let needs_difftest_sync = self.pending_difftest_sync;
        let difftest_sync_prefix = self.pending_difftest_sync_prefix;
        let pending_async_interrupts = std::mem::take(&mut self.pending_async_interrupts);
        self.pending_commit_count = 0;
        self.pending_finish = false;
        self.pending_difftest_sync = false;
        self.pending_difftest_sync_prefix = 0;
        let commit_events = std::mem::take(&mut self.pending_commit_events);

        if commit_count == 0 {
            return Ok(());
        }

        if !matches!(self.state, SimulatorState::Running | SimulatorState::Stop) {
            return Ok(());
        }

        let async_interrupt =
            match terminal_async_interrupt(&pending_async_interrupts, commit_count) {
                Ok(interrupt) => interrupt,
                Err(error) => {
                    report::print_difftest_report(&error);
                    self.state = SimulatorState::Abort;
                    return Err(error);
                }
            };

        self.statistics.on_commits(commit_count);

        if let Some(itrace) = self.itrace.as_mut() {
            let itrace_path = itrace.path().to_path_buf();
            for event in &commit_events {
                itrace
                    .write_commit_group(event)
                    .map_err(|source| SimulatorError::ItraceIo {
                        path: itrace_path.clone(),
                        source,
                    })?;
            }
        }

        if self.difftest.needs_check_context() {
            let context = self.cpu_context()?;
            let result = if needs_difftest_sync {
                // The synchronized DUT context already includes any interrupt taken at this boundary.
                self.difftest.step_and_sync(difftest_sync_prefix, &context)
            } else if let Some(interrupt) = async_interrupt {
                self.difftest.step_raise_interrupt_and_check(
                    commit_count,
                    interrupt.cause(),
                    interrupt.epc(),
                    &context,
                )
            } else {
                self.difftest.step_and_check(commit_count, &context)
            };

            if let Err(error) = result {
                let error = SimulatorError::Difftest(error);
                report::print_difftest_report(&error);
                self.state = SimulatorState::Abort;
                return Err(error);
            }
        }

        if has_finish {
            let context = self.cpu_context()?;
            self.state = if context.gpr[10] == 0 {
                eprintln!("{}HIT GOOD TRAP{}", ANSI_FG_GREEN, ANSI_RESET);
                SimulatorState::End
            } else {
                eprintln!("{}HIT BAD TRAP{}", ANSI_FG_RED, ANSI_RESET);
                SimulatorState::Abort
            };
        }

        Ok(())
    }

    pub(super) fn on_difftest_commit(&mut self, event: CommitGroupEvent) {
        let commit_count = event.valid_count();

        if commit_count == 0 {
            return;
        }

        if !matches!(self.state, SimulatorState::Running | SimulatorState::Stop) {
            return;
        }

        let previous_commit_count = self.pending_commit_count;
        self.pending_commit_count += commit_count;
        self.pending_finish |= event.has_finish();
        if let Some(interrupt) = event.async_interrupt() {
            self.pending_async_interrupts.push(PendingAsyncInterrupt {
                event: interrupt,
                commits_at_interrupt: self.pending_commit_count,
            });
        }
        self.pending_commit_events.push(event);
        if let Some(prefix_count) = event.difftest_sync_prefix_count() {
            if !self.pending_difftest_sync {
                self.pending_difftest_sync_prefix = previous_commit_count + prefix_count;
            }
            self.pending_difftest_sync = true;
        }
    }

    pub(super) fn on_difftest_context(&mut self, context: NpcCpuContext) {
        if let Some(context) = context.into_context() {
            self.latest_context = Some(context);
        }
    }
}

fn terminal_async_interrupt(
    pending: &[PendingAsyncInterrupt],
    total_commits: u64,
) -> SimulatorResult<Option<super::event::AsyncInterruptEvent>> {
    let [interrupt] = pending else {
        return if pending.is_empty() {
            Ok(None)
        } else {
            Err(SimulatorError::MultipleAsyncInterrupts {
                count: pending.len(),
                total_commits,
            })
        };
    };

    if interrupt.commits_at_interrupt != total_commits {
        return Err(SimulatorError::NonTerminalAsyncInterrupt {
            cause: interrupt.event.cause(),
            epc: interrupt.event.epc(),
            commits_at_interrupt: interrupt.commits_at_interrupt,
            total_commits,
        });
    }

    Ok(Some(interrupt.event))
}

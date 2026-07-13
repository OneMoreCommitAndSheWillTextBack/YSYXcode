use super::{
    report, CommitGroupEvent, PendingAsyncInterrupt, PendingDifftestEvents, Simulator,
    SimulatorError, SimulatorState,
};
use crate::{cpu::NpcCpuContext, SimulatorResult};

impl PendingDifftestEvents {
    pub(super) fn clear(&mut self) {
        self.commit_count = 0;
        self.finish = false;
        self.sync_prefix = None;
        self.async_interrupts.clear();
        self.commit_events.clear();
    }

    fn record_commit(&mut self, event: CommitGroupEvent) {
        let previous_commit_count = self.commit_count;
        self.commit_count += event.valid_count();
        self.finish |= event.has_finish();

        if let Some(interrupt) = event.async_interrupt() {
            self.async_interrupts.push(PendingAsyncInterrupt {
                event: interrupt,
                commits_at_interrupt: self.commit_count,
            });
        }

        if let Some(prefix_count) = event.difftest_sync_prefix_count() {
            if self.sync_prefix.is_none() {
                self.sync_prefix = Some(previous_commit_count + prefix_count);
            }
        }

        self.commit_events.push(event);
    }
}

impl Simulator {
    pub(super) fn process_difftest_events(&mut self) -> SimulatorResult<()> {
        let pending = std::mem::take(&mut self.pending_difftest_events);
        let store_conditional_gpr_mask = pending
            .commit_events
            .iter()
            .fold(0, |mask, event| mask | event.store_conditional_gpr_mask());
        let has_store_conditional = store_conditional_gpr_mask != 0;

        if pending.commit_count == 0 {
            return Ok(());
        }

        if !matches!(self.state, SimulatorState::Running | SimulatorState::Stop) {
            return Ok(());
        }

        let async_interrupt =
            match terminal_async_interrupt(&pending.async_interrupts, pending.commit_count) {
                Ok(interrupt) => interrupt,
                Err(error) => {
                    report::print_difftest_report(&error);
                    self.state = SimulatorState::Abort;
                    return Err(error);
                }
            };

        self.statistics.on_commits(pending.commit_count);

        if let Some(itrace) = self.itrace.as_mut() {
            let itrace_path = itrace.path().to_path_buf();
            for event in &pending.commit_events {
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
            let result = if let Some(difftest_sync_prefix) = pending.sync_prefix {
                // The synchronized DUT context already includes any interrupt taken at this boundary.
                self.difftest.step_and_sync(difftest_sync_prefix, &context)
            } else if has_store_conditional {
                if let Some(interrupt) = async_interrupt {
                    self.difftest
                        .step_raise_interrupt_and_check_except_gprs_and_sync(
                            pending.commit_count,
                            interrupt.cause(),
                            interrupt.epc(),
                            &context,
                            store_conditional_gpr_mask,
                        )
                } else {
                    self.difftest.step_and_check_except_gprs_and_sync(
                        pending.commit_count,
                        &context,
                        store_conditional_gpr_mask,
                    )
                }
            } else if let Some(interrupt) = async_interrupt {
                self.difftest.step_raise_interrupt_and_check(
                    pending.commit_count,
                    interrupt.cause(),
                    interrupt.epc(),
                    &context,
                )
            } else {
                self.difftest.step_and_check(pending.commit_count, &context)
            };

            if let Err(error) = result {
                let error = SimulatorError::Difftest(error);
                report::print_difftest_report(&error);
                self.state = SimulatorState::Abort;
                return Err(error);
            }

            if has_store_conditional {
                self.sync_difftest_store_conditionals(&pending.commit_events)?;
            }
        }

        if pending.finish {
            let context = self.cpu_context()?;
            self.state = if context.gpr[10] == 0 {
                SimulatorState::End
            } else {
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

        self.pending_difftest_events.record_commit(event);
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

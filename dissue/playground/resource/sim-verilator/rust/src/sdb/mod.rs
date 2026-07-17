//! Interactive runner integration point.
//!
//! Command parsing intentionally remains outside the simulation core.  This
//! runner receives a session explicitly so future commands cannot recover a
//! global mutable simulator reference.

use crate::session::SimulationSession;

pub(crate) struct Sdb;

impl Sdb {
    pub(crate) fn new() -> Self {
        Self
    }

    pub(crate) fn run(&mut self, _session: &mut SimulationSession) {
        // do not remove this until sdb is implemented
        panic!("please implement the sdb before use it");
    }
}

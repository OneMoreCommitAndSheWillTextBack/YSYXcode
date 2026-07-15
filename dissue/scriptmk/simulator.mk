$(CARGO_INPUT_SIG): FORCE
	@mkdir -p "$(dir $@)"
	@set -eu; \
	tmp=$$(mktemp "$@.tmp.XXXXXX"); \
	trap 'rm -f "$$tmp"' EXIT; \
	{ \
		printf 'cargo=%s\n' '$(CARGO)'; \
		printf 'profile=%s\n' '$(RUST_PROFILE_LEVEL)'; \
		printf 'cargo_args=%s\n' '$(RUST_PROFILE_ARGS)'; \
		printf 'cargo_target_dir=%s\n' '$(CARGO_TARGET_DIR)'; \
		printf 'cargo_bin=%s\n' '$(CARGO_BIN)'; \
		printf 'model_archive=%s\n' '$(VERILATOR_MODEL_ARCHIVE)'; \
		printf 'native_archive=%s\n' '$(SIM_NATIVE_LIB)'; \
		sha256sum scriptmk/config.mk scriptmk/simulator.mk; \
		for file in "$(SIM_RUST_DIR)/Cargo.toml" "$(SIM_RUST_DIR)/Cargo.lock" "$(SIM_RUST_DIR)/build.rs"; do sha256sum "$$file"; done; \
		find "$(SIM_RUST_DIR)/src" -type f -name '*.rs' -print | LC_ALL=C sort | \
			while IFS= read -r file; do sha256sum "$$file"; done; \
		"$(CARGO)" --version 2>&1 || true; \
	} > "$$tmp"; \
	$(call replace_if_changed,$@,$$tmp)

$(CARGO_DONE_STAMP): $(MODEL_OUTPUT_SIG) $(NATIVE_OUTPUT_SIG) $(CARGO_INPUT_SIG)
	@mkdir -p "$(dir $@)"
	@cd "$(SIM_RUST_DIR)" && \
		NPC_MODEL_ARCHIVE="$(abspath $(VERILATOR_MODEL_ARCHIVE))" \
		NPC_NATIVE_ARCHIVE="$(SIM_NATIVE_LIB)" \
		CARGO_TARGET_DIR="$(CARGO_TARGET_DIR)" \
		$(CARGO) build $(RUST_PROFILE_ARGS)
	@test -f "$(CARGO_BIN)"
	@touch "$@"

$(CARGO_OUTPUT_SIG): $(CARGO_DONE_STAMP)
	@mkdir -p "$(dir $@)"
	@set -eu; \
	tmp=$$(mktemp "$@.tmp.XXXXXX"); \
	trap 'rm -f "$$tmp"' EXIT; \
	sha256sum "$(CARGO_BIN)" > "$$tmp"; \
	$(call replace_if_changed,$@,$$tmp)

$(VERILATOR_EXEC): $(CARGO_OUTPUT_SIG) scriptmk/simulator.mk
	@mkdir -p "$(dir $@)"
	@set -eu; \
	if test -f "$@" && cmp -s "$(CARGO_BIN)" "$@"; then \
		chmod --reference="$(CARGO_BIN)" "$@"; \
		touch "$@"; \
	else \
		tmp=$$(mktemp "$@.tmp.XXXXXX"); \
		trap 'rm -f "$$tmp"' EXIT; \
		cp "$(CARGO_BIN)" "$$tmp"; \
		chmod --reference="$(CARGO_BIN)" "$$tmp"; \
		mv -f "$$tmp" "$@"; \
	fi

VERILATOR_EXEC_GOAL := $(patsubst $(CURDIR)/%,%,$(VERILATOR_EXEC))

ifneq ($(VERILATOR_EXEC_GOAL),$(VERILATOR_EXEC))
$(VERILATOR_EXEC_GOAL): $(VERILATOR_EXEC)
	@test -f "$@"
endif

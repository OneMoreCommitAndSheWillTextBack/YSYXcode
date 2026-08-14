#===============================================================================
# Simulation view: Chisel -> SystemVerilog under $(RTL_OUTPUT_DIR).
#===============================================================================
$(CHISEL_INPUT_SIG): FORCE
	@mkdir -p "$(dir $@)"
	@set -eu; \
	tmp=$$(mktemp "$@.tmp.XXXXXX"); \
	trap 'rm -f "$$tmp"' EXIT; \
	{ \
		printf 'project=%s\n' '$(PRJ)'; \
		printf 'target=%s\n' '$(TARGET)'; \
		printf 'chisel_mode=%s\n' '$(CHISEL_MODE)'; \
		printf 'elaborate_args=%s\n' '$(ELABORATE_ARGS)'; \
		printf 'mill=%s\n' '$(MILL)'; \
		printf 'build_dir=%s\n' '$(BUILD_DIR)'; \
		printf 'rtl_filelist=%s\n' '$(RTL_FILELIST)'; \
		for file in $(CHISEL_BUILD_INPUTS); do sha256sum "$$file"; done; \
		find "$(PRJ)/src" -type f -name '*.scala' -print | LC_ALL=C sort | \
			while IFS= read -r file; do sha256sum "$$file"; done; \
	} > "$$tmp"; \
	$(call replace_if_changed,$@,$$tmp)

$(CHISEL_DONE_STAMP): $(CHISEL_INPUT_SIG)
	$(call git_commit, "generate verilog")
	@mkdir -p "$(RTL_OUTPUT_DIR)" "$(dir $@)"
	$(MILL) -i $(PRJ).runMain Elaborate --ysyx-target $(TARGET) --mode $(CHISEL_MODE) --target-dir $(RTL_OUTPUT_DIR) $(ELABORATE_ARGS)
	@test -f "$(RTL_FILELIST)"
	@touch "$@"

$(RTL_OUTPUT_SIG): $(CHISEL_DONE_STAMP)
	@mkdir -p "$(dir $@)"
	@set -eu; \
	test -f "$(RTL_FILELIST)"; \
	tmp=$$(mktemp "$@.tmp.XXXXXX"); \
	trap 'rm -f "$$tmp"' EXIT; \
	{ \
		sha256sum "$(RTL_FILELIST)"; \
		while IFS= read -r source; do \
			test -n "$$source" || continue; \
			sha256sum "$(RTL_OUTPUT_DIR)/$$source"; \
		done < "$(RTL_FILELIST)"; \
	} > "$$tmp"; \
	$(call replace_if_changed,$@,$$tmp)

#===============================================================================
# Synthesis view: same Chisel sources, elaborated with --mode synth so every
# DPI bridge degenerates to an empty shell. Output lands in $(SYNTH_OUTPUT_DIR)
# and is consumed by scriptmk/syn.mk.
#===============================================================================
SYNTH_RTL_FILELIST ?= $(BUILD_DIR)/synth/filelist.f
SYNTH_OUTPUT_DIR  ?= $(dir $(SYNTH_RTL_FILELIST))

CHISEL_SYN_INPUT_SIG  ?= $(BUILD_META_DIR)/chisel-synth-inputs.sig
CHISEL_SYN_DONE_STAMP ?= $(BUILD_META_DIR)/chisel-synth-done.stamp
SYNTH_RTL_OUTPUT_SIG  ?= $(BUILD_META_DIR)/synth-rtl-output.sig

$(CHISEL_SYN_INPUT_SIG): FORCE
	@mkdir -p "$(dir $@)"
	@set -eu; \
	tmp=$$(mktemp "$@.tmp.XXXXXX"); \
	trap 'rm -f "$$tmp"' EXIT; \
	{ \
		printf 'project=%s\n' '$(PRJ)'; \
		printf 'target=%s\n' '$(TARGET)'; \
		printf 'chisel_mode=%s\n' 'synth'; \
		printf 'elaborate_args=%s\n' '$(ELABORATE_ARGS)'; \
		printf 'mill=%s\n' '$(MILL)'; \
		printf 'rtl_filelist=%s\n' '$(SYNTH_RTL_FILELIST)'; \
		for file in $(CHISEL_BUILD_INPUTS); do sha256sum "$$file"; done; \
		sha256sum scriptmk/syn.mk 2>/dev/null || true; \
		find "$(PRJ)/src" -type f -name '*.scala' -print | LC_ALL=C sort | \
			while IFS= read -r file; do sha256sum "$$file"; done; \
	} > "$$tmp"; \
	$(call replace_if_changed,$@,$$tmp)

$(CHISEL_SYN_DONE_STAMP): $(CHISEL_SYN_INPUT_SIG)
	$(call git_commit, "generate verilog (synth)")
	@mkdir -p "$(SYNTH_OUTPUT_DIR)" "$(dir $@)"
	$(MILL) -i $(PRJ).runMain Elaborate --ysyx-target $(TARGET) --mode synth --target-dir $(SYNTH_OUTPUT_DIR) $(ELABORATE_ARGS)
	@test -f "$(SYNTH_RTL_FILELIST)"
	@touch "$@"

$(SYNTH_RTL_OUTPUT_SIG): $(CHISEL_SYN_DONE_STAMP)
	@mkdir -p "$(dir $@)"
	@set -eu; \
	test -f "$(SYNTH_RTL_FILELIST)"; \
	tmp=$$(mktemp "$@.tmp.XXXXXX"); \
	trap 'rm -f "$$tmp"' EXIT; \
	{ \
		sha256sum "$(SYNTH_RTL_FILELIST)"; \
		while IFS= read -r source; do \
			test -n "$$source" || continue; \
			sha256sum "$(SYNTH_OUTPUT_DIR)/$$source"; \
		done < "$(SYNTH_RTL_FILELIST)"; \
	} > "$$tmp"; \
	$(call replace_if_changed,$@,$$tmp)

.PHONY: verilog-synth
verilog-synth: $(CHISEL_SYN_DONE_STAMP)

$(VERILATOR_CONFIG_SIG): FORCE
	@mkdir -p "$(dir $@)"
	@set -eu; \
	tmp=$$(mktemp "$@.tmp.XXXXXX"); \
	trap 'rm -f "$$tmp"' EXIT; \
	{ \
		printf 'top_module=%s\n' '$(TOP_MODULE)'; \
		printf 'verilator=%s\n' '$(VERILATOR)'; \
		printf 'verilator_root=%s\n' '$(VERILATOR_ROOT)'; \
		printf 'verilator_flags=%s\n' '$(VERILATOR_FLAGS)'; \
		printf 'rtl_filelist=%s\n' '$(RTL_FILELIST)'; \
		printf 'obj_dir=%s\n' '$(VERILATOR_OBJ_DIR)'; \
		sha256sum scriptmk/config.mk scriptmk/verilator.mk; \
		"$(VERILATOR)" --version 2>&1 || true; \
	} > "$$tmp"; \
	$(call replace_if_changed,$@,$$tmp)

$(VERILATOR_CONFIG_APPLIED_STAMP): $(VERILATOR_CONFIG_SIG)
	@rm -rf "$(VERILATOR_OBJ_DIR)"
	@mkdir -p "$(VERILATOR_OBJ_DIR)" "$(dir $@)"
	@cp "$<" "$@"

$(VERILATOR_INPUT_SIG): FORCE
	@mkdir -p "$(dir $@)"
	@set -eu; \
	tmp=$$(mktemp "$@.tmp.XXXXXX"); \
	trap 'rm -f "$$tmp"' EXIT; \
	{ \
		for file in $(EXTRA_V); do sha256sum "$$file"; done; \
	} | LC_ALL=C sort > "$$tmp"; \
	$(call replace_if_changed,$@,$$tmp)

$(VERILATOR_DONE_STAMP): $(RTL_OUTPUT_SIG) $(VERILATOR_CONFIG_APPLIED_STAMP) $(VERILATOR_INPUT_SIG)
	@mkdir -p "$(VERILATOR_OBJ_DIR)" "$(dir $@)"
	$(VERILATOR) $(VERILATOR_FLAGS) -F "$(RTL_FILELIST)" $(EXTRA_V) \
		--top-module $(TOP_MODULE) \
		--Mdir "$(VERILATOR_OBJ_DIR)"
	@test -f "$(VERILATOR_MODEL_MK)"
	@test -f "$(VERILATOR_MODEL_HEADER)"
	@touch "$@"

$(VERILATOR_OUTPUT_SIG): $(VERILATOR_DONE_STAMP)
	@mkdir -p "$(dir $@)"
	@set -eu; \
	tmp=$$(mktemp "$@.tmp.XXXXXX"); \
	trap 'rm -f "$$tmp"' EXIT; \
	find "$(VERILATOR_OBJ_DIR)" -maxdepth 1 -type f \
		\( -name 'V$(TOP_MODULE)*.cpp' -o -name 'V$(TOP_MODULE)*.h' -o \
		   -name 'V$(TOP_MODULE)*.mk' -o -name 'V$(TOP_MODULE)__verFiles.dat' \) \
		-print | LC_ALL=C sort | \
		while IFS= read -r file; do sha256sum "$$file"; done > "$$tmp"; \
	$(call replace_if_changed,$@,$$tmp)

$(MODEL_DONE_STAMP): $(VERILATOR_OUTPUT_SIG) $(VERILATOR_CONFIG_APPLIED_STAMP)
	@mkdir -p "$(dir $@)"
	+$(MAKE) -C "$(VERILATOR_OBJ_DIR)" -f "$(notdir $(VERILATOR_MODEL_MK))" "$(notdir $(VERILATOR_MODEL_ARCHIVE))"
	@test -f "$(VERILATOR_MODEL_ARCHIVE)"
	@touch "$@"

$(MODEL_OUTPUT_SIG): $(MODEL_DONE_STAMP)
	@mkdir -p "$(dir $@)"
	@set -eu; \
	tmp=$$(mktemp "$@.tmp.XXXXXX"); \
	trap 'rm -f "$$tmp"' EXIT; \
	sha256sum "$(VERILATOR_MODEL_ARCHIVE)" > "$$tmp"; \
	$(call replace_if_changed,$@,$$tmp)

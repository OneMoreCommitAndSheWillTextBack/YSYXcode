$(CHISEL_INPUT_SIG): FORCE
	@mkdir -p "$(dir $@)"
	@set -eu; \
	tmp=$$(mktemp "$@.tmp.XXXXXX"); \
	trap 'rm -f "$$tmp"' EXIT; \
	{ \
		printf 'project=%s\n' '$(PRJ)'; \
		printf 'target=%s\n' '$(TARGET)'; \
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
	@mkdir -p "$(BUILD_DIR)" "$(dir $@)"
	$(MILL) -i $(PRJ).runMain Elaborate --ysyx-target $(TARGET) --target-dir $(BUILD_DIR)
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

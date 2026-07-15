$(NATIVE_INPUT_SIG): FORCE
	@mkdir -p "$(dir $@)"
	@set -eu; \
	tmp=$$(mktemp "$@.tmp.XXXXXX"); \
	trap 'rm -f "$$tmp"' EXIT; \
	{ \
		printf 'cxx=%s\n' '$(CXX)'; \
		printf 'ar=%s\n' '$(AR)'; \
		printf 'verilator_root=%s\n' '$(VERILATOR_ROOT)'; \
		printf 'verilator_flags=%s\n' '$(VERILATOR_FLAGS)'; \
		printf 'top_module=%s\n' '$(TOP_MODULE)'; \
		printf 'native_build_dir=%s\n' '$(SIM_NATIVE_BUILD_DIR)'; \
		printf 'native_lib=%s\n' '$(SIM_NATIVE_LIB)'; \
		printf 'model_header=%s\n' '$(VERILATOR_MODEL_HEADER)'; \
		printf 'cxxflags=%s\n' '$(SIM_NATIVE_CXXFLAGS)'; \
		printf 'cppflags=%s\n' '$(SIM_NATIVE_CPPFLAGS)'; \
		sha256sum scriptmk/config.mk scriptmk/native.mk "$(SIM_CPP_DIR)/Makefile"; \
		"$(CXX)" --version 2>&1 || true; \
		find "$(SIM_CPP_DIR)" -type f \( -name '*.cpp' -o -name '*.h' \) -print | LC_ALL=C sort | \
			while IFS= read -r file; do sha256sum "$$file"; done; \
	} > "$$tmp"; \
	$(call replace_if_changed,$@,$$tmp)

$(NATIVE_DONE_STAMP): $(VERILATOR_OUTPUT_SIG) $(VERILATOR_CONFIG_APPLIED_STAMP) $(NATIVE_INPUT_SIG)
	@mkdir -p "$(dir $@)" "$(dir $(SIM_NATIVE_LIB))"
	+$(MAKE) -C "$(SIM_CPP_DIR)" \
		NATIVE_BUILD_DIR="$(SIM_NATIVE_BUILD_DIR)" \
		NATIVE_LIB="$(SIM_NATIVE_LIB)" \
		VERILATOR_ROOT="$(VERILATOR_ROOT)" \
		MODEL_HEADER="$(abspath $(VERILATOR_MODEL_HEADER))" \
		CXX="$(CXX)" AR="$(AR)" \
		NATIVE_CONFIG_TAG='$(TOP_MODULE)|$(VERILATOR_FLAGS)' \
		NATIVE_CXXFLAGS='$(SIM_NATIVE_CXXFLAGS)' \
		NATIVE_CPPFLAGS='$(SIM_NATIVE_CPPFLAGS)' \
		"$(SIM_NATIVE_LIB)"
	@test -f "$(SIM_NATIVE_LIB)"
	@touch "$@"

$(NATIVE_OUTPUT_SIG): $(NATIVE_DONE_STAMP)
	@mkdir -p "$(dir $@)"
	@set -eu; \
	tmp=$$(mktemp "$@.tmp.XXXXXX"); \
	trap 'rm -f "$$tmp"' EXIT; \
	sha256sum "$(SIM_NATIVE_LIB)" > "$$tmp"; \
	$(call replace_if_changed,$@,$$tmp)

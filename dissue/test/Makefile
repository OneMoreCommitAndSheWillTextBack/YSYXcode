include mk/extensions.mk

EXTENSIONS := $(SUPPORTED_EXTENSIONS)

.PHONY: all run list clean help

all run:
	@if [ -z "$(EXT)" ]; then \
		echo "[Error] EXT is required."; \
		echo "supported extensions: $(EXTENSIONS)"; \
		echo "usage: make -C test run EXT=riscv32i [ALL=\"quick-sort asm-add\"]"; \
		exit 1; \
	fi
	@if ! echo " $(EXTENSIONS) " | grep -q " $(EXT) "; then \
		echo "[Error] unknown EXT=$(EXT)"; \
		echo "supported extensions: $(EXTENSIONS)"; \
		exit 1; \
	fi
	@if [ ! -f "$(EXT)/Makefile" ]; then \
		echo "[Error] extension directory is missing or incomplete: $(EXT)"; \
		echo "expected: $(EXT)/Makefile"; \
		exit 1; \
	fi
	@$(MAKE) --no-print-directory -C "$(EXT)" run

list:
	@if [ -n "$(EXT)" ]; then \
		if ! echo " $(EXTENSIONS) " | grep -q " $(EXT) "; then \
			echo "[Error] unknown EXT=$(EXT)"; \
			echo "supported extensions: $(EXTENSIONS)"; \
			exit 1; \
		fi; \
		if [ ! -f "$(EXT)/Makefile" ]; then \
			echo "[Error] extension directory is missing or incomplete: $(EXT)"; \
			echo "expected: $(EXT)/Makefile"; \
			exit 1; \
		fi; \
		$(MAKE) --no-print-directory -C "$(EXT)" list; \
	else \
		echo "supported extensions: $(EXTENSIONS)"; \
		echo "usage: make -C test run EXT=riscv32i [ALL=\"quick-sort asm-add\"]"; \
	fi

clean:
	@for ext in $(EXTENSIONS); do \
		if [ -f "$$ext/Makefile" ]; then \
			$(MAKE) --no-print-directory -C "$$ext" clean; \
		fi; \
	done

help:
	@echo "usage: make -C test run EXT=<extension> [ALL=\"test-a test-b\"]"
	@echo "supported extensions: $(EXTENSIONS)"

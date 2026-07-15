.PHONY: FORCE
FORCE:

define replace_if_changed
if test -f "$(1)" && cmp -s "$(2)" "$(1)"; then \
	rm -f "$(2)"; \
else \
	mv -f "$(2)" "$(1)"; \
fi
endef

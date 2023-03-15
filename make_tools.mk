
MAKEFLAGS += --no-print-directory

# Inclusive list. If you don't want a tool to be built, don't add it here.
TOOLDIRS := $(filter-out tools/agbcc tools/binutils tools/poryscript,$(wildcard tools/*))

.PHONY: all $(TOOLDIRS)

all: $(TOOLDIRS)

$(TOOLDIRS):
	@$(MAKE) -C $@

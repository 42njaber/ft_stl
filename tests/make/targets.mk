
MAKECMDGOALS ?= 
ifeq ($(filter $(NAME),$(MAKECMDGOALS)),$(MAKECMDGOALS))
ifeq ($(words $(MAKECMDGOALS)),1)
TARGET := $(MAKECMDGOALS)
endif
endif

ifdef TARGET
$(TARGET): $(call objects,$(SRC))
	$(LD) -o $@ $^ $(LDFLAGS)
	$(call GC,fclean,$@)

else
.PHONY: $(NAME)

$(NAME):
	@echo MAKE: $@
	@$(MAKE) --no-print-directory $@
endif


MD_SUFFIX=~MD5

objects=$(1:$S%=$O%.o)
sources=$(1:$O%.o=$S%)

.SECONDARY:
%$(MD_SUFFIX): $$(call sources,$$(basename $$*)) | mkpath@$$(@D)/
	$(call GC,clean,$@.d)
	@echo $(CXX) -c $< $(CXXFLAGS) -o [MD5]$(basename $*)
	@$(CXX) -c $< $(CXXFLAGS) -MMD -MP -MF $@.d -o $@
	$(call GC,clean,$@)
	@ echo "$@: OFLAGS=$(CXXFLAGS)" >> $@.d

md5mode = $(shell echo "$1" | md5sum | cut -d' ' -f1)
%.o: MDFILE=$@.$(call md5mode,$(call MDKEY))$(MD_SUFFIX)

.INTERMEDIATE:
%.o: $$(MDFILE) $$(shell [ "$$@" -ef "$$(MDFILE)" ] || echo "relink")
	@ln -fv $< $@
	$(call GC,clean,$@)

.PHONY: relink

-include $(patsubst %,%.d,$(wildcard $O**$(MD_SUFFIX)))

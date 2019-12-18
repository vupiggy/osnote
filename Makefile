# Only some Linux ditros and MacOS are taken care

ifeq ($(shell uname -s), Darwin)
AWK=/usr/local/bin/gawk
else
AWK=gawk
endif

input_tex=									\
        $(shell [ "$1" != "" ] && $(AWK) '/^(\\input|\\include)\{.*\}$$/	\
                {								\
                    input=gensub(/.*{(.*)}.*/, "\\1", "g");			\
                    if (index(input, ".tex") == 0) {				\
                        if (index(input, "\\") != 1) {				\
                            printf("%s.tex ", input);				\
                        }							\
                    } else {							\
                        if (index(input, "\\") != 1) {				\
                            printf("%s ", input);				\
                        }							\
                    }								\
                }' $1)

TEXPDFTARGETS=os.pdf
master_tex=$(TEXPDFTARGETS:.pdf=.tex)

tex := $(call input_tex,$(master_tex))
tex += $(call input_tex,$(tex))

all: $(TEXPDFTARGETS)

%.d: %.tex
	@echo "Generate depenent inputs"
	@echo "$(<:.tex=.tex.pdf) $(<:.tex=.d): $< $(tex) $(src)" >$@

include $(master_tex:.tex=.d)

%.pdf: %.tex %.d
	@echo "TeXing" $< "3 times..."
	@set -e; \
	 for i in {1..3}; do echo "TeXing $$i";					\
		xelatex -halt-on-error -shell-escape -interaction=batchmode $<	\
		|| (echo "Failed...exit"; exit 1);				\
	 done

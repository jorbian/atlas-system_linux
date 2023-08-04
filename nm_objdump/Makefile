define HNM_CODE
program='hnm'
command_string='nm -p {}'
endef

define HOBJDUMP
program='hobjdump'
command_string='objdump -sf {}'
endef

define INVOKE

run_fake_program(filename, program, command_string)
endef

export HNM_CODE
export HOBJDUMP
export INVOKE

all: hnm hobjdump

hnm:
	cp ./src/fake_elf.py $@
	@echo "$$HNM_CODE" >> $@
	chmod +x $@
	@echo "$$INVOKE" >> $@

hobjdump:
	cp ./src/fake_elf.py $@
	@echo "$$HOBJDUMP" >> $@
	chmod +x $@
	@echo "$$INVOKE" >> $@



define INVOKE

run_fake_program(filename, program, command_string)
endef

export INVOKE

all: 0-hreadelf 1-hreadelf 2-hreadelf

0-hreadelf:
	cp ./src/fake_elf.py $@
	@echo -n "program='0-" >> $@
	@echo "hreadelf'" >> $@
	@echo "command_string='readelf -W -h {}'" >> $@
	chmod +x $@
	@echo "$$INVOKE" >> $@

1-hreadelf:
	cp ./src/fake_elf.py $@
	@echo -n "program='1-" >> $@
	@echo "hreadelf'" >> $@
	@echo "command_string='readelf -W -S {}'" >> $@
	chmod +x $@
	@echo "$$INVOKE" >> $@

2-hreadelf:
	cp ./src/fake_elf.py $@
	@echo -n "program='2-" >> $@
	@echo "hreadelf'" >> $@
	@echo "command_string='readelf -W -l {}'" >> $@
	chmod +x $@
	@echo "$$INVOKE" >> $@
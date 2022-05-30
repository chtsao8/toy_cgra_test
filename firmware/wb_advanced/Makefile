TOOLCHAIN_PATH = /opt/riscv32imc/bin/
# TOOLCHAIN_PATH = /ef/apps/bin/

# ---- Test patterns for project raven ----

.SUFFIXES:

PATTERN = wb_advanced

hex:  ${PATTERN:=.hex}

#%.elf: %.c ../sections.lds ../start.s spi_io.c spi_io.h ../print_io.c ../print_io.h
%.elf: %.c ../sections.lds ../start.s ../print_io.c ../print_io.h
	$(TOOLCHAIN_PATH)riscv32-unknown-elf-gcc -O0 -march=rv32i -Wl,-Bstatic,-T,../sections.lds,--strip-debug -ffreestanding -nostdlib -o $@ ../start.s ../print_io.c $<
	${TOOLCHAIN_PATH}/riscv32-unknown-elf-objdump -D wb_advanced.elf > wb_advanced.lst

%.hex: %.elf
	$(TOOLCHAIN_PATH)riscv32-unknown-elf-objcopy -O verilog $< $@
	sed -i 's/@10000000/@00000000/g' $@

%.bin: %.elf
	$(TOOLCHAIN_PATH)riscv32-unknown-elf-objcopy -O binary $< $@

client: client.c
	gcc client.c -o client

flash: wb_advanced.hex
	python3 ../util/caravel_hkflash.py wb_advanced.hex

flash2: wb_advanced.hex
	python3 ../util/caravel_flash.py $<

# ---- Clean ----

clean:
	rm -f *.elf *.hex *.bin *.vvp *.vcd

.PHONY: clean hex all flash


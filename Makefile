all: run

o.bin: bootloader.asm
	nasm -i utils/ -f bin $< -o $@

run: o.bin
	qemu-system-x86_64 o.bin

clean:
	rm -r *.bin *.o *.dis
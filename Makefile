#G:\mingw\usr\bin
#G:\mingw\mingw64\bin

all: run

run_kernel.o: kernel/run_kernel.asm
	nasm $< -f elf -o kernel/$@

kernel.o: 
	i686-elf-gcc -ffreestanding -c kernel/kernel.c -o kernel/$@ 

kernel.bin: run_kernel.o kernel.o
	i686-elf-ld kernel/run_kernel.o kernel/kernel.o -Ttext=0x1000 --oformat binary -o kernel/$@ 

bootloader.bin: bootloader/bootloader.asm
	nasm -i bootloader/ -f bin $< -o bootloader/$@

os_img: bootloader.bin kernel.bin
	cat bootloader/bootloader.bin kernel/kernel.bin > os_img.bin

run: os_img
	qemu-system-x86_64 -fda os_img.bin

clean:
	rm -r *.bin *.o *.dis
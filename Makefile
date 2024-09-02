C_SOURCES = $(wildcard kernel/*.c drivers/*.c utils/*.c)
HEADERS = $(wildcard kernel/*.h drivers/*.h utils/*.h)

OBJ = ${C_SOURCES:.c=.o}

all: run

%.o: %.asm
	nasm $< -f elf -o $@

%.o: %.c ${HEADERS}
	i686-elf-gcc -ffreestanding -c $< -o $@ 

bootloader/bootloader.bin: bootloader/bootloader.asm
	nasm -i utils -f bin $< -o $@

kernel/kernel.bin: kernel/run_kernel.o ${OBJ}
	i686-elf-ld $^ -Ttext=0x1000 --oformat binary -o $@ 


os_img: bootloader/bootloader.bin kernel/kernel.bin
	cat $^ > os_img.bin

run: os_img
	qemu-system-x86_64 -fda os_img.bin

clean:
	rm -rf bootloader/*.bin bootloader/*.o bootloader/*.dis
	rm -rf kernel/*.bin kernel/*.o kernel/*.dis
	rm -rf drivers/*.bin drivers/*.o drivers/*.dis
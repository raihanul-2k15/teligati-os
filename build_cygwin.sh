nasm -f elf -o kasm.o kernel.asm
i586-elf-gcc -m32 -o kc.o -c kernel.c
i586-elf-ld -m elf_i386 -T link.ld -o kernel.bin kasm.o kc.o
qemu-system-i386 -kernel kernel.bin

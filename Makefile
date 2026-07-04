CC = clang
AS = nasm
LD = ld.lld

CFLAGS = -ffreestanding -O2 -std=gnu23 -mcmodel=kernel -mno-red-zone -fno-stack-protector -fno-builtin -nostdlib -Wall -Wno-unused-variable -Wno-unused-function -masm=intel -m64 -g 

C_SOURCES = COURRMOV.c idt.c linux_syscall.c malloc.c outb.c printf.c shell.c basicgpu.c inb.c memcpy.c outl.c process.c intelgpu.c gdt.c inl.c kernel.c memory.c strcmp.c 
OBJ = $(C_SOURCES:.c=.o) pm_entry.o idt_asm.o asmidtmacro.o idt_asmtype2.o reload.o

all: kernel.bin

kernel.elf: $(OBJ)
	$(LD) -T linker.ld -o kernel.elf $(OBJ)

kernel.bin: kernel.elf
	objcopy -O binary kernel.elf kernel.bin

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.asm
	$(AS) -f elf64 $< -o $@

clean:
	rm -f *.o kernel.elf kernel.bin
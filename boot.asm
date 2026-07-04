[BITS 16]
[ORG 0x7C00]
global _start
extern _start2
_start:
cli
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7C00
    mov [BOOT_DRIVE], dl

    ; --- Reset Disk ---
    mov ah, 0
    int 0x13

    ; --- Load Kernel (0x1000:0000 = 0x10000) ---
    mov ax, 0x1000          
    mov es, ax
    xor bx, bx  
    
    mov ah, 0x02
    mov al, 100  ; 16KB is enough for your 13KB kernel
    mov ch, 0x00
    mov dh, 0x00
    mov cl, 0x02            
    mov dl, 0x80
    int 0x13
    jc disk_error           

    ; --- A20 & Protected Mode ---
    in al, 0x92
    or al, 2
    out 0x92, al

    lgdt [gdt_descriptor]
    mov eax, cr0
    or eax, 0x1
    mov cr0, eax
    ; ... (after setting cr0) ...
    
    ; 1. Jump to a local 32-bit label to fix the house
    jmp 0x08:init_pm

[BITS 32]
init_pm:
    ; 2. NOW set the 32-bit registers properly
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    ; 3. Setup a real 32-bit stack so C doesn't die
    mov ebp, 0x90000
    mov esp, ebp


    ; Set up a real stack so C doesn't panic
    mov ebp, 0x90000
    mov esp, ebp

    ; FINALLY jump to your kernel_main
    jmp 0x10000

disk_error:
    mov ah, 0x0e
    mov al, 'D'
    int 0x10
    jmp $

BOOT_DRIVE db 0

; 1. Enable PAE (Physical Address Extension)
mov eax, cr4
or eax, 1 << 5
mov cr4, eax

; 2. Point CR3 to the page tables (You need to define these somewhere in memory!)
; I'm using 0x8000 as an example address for your PML4 table
mov eax, 0x8000
mov cr3, eax

; 3. Enable Long Mode in EFER MSR
mov ecx, 0xC0000080
rdmsr
or eax, 1 << 8
wrmsr

; 4. Enable Paging
mov eax, cr0
or eax, 1 << 31
mov cr0, eax

[BITS 64]
init_64:
    ; Setup 64-bit stack
    mov rsp, 0x900000
    

call _start2

times 510-($-$$) db 0
dw 0xAA55
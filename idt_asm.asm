[bits 64]
extern idt_handler_c 

global idt_common_stub
idt_common_stub:
    call idt_handler_c ; Jump to C logic
    push rax
push rcx
push rdx
push rbx
push rbp
push rsi
push rdi
push r8
push r9
push r10
push r11
push r12
push r13
push r14
push r15

    iretq              ; Interrupt Return

global interrupt_handler_0
interrupt_handler_0:
    push 0            ; Dummy error code
    push 0            ; Interrupt number 0
    jmp idt_common_stub
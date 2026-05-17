extern interrupt_handler_c
extern printf

%macro asmerrcode 1
global interrupthndlr%1
interrupthndlr%1:
push qword 0
push qword%1
jmp interrupt_handler_c
%endmacro


; main logic

%if interrupthndlr 14, printf("Uh oh, a critical error has been found.")
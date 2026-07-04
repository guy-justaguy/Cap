#include <stdint.h>
extern void saveallreg;

long sys_exit(long code);
uint64_t syscall_table[] = {
    [60] = sys_exit
};
typedef struct {
    uint64_t rax, rcx, rdx, rbx, rbp, 
    rsi, rdi, r8, 
    r9, r10,
    r11, r12,
    r13, r14, r15;
} reg_t;

void syscallhndlr(reg_t *regs)  {
if (regs->rax == 60) {
        sys_exit(regs->rdi);
        }
}
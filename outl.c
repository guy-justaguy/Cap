#include <stdint.h>

void outl(uint32_t value, uint16_t port) {
    __asm__ volatile ("out dx, eax"
        :
        : "a"(value), "Nd"(port));
}

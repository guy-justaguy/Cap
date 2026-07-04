#include <stdint.h>


uint32_t inl(uint16_t port) {
    uint32_t result;
    // We use 'al' for the 8-bit result and 'dx' for the port
    __asm__ volatile("in eax, dx" 
        : "=a" (result) :"d"  (port));
    return result;
}

uint32_t inladdr(uint16_t port) {
    uint32_t* result;
    // We use 'al' for the 8-bit result and 'dx' for the port
    __asm__ volatile("in eax, dx" 
        : "=a" (result) :"d"  (port));
    return *result;
}
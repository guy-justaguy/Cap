#include <stdint.h>
extern void reload();
struct gdt {
uint64_t gdt0;
uint64_t gdt1;
uint64_t gdt2;
} __attribute__((packed));
struct gdt_ptr {
uint16_t lmt;
uint64_t bse;
} __attribute__((packed));

struct gdt gdt;
struct gdt_ptr gdtptr;

void GDTLOADSET() {
gdt.gdt0 = 0;
gdt.gdt1 = 0x00AF9A000000FFFF;
gdt.gdt2 = 0x00CF92000000FFFF;
gdtptr.lmt = sizeof(gdt) - 1;
gdtptr.bse = (uint64_t)&gdt;
}

void GDTLOAD() {
    GDTLOADSET();
    __asm__ volatile ("lgdt %0" : : "m"(gdtptr));
    reload();
}
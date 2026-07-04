#include <stdint.h>

extern void outb(unsigned short port, unsigned char value);
extern unsigned char inb(unsigned short port);
extern void COURRMOV();
extern void interrupt_handler_0(); 
extern void printf(const char* format, ...);
void remapPIC() {
    // Start initialization
    outb(0x20, 0x11);
    outb(0xA0, 0x11);
    // Set offsets (Master = 32, Slave = 40)
    outb(0x21, 0x20);
    outb(0xA1, 0x28);
    outb(0x21, 0x04);
    outb(0xA1, 0x02);
    // Set APIC mode
    outb(0x21, 0x02);
    outb(0xA1, 0x02);
    // Clear masks (Unmask all)
    outb(0x21, 0x0);
    outb(0xA1, 0x0);
}

// 64-bit IDT entries MUST be 16 bytes each
struct idt_entry_64 {
    uint16_t offset_low;
    uint16_t selector;
    uint8_t  ist;
    uint8_t  types_attr;
    uint16_t offset_mid;
    uint32_t offset_high;
    uint32_t reserved;
} __attribute__((packed));

// 64-bit IDT pointer MUST be 10 bytes
struct idt_ptr_64 {
    uint16_t limit;
    uint64_t base;
} __attribute__((packed));

struct idt_entry_64 idt[256] = {0}; 
struct idt_ptr_64 idt_ptr_struct;

void set_idt_gate(int n, uint64_t handler) {
    idt[n].offset_low  = (uint16_t)(handler & 0xFFFF);
    idt[n].selector    = 0x08; 
    idt[n].ist         = 0;
    idt[n].types_attr  = 0x8E; // Present, Ring 0, Interrupt Gate
    idt[n].offset_mid  = (uint16_t)((handler >> 16) & 0xFFFF);
    idt[n].offset_high = (uint32_t)((handler >> 32) & 0xFFFFFFFF);
    idt[n].reserved    = 0;
}
extern void interrupthndlr_0();
extern void interrupthndlrpusherr_13();
extern void interrupthndlrpusherr_14();
extern void interrupthndlr_1();
extern void interrupthndlr_2();
extern void interrupthndlr_3();
extern void interrupthndlr_4();
extern void interrupthndlr_5();
extern void interrupthndlr_6();
extern void interrupthndlr_7();
extern void interrupthndlr_8();
extern void interrupthndlr_9();
extern void interrupthndlr_16();
extern void interrupthndlr_18();
extern void interrupthndlr_19();
extern void interrupthndlr_19();
extern void interrupthndlr_20();
extern void interrupthndlrdevice_32();
extern void interrupthndlrpusherr_8();
extern void interrupthndlrpusherr_10();
extern void interrupthndlrpusherr_11();
extern void interrupthndlrpusherr_12();
extern void interrupthndlrpusherr_17();

__attribute__((force_align_arg_pointer))
void IDTLOAD() {
    remapPIC();

    set_idt_gate(0, (uint64_t)interrupthndlr_0);
    set_idt_gate(1, (uint64_t)interrupthndlr_1);
    set_idt_gate(2, (uint64_t)interrupthndlr_2);
    set_idt_gate(3, (uint64_t)interrupthndlr_3);
    set_idt_gate(4, (uint64_t)interrupthndlr_4);
    set_idt_gate(5, (uint64_t)interrupthndlr_5);
    set_idt_gate(6, (uint64_t)interrupthndlr_6);
    set_idt_gate(7, (uint64_t)interrupthndlr_7);
    set_idt_gate(8, (uint64_t)interrupthndlrpusherr_8);
    set_idt_gate(9, (uint64_t)interrupthndlr_9);
    set_idt_gate(10, (uint64_t)interrupthndlrpusherr_10);
    set_idt_gate(11, (uint64_t)interrupthndlrpusherr_11);
    set_idt_gate(12, (uint64_t)interrupthndlrpusherr_12);
    set_idt_gate(13, (uint64_t)interrupthndlrpusherr_13);
    set_idt_gate(14, (uint64_t)interrupthndlrpusherr_14);
    set_idt_gate(16, (uint64_t)interrupthndlr_16);
    set_idt_gate(17, (uint64_t)interrupthndlrpusherr_17);
    set_idt_gate(18, (uint64_t)interrupthndlr_18);
    set_idt_gate(19, (uint64_t)interrupthndlr_19);
    set_idt_gate(20, (uint64_t)interrupthndlr_20);
    set_idt_gate(32, (uint64_t)interrupthndlrdevice_32);

    // Setup the 10-byte pointer for 64-bit lidt
    idt_ptr_struct.limit = (sizeof(struct idt_entry_64) * 256) - 1;
    idt_ptr_struct.base  = (uint64_t)&idt;

    // Point lidt to the 10-byte struct and load IDT
    __asm__ __volatile__("lidt %0" :: "m"(idt_ptr_struct));
  //  asm volatile("sti");
     
}

void idt_handler_c() {
    // error
    printf("Uh oh, a critical error has occured. to report bugs, email to tungsahuur1234@gmail.com.");
    // EOI
        outb(0xA0, 0x20); // Slave PIC
    outb(0x20, 0x20); // Master PIC

 }
 void idt_handlertype2_c() {
        outb(0xA0, 0x20); // Slave PIC
    outb(0x20, 0x20); // Master PIC

 }
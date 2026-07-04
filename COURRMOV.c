#include "cursorwhite.h"
#include <stdint.h>

extern void outb(unsigned short port, unsigned char value);
extern unsigned char inl(uint16_t port);
uint8_t flags;
uint8_t delta_x;
uint8_t delta_y;
uint32_t savepos;
uint32_t realcourr;
uint32_t screen_width = 1024;
uint32_t offset; // This should be set to the mouse's X and Y position
uint32_t mouse_xy;

// extern bckb lib start
uint32_t BCKB[4096];
uint32_t BCKB1[4096];
uint32_t BCKB2[4096];
uint32_t *framebuffer = (uint32_t*)0xFD000000;
unsigned short status;
unsigned short status2;
// extern bckb lib end



 // ---CORRMOV--//
void initmouse() {
outb (0xA8, 0x64);
outb (0xD4, 0x64);
outb (0xf8, 0x60);
flags = inl(0x60);
}
void delta_xyinfofetcher() {
   status = inl(0x64);
if(status & 0x1) {
delta_x = inl(0x60);
}
status2 = inl(0x64);
if(status2 & 0x1) {
delta_y = inl(0x60);
}
}
static uint32_t real_x = 0;
static uint32_t real_y = 0; 
void calc() {
realcourr = (real_y * 1024) + real_x;
real_x += delta_x;
real_y -= delta_y;
savepos = realcourr;
}
void COURRMOV() {
    delta_xyinfofetcher();
 calc();   
}
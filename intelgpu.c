#include <stdint.h>
#include "intelgpu2d.h"
extern uint32_t inladdr(uint16_t port);
extern void outl(uint32_t value, uint16_t port);


volatile uint32_t* PGTBL_CTL;
volatile uint32_t* PGTBL_ER;
volatile uint32_t* PGTBL_CTL2;
volatile uint32_t* PGTBL_STR2;
volatile uint32_t* PP_DIR_BASE;
volatile uint32_t* PP_DCIR;
volatile uint32_t* PP_DCDR;
volatile uint32_t* PP_DCLV;
volatile uint32_t* PP_PFIR;
volatile uint32_t* PP_PFIC;
volatile uint32_t* PP_PFD;
volatile uint32_t* TLB_RD_EXT;
volatile uint32_t* VF_REG;
volatile uint32_t* CS_REG;
volatile uint32_t* TEXT_CHC;
volatile uint32_t* RNDR_CHC;
volatile uint32_t* GFX_MODE;
volatile uint32_t* EXCC;
volatile uint32_t* RING_BUFFER_TAIL;
volatile uint32_t* RING_BUFFER_HEAD;
volatile uint32_t* RING_BUFFER_START;
volatile uint32_t *RING_BUFFER_CONTROL;
volatile uint32_t* UHPTR;
volatile uint32_t* HW_MEMRD;
volatile uint32_t* IPEIR;
volatile uint32_t* HW_MEMCWR;
volatile uint32_t* IPEHR;
volatile uint32_t* INSTDONE;
volatile uint32_t* INSTPS;
volatile uint32_t* ACTHD;
volatile uint32_t* DMA_FADD_P;
volatile uint32_t* INSTDONE_1;
volatile uint32_t* GFX_FLSH_CNTL;
volatile uint32_t* CTXT_PREMP_DBG;
volatile uint32_t* NOPID;
volatile uint32_t* PR_CTR_CTL;
volatile uint32_t* PR_CTL_THRSH;
volatile uint32_t* PR_CTL;
volatile uint32_t* HWS_PGA;
volatile uint32_t* PWRCTXA;
volatile uint32_t* HWSTAM;
volatile uint32_t* IER;
volatile uint32_t* IIR;
volatile uint32_t* IMR;
volatile uint32_t* ISR;
volatile uint32_t* EIR;
volatile uint32_t* EMR;
volatile uint32_t* ESR;
volatile uint32_t* PRBL_SF;
volatile uint32_t* INSTPM;
volatile uint32_t* CACHE_MODE_0;
volatile uint32_t* CACHE_MODE_1;
volatile uint32_t* FBC_RT_BASE_ADDR_REGISTER;
volatile uint32_t* BB_ADDR;
volatile uint32_t* BB_STATE;
volatile uint32_t* CTXT_SR_CTL;
volatile uint32_t* CCID;
volatile uint32_t* CXT_SIZE;
volatile uint32_t* CXT_SIZE_NOEXT;
volatile uint32_t* MI_DISPLAY_POWER_DOWN;
volatile uint32_t* MI_ARB_STATE;
volatile uint32_t* MI_RDRET_STATE;
volatile uint32_t* MI_MODE;
volatile uint32_t* ECOSKPD;
volatile uint32_t* CSFLFSM;
volatile uint32_t* CSFLFLAG;
volatile uint32_t* CSFLTRK;
volatile uint32_t* CSCMDOP;
volatile uint32_t* CSCMDVLD;
volatile uint32_t* PREEMPDLY;
volatile uint32_t* CLKCMP;
volatile uint32_t* VFDC;
volatile uint32_t* VFSKPD;


uint32_t *mmiobase;
void findintelgpu(uint16_t bus, uint16_t device, uint32_t offset, uint32_t value) {
 uint64_t BARBASE = (1U << 31) | (bus << 16) | (device << 11) | (value << 8);
outl(0xCF8, BARBASE);
mmiobase = (uint32_t*)(uintptr_t)inladdr(0xCFC); 
}
void INTELGPUREGMAP() {
findintelgpu(0, 2, 0, 0);
  PGTBL_CTL = (mmiobase + 0x2020);
  PGTBL_ER = (mmiobase + 0x2024);
  PGTBL_CTL2 = (mmiobase + 0x20C4);
  PGTBL_STR2 = (mmiobase + 0X20C8);
  PP_DIR_BASE = (mmiobase   + 0X2518);
  PP_DCIR  = (mmiobase + 0x2500);
  PP_DCDR = (mmiobase + 0x2504);
  PP_DCLV = (mmiobase + 0x2508);
  PP_PFIR = (mmiobase + 0x2510);
  PP_PFIC = (mmiobase + 0x2514);
  PP_PFD = (mmiobase + 0x2580);
  TLB_RD_EXT = (mmiobase + 0x251c);
  VF_REG = (mmiobase + 0xB100);
  CS_REG = (mmiobase + 0xB200);
  TEXT_CHC = (mmiobase + 0xB300);
  RNDR_CHC = (mmiobase + 0xB400);
  GFX_MODE = (mmiobase + 0X2520);
  EXCC = (mmiobase + 0X2028);
  RING_BUFFER_TAIL = (mmiobase + 0X2030);
  RING_BUFFER_HEAD = (mmiobase + 0X2034);
  RING_BUFFER_START = (mmiobase + 0X2038);
  RING_BUFFER_CONTROL = (mmiobase + 0X203C);
  UHPTR = (mmiobase + 0X2134);
  HW_MEMRD = (mmiobase + 0X2060);
  IPEIR = (mmiobase + 0X2064);
  HW_MEMCWR = (mmiobase + 0X2064);
  IPEHR = (mmiobase + 0X2068);
  INSTDONE = (mmiobase + 0X206C);
  INSTPS = (mmiobase + 0X2070);
  ACTHD = (mmiobase + 0X2074);
  DMA_FADD_P = (mmiobase + 0X2078);
  INSTDONE_1 = (mmiobase + 0X207C);
  GFX_FLSH_CNTL = (mmiobase + 0X2170);
  CTXT_PREMP_DBG = (mmiobase + 0X2718);
  NOPID = (mmiobase + 0X2094);
  PR_CTR_CTL = (mmiobase + 0X2178);
  PR_CTL_THRSH = (mmiobase + 0X217C);
  PR_CTL = (mmiobase + 0X2190);
  HWS_PGA = (mmiobase + 0X2080);
  PWRCTXA = (mmiobase + 0X2088); 
  HWSTAM = (mmiobase + 0X2098);
  IER =(mmiobase + 0X20A0);
  IIR =(mmiobase + 0X20A4);
  IMR =(mmiobase + 0X20A8);
  ISR =(mmiobase + 0X20AC);
  EIR =(mmiobase + 0X20B0);
  EMR =(mmiobase + 0X20B4);
  ESR =(mmiobase + 0X20B8);
  PRBL_SF =(mmiobase + 0X2680);
  INSTPM =(mmiobase + 0X20C0);
  CACHE_MODE_0 =(mmiobase + 0X2120);
  CACHE_MODE_1 =(mmiobase +  0X2124); 
  FBC_RT_BASE_ADDR_REGISTER =  (mmiobase +  0X2128);
  BB_ADDR = (mmiobase +  0X2140);
  BB_STATE = (mmiobase +  0X2110);
  CTXT_SR_CTL = (mmiobase +  0X2714);
  CCID = (mmiobase +  0X2180);
  CXT_SIZE = (mmiobase +  0X21A0);
  CXT_SIZE_NOEXT = (mmiobase +  0X21A4); 
  MI_DISPLAY_POWER_DOWN = (mmiobase +  0X20E0);
  MI_ARB_STATE = (mmiobase +  0X20E4);
  MI_RDRET_STATE = (mmiobase +  0X20fc);
  MI_MODE = (mmiobase +  0X209C);
  ECOSKPD = (mmiobase +  0X21D0);
  CSFLFSM = (mmiobase +  0X2200);
  CSFLFLAG = (mmiobase +  0X2204);
  CSFLTRK = (mmiobase +  0X2208);
  CSCMDOP = (mmiobase +  0X220C);
  CSCMDVLD = (mmiobase +  0X2210);
  PREEMPDLY = (mmiobase +  0X2214);
  CLKCMP = (mmiobase +  0X2360);
  VFDC = (mmiobase +  0X2450);
  VFSKPD = (mmiobase +  0X2470);
  }


int mmiowritetype2(uint32_t val, uint32_t* mmiowriteaddr)  {
*mmiowriteaddr = val;
  return 0;
}
int mmiowrite(uint32_t val, uint32_t* mmiowriteaddr, uint32_t mmio_offset)  {
uint32_t* addr = (mmiowriteaddr + mmio_offset);
*addr = val;
return 0;
}

int addrwrite(uint32_t val, uint32_t *writeaddr)  {
*writeaddr = val;
return 0;
}

void initgpu() {
 volatile uint32_t* gttbase;
 volatile uint32_t* gtt;
 uint32_t* finalpte;
 gttbase = mmiobase;
gtt = (volatile uint32_t*)0x100000;
volatile uint32_t* gttaddr = (volatile uint32_t*)(uintptr_t)(*gtt + *gttbase);
uint32_t idx = 0x100000 >> 12;
uint32_t pte = (*gttaddr & 0xFFFFF000 | 1);
pte = *finalpte;
gttaddr[idx] = *finalpte;
RING_BUFFER_CONTROL = 0;
RING_BUFFER_TAIL = 0;
RING_BUFFER_HEAD = 0;
RING_BUFFER_START  = 0;
gttaddr = RING_BUFFER_CONTROL;
uint32_t ring_size_config = (*gttaddr - 4096) & 0x001FF000;
uint32_t ring_enable_bit = 1;
*RING_BUFFER_CONTROL = (ring_size_config | ring_enable_bit);
HWS_PGA = (volatile uint32_t*)(mmiobase + 0x200000);
}

void main() {
  initgpu();
 uint32_t* ringlog;
 uint32_t* ringbuff = (uint32_t*)(mmiobase + 0x100000);
ringlog = (uint32_t*)(mmiobase + 0x200000);
addrwrite(RCP_NOOP, ringbuff); 
}
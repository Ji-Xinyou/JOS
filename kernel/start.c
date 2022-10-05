#include "include/defs.h"
#include "include/x64.h"
#include "include/memlayout.h"
#include "include/mmu.h"
#include "include/logger.h"

extern char end[];

void init();

void
_start()
{
    init();
}

void
kinit1(char* vs, char* ve)
{
    kinit(vs, ve);
}

void
logger_init()
{
    LOG_INFO("UART Initialzing...");
    uart_init();
}

void
register_log()
{
    LOG_INFO("cr3 is at %p", r_cr3());
    LOG_INFO("rsp is at %p", r_rsp());
}

void
init()
{
    LOG_INFO("J-i-OS Initializing...");

    logger_init();

    register_log();

    // 0 ~ 2MB are mapped in prot_pg.S
    LOG_INFO("Mapping from %p to %p", end, (char *)SCRATCH_MAP_END);
    kinit1(end, (char *)SCRATCH_MAP_END);

    LOG_INFO("IDT Initialzing...");
    idt_init();

    LOG_INFO("VGA buffer Initializing...");
    vga_init();

    LOG_INFO("Initialization Done. Entering J-i-OS");
}

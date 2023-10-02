#include "kernel.h"
#include "config.h"
#include "status.h"
#include "idt/idt.h"
#include "io/io.h"
#include "isr80h/isr80h.h"
#include "memory/memory.h"
#include "memory/heap/kheap.h"
#include "memory/paging/paging.h"
#include "string/string.h"
#include "fs/file.h"
#include "disk/disk.h"
#include "disk/streamer.h"
#include "fs/pparser.h"
#include "gdt/gdt.h"
#include "task/tss.h"
#include "task/task.h"
#include "task/process.h"
#include "keyboard/keyboard.h"

#include <stdint.h>
#include <stddef.h>

uint16_t* video_mem = 0;
uint16_t terminal_row = 0;
uint16_t terminal_col = 0;

uint16_t terminal_make_char(char c, char color)
{
    return (color << 8) | c;
}

void terminal_put_char(int x, int y, char c, char color)
{
    video_mem[(y * VGA_WIDTH) + x] = terminal_make_char(c, color);
}

void terminal_writechar(char c, char color)
{
    if(c == '\n') 
    {
        terminal_row += 1;
        terminal_col = 0;
        return;
    }

    terminal_put_char(terminal_col, terminal_row, c, color);
    terminal_col += 1;
    if(terminal_col >= VGA_WIDTH)
    {
        terminal_col = 0;
        terminal_row += 1;
    }
}

void terminal_initialize()
{
    video_mem = (uint16_t*)(0xB8000);
    terminal_row = 0;
    terminal_col = 0;
    for (int y = 0; y < VGA_HEIGHT; y++)
    {  
        for(int x = 0; x < VGA_WIDTH; x++) 
            terminal_put_char(x, y, ' ', 0);
    }
}

void print(const char* str) 
{
    size_t len = strlen(str);
    for (int i = 0; i < len; i++) 
        terminal_writechar(str[i], 15);
}

static struct paging_4gb_chunk* kernel_chunk = 0;

void panic(const char* message)
{
    print(message);
    while(1)
    {

    }
}

void kernel_page()
{
    kernel_registers();
    paging_switch(kernel_chunk);
}

struct tss tss;
struct gdt gdt_real[MODERNOS_TOTAL_GDT_SEGMENTS];
struct gdt_structured gdt_structed[MODERNOS_TOTAL_GDT_SEGMENTS] = {
    {.base = 0x00, .limit = 0x00, .type = 0x00},                        // NULL Segment
    {.base = 0x00, .limit = 0xFFFFFFFF, .type = 0x9A},                  // Kernel Code Segment
    {.base = 0x00, .limit = 0xFFFFFFFF, .type = 0x92},                  // Kernel Data Segment
    {.base = 0x00, .limit = 0xFFFFFFFF, .type = 0xF8},                  // User Code Segment
    {.base = 0x00, .limit = 0xFFFFFFFF, .type = 0xF2},                  // User Data Segment
    {.base = (uint32_t)&tss, .limit = sizeof(tss), .type = 0xE9}        // TSS Segment
};
 
void kernel_main() 
{
    terminal_initialize();

    // Load the GDT
    memset(gdt_real, 0x00, sizeof(gdt_real));
    gdt_structured_to_gdt(gdt_real, gdt_structed, MODERNOS_TOTAL_GDT_SEGMENTS);
    gdt_load(gdt_real, sizeof(gdt_real));

    // Initialize the heap
    kheap_init();

    // Inititalize filesystems
    fs_init();

    // Search and initailize the disks
    disk_search_and_init();

    // Initialize the interrupt descriptor table
    idt_init();

    // Setup the tss
    memset(&tss, 0x00, sizeof(tss));
    tss.esp0 = 0x600000;
    tss.ss0 = KERNEL_DATA_SELECTOR;

    // Load the tss
    tss_load(0x28);

    // Setup paging
    kernel_chunk = paging_new_4gb(PAGING_IS_WRITEABLE | PAGING_IS_PRESENT | PAGING_ACCESS_FROM_ALL);

    // Switch to kernel paging chunk
    paging_switch(kernel_chunk);

    // Enable paging
    enable_paging();  

    // Register the kernel commands 
    isr80h_register_commands();

    // Initialize all the system keyboards
    keyboard_init();

    struct process* process = 0;
    int res = process_load("0:/blank.bin", &process);
    if(res != MODERNOS_ALL_OK)
        panic("Failed to load blank.bin");

    task_run_first_ever_task();

    while(1)
    {

    }
}
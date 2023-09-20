#ifndef CONFIG_H
#define CONFIG_H

#define KERNEL_CODE_SELECTOR 0x08
#define KERNEL_DATA_SELECTOR 0x10

#define MODERNOS_TOTAL_INTERRUPTS 512

// 100MB heap size
#define MODERNOS_HEAP_SIZE_BYTES 104857600
#define MODERNOS_HEAP_BLOCK_SIZE_BYTES 4096
#define MODERNOS_HEAP_ADDRESS 0x01000000
#define MODERNOS_HEAP_TABLE_ADDRESS 0x00007E00

#define MODERNOS_SECTOR_SIZE 512

#define MODERNOS_MAX_FILESYSTEMS 12
#define MODERNOS_MAX_FILEDESCRIPTORS 512

#define MODERNOS_MAX_PATH 108

#define MODERNOS_TOTAL_GDT_SEGMENTS 6

#endif
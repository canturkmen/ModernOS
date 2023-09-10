#ifndef DISK_H
#define DISK_H

#include "fs/file.h"

typedef unsigned int MODERNOS_DISK_TYPE;

// Represents a real physical hard disk 
#define MODERNOS_DISK_TYPE_REAL 0

struct disk 
{
    MODERNOS_DISK_TYPE type;
    int sector_size;

    struct filesystem* filesystem;
};  

struct disk* disk_get(int index);
void disk_search_and_init();
int disk_read_block(struct disk* idisk, unsigned int lba, int total, void* buff);
int disk_read_sector(int lba, int total, void* buffer);

#endif
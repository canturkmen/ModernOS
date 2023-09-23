#ifndef PROCESS_H
#define PROCESS_H

#include <stdint.h>

#include "config.h"
#include "task.h"

struct process
{
    // The process id
    uint16_t id;

    char filename[MODERNOS_MAX_PATH];

    // The main process task
    struct task* task;

    // The memory (malloc) allocations of the process
    void* allocations[MODERNOS_MAX_PROGRAMS_ALLOCATIONS];

    // The physical pointer to the process memory
    void* ptr;

    // The physical memory to stack memory
    void* stack;

    // The size of the data pointed to by the ptr
    uint32_t size;
};  

int process_load_for_slot(const char* filename, struct process** process, int process_slot);
int process_load(const char* filename, struct process** process);

#endif
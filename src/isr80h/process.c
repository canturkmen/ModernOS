#include "process.h"
#include "task/process.h"
#include "task/task.h"
#include "config.h"
#include "status.h"

void* isr80h_command6_process_load_start(struct interrupt_frame* frame)
{
    void* filename_user_pointer = task_get_stack_item(task_current(), 0);
    char filename[MODERNOS_MAX_PATH];
    int res = copy_string_from_task(task_current(), filename_user_pointer, filename, sizeof(filename));
    if(res < 0) 
        goto out;

    struct process* process = 0;
    res = process_load_switch(filename, &process);

    task_switch(process->task);

out:
    return res;
}

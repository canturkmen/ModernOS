#ifndef MODERNOS_H
#define MODERNOS_H

#include <stddef.h>
#include <stdbool.h>

struct command_argument
{
    char argument[512];
    struct command_argument* next;
};

struct process_arguments
{
    int argc;
    char** argv;
};

void print(const char *message);
int modernos_getkey();
void modernos_putchar(char c);
void *modernos_malloc(size_t size);
void modernos_free(void *ptr);
int modernos_getkeyblock();
void modernos_terminal_readline(char *out, int max, bool output_while_typing);
void modernos_process_load_start(const char* filename);
struct command_argument* modernos_parse_command(const char* command, int max);
void modernos_process_get_arguments(struct process_arguments* arguments);
int modernos_system(struct command_argument* arguments);
int modernos_system_run(const char* command);

#endif

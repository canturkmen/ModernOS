#ifndef MODERNOS_H
#define MODERNOS_H

#include <stddef.h>

void print(const char *message);
int getkey();
void modernos_putchar(char c);
void *modernos_malloc(size_t size);
void modernos_free(void *ptr);

#endif

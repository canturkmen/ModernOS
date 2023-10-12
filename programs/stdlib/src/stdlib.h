#ifndef STDLIB_H
#define STDLIB_H

#include <stddef.h>

void* malloc(size_t size);
void free(void* ptr);
void modernos_free(void* ptr);
char* itoa(int i);

#endif
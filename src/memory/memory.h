#ifndef MEMORY
#define MEMORY

#include <stddef.h>

void* memset(void* ptr, int c, size_t size);
int memcmp(void* s1, void* s2, int count);

#endif
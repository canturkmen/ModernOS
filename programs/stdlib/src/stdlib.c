#include "stdlib.h"
#include "modernos.h"

void* malloc(size_t size)
{
    return modernos_malloc(size);
}

void free(void* ptr)
{
    modernos_free(ptr);
}
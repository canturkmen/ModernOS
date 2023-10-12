#include "stdio.h"
#include "modernos.h"

int putchar(int c)
{
    modernos_putchar((char)c);
    return 0;
}
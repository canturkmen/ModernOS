#include "modernos.h"

int modernos_getkeyblock()
{
    int val = modernos_getkey();
    do 
    {
        val = modernos_getkey();
    } 
    while(val == 0);
    return val;
}
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

void modernos_terminal_readline(char *out, int max, bool output_while_typing)
{
    int i = 0;
    for(i = 0; i < max - 1; i++)
    {
        char key = modernos_getkeyblock();

        // Carriage return means we have read the line
        if(key == 13)
            break;

        if(output_while_typing)
            modernos_putchar(key);

        // Backspace
        if(key == 0x08 && i >= 1)
        {
            out[i-1] = 0x00;
            i -= 2;
            continue;
        }

        out[i] = key;
    }

    out[i] = 0x00;
}
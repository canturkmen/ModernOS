#include "modernos.h"
#include "stdlib.h"
#include "stdio.h"

int main(int argc, char **argv)
{
    printf("My age is %i\n", 21);
    print("Hello, how are you\n");

    print(itoa(5343));
    putchar('Z');

    void *ptr = malloc(512);
    free(ptr);

    modernos_getkeyblock();
    print("Hello world\n");

    char buf[10242];

    modernos_terminal_readline(buf, sizeof(buf), true);
    
    print(buf);

    while(1)
    {

    }
    return 0;
}
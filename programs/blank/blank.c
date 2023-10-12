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

    while (1)
    {
        if (getkey() != 0)
            print("Key was pressed");
    }
    return 0;
}
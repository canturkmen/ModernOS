#include "modernos.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int main(int argc, char **argv)
{
    printf("My age is %i\n", 21);

    char words[] = "Hello, how are you?";
    const char* token = strtok(words, " ");

    while(token)
    {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }


    while(1)
    {
        
    }

    return 0;
}
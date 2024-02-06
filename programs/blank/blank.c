#include "modernos.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int main(int argc, char **argv)
{
    char string[] = "hello world";
    struct command_argument* root_command = modernos_parse_command(string, sizeof(string));
    printf("%s\n", root_command->argument);
    printf("%s\n", root_command->next->argument);

    while(1)
    {
        
    }

    return 0;
}
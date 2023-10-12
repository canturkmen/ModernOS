#include "modernos.h"
#include "stdlib.h"

int main(int argc, char** argv)
{
    print("Hello, how are you\n");

    print(itoa(5343));

    void* ptr = malloc(512);
    free(ptr);

    while(1) 
    {
        if(getkey() != 0)
            print("Key was pressed");    
    }
    return 0;
}
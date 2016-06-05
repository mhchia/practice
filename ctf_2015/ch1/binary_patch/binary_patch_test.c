#include <stdio.h>
#include <string.h>

int main(void)
{
    char key[20] = {0}; // list init
    gets(key);
    if (strcmp(key, "HAHA POINT") == 0)
        puts("Register OK");
    else
        puts("Register Failed");

}


#include <string.h>

void overflow(char *arg)
{
    char name[8];
    strcpy(name, arg);
}

int main(int argc, char *argv[])
{
    overflow(argv[1]);

}


#include <stdio.h>
char add_one(char c)
{
    return c + 1;
}
int main()
{
    int i= 0;
    char s[8] = {0};
    scanf("%s", s);
    while (s[i]) {
        printf( "%d\n", add_one(s[i++]));
    }
}

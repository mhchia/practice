#include <stdio.h>
#include <string.h>


void ReplaceSpaces(char* a)
{
    if (!a) return;
    size_t len = strlen(a);
    if (len <= 0) return;
    size_t len_final = len;
    size_t i = 0;
    for (i = 0; i < len; ++i) {
        if (a[i] == ' ') len_final += 2;
    }
    char *p1 = &a[len], *p2 = &a[len_final];
    while (p1 < p2) {
        if (*p1 != ' ') {
            *(p2--) = *p1;
        } else {
            *(p2--) = '0';
            *(p2--) = '2';
            *(p2--) = '%';
        }
        --p1;
    }
}

int main(void)
{
    char a[20] = "    ";
    puts(a);
    ReplaceSpaces(a);
    puts(a);
}


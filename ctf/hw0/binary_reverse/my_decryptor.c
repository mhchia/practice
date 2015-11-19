#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void *encrypt(int *a, int n)
{
    int i;
    for (i = 0; i < n; ++i) {
        void *base = a + 4 * i;
        int *i0 = base;
        char *b0 = (char *)base;
        char *b1 = (char *)base + 1;
        char *b2 = (char *)base + 2;
        char *b3 = (char *)base + 3;

        int original_val = *(int *)base;
        char *ob0 = (char *)(&original_val);
        char *ob1 = (char *)(ob0 + 1);
        char *ob2 = (char *)(ob0 + 2);
        char *ob3 = (char *)(ob0 + 3);
        *b0 = *ob2 ^ *ob1 ^ *ob0;
        *b1 = *ob1 ^ *ob3;
        *b2 = *ob0 ^ *ob2;
        *b3 = *ob0 ^ *ob1;
        if (n - 1 > i) {
            *i0 ^= ~*(i0 + 1);
        }
    }
}

int main(int argc, char *argv[])
{

    int result; // eax@2
    int v4; // ST18_4@3
    signed int v5; // ST1C_4@3
    void *ptr; // ST28_8@3
    FILE *v7; // ST20_8@3
    FILE *stream; // [sp+20h] [bp-10h]@1

    stream = fopen(argv[1], "rb");
    if ( stream )
    {
      fseek(stream, 0LL, 2);
      v4 = ftell(stream); // file size
      v5 = (v4 & 0xFFFFFFFC) + 4;
      fseek(stream, 0LL, 0);
      ptr = malloc(v5);
      fread(ptr, v4, 1uLL, stream);
      memset((char *)ptr + v4, v5 - v4, v5 - v4);
      encrypt((int *)ptr, v5 / 4);
      fclose(stream);
      v7 = fopen(argv[2], "wb");
      fwrite(ptr, v5, 1uLL, v7);
      fclose(v7);
      free(ptr);
      result = 0;
    }
    else
    {
      result = 0;
    }
    return result;

}


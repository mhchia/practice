#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// fmtstr

time_t z()
{
  return 1000000;
}
int readline(char *a1, int a2)
{
  int i; // [sp+1Ch] [bp-Ch]@1

//  for ( i = 0; a2 - 1 > i; ++i )
  for ( i = 0; i < a2 - 1; ++i )
  {
//    if ( read(0, (void *)(i + a1), 1u) <= 0 )
    if ( read(0, &a1[i], 1u) <= 0 )
      exit(-1);
//    if ( *(_BYTE *)(i + a1) == 10 )
    if ( a1[i] == '\n' )
      return i;
  }
//  *(_BYTE *)(a2 - 1 + a1) = 0;
  a1[a2 - 1] = '\0';
  return a2 - 1;
}

int len;

int main(int argc, const char **argv, const char **envp)
{
  void *v3; // esp@1
  int v4; // ebx@2
  char *format; // [sp+0h] [bp-Ch]@1
  char v7; // [sp+7h] [bp-5h]@1
  int *v8; // [sp+8h] [bp-4h]@1

  v8 = &argc;
  alarm(0x3Cu);
  setvbuf(stdout, 0, 2, 0);
  len = z() / 0xFA0u;
  printf("Echo string (less than %d bytes)\n", len);
  v3 = alloca(16 * ((len + 31) / 0x10u)); // size of memory allocated to v3 is multiplicatives of 16
  format = (char *)(16 * ((unsigned int)&v7 >> 4)); // format is points to dexidecimal alignment prior to the memory pointed by v7
  while ( len > 0 ) // len = number of char left to be read.
  {
    v4 = len;
    len = v4 - readline(format, len + 1); // read a line.
    printf(format); // and print the read line.
  }
  puts("Bye!!");
  return 0;
}


#include <stdio.h>
#include <stdlib.h>

int read_80_bytes(int *a1)
{
  int result; // eax@2
  signed int i; // [sp+1Ch] [bp-Ch]@1

  for ( i = 0; ; ++i )
  {
    if ( i <= 799 )
    {
      read(0, (void *)(i + a1), 1u);
      result = *(char *)(i + a1);
      if ( (char)result != 10 )
        continue;
    }
    break;
  }
  return result;
}

int main(int argc, const char **argv, const char **envp)
{
  int v4; // [sp+14h] [bp-5Ch]@1
  int v5; // [sp+64h] [bp-Ch]@3
  int v6; // [sp+68h] [bp-8h]@1
  int i; // [sp+6Ch] [bp-4h]@3

  read_80_bytes(&v4);
  v6 = atoi((const char *)&v4);
  printf("%d\n", v6);
  exit(1);
  if ( (unsigned int)v6 > 0x28 )
    exit(0);
  v5 = open("/home/xorflag/key", 0);
  read(v5, &v4, v6);
  close(v5);
  v5 = open("/home/xorflag/flag", 0);
  read(v5, (char *)&v4 + v6, v6);
  close(v5);
  for ( i = 0; i < v6; ++i )
    *((char *)&v4 + i) ^= *((char *)&v4 + i + v6);
  return write(1, &v4, v6);
}


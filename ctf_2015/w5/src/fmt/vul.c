#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main() {
  setvbuf(stdout, 0, _IONBF, 0);
  char str[200];
  while(fgets(str, sizeof(str), stdin)) {
    printf(str);
  }
  exit(0);
}

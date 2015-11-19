#include <stdio.h>

char str[256];

int main() {

  struct {
    char buf[16];
    int i;
    int j;
  } p;
#define buf p.buf
#define i p.i
#define j p.j

  fgets(str, sizeof(str), stdin);
  for (i=0, j=0; str[i]!='\n'; ++i) {
    if (str[i]!=' ') {
      buf[j++] = str[i];
    }
  }
  buf[j] = 0;
  puts(buf);
}

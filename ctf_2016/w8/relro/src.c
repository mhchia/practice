#include <stdio.h>
#include <unistd.h>
#include <string.h>

char buf[1000000];

int main() {
  char local[10];
  int len = read(0, buf, sizeof(buf));
  memcpy(local, buf, len);
  return 0;
}

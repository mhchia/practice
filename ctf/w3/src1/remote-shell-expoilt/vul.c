#include <stdio.h>
#include <string.h>

char good[200];

int main() {
  char buf[100];
  gets(buf);
  strcpy(good, buf);
  puts(good);
}

#include <stdio.h>
#include <stdlib.h>
int bitcount(unsigned int);
int main(){
    int count = 0, a;
    a = 39283284;
    count = bitcount(a);
    printf("%d有%d個位元為1\n\n", a, count);
    return 0;
}

int bitcount(unsigned int n)
{

   int count = 0 ;
   int i ;
   for(i=65536;i;i>>=1)if(i&n)count++;
   return count ;
}

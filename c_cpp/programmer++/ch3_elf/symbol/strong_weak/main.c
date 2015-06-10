#include <stdio.h>

extern choose_strong_or_weak;
extern char if_all_weak_choose_the_largest_one;

int main(void)
{
//    if_all_weak_choose_the_largest_one = 2147483648;
    short int a = 2;
    printf("the strong ones value : %d\n", choose_strong_or_weak);
    printf("the largest ones size : %f %d\n", if_all_weak_choose_the_largest_one, sizeof(if_all_weak_choose_the_largest_one));
    printf("%d\n", sizeof(a));
}

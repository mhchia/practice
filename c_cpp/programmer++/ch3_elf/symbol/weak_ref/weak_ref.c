// declare a weak symbol
void foo() __attribute__ ((weak)) ;

int main(void)
{
    if (foo)
        foo();
}

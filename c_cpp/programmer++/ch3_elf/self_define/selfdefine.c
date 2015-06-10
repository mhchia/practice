/*
    test for selfdefined sections
*/
__attribute__((section("FOO"))) long int global = 42;
int main(void)
{
}

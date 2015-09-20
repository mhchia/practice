#include <iostream>

int a(int b)
{

}

/*
char a(int b) // error, new declaration for a, thus we know the functions symbol is defined by (1)function_name (2)parameters type and numbers.
{

}
*/
int a(char b) // ok
{
}

int a(int b, int c)
{
}

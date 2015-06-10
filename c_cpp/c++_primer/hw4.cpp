#include <iostream>

using namespace std;

int tripleByValue(char a)
{
    return a * 3;
}
int tripleByValue(int a)
{
    return a * 3;
}
int tripleByValue(double a)
{
    return a * 3;
}

void tripleByRef(char &a)
{
    a *= 3;
}
void tripleByRef(double &a)
{
    a *= 3;
}
void tripleByRef(int &a)
{
    a *= 3;
}

int main(void)
{
    char a = 1;
    double b = 1.0;
    int c = 1;

    cout << tripleByValue(a) << endl;
    cout << tripleByValue(b) << endl;
    cout << tripleByValue(c) << endl;

    tripleByRef(a);
    tripleByRef(b);
    tripleByRef(c);

    cout << (int)a << endl;
    cout << b << endl;
    cout << c << endl;
}

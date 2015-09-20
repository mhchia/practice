#include <iostream>

void print(std::string) {}
void print(double) {}
void print(int c) {}

void foo(void)
{
    void print(int);
    print("value"); // error, 因為在內層宣告了print，compiler只抓到內層的就不會再去外層找declaration了.
}

int main(void)
{
}


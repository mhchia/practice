#include <string>
#include <iostream>
struct A
{
std::string name;
A(std::string n) : name(n) { }

};

struct B : A
{
B(std::string bbb) : A(bbb) { }
void GetName() { std::cout << name << std::endl;}
};

int main(void)
{
    B b("aaa");
    b.GetName();
}


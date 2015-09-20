#include <iostream>

/*
int a(int b)
{

}
*/
int a(float b)
{
    std::cout << "float" << std::endl;
    return b;
}
int a(const int b) // redefinition. of int a(int)
{
    std::cout << "const int" << std::endl;
    return b;
}

void take_string(std::string &s) {}
void take_string2(const std::string &s) {}
int main(void)
{
    float b = 3.5;
    a(b); // print "float", 代表當b適用於多種overloaded function時，會選最match的?

//    take_string("haha"); // error, "haha" is const char *, but take_string need std::string.
    take_string2("haha"); // ok, because of const, "haha" can be converted to std::string and fed to the parameter const std::string &s.

    return 0;
}


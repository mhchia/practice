#include <iostream>
#include <string>

class MyString
{
public:
    // Compilers use single parameter constructor to convert from one type to
    // another to get the right type for a parameter.
    // Assume that there is a function with a parameter of one class type.
    // If we give it an argument with another type, the compiler will check
    // if the class type has a constructor with only one argument and takes
    // parameters type as that argument. If so, compiler does implicit
    // conversion from the argument type to that class type.
    // If you don't want this happenning, add the explicit keyword before
    // the constructor.
    explicit MyString(int n) : size(n), int_string(n, '1') { }

    // MyString(int n) : size(n), int_string(n, '1') { }
    std::string GetString() const { return int_string; }

private:
    mutable int size;
    mutable std::string int_string;
};

void Print(const MyString& str)
{
    std::cout << str.GetString() << std::endl;
}

int main(void)
{
    // int type but not const Mystring& type, compiler will search class
    // Mystring's constructor to find if there exists an implicit conversion
    // if the constructor has no prefix `explicit`.
    Print(3);
}


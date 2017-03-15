#include <iostream>


class A {
    private:
        int value;
public:
    A() = default;
    A(int n) { value = n; std::cout << "copy constructor A(int) is called" << std::endl; }
    // error: copy constructor must pass its first argument by reference
    A(A other) { value = other.value; std::cout << "copy constructor A(A) is called" << std::endl; }

    void Print() { std::cout << value << std::endl; }
};

int main(void)
{
    // only copy constructor A(int) is called
    A a = 10;
    A b;
    b.Print();
    b = a;
    // A(A) is called
    A c = a;
}


#include <iostream>

class Empty {
    public:
        virtual void test() {} // 8 bytes, because if a class has virtual function, c++ compiler creates an virtual function table for it, and adds a pointer to the table to each class instance. A pointer in 64 bits machine needs 8 bytes.
};

int main(void)
{

    std::cout << sizeof(Empty) << std::endl;
}


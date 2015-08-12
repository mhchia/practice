#include <iostream>
#include <cstdlib>

class A
{

public:
    A()
    {
        std::cout << "A()" << std::endl;
    }
    ~A()
    {
        std::cout << "~A()" << std::endl;
    }
};


int main(void)
{
    // contructor and destructor will NOT be called when malloc and free.
    A *a = static_cast<A*>(malloc(sizeof(A)));
    std::free(a);
    a = nullptr;

    // contructor and destructor will be called when using new and delete.
    a = new A; // new and delete manipulate objects in "free store". Though, we can see object allocated by "new" is store in heap!!!
    delete a;
}


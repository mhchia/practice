#include <iostream>

class Test {
public:

    int a;

    Test()
    {
        std::cout << "constructor" << std::endl;
    }
    Test(const Test &t)
    {
        std::cout << "copy constructor" << std::endl;
    }
    Test& operator=(const Test &t)
    {
        std::cout << "assign operator" << std::endl;
    }
    void print()
    {
        std::cout << a << " ";
    }
};

Test t8778();
int main(void)
{
    Test t1; // print "constructor", default constructor

    Test *t2 = new Test; // print "constructor", default constructor

    Test t3(); // print nothing, t3 is a function.

    Test t4{}; // print "constructor"

    Test t5 = t1; // print "copy constructor"

    t1 = t4; // print "assign operator"

    Test t6 = Test(); // print "constructor"

    Test t7 = Test(t6); // print "copy constructor"

    Test t8(t7); // print "copy constructor"
    int a;
    std::cout << a << std::endl;
    return 0;
}



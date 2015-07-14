#include <iostream>

class Test
{
private:
    const int &a;
public:
    Test() : a(100)
    {
    }

    /*
    void SetA(const int &t)
    {
        a = t;
    }
    */
    void PrintA()
    {
        std::cout << a << std::endl;
    }
};


int main(void)
{
    Test t = Test();
    t.PrintA();
//    t.SetA(5);

    t.PrintA();
}


#include <iostream>

class T {
private:
    const int &a;
    const std::string &s;

public:
    void func()
    {
        std::cout << "shit" << std::endl;
    }
    T(int b) : a(2l), s("shit")
    {
        func();
    }

};

int main(void)
{
    

}


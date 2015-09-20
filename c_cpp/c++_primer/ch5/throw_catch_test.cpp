#include <iostream>
#include <stdexcept>

using std::runtime_error;
using std::cout;
using std::endl;

/*
    Exceptions are cought by the nearest catch.
*/

void func2()
{
    throw runtime_error("errorrrrrrrrrrr");
}

void func1()
{
    /*
    try {
        func2();
    } catch (runtime_error err) {
        cout << "Catched by func1 :)" << endl;
    }*/
    func2();
    cout << "sh*t" << endl; // will not be executed
}

int main(void)
{
    try {
        func1();
    } catch (runtime_error err) {
        cout << "Catched by main :(" << endl;
    }
    /* if without try block,

        terminate called after throwing an instance of 'std::runtime_error'
          what():  errorrrrrrrrrrr
        Aborted (core dumped)
    */

    return 0;
}


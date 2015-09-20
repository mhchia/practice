#include <iostream>

int get_size()
{
    static int a = -5;
    ++a;
    return a;
}

int main(void)
{

    begin:;

    /*
    goto end; // error:   crosses initialization of ‘int ix’
    int ix = 0;

    end:;
    ix = 5;
    */

    test:
        int sz = get_size();
        if (sz <= 0) {
            std::cout << sz << std::endl;
            goto test;
        }
}


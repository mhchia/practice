#include <iostream>

class T {};
int get_num()
{
    return 0;
}

int main(void)
{

    /* if statment
         if (condition)
            statement
         else
            statement2

        * the condition can be expression or initialized variable declaration, and both of which must be able to be converted to bool.

    */

    if (int a = get_num()) {
        std::cout << a << std::endl;
    }

    T t;
//    if (t) { } // error, cannot convert t to bool.
}


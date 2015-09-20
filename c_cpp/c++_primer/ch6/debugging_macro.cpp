#include <iostream>

void Print()
{
    /* __func__ is the variable defined by compiler in every function */
#ifndef NDEBUG
    std::cout << __func__ << std::endl; // __func__ is a static const char[] holding the function name.
#endif
}

int main(void)
{
    /* These are variable defined by preprocessor. */
    std::cout << "File name : " << __FILE__ << std::endl
              << "Date      : " << __DATE__ << std::endl // preprocessing date.
              << "Time      : " << __TIME__ << std::endl // preprocessing time
              << "Line      : " << __LINE__ << std::endl //should be 15
              << "Function  : " << __func__ << std::endl;

}


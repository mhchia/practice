#include <iostream>

typedef double wages;

typedef wages base, *double_ptr_t; // base is alias to wages, so base is alias to double.  and that double_ptr_t is alias to *p

using ha = double; // ha is alias to double

using pstring = char*; // typedef char *pstring


int main(void)
{
    double_ptr_t p = nullptr; // double *p = nullptr;

    const pstring a = nullptr; // XXX char * const a = nullptr; !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! NOT pointer to a const char
    // a const in base type modify the give type! pstring is a "ptr to char", so after modified it become "const ptr to char"
    a = nullptr; // error, because that a is a const ptr!!!!
}


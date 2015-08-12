#include <iostream>

using std::string;
int main(void)
{
    int i; double d; const string *ps; char *pc = "c"; void *pv;

    // (a)
    pv = (void*)ps;
    pv = static_cast<void*>(const_cast<string*>(ps));

    // (b)
    i = int(*pc);
    i = static_cast<int>(*pc);

    // (c)
    pv = &d;
    pv = static_cast<void*>(&d);

    // (d)
    pc = (char*)pv;
    pc = static_cast<char*>(pv);
}


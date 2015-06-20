#include <iostream>

int main(void)
{
    // uninitialied const error!
    /*
    const int buf;
    */
    int cnt = 0;
    const int sz = cnt;
    ++cnt; ++sz;
}

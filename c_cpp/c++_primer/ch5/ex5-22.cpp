#include <iostream>

int get_size()
{
    static int a = -5;
    ++a;
    return 0;
}

int main(void)
{
    while (int sz = get_size()) {
        if (sz > 0)
            break;
    }

}


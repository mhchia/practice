#include <iostream>

namespace hahaha {
    int a = 0;

    namespace hehehe {
        int shit;
        int fuck;
    };
};

namespace {
};
int shit = 2;


int main(void)
{
    std::cout << ::shit << std::endl;

}


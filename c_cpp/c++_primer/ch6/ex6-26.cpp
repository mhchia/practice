#include <iostream>

int main(int argc,char *argv[])
{
    for (size_t i = 0; i < argc; ++i) {
        std::cout << "argv[" << i << "] : " << argv[i] << std::endl;
    }

    return 0;
}


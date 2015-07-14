#include <iostream>
#include <ctime>

int main(void)
{
    clock_t t = clock();
    std::cout << t << std::endl;
    for (int i = 0; i < 10000; i++);
    std::cout << clock() << std::endl;
    std::cout << (float)(clock() - t) / CLOCKS_PER_SEC << std::endl;

    return 0;
}


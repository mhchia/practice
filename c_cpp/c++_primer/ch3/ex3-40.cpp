#include <iostream>
#include <iterator>
#include <cstring>
#include <cstddef>

int main(void)
{
    const char a1[] = "hello,", a2[] = "world"; // '\0' is default concat to the strings.
    char a3[100] = "";
    size_t size_a3 = std::end(a3) - std::begin(a3);

    if (strlen(a1) + strlen(a2) + 1 <= size_a3) {
        strcpy(a3, a1);
        strcat(a3, a2);
        a3[strlen(a1) + strlen(a2)] = '\0';
    }

    std::cout << a3 << std::endl;

    return 0;
}


#include <iostream>

int main(void)
{
    std::string buffer, last, max; // default init to ""
    unsigned int max_cnt = 0, last_cnt = 0;

    while (std::cin >> buffer) {
        if (buffer == last)
            ++last_cnt;
        else
            last_cnt = 1;

        if (last_cnt > max_cnt) {
            max = last;
            max_cnt = last_cnt;
        }

        last = buffer;
    }

    std::cout << max << " occurred " << max_cnt << " times." << std::endl;

    return 0;
}


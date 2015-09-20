#include <iostream>
#include <stdexcept>

int main(void)
{
    int a, b;

    while (std::cin >> a >> b) {
        try {
            if (b == 0) {
                throw std::runtime_error("Divider cannot be 0");
            }
            std::cout << (a / b) << std::endl;
            break;
        } catch (std::runtime_error err) {
            std::cout << err.what()
                      << "\nTry again ? [y]" << std::endl;
            char c;
            std::cin >> c;
            if (!std::cin || c == 'n')
                break;
        }
    }

}


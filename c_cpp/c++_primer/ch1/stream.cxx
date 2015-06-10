// iostream defines two types, istream, ostream
// And, it defines 4 objects, cin(istream), cout, cerr, clog(ostream)
#include <iostream>

int main(void)
{
    std::cout << "Enter two numbers : " << std::endl;
    int v1 = 0, v2 = 0;
    // 1. input operator >> takes an istream object from left and a object from right.
    // 2. reads the data from the istream object and stores to the right objects
    // 3. return the left istream object.
    (std::cin >> v1) >> v2;
    ((((((std::cout << "The sum of ") << v1) << " and ") << v2)
              << " is ") << v1 + v2) << std::endl;
    return 0;
}

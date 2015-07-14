#include <iostream>
#include <map>

class A {
public:
    

};

int main(void)
{
    std::map<int, std::string> cc;
    cc[2] = "str";
    cc[3] = "apple";
    cc[4] = "orange";
    for (auto &a : cc) {
        std::cout << a.second << std::endl;
    }
    return 0;
}


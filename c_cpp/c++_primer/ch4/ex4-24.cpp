#include <iostream>
#include <string>

using std::string;

int main(void)
{
    int grade = 78;
    string finalgrade = (((grade > 90) ? "high pass"
                                       : (grade < 60)) ? "fail" : "pass");

    std::cout << finalgrade << std::endl;

    return 0;
}


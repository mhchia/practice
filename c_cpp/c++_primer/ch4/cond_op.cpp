#include <iostream>
#include <string>

using std::string;
int main(void)
{
    int a = 1;
    int grade = 66;
    int b = true ? a : 2;

    string finalgrade = (grade < 60) ? "fail" : "pass";
    finalgrade = (grade > 90) ? "high pass"
                              : (grade < 60) ? "fail" : "pass";
}


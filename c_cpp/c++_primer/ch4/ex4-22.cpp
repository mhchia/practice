#include <string>

using std::string;
int main(void)
{
    int grade = 78;

    /* using conditional operator */
    string finalgrade = (grade > 90) ? "high pass"
                                     : (grade > 75) ? "pass"
                                                    : (grade >= 60) ? "low pass" : "fail";

    /* using if */
    if (grade > 90)
        finalgrade = "high_pass";
    else if (grade > 75)
        finalgrade = "pass";
    else if (grade >= 60)
        finalgrade = "low pass";
    else
        finalgrade = "fail";

}


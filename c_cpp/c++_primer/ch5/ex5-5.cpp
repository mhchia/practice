#include <iostream>

int main(void)
{
    unsigned int grade;
    std::cin >> grade;

    std::string letter_grade; // default init to ""

    if (grade < 60) {
        letter_grade = "F";
    } else if (grade == 100) {
        letter_grade = "A++";
    } else if (grade >= 60 && grade < 100) {
        if (grade < 70)
            letter_grade = "D";
        else if (grade < 80)
            letter_grade = "C";
        else if (grade < 90)
            letter_grade = "B";
        else if (grade < 100)
            letter_grade = "A";

        // append plus or minus
        if (grade % 10 > 7)
            letter_grade += "+";
        else if (grade % 10 < 3)
            letter_grade += "-";
    }

    std::cout << letter_grade << std::endl;
}


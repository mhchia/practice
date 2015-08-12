#include <iostream>

int main(void)
{
    unsigned int grade;
    std::cin >> grade;

    std::string letter_grade; // default init to ""

    letter_grade = (grade < 60) ? "F" :
                                 (grade == 100) ? "A++" :
                                                  (grade >= 60 && grade < 100) ? (grade < 70) ? "D" : (grade < 80) ? "C" : (grade < 90) ? "B" : (grade < 100) ? "A" : "" : "";
    letter_grade += (grade >= 60 && grade < 100) ? (grade % 10 > 7) ? "+" : "" : "";
    letter_grade += (grade >= 60 && grade < 100) ? (grade % 10 < 3) ? "-" : "" : "";

    std::cout << letter_grade << std::endl;
}


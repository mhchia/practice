#include <iostream>

using std::string;
int main(void)
{
    string s1(10, 'c'), s2; // direct init, default init.
    s1 = s2; // assignment

    string ss1 = "hello ", ss2 = "world\n";
    string ss3 = ss1 + ss2; // equivalent to : temp = ss1 + ss2, ss3 = temp.
    // adding strings yields a new string.
    ss1 += ss2; // equivalent to ss1 = ss1 + ss2;

    string a1 = "ha";
//    string a2 = "aa" + "bb"; // error: invalid operands of types ‘const char [3]’ and ‘const char [3]’ to binary ‘operator+’
    string a3 = "hey" + a1; // ok, + operator must have at least one operand with string type.
    string a4 = "aa" "bb"   "cc"
"dd"; // however, we can use space/tab/newline to concat string literals.
    string a5 = "he" "yo" + a1;
    string a6 = a1 + "ha" + "yo"; // ok
    string a7 = (a1 + "ha") + "yo"; // the same as above.
//    string a8 = a1 + ("ha" + "yo"); // not ok.
}


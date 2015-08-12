#include <string>
using std::string;

int main(void)
{
    string s1; // default initialization, s1 is empty.
    string s2 = s1; // copy from s1 to s2
    /*
    above is the same as
    string s2(s1);
    */
    string s3 = "ha"; // s3 is the copy of the string literal "ha"
    string s4(10, 'c'); // s4 is cccccccccc

    string s5 = "hihi"; // copy initialization
    string s6("haha"); // direct initialization
    string s7(10, 'a'); // direct initialization

    string s8 = string(10, 'c'); // copy initialization, explicitly create a temporary object and copy to s8
    /*
    above is the same as
    string temp(10, 'c');
    string s8 = temp;
    */

}


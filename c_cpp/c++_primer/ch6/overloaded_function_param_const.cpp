#include <iostream>

using std::string;

/* redeclaration is ok */
int a(int a);
int a(int a);

/* overloaded ignore top-level const */
using myInt = int;
void func(int a) {}
//void func(myInt a) {} // error, redefinition.
//void func(const int a) {} // error, redefinition. top-level const is ignored by compiler

/* overloaded function does NOT ignore low-level const */
void func(int *a) {}
void func(const int *a) {}
void func(int &a) {}
void func(const int &a) {}


/*
   Write the const one first, because const can eat const/nonconst parameters
   Then, overloading the non-const version. Make non-const call the const one.
*/
const string &ShorterString(const string &s1, const string &s2)
{
    return (s1.size() >= s2.size()) ? s1 : s2;
}

string &ShorterString(string &s1, string &s2)
{
//    const string &shorter_string = ShorterString(s1, s2); // error, oh-no, it recurses.
    // Thus, we need to explicitly convert them to const one.
    const string &shorter_string = ShorterString(const_cast<const string&>(s1),
                                                 const_cast<const string&>(s2)
                                   );
    // we know that originally the string is non-const, it is safe to const_cast its constness.
    return const_cast<string&>(shorter_string);
}


int main(void)
{
    string s1("ha"), s2("haha");
    std::cout << ShorterString(s1, s2) << std::endl;

    return 0;
}


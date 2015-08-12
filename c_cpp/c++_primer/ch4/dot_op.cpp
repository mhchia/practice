#include <iostream>
#include <string>

int main(void)
{
    std::string s1 = "a string", *p = &s1;

    auto n = s1.size(); // string::size_type
    n = (*p).size(); // cannot be *p.size(), because dot op is prior to dereference op, will incur error : p is a pointer and doent have a size member.
    n = p->size();
}


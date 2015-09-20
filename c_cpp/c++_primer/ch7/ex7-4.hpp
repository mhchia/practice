#ifndef EX7_4_H
#define EX7_4_H

#include <iostream>
#include <string>

struct Person
{
    std::string name;
    std::string address; // default init to empty string.
    std::string GetName() const;
    std::string GetAddress() const;
};

inline std::string Person::GetName() const { return name; }
inline std::string Person::GetAddress() const { return address; }

/* nonmember class related function should be declared in the same .h as the class */

std::istream &read(std::istream &, Person &);
std::ostream &print(std::ostream &, const Person &);

#endif

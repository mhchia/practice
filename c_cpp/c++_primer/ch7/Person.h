#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person
{
public:
    Person() = default; // tell compiler to synthesize us a default constructor.
    // member functions defined in class body are defaultly inline.
    inline Person(const std::string &name, const std::string &address)
    {
        this->name = name;
        this->address = address;
    }
    std::string GetName() const;
    std::string GetAddress() const;

private:
    std::string name;
    std::string address; // default init to empty string.
/*
    friend declarations for nomember related functions.
    give them access to Person's private members.
*/
friend std::istream &read(std::istream&, Person&);
friend std::ostream &print(std::ostream&, const Person&);
};

inline std::string Person::GetName() const { return name; }
inline std::string Person::GetAddress() const { return address; }

/* nonmember class related function should be declared in the same .h as the class */

std::istream &read(std::istream &, Person &);
std::ostream &print(std::ostream &, const Person &);

#endif

#include <iostream>

class Animal
{
public:
    virtual void eat()
    {
        std::cout << "I eat generic food" << std::endl;
    }
};

class Cat : public Animal
{
public:
    void eat()
    {
        std::cout << "I eat rats" << std::endl;
    }
};

void EatWhat(Animal &st)
{
    st.eat();
}

int main(void)
{
    Animal animal;
    Cat cat;
    EatWhat(animal);
    EatWhat(cat); // Although Cat is treated as Animal in EatWhat(), Animal's eat method is declared as virtual, and that cause the cat still print "I eat rats". 就是讓Derived class在被當作為Parent class時仍能使用到他overload的function.
}


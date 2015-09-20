#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>

class Screen {
public:
//    typedef std::string::size_type pos;
    using pos = std::string::size_type; // equivalent to above.

    Screen() = default; // needed because we have another constructor.
    Screen(pos ht, pos wd, char c) : height(ht), width(wd),
                                     contents(ht * wd, c) { } // inlined
    char get() const { return contents[cursor]; } // inlined. doesnt modify object, so `this` should be const ptr to const
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);
    void some_member() const { ++access_ctr; } // using mutable to define a member makes const member function be able to modify that member.

    Screen &set(char);
    Screen &set(pos, pos, char);

    /*
        Q : why should we need to overload the const one?
        A : The const member function can be called by const and nonconst objects.
            If the nonconst one calls this const member function, and it returns
            the ref to const object, this object cannot call any nonconst member
            functions anymore!
            Thus, overloading the const member function with a nonconst one.
            The nonconst member function takes parameter this as const-ptr-to-nonconst,
            which can be returned as ref-to-nonconst. And th returned object can therefore
            be used to call nonconst member functions.
    */
    const Screen &display(std::ostream &os) const { do_display(os); return *this; }
    Screen &display(std::ostream &os);

private:
    pos cursor = 0; // in-class initializer.
    pos height = 0, width = 0;
    std::string contents;

    void do_display(std::ostream &os) const;

//    mutable const size_t access_ctr; // error: const ‘access_ctr’ cannot be declared ‘mutable’
    mutable size_t access_ctr;

/* friend declaration */
friend class WindowManager; // make friend with class Window_mgr. It is a declaration, so we don't need to include WindowManager.h immediately.
};

/*
    inline can be specified in declaration and definition, or both.
    It is more preferred that inline is only specified in definition,
    because that inline function's definition must be in the header file.
*/

char Screen::get(pos r, pos c) const // the inline is specified in declaration, so here is not needed.
{
    pos row = r * width;
    return contents[row + c];
}

inline // specify `inline` in definition but not in declaration. It's a preferred way.
Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this; // lvalue.
}

inline // specify inline on definition.
Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline
Screen &Screen::set(pos r, pos col, char c)
{
    contents[r * width + col] = c;
    return *this;
}

inline
Screen &Screen::display(std::ostream &os)
{
    do_display(os);
    return *this;
/*
    const Screen &temp = const_cast<const Screen&>(*this);
    do_display(os);
    return const_cast<Screen&>(*this);
*/
}

inline
void Screen::do_display(std::ostream &os) const
{
    for (std::string::size_type i = 0; i < contents.size(); ++i) {
        std::cout << contents[i];
        if ((i + 1)% width == 0) {
            std::cout << std::endl;
        }
    }
}

#endif

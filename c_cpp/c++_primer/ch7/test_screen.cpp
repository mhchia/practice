#include <iostream>

#include "Screen.h"

int main(void)
{
//    Screen myscreen;
    Screen myscreen(10, 10, '#');
    char ch = myscreen.get();
    ch = myscreen.get(0, 0);
    myscreen.set('0');
    myscreen.move(1, 1).set('1');
    myscreen.move(8, 8).set('8');
    myscreen.display(std::cout).set('9');
}


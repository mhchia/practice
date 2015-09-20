#include <iostream>

void ff(int);
void ff(short);

void manip(long);
void manip(float);
//void manip(double);

int main(void)
{
    ff('a'); // ff(int) is called, because that small ints are converted to int.
//    manip(3.14); // the float literal is double type, can be converted into long or float, so this incurs ambiguous call.
}


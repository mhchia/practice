#include <iostream>
#include <vector>

#include "ex6-55.h"

using std::vector;

int a(int, int);

typedef int F(int, int);
using F = int(int, int);

int main(void)
{
    vector<F*> fpvec;

    fpvec.push_back(&add);
    fpvec.push_back(&substract);
    fpvec.push_back(&multiply);
    fpvec.push_back(&divide);

    for (F* i : fpvec) {
        std::cout << (*i)(5, 3) << std::endl;
    }

    return 0;
}

int add(int a, int b) { return (a + b); }
int substract(int a, int b) { return (a - b); }
int multiply(int a, int b) { return (a * b); }
int divide(int a, int b) { return (a / b); }

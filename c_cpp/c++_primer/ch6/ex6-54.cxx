#include <iostream>
#include <vector>

using std::vector;

int a(int, int);

typedef int F(int, int);
using F = int(int, int);

int main(void)
{
    F* fptr = a;
    vector<F*> fpvec{nullptr, fptr};
}


int b(int a) {}
int b(int a, int b = 1) {} // ok.

int main(void)
{
    const int &a = 1; // only const allows it. normal reference is only allowed to bind to objects.
    b(1, 2); // ok
    b(1);//  error: call of overloaded ‘b(int)’ is ambiguous
}


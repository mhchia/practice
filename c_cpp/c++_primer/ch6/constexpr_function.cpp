#include <iostream>

/*  constexpr function returns constexpr.
    * Its return type and parameters must be a literal type.
    * Its body must contain exactly one return statement.

    * Compiler will replace the constexpr function with its resulting value.
*/
constexpr int new_sz()
{
    return 42;
    /* constexpr function應該只能有一個return */
//    return 2; // error: body of constexpr function ‘constexpr int new_sz()’ not a return-statement.
}
constexpr int fool = new_sz(); // ok, foo is a const expression.

constexpr size_t scale(size_t cnt) { return new_sz() * cnt; } // scale(arg) is a constexpr function if arg is a constant expression.

int main(void)
{
    int arr[scale(1)];
    int i;
    std::cin >> i;
//    int arr2[scale(i)]; // error, scale(i) is not a constant expression.
    // thus we can see, A constexpr function not necessarily returns a constant expression. It depends on its

}


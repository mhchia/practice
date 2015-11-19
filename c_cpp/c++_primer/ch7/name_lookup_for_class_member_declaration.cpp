#include <string>

typedef double Money;
std::string bal; // default init.

class Account {
    public:
        Money balance() { return bal; }
    private:
        Money bal;
};
/*
 *  because that function bodies are processed after the entire class is seen.
 *  Thus, the return inside that function returns the member name bal. not the outer scope string bal.
 */

int main(void)
{

}


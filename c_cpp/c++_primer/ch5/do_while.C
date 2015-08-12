#include <iostream>

int get_response()
{
    static int count = 5;

    --count;

    return count;
}

int main(void)
{
    std::string rsp;

    do {
        std::cout << "please enter two values: ";
        int val1 = 0, val2 = 0;
        std::cin >> val1 >> val2;
        std::cout << "the sum of " << val1 << " and " << val2
                  << " = " << val1 + val2 << "\n\n"
                  << "More? Enter yes or no: ";
        std::cin >> rsp;

    } while (!rsp.empty() && rsp[0] != 'n');


    /*
    do {

    } while (int i = 0); // error, variable definition are not permitted in the do while block.
    */

    /* variable used in condition must be defined outside the do while body!!!!!!!!!!
    do {
        int ival = get_response();
    } while (ival); // error, ival is not declared in this scope.
    */

}


#include <iostream>

struct Sales_data
{
    std::string book_no;
    unsigned int sold_books = 0;
    double revenue = 0.0f;
};
int main(void)
{
    Sales_data d;
    // if without initializer in Sales_data, the values are undefined!
    std::cout << d.book_no << " " << d.sold_books << " " << d.revenue << std::endl;
    return 0;
}

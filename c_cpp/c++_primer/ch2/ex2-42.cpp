#include <iostream>
#include "Sales_data.h"

int main(void)
{
    Sales_data a, b;
    double temp_value;
    std::cin >> a.book_no >> a.sold_books >> temp_value;
    a.revenue += a.sold_books * temp_value;
    std::cin >> b.book_no >> b.sold_books >> temp_value;
    b.revenue += b.sold_books * temp_value;

    if (a.book_no == b.book_no) {
        unsigned total_count = a.sold_books + b.sold_books;
        double total_revenue = a.revenue + b.revenue;
        std::cout << a.book_no << " " << total_count;
        std::cout << " " << total_revenue << std::endl;
        if (total_count != 0)
            std::cout << total_revenue / total_count << std::endl;
        else
            std::cout << "(no sales)" << std::endl;
    } else {
        std::cerr << "Data must have same book_no" << std::endl;
        return -1;
    }
}


#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
struct Sales_data
{
    std::string book_no;
    unsigned int sold_books = 0;
    double revenue = 0.0;
};
#endif

#include <iostream>

/*
struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
} a, b, c
is equivalent to */
struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
struct Sales_data a, b, c;

int main(void)
{
    struct Sales_data d;
    return 0;
}


#include <iostream>
#include "ex7-1.h"

std::istream &read(std::istream &is, struct Sales_data &a)
{
    double price = 0;
    is >> a.bookNo >> a.units_sold >> price;
    a.revenue = price * a.units_sold;

    return is;
}

std::ostream &print(std::ostream &os, const struct Sales_data &a)
{
    os << a.bookNo << " " << a.units_sold << " "
       << a.revenue << " " << a.avg_price();

    return os;
}

double Sales_data::avg_price() const
{
    if (units_sold) {
        return revenue / units_sold;
    } else {
        return 0;
    }
}

Sales_data& Sales_data::combine(const Sales_data &a)
{
    if (bookNo == a.bookNo) {
        units_sold += a.units_sold;
        revenue += a.revenue;
    }
    return (*this);
}

Sales_data add(const Sales_data &a, const Sales_data &b)
{
    Sales_data result = a;
    result.combine(b);
    return result;
}

int main(void)
{

}


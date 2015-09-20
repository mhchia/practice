#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>

class Sales_data { // use class instead of struct because Sales_data has private members.
// friends declaration give these function access to Sales_data's members.
friend Sales_data add(const Sales_data&, const Sales_data&);
friend std::istream &read(std::istream&, Sales_data&);
friend std::ostream &print(std::ostream&, const Sales_data&);
    // constructor add.
public:
    Sales_data() = default; // To explicitly tell constructor to synthesize default constructor for us.
    Sales_data(const std::string &s) : bookNo(s) { }
    Sales_data(const std::string &s, unsigned n, double p):
               bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(std::istream &);
    // other members
    const std::string &isbn() const { return bookNo; } // implicitly inline. Because that isbn() doesn't modify member's in *this, so we pass this as a const-ptr-to-const to isbn()
    Sales_data& combine(const Sales_data &); // implicitly inline.

private:
    double avg_price() const;
    std::string bookNo; // default init.
    unsigned units_sold = 0; // initializer.
    double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::istream &read(std::istream &is, Sales_data &a);
std::ostream &print(std::ostream &os, const Sales_data &a);

inline
double Sales_data::avg_price() const
{
    if (units_sold) {
        return revenue / units_sold;
    } else {
        return 0;
    }
}



#endif

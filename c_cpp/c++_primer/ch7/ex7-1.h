#ifndef EX7_1_H
#define EX7_1_H

#include <iostream>

struct Sales_data {
    // constructor add.
    Sales_data() = default; // To explicitly tell constructor to synthesize default constructor for us.
    Sales_data

    const std::string &isbn() const { return bookNo; } // implicitly inline. Because that isbn() doesn't modify member's in *this, so we pass this as a const-ptr-to-const to isbn()
    Sales_data& combine(const Sales_data &); // implicitly inline.
    double avg_price() const;
    std::string bookNo; // default init.
    unsigned units_sold = 0; // initializer.
    double revenue = 0.0;

};


Sales_data add(const Sales_data&, const Sales_data&);
std::istream &read(std::istream &is, struct Sales_data &a);
std::ostream &print(std::ostream &os, const struct Sales_data &a);


#endif

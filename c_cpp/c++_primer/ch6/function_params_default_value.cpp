#include <iostream>

typedef std::string::size_type sz;

/* all parameter can be given default value only once! */
std::string window(sz height, sz width, char description);
std::string window(sz, sz, char);
//std::string window(sz=1, sz=2, char); // error, default value should be given from right to left. In other words, if the right has no default value, the left cannot have default value.
std::string window(sz, sz, char=' ');
std::string window(sz=1, sz=1, char); // now, all parameters are given default value. no one can be given any default value now.
//std::string window(sz=2, sz, char); // error :  default argument given for parameter 1.

sz wd = 90;
char def = ' ';
sz ht();
std::string screen(sz = ht(), sz = wd, char = def); // ok, but default values must appear outside a function. default value竟然可以是變數耶!

int main(void)
{
    /* decaration using local object is an error */
    sz wd_ = 90;
    char def_ = ' ';
    sz ht_();
//    std::string screen_(sz = ht_(), sz = wd_, char = def_); // error: local variable ‘wd_’ may not appear in this context

    def = '*';
    sz wd = 100;
    std::string window_my = screen(); // calls screen(ht(), 80, '*') instead of screen(ht(), 100, '*'), because that compiler will not choose the local object to be default value.

}


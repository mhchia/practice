int main(void)
{
    double dval; int ival; int *pi;
    dval = ival = pi = 0; // error: invalid conversion from ‘int*’ to ‘int’

    // be corrected to ...
    pi = 0;
    dval = ival; // ok
}


#include <iostream>

struct xgcd {
    int x, y, gcd;
};

int x[2] = {1, 0}, y[2] = {0, 1};

xgcd xeuclidean(int a, int b)
{
    xgcd result;
    int q, r;
    int xx, yy;
    q = a / b; // quotient
    r = a % b; // remainder
    xx = x[1]; yy = y[1]; // preserve the previous x1, y1
    x[1] = -q * x[1] + x[0];
    y[1] = -q * y[1] + y[0];
    x[0] = xx; y[0] = yy;
    if (r == 0) {
        result.gcd = b;
        result.x = x[0];
        result.y = y[0];
        return result;
    } else {
        return xeuclidean(b, r);
    }
}

int main(void)
{
    int a = 7812, b = 6084;
    xgcd result = xeuclidean(a, b);
    std::cout << a << "(" << result.x << ")" << " + "
              << b << "(" << result.y << ")" << " = "
              << result.gcd << std::endl;

    return 0;
}


#include <iostream>
#include <sstream>
#include <string>

#include <math.h>

using namespace std;

class CVec3d
{
    double x, y, z;
    public:
        CVec3d(double x1=0.0, double y1=0.0, double z1=0.0);
        CVec3d(CVec3d &v);
        CVec3d cross(CVec3d v); // compute the cross product
        double norm(); // length of vector
        // need more member function and/or global functions
        friend istream& operator>>(istream &in, CVec3d &a)
        {
            in >> a.x >> a.y >> a.z;
        }
        friend ostream& operator<<(ostream &out, const CVec3d &a)
        {
            out << "(" << a.x << ", " << a.y << ", " << a.z << ")";
        }
        friend CVec3d operator*(double times, CVec3d &a)
        {
            CVec3d b;
            b.x = times * a.x;
            b.y = times * a.y;
            b.z = times * a.z;
            return b;
        }
        CVec3d operator-(CVec3d &a)
        {
            CVec3d b;
            b.x = this->x - a.x;
            b.y = this->y - a.y;
            b.z = this->z - a.z;
            return b;
        }
        CVec3d operator/(double a)
        {
            CVec3d b;
            b.x = this->x / a;
            b.y = this->y / a;
            b.z = this->z / a;
            return b;
        }
        double dot(CVec3d &a)
        {
            return (this->x * a.x + this->y * a.y + this->z * a.z);
        }
        CVec3d unit()
        {
            double length = sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
            CVec3d b;
            b.x = this->x / length;
            b.y = this->y / length;
            b.z = this->z / length;
            return b;
        }
};

CVec3d::CVec3d(double x1, double y1, double z1)
{
}

int main(void)
{
    CVec3d p1, p2, p3, a, b, c;
    cout << "\n Input vector p1: "; cin >> p1;
    cout << "\n Input vector p2: "; cin >> p2;
    cout << "\n Input vector p3: "; cin >> p3;
//    a=p2-p1; b=p3-p1; c=a.cross(b);
    (p2-p1) = a; // wtf
    a = (p2 - p1);
    cout << a;
    cout << (p2 - p1);

    /*
    a=p2-p1; b=p3-p1;
    cout << "\n Vector a: " << a << "\n Vector b: " << b << "\n Vector c : " << c;
    cout << "\n a dot b: " << a.dot(b);
    cout << "\n Vector 2*a: " << 2*a << "\n Vector b/0.5: " << b/0.5;
    cout << "\n Unit Vector of c: " << c.unit();
    */
    return 0;
}

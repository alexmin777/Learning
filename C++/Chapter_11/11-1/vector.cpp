#include <cmath>
#include "vector.h"

using std::cos;
using std::sin;
using std::sqrt;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR {
    const double Rad_to_deg = 45.0 / atan(1.0);

    void Vector::set_x()
    {
        x = mag * cos(ang);
    }

    void Vector::set_y()
    {
        y = mag * sin(ang);
    }

    void Vector::set_mag()
    {
        mag = sqrt(x * x + y * y);
    }

    void Vector::set_ang()
    {
        if (x == 0 && y == 0)
            ang = 0;
        else
            ang = atan2(y, x);
    }

    Vector::Vector()
    {
        x = y = mag = ang = 0;
        mode = RECT;
    }

    Vector::Vector(double n1, double n2, Mode form)
    {
        mode = form;
        if (RECT == mode) {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        } else if (POL == mode) {
            mag = n1;
            ang = n2 / Rad_to_deg;
            set_x();
            set_y();
        } else {
            cout << "Incorrcet 3rd argument to Vector() --";
            cout << "vector set to 0\n";
            x = y = mag = ang = 0;
            mode = RECT;
        }
    }

    Vector::~Vector()
    {

    }

    void Vector::reset(double n1, double n2, Mode form)
    {
        mode = form;

        if (RECT == mode) {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        } else if (POL == mode) {
            mag = n1;
            ang = n2 / Rad_to_deg;
            set_x();
            set_y();
        } else {
            cout << "Incorrcet 3rd argument to Vector() --";
            cout << "vector set to 0\n";
            x = y = mag = ang = 0;
            mode = RECT;
        }
    }

    Vector Vector::operator+(const Vector & b) const
    {
        return Vector(x + b.x, y + b.y);
    }

    std::ostream & operator<<(std::ostream & os, const Vector & b)
    {
        if (Vector::RECT == b.mode) {
            os << "(x, y) = (" << b.x << ", " << b.y << ")"; 
        } else if (Vector::POL == b.mode) {
            os << "(m, a) = (" << b.mag << ", " << b.ang * Rad_to_deg << ")";
        } else {
            os << "Vector object mode is invalid";
        }

        return os;
    }
}
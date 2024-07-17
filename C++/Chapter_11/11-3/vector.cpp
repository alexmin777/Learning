#include <cmath>
#include "vector.h"

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR {
    const double Rad_to_deg = 45.0 / atan(1.0);

    //private
    void Vector::set_x(double mag, double ang)
    {
        x = mag * cos(ang);
    }

    void Vector::set_y(double mag, double ang)
    {
        y = mag * sin(ang);
    }

    double Vector::set_mag() const
    {
        return sqrt(x * x + y * y);
    }

    double Vector::set_ang() const
    {
        double ang;

        if (0.0 == x && 0.0 == y)
            ang = 0.0;
        else
            ang = atan2(y, x);
        
        return ang;
    }

    //public
    Vector::Vector()
    {
        x = y = 0.0;
        mode = RECT;
    }

    Vector::Vector(double n1, double n2, Mode form)
    {
        mode = form;

        if (RECT == mode) {
            x = n1;
            y = n2;
        } else if (POL == mode) {
            set_x(n1, n2 / Rad_to_deg);
            set_y(n1, n2 / Rad_to_deg);
        } else {
            cout << "Incorrect 3rd argument to Vector() -- ";
            cout << "vector set to 0\n";
            x = y = 0.0;
            mode = RECT;
        }
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
            set_x(n1, n2 / Rad_to_deg);
            set_y(n1, n2 / Rad_to_deg);
        } else {
            cout << "Incorrect 3rd argument to Vector() -- ";
            cout << "vector set to 0\n";
            x = y = 0.0;
            mode = RECT;
        }
    }

    Vector::~Vector()
    {
    }

    void Vector::polar_mode()
    {
        mode = POL;
    }

    void Vector::rect_mode()
    {
        mode = RECT;
    }

    Vector Vector::operator+(const Vector & b) const
    {
        return Vector(x + b.x, y + b.y);
    }

    Vector Vector::operator-(const Vector & b) const
    {
        return Vector(x - b.x, y - b.y);
    }

    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }

    Vector Vector::operator*(double n) const
    {
        return Vector(x * n, y * n);
    }

    //friend
    Vector operator*(double n, const Vector & a)
    {
        return a * n;
    }

    std::ostream & operator<<(std::ostream & os, const Vector & v)
    {
        if (Vector::RECT == v.mode) {
            os << "(x,y) = (" << v.x << ", " << v.y << ")";
        } else if (Vector::POL == v.mode) {
            os << "(m,a) = (" << v.magval() << ", "
                << v.angval() * Rad_to_deg << ")";
        } else {
            os << "Vector object mode is invalid";
        }
        return os;
    }
}
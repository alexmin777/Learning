#ifndef __VECTOR_H_
#define __VECTOR_H_

#include <iostream>

namespace VECTOR
{
    class Vector
    {
    public:
        enum Mode {RECT, POL};
    private:
        double x, y;
        double mag, ang;
        Mode mode;
        void set_x();
        void set_y();
        void set_mag();
        void set_ang();

    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        ~Vector();
        void reset(double n1, double n2, Mode form = POL);
        double x_val() const {return x;};
        double y_val() const {return y;};
        double mag_val() const {return mag;};
        double ang_val() const {return ang;};
        void polar_mode() {mode = POL;};
        void rect_mode() {mode = RECT;};
        Vector operator+(const Vector & b) const;

    //friend
        friend std::ostream & operator<<(std::ostream & os, const Vector & b);
    };
}

#endif
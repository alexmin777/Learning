#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
namespace VECTOR {
	class Vector 
	{
	public:
		enum Mode {RECT, POL};
	private:
		//private datas
		double x;
		double y;
		Mode mode;
		//private interface
		void set_x(double, double);
		void set_y(double, double);
	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void reset(double n1, double n2, Mode form = RECT);
		~Vector();
		double xval() const { return x; };
		double yval() const { return y; };
		double magval() const;
		double angval() const;
		void polar_mode();
		void rect_mod();
		//operator overloading
		Vector operator+(const Vector& b) const;
		Vector operator-(const Vector& b) const;
		Vector operator-() const;
		Vector operator*(double n) const;
		//friends
		friend Vector operator*(double n, const Vector& a);
		friend std::ostream& operator<<(std::ostream& os, const Vector& v);
	};
}
#endif // !VECTOR_H

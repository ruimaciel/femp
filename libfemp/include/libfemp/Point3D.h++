#ifndef FEMP_POINT3D_HPP
#define FEMP_POINT3D_HPP

#include <iostream>


namespace fem
{


class Point3D
{
public:
	double data[3];

	// constructors
	Point3D();
	Point3D(const double& a, const double& b, const double& c = 0);
	Point3D(const Point3D &copied);

	// class destructor
	virtual ~Point3D();


	void set(const double& a, const double& b, const double& c = 0);
	void set_cylindrical(const double& radius, const double& alfa, const double &height = 0);

	double norm() const;  // returns the vector's "lenght"
	void normalize(); // converts the vector to it's director vector (norm() == 1)
	Point3D director() const;  // return the vector's director vector

	void zero();   // assigns 0 to all the vector's values

	// returns individual values from the vector
	double x() const	{return data[0];}
	double y() const	{return data[1];}
	double z() const	{return data[2];}

	// sets individual vector values
	void x(const double &val) {data[0] = val;}
	void y(const double &val) {data[1] = val;}
	void z(const double &val) {data[2] = val;}

	// increments a member's value
	void inc_x(const double &ratio)	{data[0] += ratio;}
	void inc_y(const double &ratio)	{data[1] += ratio;}
	void inc_z(const double &ratio)	{data[2] += ratio;}

	// decrements a member's value
	void dec_x(const double &ratio)	{data[0] -= ratio;}
	void dec_y(const double &ratio)	{data[1] -= ratio;}
	void dec_z(const double &ratio)	{data[2] -= ratio;}

	Point3D operator = (const Point3D &other);
	Point3D operator + (const Point3D &other);
	Point3D operator - (const Point3D &other);

	Point3D operator += (const Point3D &other);
	Point3D operator -= (const Point3D &other);
	Point3D operator *= (const double &scalar);

	bool operator == (const Point3D &other);
	bool operator != (const Point3D &other);


	friend Point3D operator +(const Point3D &lhs, const Point3D &rhs);
	friend Point3D operator -(const Point3D &lhs, const Point3D &rhs);
	friend Point3D operator *(const double &s, const Point3D &v);
	friend Point3D operator *(const Point3D &v, const double &s);

	friend Point3D cross_product(const Point3D &LHV, const Point3D &RHV);      //assuming vector is 3D
	friend double dot_product(const Point3D &LHV, const Point3D &RHV);
	friend Point3D getNormalVector(const Point3D &a, const Point3D &b, const Point3D &c);
};


Point3D cross_product(const Point3D &LHV, const Point3D &RHV);      //assuming vector is 3D
double dot_product(const Point3D &LHV, const Point3D &RHV);
Point3D getNormalVector(Point3D &a, Point3D &b, Point3D &c);

std::ostream &operator<< (std::ostream &out, const Point3D &p);


}	// namespace fem

#endif


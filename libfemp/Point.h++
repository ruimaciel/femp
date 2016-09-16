#ifndef FEMP_POINT_HPP
#define FEMP_POINT_HPP

#include <iostream>


namespace fem
{


class Point
{
public:
	double data[3];

	// constructors
	Point();
	Point(const double& a, const double& b, const double& c = 0);
	Point(const Point &copied);

	// class destructor
	virtual ~Point();


	void set(const double& a, const double& b, const double& c = 0);
	void set_cylindrical(const double& radius, const double& alfa, const double &height = 0);

	double norm() const;  // returns the vector's "lenght"
	void normalize(); // converts the vector to it's director vector (norm() == 1)
	Point director() const;  // return the vector's director vector

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

	Point operator = (const Point &other);
	Point operator + (const Point &other);
	Point operator - (const Point &other);

	Point operator += (const Point &other);
	Point operator -= (const Point &other);
	Point operator *= (const double &scalar);

	bool operator == (const Point &other);
	bool operator != (const Point &other);


	friend Point operator +(const Point &lhs, const Point &rhs);
	friend Point operator -(const Point &lhs, const Point &rhs);
	friend Point operator *(const double &s, const Point &v);
	friend Point operator *(const Point &v, const double &s);

	friend Point cross_product(const Point &LHV, const Point &RHV);      //assuming vector is 3D
	friend double dot_product(const Point &LHV, const Point &RHV);
	friend Point getNormalVector(const Point &a, const Point &b, const Point &c);
};


Point cross_product(const Point &LHV, const Point &RHV);      //assuming vector is 3D
double dot_product(const Point &LHV, const Point &RHV);
Point getNormalVector(Point &a, Point &b, Point &c);

std::ostream &operator<< (std::ostream &out, const Point &p);


}	// namespace fem
#endif 


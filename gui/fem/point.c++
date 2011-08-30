
#include <math.h>   // trigonometry functions
#include "point.h++"


namespace fem
{

point::point()
{
	this->data[0] = 0;
	this->data[1] = 0;
	this->data[2] = 0;
}


point::point(const double& a, const double& b, const double& c)
{
    this->data[0] = a;
    this->data[1] = b; 
    this->data[2] = c;
}


point::point(const point &copied)
{
	this->data[0] = copied.data[0];
  	this->data[1] = copied.data[1];
  	this->data[2] = copied.data[2];
}


point::~point()
{
    // nothing to do here
}


/*
	Sets the vector according to the given values
*/
void 
point::set(const double& a, const double& b, const double& c)
{
	this->data[0] = a;
	this->data[1] = b;
	this->data[2] = c;
}


/*
	Converts the given cylindrical coordinates to regular coordinates
*/
void 
point::set_cylindrical(const double& radius, const double& alfa, const double &height)
{
	// alfa is the angle the vector makes with the OX axis
	// angle in degrees
	double angle = (alfa*3.14169f)/180;
	this->data[0] = radius*cos(angle);
	this->data[1] = radius*sin(angle);
	this->data[2] = height;
}


/*
	Returns the vector's norm (or length);
*/
double 
point::norm() const
{
	return sqrt(this->data[0]*this->data[0] + this->data[1]*this->data[1] + this->data[2]*this->data[2] );
}


/*
	Normalizes the vector (norm == 1)
*/
void 
point::normalize()
{
    double length = norm();
    if(length != 0)
    {
    	this->data[0] /= length;
	    this->data[1] /= length;
	    this->data[2] /= length;
    }
}


point 
point::director() const
{
	point temp = *this;
	double length = temp.norm();

	temp.data[0] /= length;
	temp.data[1] /= length;
	temp.data[2] /= length;

	return temp;
}


void 
point::zero()
{
    this->data[0] = this->data[1] = this->data[2];
}


point 
point::operator = (const point &other)
{
	if(&other != this)
  	{
  	    this->data[0] = other.data[0];
  	    this->data[1] = other.data[1];
  	    this->data[2] = other.data[2];
	}
	return *this;
}


point 
point::operator + (const point &other)
{
	point tmp;
  	tmp.data[0] = this->data[0] + other.data[0];
  	tmp.data[1] = this->data[1] + other.data[1];
  	tmp.data[2] = this->data[2] + other.data[2];
  	return tmp;
}


point 
point::operator - (const point &other)
{
	point tmp;
  	tmp.data[0] = this->data[0] - other.data[0];
  	tmp.data[1] = this->data[1] - other.data[1];
  	tmp.data[2] = this->data[2] - other.data[2];
  	return tmp;
}


point 
point::operator += (const point &other)
{
	this->data[0] += other.data[0];
	this->data[1] += other.data[1];
	this->data[2] += other.data[2];

	return *this;
}


point 
point::operator -= (const point &other)
{
	this->data[0] -= other.data[0];
	this->data[1] -= other.data[1];
	this->data[2] -= other.data[2];

	return *this;
}


point 
point::operator *= (const double &scalar)
{
	this->data[0] *= scalar;
	this->data[1] *= scalar;
	this->data[2] *= scalar;

	return *this;
}


bool 
point::operator == (const point &other)
{
	if(&other != this)
  	{
  		if (other.data[0] != this->data [0]) return false;
  		if (other.data[1] != this->data [1]) return false;
  		if (other.data[2] != this->data [2]) return false;
	}
	return true;
}


bool 
point::operator != (const point &other)
{
	if(&other != this)
  	{
  		if (other.data[0] != this->data [0]) return true;
  		if (other.data[1] != this->data [1]) return true;
  		if (other.data[2] != this->data [2]) return true;
	}
	return false;
}


/*
	Friend functions
*/

point operator +(const point &lhs, const point &rhs)
{
	point temp;
	temp.data[0] = lhs.data[0] + rhs.data[0];
	temp.data[1] = lhs.data[1] + rhs.data[1];
	temp.data[2] = lhs.data[2] + rhs.data[2];
	return temp;
}


point operator -(const point &lhs, const point &rhs)
{
	point temp;
	temp.data[0] = lhs.data[0] - rhs.data[0];
	temp.data[1] = lhs.data[1] - rhs.data[1];
	temp.data[2] = lhs.data[2] - rhs.data[2];
	return temp;
}


point operator *(const double &s, const point &v)
{
	point temp;
	temp.data[0] = s * v.data[0];
	temp.data[1] = s * v.data[1];
	temp.data[2] = s * v.data[2];
	return temp;
}


point operator *(const point &v, const double &s)
{
	point temp;
	temp.data[0] = s * v.data[0];
	temp.data[1] = s * v.data[1];
	temp.data[2] = s * v.data[2];
	return temp;
}


point cross_product(const point &LHV, const point &RHV)
{
	point temp;
	temp.data[0] =  LHV.data[1]*RHV.data[2] - LHV.data[2]*RHV.data[1];
	temp.data[1] = -LHV.data[0]*RHV.data[2] + LHV.data[2]*RHV.data[0];
	temp.data[2] =  LHV.data[0]*RHV.data[1] - LHV.data[1]*RHV.data[0];
	return temp;
}

double dot_product(const point &LHV, const point &RHV)
{
	return LHV.data[0]*RHV.data[0] + LHV.data[1]*RHV.data[1] + LHV.data[2]*RHV.data[2];
}


point getNormalVector(const point &a, const point &b, const point &c)
{
	return cross_product(b-a, c-b);
}


point getNormalVector(point &a, point &b, point &c)
{
	return cross_product(b-a, c-b);
}


std::ostream &operator<< (std::ostream &out, const point &p)
{
	out << "[" << p.x() << ", " << p.y() << ", " << p.z() << "]";
	return out;
}

}

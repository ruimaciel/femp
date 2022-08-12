#include <math.h>  // trigonometry functions

#include <libfemp/Point3D.h++>

namespace fem {

Point3D::Point3D() {
	this->data[0] = 0;
	this->data[1] = 0;
	this->data[2] = 0;
}

Point3D::Point3D(double a, double b, double c) {
	this->data[0] = a;
	this->data[1] = b;
	this->data[2] = c;
}

Point3D::Point3D(const Point3D& copied) {
	this->data[0] = copied.data[0];
	this->data[1] = copied.data[1];
	this->data[2] = copied.data[2];
}

Point3D::~Point3D() {
	// nothing to do here
}

/*
	Sets the vector according to the given values
*/
void Point3D::set(double a, double b, double c) {
	this->data[0] = a;
	this->data[1] = b;
	this->data[2] = c;
}

/*
	Converts the given cylindrical coordinates to regular coordinates
*/
void Point3D::set_cylindrical(double radius, double alfa, double height) {
	// alfa is the angle the vector makes with the OX axis
	// angle in degrees
	double angle = (alfa * 3.14169f) / 180;
	this->data[0] = radius * cos(angle);
	this->data[1] = radius * sin(angle);
	this->data[2] = height;
}

/*
	Returns the vector's norm (or length);
*/
double Point3D::norm() const { return sqrt(this->data[0] * this->data[0] + this->data[1] * this->data[1] + this->data[2] * this->data[2]); }

/*
	Normalizes the vector (norm == 1)
*/
void Point3D::normalize() {
	double length = norm();
	if (length != 0) {
		this->data[0] /= length;
		this->data[1] /= length;
		this->data[2] /= length;
	}
}

Point3D Point3D::director() const {
	Point3D temp = *this;
	double length = temp.norm();

	temp.data[0] /= length;
	temp.data[1] /= length;
	temp.data[2] /= length;

	return temp;
}

void Point3D::zero() {
	this->data[0] = 0;
	this->data[1] = 0;
	this->data[2] = 0;
}

double Point3D::x() const { return data[0]; }

double Point3D::y() const { return data[1]; }

double Point3D::z() const { return data[2]; }

void Point3D::x(double val) { data[0] = val; }

void Point3D::y(double val) { data[1] = val; }

void Point3D::z(double val) { data[2] = val; }

Point3D& Point3D::operator=(const Point3D& other) {
	if (&other != this) {
		this->data[0] = other.data[0];
		this->data[1] = other.data[1];
		this->data[2] = other.data[2];
	}
	return *this;
}

Point3D Point3D::operator+(const Point3D& other) {
	Point3D tmp;
	tmp.data[0] = this->data[0] + other.data[0];
	tmp.data[1] = this->data[1] + other.data[1];
	tmp.data[2] = this->data[2] + other.data[2];
	return tmp;
}

Point3D Point3D::operator-(const Point3D& other) {
	Point3D tmp;
	tmp.data[0] = this->data[0] - other.data[0];
	tmp.data[1] = this->data[1] - other.data[1];
	tmp.data[2] = this->data[2] - other.data[2];
	return tmp;
}

Point3D Point3D::operator+=(const Point3D& other) {
	this->data[0] += other.data[0];
	this->data[1] += other.data[1];
	this->data[2] += other.data[2];

	return *this;
}

Point3D Point3D::operator-=(const Point3D& other) {
	this->data[0] -= other.data[0];
	this->data[1] -= other.data[1];
	this->data[2] -= other.data[2];

	return *this;
}

Point3D Point3D::operator*=(double scalar) {
	this->data[0] *= scalar;
	this->data[1] *= scalar;
	this->data[2] *= scalar;

	return *this;
}

bool Point3D::operator==(const Point3D& other) {
	if (&other != this) {
		if (other.data[0] != this->data[0]) return true;
		if (other.data[1] != this->data[1]) return true;
		if (other.data[2] != this->data[2]) return true;
	}
	return false;
}

/*
	Friend functions
*/

Point3D operator+(const Point3D& lhs, const Point3D& rhs) {
	Point3D temp;
	temp.data[0] = lhs.data[0] + rhs.data[0];
	temp.data[1] = lhs.data[1] + rhs.data[1];
	temp.data[2] = lhs.data[2] + rhs.data[2];
	return temp;
}

Point3D operator-(const Point3D& lhs, const Point3D& rhs) {
	Point3D temp;
	temp.data[0] = lhs.data[0] - rhs.data[0];
	temp.data[1] = lhs.data[1] - rhs.data[1];
	temp.data[2] = lhs.data[2] - rhs.data[2];
	return temp;
}

Point3D operator*(double s, const Point3D& v) {
	Point3D temp;
	temp.data[0] = s * v.data[0];
	temp.data[1] = s * v.data[1];
	temp.data[2] = s * v.data[2];
	return temp;
}

Point3D operator*(const Point3D& v, double s) {
	Point3D temp;
	temp.data[0] = s * v.data[0];
	temp.data[1] = s * v.data[1];
	temp.data[2] = s * v.data[2];
	return temp;
}

Point3D cross_product(const Point3D& LHV, const Point3D& RHV) {
	Point3D temp;
	temp.data[0] = LHV.data[1] * RHV.data[2] - LHV.data[2] * RHV.data[1];
	temp.data[1] = -LHV.data[0] * RHV.data[2] + LHV.data[2] * RHV.data[0];
	temp.data[2] = LHV.data[0] * RHV.data[1] - LHV.data[1] * RHV.data[0];
	return temp;
}

double dot_product(const Point3D& LHV, const Point3D& RHV) { return LHV.data[0] * RHV.data[0] + LHV.data[1] * RHV.data[1] + LHV.data[2] * RHV.data[2]; }

Point3D getNormalVector(const Point3D& a, const Point3D& b, const Point3D& c) { return cross_product(b - a, c - b); }

Point3D getNormalVector(Point3D& a, Point3D& b, Point3D& c) { return cross_product(b - a, c - b); }

std::ostream& operator<<(std::ostream& out, const Point3D& p) {
	out << "[" << p.x() << ", " << p.y() << ", " << p.z() << "]";
	return out;
}
}  // namespace fem

#ifndef FEMP_POINT3D_HPP
#define FEMP_POINT3D_HPP

#include <iostream>

namespace fem {

class Point3D {
public:
    double data[3];

    // constructors
    Point3D();
    Point3D(double a, double b, double c = 0);
    Point3D(const Point3D& copied);

    // class destructor
    virtual ~Point3D();

    void set(double a, double b, double c = 0);
    void set_cylindrical(double radius, double alfa, double height = 0);

    double norm() const; // returns the vector's "lenght"
    void normalize(); // converts the vector to it's director vector (norm() == 1)
    Point3D director() const; // return the vector's director vector

    /**
     * Assigns 0 to all the vector's values
     */
    void zero();

    /**
     * Returns individual values from the vector
     */
    double x() const;
    double y() const;
    double z() const;

    /**
     * Sets individual vector values
     */
    void x(double val);
    void y(double val);
    void z(double val);

    Point3D& operator=(const Point3D& other);
    Point3D operator+(const Point3D& other);
    Point3D operator-(const Point3D& other);

    Point3D operator+=(const Point3D& other);
    Point3D operator-=(const Point3D& other);
    Point3D operator*=(double scalar);

    bool operator==(const Point3D& other);
    bool operator!=(const Point3D& other);

    friend Point3D operator+(const Point3D& lhs, const Point3D& rhs);
    friend Point3D operator-(const Point3D& lhs, const Point3D& rhs);
    friend Point3D operator*(double s, const Point3D& v);
    friend Point3D operator*(const Point3D& v, double s);

    friend Point3D cross_product(const Point3D& LHV, const Point3D& RHV); //assuming vector is 3D
    friend double dot_product(const Point3D& LHV, const Point3D& RHV);
    friend Point3D getNormalVector(const Point3D& a, const Point3D& b, const Point3D& c);
};

Point3D cross_product(const Point3D& LHV, const Point3D& RHV); //assuming vector is 3D
double dot_product(const Point3D& LHV, const Point3D& RHV);
Point3D getNormalVector(Point3D& a, Point3D& b, Point3D& c);

std::ostream& operator<<(std::ostream& out, const Point3D& p);

} // namespace fem

#endif

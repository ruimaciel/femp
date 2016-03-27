#ifndef FEMP_POINT_HPP
#define FEMP_POINT_HPP

#include <iostream>


namespace fem
{
    class point
    {
    	public:
    		double data[3];
    		
    		// constructors
    		point();
    		point(const double& a, const double& b, const double& c = 0);
    		point(const point &copied);
    			
    		// class destructor
    		virtual ~point();
    		
    		
    		void set(const double& a, const double& b, const double& c = 0);
    		void set_cylindrical(const double& radius, const double& alfa, const double &height = 0);
    		
    		double norm() const;  // returns the vector's "lenght"
    		void normalize(); // converts the vector to it's director vector (norm() == 1)
    		point director() const;  // return the vector's director vector
    		
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

      		point operator = (const point &other);
      		point operator + (const point &other);
      		point operator - (const point &other);
      		
      		point operator += (const point &other);
      		point operator -= (const point &other);
      		point operator *= (const double &scalar);
    	
        	bool operator == (const point &other);
        	bool operator != (const point &other);
    
        	
    		friend point operator +(const point &lhs, const point &rhs);
    		friend point operator -(const point &lhs, const point &rhs);
    		friend point operator *(const double &s, const point &v);
    		friend point operator *(const point &v, const double &s);
    
    		friend point cross_product(const point &LHV, const point &RHV);      //assuming vector is 3D
    		friend double dot_product(const point &LHV, const point &RHV);
		friend point getNormalVector(const point &a, const point &b, const point &c);
    };

    point cross_product(const point &LHV, const point &RHV);      //assuming vector is 3D
    double dot_product(const point &LHV, const point &RHV);
    point getNormalVector(point &a, point &b, point &c);

    std::ostream &operator<< (std::ostream &out, const point &p);
}
#endif 


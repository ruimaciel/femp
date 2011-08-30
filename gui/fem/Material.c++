#include "Material.h++"

namespace fem
{

Material::Material()
{
}


Material::Material(const Material &copied)
{
	this->label = copied.label;
	this->type = copied.type;
	//TODO support other materials
	this->E = copied.E;
	this->nu = copied.nu;
	this->fy = copied.fy;
}


Material::~Material()
{
}


Eigen::Matrix<double, 6, 6> 
Material::generateD()
{
	Eigen::Matrix<double,6,6> D;

	switch(type)
	{
		case MAT_LINEAR_ELASTIC:
			{
				double a = E/((1+nu)*(1-2*nu));	// temp variable

				// attribute values to D
				// isotropic Hooke's law (fish, pg 241)
				D.setZero();
				D(0,0) = a*(1-nu);	D(0,1) = a*nu; 		D(0,2) = a*nu;
				D(1,0) = a*nu; 		D(1,1) = a*(1-nu); 	D(1,2) = a*nu;
				D(2,0) = a*nu; 		D(2,1) = a*nu; 		D(2,2) = a*(1-nu);
				D(3,3) = a*(1-2*nu)/2.0;
				D(4,4) = a*(1-2*nu)/2.0;
				D(5,5) = a*(1-2*nu)/2.0;
			}
			break;

		default:
			assert(false);	//TODO this part must not be reached
	}

	return D;
}

}

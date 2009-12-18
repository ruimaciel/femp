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


blitz::TinyMatrix<double, 6, 6> Material::generateD()
{
	blitz::TinyMatrix<double, 6, 6> D;

	switch(type)
	{
		case MAT_LINEAR_ELASTIC:
		{
			double a = E/((1+nu)*(1-2*nu));	// temp variable

			// attribute values to D
			// isotropic Hooke's law (fish, pg 241)
			D =	a*(1-nu),	a*nu,	a*nu,	0,	0,	0,
				  a*nu,	a*(1-nu),	a*nu,	0,	0,	0,
				  a*nu,	a*nu,	a*(1-nu),	0,	0,	0,
				  0,	0,	0,	a*(1-2*nu)/2,	0,	0,
				  0,	0,	0,	0,	a*(1-2*nu)/2,	0,
				  0,	0,	0,	0,	0,	a*(1-2*nu)/2;
		}
		break;
	
		default:
		assert(false);	//TODO this part must not be reached
	}

	return D;
}

}

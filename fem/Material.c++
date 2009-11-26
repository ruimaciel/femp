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

}

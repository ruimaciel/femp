#include "NodeRestrictions.h++"


namespace fem
{

NodeRestrictions:: NodeRestrictions()
{
	reset();
}


NodeRestrictions::NodeRestrictions(const NodeRestrictions &copied)
{
	this->d[0] = copied.d[0];
	this->d[1] = copied.d[1];
	this->d[2] = copied.d[2];
	this->r[0] = copied.r[0];
	this->r[1] = copied.r[1];
	this->r[2] = copied.r[2];
}


NodeRestrictions::~NodeRestrictions()
{
}


enum NodeRestrictions::Type NodeRestrictions::extractType(char *buffer)
{
	char *p = buffer;
	switch(*p)
	{
		case 'd':
			p++;
			switch(*p)
			{
				case 'x':
					p++;
					if(*p == '\0')
						return NR_DX;
					else
						return NR_INVALID;
					break;

				case 'y':
					p++;
					if(*p == '\0')
						return NR_DY;
					else
						return NR_INVALID;
					break;

				case 'z':
					p++;
					if(*p == '\0')
						return NR_DZ;
					else
						return NR_INVALID;
					break;

				default:
					return NR_INVALID;
			}
			break;

		case 'r':
			p++;
			switch(*p)
			{
				case 'x':
					p++;
					if(*p == '\0')
						return NR_RX;
					else
						return NR_INVALID;
					break;

				case 'y':
					p++;
					if(*p == '\0')
						return NR_RY;
					else
						return NR_INVALID;
					break;

				case 'z':
					p++;
					if(*p == '\0')
						return NR_RZ;
					else
						return NR_INVALID;
					break;

				default:
					return NR_INVALID;
					break;
			}
			break;

		default:
			return NR_INVALID;
			break;
	}
}


void NodeRestrictions::reset()
{
	this->d[0] = false;
	this->d[1] = false;
	this->d[2] = false;
	this->r[0] = false;
	this->r[1] = false;
	this->r[2] = false;
}

}

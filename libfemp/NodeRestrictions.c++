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
}


bool
NodeRestrictions::free()	const
{
	return !(d[0] || d[1] || d[2]);
}


enum NodeRestrictions::Type
		NodeRestrictions::extractType(char *buffer)
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

	default:
		return NR_INVALID;
		break;
	}
}


void
NodeRestrictions::reset()
{
	this->d[0] = false;
	this->d[1] = false;
	this->d[2] = false;
}

}	// namespace fem

#include "ViewportColors.h++"


ViewportColors::ViewportColors ()
{
	tetrahedron8[0] = 0, tetrahedron8[1] = 0, tetrahedron8[2] = 0;
}


ViewportColors::ViewportColors (const ViewportColors &copied)
{
	tetrahedron8 = copied.tetrahedron8;
}


ViewportColors::~ViewportColors ()
{
}



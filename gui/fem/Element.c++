/* Generated by re2c 0.13.5 on Sun May  9 12:13:28 2010 */
#line 1 "fem/Element.c++.re2c"
#include "Element.h++"

#include <iostream>
#include <assert.h>

namespace fem
{

Element::Element()
{
}


Element::Element(const Element &copied)
{
	this->material = copied.material;
	this->nodes = copied.nodes;
	this->type = copied.type;
}

Element::~Element()
{
}

enum Element::Error Element::set(Type type, std::vector<size_t> nodes)
{
	switch(type)
	{
		case FE_LINE2:
			if(nodes.size() != 2)
			{
				return ERR_NODE_NUMBER;
			}
			break;

		case FE_TETRAHEDRON4:
			if(nodes.size() != 4)
			{
				return ERR_NODE_NUMBER;
			}
			break;

		case FE_TETRAHEDRON10:
			if(nodes.size() != 10)
			{
				return ERR_NODE_NUMBER;
			}
			break;


		case FE_HEXAHEDRON8:
			if(nodes.size() != 8)
			{
				return ERR_NODE_NUMBER;
			}
			break;

		case FE_HEXAHEDRON27:
			if(nodes.size() != 27)
			{
				return ERR_NODE_NUMBER;
			}
			break;

		case FE_PRISM6:
			if(nodes.size() != 6)
			{
				return ERR_NODE_NUMBER;
			}
			break;

		default:
			std::cerr << "error: unsupported type" << std::endl;
			return ERR_INVALID_TYPE;
			break;
	}
	this->type = type;
	this->nodes = nodes;

	// all went well
	return ERR_OK;
}


enum Element::Type Element::extractType(char *buffer)
{
	char *p = buffer;
	char *q;

#line 93 "fem/Element.c++"
{
	char yych;

	yych = (char)*p;
	switch (yych) {
	case 'e':	goto yy9;
	case 'h':	goto yy6;
	case 'i':	goto yy8;
	case 'l':	goto yy2;
	case 'p':	goto yy7;
	case 'q':	goto yy5;
	case 't':	goto yy4;
	default:	goto yy10;
	}
yy2:
	yych = (char)*(q = ++p);
	switch (yych) {
	case 'i':	goto yy134;
	default:	goto yy3;
	}
yy3:
#line 126 "fem/Element.c++.re2c"
	{return FE_INVALID; }
#line 117 "fem/Element.c++"
yy4:
	yych = (char)*(q = ++p);
	switch (yych) {
	case 'e':	goto yy91;
	case 'r':	goto yy92;
	default:	goto yy3;
	}
yy5:
	yych = (char)*(q = ++p);
	switch (yych) {
	case 'u':	goto yy76;
	default:	goto yy3;
	}
yy6:
	yych = (char)*(q = ++p);
	switch (yych) {
	case 'e':	goto yy60;
	default:	goto yy3;
	}
yy7:
	yych = (char)*(q = ++p);
	switch (yych) {
	case 'r':	goto yy37;
	case 'y':	goto yy36;
	default:	goto yy3;
	}
yy8:
	yych = (char)*(q = ++p);
	switch (yych) {
	case 't':	goto yy21;
	default:	goto yy3;
	}
yy9:
	yych = (char)*(q = ++p);
	switch (yych) {
	case 'd':	goto yy11;
	default:	goto yy3;
	}
yy10:
	yych = (char)*++p;
	goto yy3;
yy11:
	yych = (char)*++p;
	switch (yych) {
	case 'g':	goto yy13;
	default:	goto yy12;
	}
yy12:
	p = q;
	goto yy3;
yy13:
	yych = (char)*++p;
	switch (yych) {
	case 'e':	goto yy14;
	default:	goto yy12;
	}
yy14:
	yych = (char)*++p;
	switch (yych) {
	case '4':	goto yy15;
	case '5':	goto yy17;
	case '6':	goto yy19;
	default:	goto yy12;
	}
yy15:
	++p;
#line 120 "fem/Element.c++.re2c"
	{return FE_EDGE4;}
#line 186 "fem/Element.c++"
yy17:
	++p;
#line 121 "fem/Element.c++.re2c"
	{return FE_EDGE5;}
#line 191 "fem/Element.c++"
yy19:
	++p;
#line 122 "fem/Element.c++.re2c"
	{return FE_EDGE6;}
#line 196 "fem/Element.c++"
yy21:
	yych = (char)*++p;
	switch (yych) {
	case 'r':	goto yy22;
	default:	goto yy12;
	}
yy22:
	yych = (char)*++p;
	switch (yych) {
	case 'i':	goto yy23;
	default:	goto yy12;
	}
yy23:
	yych = (char)*++p;
	switch (yych) {
	case 'a':	goto yy24;
	default:	goto yy12;
	}
yy24:
	yych = (char)*++p;
	switch (yych) {
	case 'n':	goto yy25;
	default:	goto yy12;
	}
yy25:
	yych = (char)*++p;
	switch (yych) {
	case 'g':	goto yy26;
	default:	goto yy12;
	}
yy26:
	yych = (char)*++p;
	switch (yych) {
	case 'l':	goto yy27;
	default:	goto yy12;
	}
yy27:
	yych = (char)*++p;
	switch (yych) {
	case 'e':	goto yy28;
	default:	goto yy12;
	}
yy28:
	yych = (char)*++p;
	switch (yych) {
	case '1':	goto yy29;
	case '9':	goto yy30;
	default:	goto yy12;
	}
yy29:
	yych = (char)*++p;
	switch (yych) {
	case '2':	goto yy32;
	case '5':	goto yy34;
	default:	goto yy12;
	}
yy30:
	++p;
#line 114 "fem/Element.c++.re2c"
	{return FE_ITRIANGLE9;}
#line 257 "fem/Element.c++"
yy32:
	++p;
#line 116 "fem/Element.c++.re2c"
	{return FE_ITRIANGLE12;}
#line 262 "fem/Element.c++"
yy34:
	++p;
#line 118 "fem/Element.c++.re2c"
	{return FE_ITRIANGLE15;}
#line 267 "fem/Element.c++"
yy36:
	yych = (char)*++p;
	switch (yych) {
	case 'r':	goto yy48;
	default:	goto yy12;
	}
yy37:
	yych = (char)*++p;
	switch (yych) {
	case 'i':	goto yy38;
	default:	goto yy12;
	}
yy38:
	yych = (char)*++p;
	switch (yych) {
	case 's':	goto yy39;
	default:	goto yy12;
	}
yy39:
	yych = (char)*++p;
	switch (yych) {
	case 'm':	goto yy40;
	default:	goto yy12;
	}
yy40:
	yych = (char)*++p;
	switch (yych) {
	case '1':	goto yy41;
	case '6':	goto yy42;
	default:	goto yy12;
	}
yy41:
	yych = (char)*++p;
	switch (yych) {
	case '5':	goto yy46;
	case '8':	goto yy44;
	default:	goto yy12;
	}
yy42:
	++p;
#line 101 "fem/Element.c++.re2c"
	{return FE_PRISM6;}
#line 310 "fem/Element.c++"
yy44:
	++p;
#line 108 "fem/Element.c++.re2c"
	{return FE_PRISM18;}
#line 315 "fem/Element.c++"
yy46:
	++p;
#line 112 "fem/Element.c++.re2c"
	{return FE_PRISM15;}
#line 320 "fem/Element.c++"
yy48:
	yych = (char)*++p;
	switch (yych) {
	case 'a':	goto yy49;
	default:	goto yy12;
	}
yy49:
	yych = (char)*++p;
	switch (yych) {
	case 'm':	goto yy50;
	default:	goto yy12;
	}
yy50:
	yych = (char)*++p;
	switch (yych) {
	case 'i':	goto yy51;
	default:	goto yy12;
	}
yy51:
	yych = (char)*++p;
	switch (yych) {
	case 'd':	goto yy52;
	default:	goto yy12;
	}
yy52:
	yych = (char)*++p;
	switch (yych) {
	case '1':	goto yy53;
	case '5':	goto yy54;
	default:	goto yy12;
	}
yy53:
	yych = (char)*++p;
	switch (yych) {
	case '3':	goto yy58;
	case '4':	goto yy56;
	default:	goto yy12;
	}
yy54:
	++p;
#line 102 "fem/Element.c++.re2c"
	{return FE_PYRAMID5;}
#line 363 "fem/Element.c++"
yy56:
	++p;
#line 109 "fem/Element.c++.re2c"
	{return FE_PYRAMID14;}
#line 368 "fem/Element.c++"
yy58:
	++p;
#line 113 "fem/Element.c++.re2c"
	{return FE_PYRAMID13;}
#line 373 "fem/Element.c++"
yy60:
	yych = (char)*++p;
	switch (yych) {
	case 'x':	goto yy61;
	default:	goto yy12;
	}
yy61:
	yych = (char)*++p;
	switch (yych) {
	case 'a':	goto yy62;
	default:	goto yy12;
	}
yy62:
	yych = (char)*++p;
	switch (yych) {
	case 'h':	goto yy63;
	default:	goto yy12;
	}
yy63:
	yych = (char)*++p;
	switch (yych) {
	case 'e':	goto yy64;
	default:	goto yy12;
	}
yy64:
	yych = (char)*++p;
	switch (yych) {
	case 'd':	goto yy65;
	default:	goto yy12;
	}
yy65:
	yych = (char)*++p;
	switch (yych) {
	case 'r':	goto yy66;
	default:	goto yy12;
	}
yy66:
	yych = (char)*++p;
	switch (yych) {
	case 'o':	goto yy67;
	default:	goto yy12;
	}
yy67:
	yych = (char)*++p;
	switch (yych) {
	case 'n':	goto yy68;
	default:	goto yy12;
	}
yy68:
	yych = (char)*++p;
	switch (yych) {
	case '2':	goto yy71;
	case '8':	goto yy69;
	default:	goto yy12;
	}
yy69:
	++p;
#line 100 "fem/Element.c++.re2c"
	{return FE_HEXAHEDRON8;}
#line 433 "fem/Element.c++"
yy71:
	yych = (char)*++p;
	switch (yych) {
	case '0':	goto yy72;
	case '7':	goto yy74;
	default:	goto yy12;
	}
yy72:
	++p;
#line 111 "fem/Element.c++.re2c"
	{return FE_HEXAHEDRON20;}
#line 445 "fem/Element.c++"
yy74:
	++p;
#line 107 "fem/Element.c++.re2c"
	{return FE_HEXAHEDRON27;}
#line 450 "fem/Element.c++"
yy76:
	yych = (char)*++p;
	switch (yych) {
	case 'a':	goto yy77;
	default:	goto yy12;
	}
yy77:
	yych = (char)*++p;
	switch (yych) {
	case 'd':	goto yy78;
	default:	goto yy12;
	}
yy78:
	yych = (char)*++p;
	switch (yych) {
	case 'r':	goto yy79;
	default:	goto yy12;
	}
yy79:
	yych = (char)*++p;
	switch (yych) {
	case 'a':	goto yy80;
	default:	goto yy12;
	}
yy80:
	yych = (char)*++p;
	switch (yych) {
	case 'n':	goto yy81;
	default:	goto yy12;
	}
yy81:
	yych = (char)*++p;
	switch (yych) {
	case 'g':	goto yy82;
	default:	goto yy12;
	}
yy82:
	yych = (char)*++p;
	switch (yych) {
	case 'l':	goto yy83;
	default:	goto yy12;
	}
yy83:
	yych = (char)*++p;
	switch (yych) {
	case 'e':	goto yy84;
	default:	goto yy12;
	}
yy84:
	yych = (char)*++p;
	switch (yych) {
	case '4':	goto yy85;
	case '8':	goto yy89;
	case '9':	goto yy87;
	default:	goto yy12;
	}
yy85:
	++p;
#line 98 "fem/Element.c++.re2c"
	{return FE_QUADRANGLE4;}
#line 511 "fem/Element.c++"
yy87:
	++p;
#line 105 "fem/Element.c++.re2c"
	{return FE_QUADRANGLE9;}
#line 516 "fem/Element.c++"
yy89:
	++p;
#line 110 "fem/Element.c++.re2c"
	{return FE_QUADRANGLE8;}
#line 521 "fem/Element.c++"
yy91:
	yych = (char)*++p;
	switch (yych) {
	case 't':	goto yy111;
	default:	goto yy12;
	}
yy92:
	yych = (char)*++p;
	switch (yych) {
	case 'i':	goto yy93;
	default:	goto yy12;
	}
yy93:
	yych = (char)*++p;
	switch (yych) {
	case 'a':	goto yy94;
	default:	goto yy12;
	}
yy94:
	yych = (char)*++p;
	switch (yych) {
	case 'n':	goto yy95;
	default:	goto yy12;
	}
yy95:
	yych = (char)*++p;
	switch (yych) {
	case 'g':	goto yy96;
	default:	goto yy12;
	}
yy96:
	yych = (char)*++p;
	switch (yych) {
	case 'l':	goto yy97;
	default:	goto yy12;
	}
yy97:
	yych = (char)*++p;
	switch (yych) {
	case 'e':	goto yy98;
	default:	goto yy12;
	}
yy98:
	yych = (char)*++p;
	switch (yych) {
	case '1':	goto yy103;
	case '2':	goto yy104;
	case '3':	goto yy99;
	case '6':	goto yy101;
	default:	goto yy12;
	}
yy99:
	++p;
#line 97 "fem/Element.c++.re2c"
	{return FE_TRIANGLE3;}
#line 577 "fem/Element.c++"
yy101:
	++p;
#line 104 "fem/Element.c++.re2c"
	{return FE_TRIANGLE6;}
#line 582 "fem/Element.c++"
yy103:
	yych = (char)*++p;
	switch (yych) {
	case '0':	goto yy109;
	case '5':	goto yy107;
	default:	goto yy12;
	}
yy104:
	yych = (char)*++p;
	switch (yych) {
	case '1':	goto yy105;
	default:	goto yy12;
	}
yy105:
	++p;
#line 119 "fem/Element.c++.re2c"
	{return FE_TRIANGLE21;}
#line 600 "fem/Element.c++"
yy107:
	++p;
#line 117 "fem/Element.c++.re2c"
	{return FE_TRIANGLE15;}
#line 605 "fem/Element.c++"
yy109:
	++p;
#line 115 "fem/Element.c++.re2c"
	{return FE_TRIANGLE10;}
#line 610 "fem/Element.c++"
yy111:
	yych = (char)*++p;
	switch (yych) {
	case 'r':	goto yy112;
	default:	goto yy12;
	}
yy112:
	yych = (char)*++p;
	switch (yych) {
	case 'a':	goto yy113;
	default:	goto yy12;
	}
yy113:
	yych = (char)*++p;
	switch (yych) {
	case 'h':	goto yy114;
	default:	goto yy12;
	}
yy114:
	yych = (char)*++p;
	switch (yych) {
	case 'e':	goto yy115;
	default:	goto yy12;
	}
yy115:
	yych = (char)*++p;
	switch (yych) {
	case 'd':	goto yy116;
	default:	goto yy12;
	}
yy116:
	yych = (char)*++p;
	switch (yych) {
	case 'r':	goto yy117;
	default:	goto yy12;
	}
yy117:
	yych = (char)*++p;
	switch (yych) {
	case 'o':	goto yy118;
	default:	goto yy12;
	}
yy118:
	yych = (char)*++p;
	switch (yych) {
	case 'n':	goto yy119;
	default:	goto yy12;
	}
yy119:
	yych = (char)*++p;
	switch (yych) {
	case '1':	goto yy123;
	case '2':	goto yy122;
	case '3':	goto yy121;
	case '4':	goto yy124;
	case '5':	goto yy120;
	default:	goto yy12;
	}
yy120:
	yych = (char)*++p;
	switch (yych) {
	case '6':	goto yy132;
	default:	goto yy12;
	}
yy121:
	yych = (char)*++p;
	switch (yych) {
	case '5':	goto yy130;
	default:	goto yy12;
	}
yy122:
	yych = (char)*++p;
	switch (yych) {
	case '0':	goto yy128;
	default:	goto yy12;
	}
yy123:
	yych = (char)*++p;
	switch (yych) {
	case '0':	goto yy126;
	default:	goto yy12;
	}
yy124:
	++p;
#line 99 "fem/Element.c++.re2c"
	{return FE_TETRAHEDRON4;}
#line 697 "fem/Element.c++"
yy126:
	++p;
#line 106 "fem/Element.c++.re2c"
	{return FE_TETRAHEDRON10;}
#line 702 "fem/Element.c++"
yy128:
	++p;
#line 123 "fem/Element.c++.re2c"
	{return FE_TETRAHEDRON20;}
#line 707 "fem/Element.c++"
yy130:
	++p;
#line 124 "fem/Element.c++.re2c"
	{return FE_TETRAHEDRON35;}
#line 712 "fem/Element.c++"
yy132:
	++p;
#line 125 "fem/Element.c++.re2c"
	{return FE_TETRAHEDRON56;}
#line 717 "fem/Element.c++"
yy134:
	yych = (char)*++p;
	switch (yych) {
	case 'n':	goto yy135;
	default:	goto yy12;
	}
yy135:
	yych = (char)*++p;
	switch (yych) {
	case 'e':	goto yy136;
	default:	goto yy12;
	}
yy136:
	yych = (char)*++p;
	switch (yych) {
	case '2':	goto yy137;
	case '3':	goto yy139;
	default:	goto yy12;
	}
yy137:
	++p;
#line 96 "fem/Element.c++.re2c"
	{return FE_LINE2;}
#line 741 "fem/Element.c++"
yy139:
	++p;
#line 103 "fem/Element.c++.re2c"
	{return FE_LINE3;}
#line 746 "fem/Element.c++"
}
#line 127 "fem/Element.c++.re2c"

}


int Element::node_number() const
{
	switch(this->type)
	{
		case FE_TRIANGLE3:
			return 3;
			break;

		case FE_TRIANGLE6:
			return 6;
			break;

		case FE_TRIANGLE10:
			return 10;
			break;

		case FE_QUADRANGLE4:
			return 4;
			break;

		case FE_QUADRANGLE9:
			return 9;
			break;

		case FE_TETRAHEDRON4:
			return 4;
			break;

		case FE_TETRAHEDRON10:
			return 10;
			break;

		case FE_HEXAHEDRON8:
			return 8;
			break;

		case FE_HEXAHEDRON20:
			return 20;
			break;

		case FE_HEXAHEDRON27:
			return 27;
			break;

		case FE_PRISM6:
			return 6;
			break;

		default:
			std::cerr << "Element::node_number(): unsupported element" << std::endl;
			assert(0);
			break;
	}
}


enum Element::ElementFamily Element::family() const
{
	switch(this->type)
	{
		case FE_TRIANGLE3   :
		case FE_TRIANGLE6   :
		case FE_TRIANGLE10  :
		case FE_TRIANGLE15  :
		case FE_TRIANGLE21  :
		case FE_ITRIANGLE9  :
		case FE_ITRIANGLE12 :
		case FE_ITRIANGLE15 :
			return EF_TRIANGLE;
			break;

		case FE_QUADRANGLE4 :
		case FE_QUADRANGLE8 :
		case FE_QUADRANGLE9 :
			return EF_QUADRILATERAL;
			break;

		case FE_TETRAHEDRON4:
		case FE_TETRAHEDRON10:
		case FE_TETRAHEDRON20:
		case FE_TETRAHEDRON35:
		case FE_TETRAHEDRON56:
			return EF_TETRAHEDRON;
			break;

		case FE_HEXAHEDRON8:
		case FE_HEXAHEDRON20:
		case FE_HEXAHEDRON27:
			return EF_HEXAHEDRON;
			break;

		case FE_PRISM6      :
		case FE_PRISM18     :
		case FE_PRISM15     :
			return EF_PRISM;
			break;

		case FE_PYRAMID5    :
		case FE_PYRAMID14   :
		case FE_PYRAMID13   :
			return EF_PYRAMID;
			break;

		default:
			return EF_INVALID;
			break;
	}
}


int Element::degree() const
{
	switch(this->type)
	{
		case FE_TRIANGLE3   :
		case FE_TRIANGLE6   :
		case FE_TRIANGLE10  :
		case FE_TRIANGLE15  :
		case FE_TRIANGLE21  :
		case FE_ITRIANGLE9  :
		case FE_ITRIANGLE12 :
		case FE_ITRIANGLE15 :
			return 1;	//TODO change
			break;

		case FE_QUADRANGLE4 :
		case FE_QUADRANGLE8 :
		case FE_QUADRANGLE9 :
			return 1;
			break;

		case FE_TETRAHEDRON4:
			return 1;	//TODO change
			break;

		case FE_TETRAHEDRON10:
		case FE_TETRAHEDRON20:
		case FE_TETRAHEDRON35:
		case FE_TETRAHEDRON56:
			return 1;	//TODO change
			break;

		case FE_HEXAHEDRON8:
			return 4;	//TODO change
			break;

		case FE_HEXAHEDRON20:
		case FE_HEXAHEDRON27:
			return 4;	//TODO change
			break;

		case FE_PRISM6      :
		case FE_PRISM18     :
		case FE_PRISM15     :
			return 1;	//TODO change
			break;

		case FE_PYRAMID5    :
		case FE_PYRAMID14   :
		case FE_PYRAMID13   :
			return 1;	//TODO change
			break;

		default:
			return 0;	// should never be reached
			break;
	}

}
}

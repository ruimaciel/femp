%{
#define YY_HEADER_EXPORT_START_CONDITIONS

#include <stdio.h>
#include "lex.msh_yy.h" /* for the lexer's start states */

#include <vector>
#include <QString>

#include "fem_msh.h++"



std::vector<size_t> temp;	/*temporary node vector*/
size_t ti;

void yyerror(fem::Model &model, char const *s)
{
	fflush(stderr);
	fprintf(stderr,"error at line %d: %s\n", msh_yylineno, s);
}

%}

%union {
	double 	real;
	int	integer;
	char *	text;
} 

%error-verbose
%name-prefix = "msh_yy"
%parse-param {fem::Model &model}
%defines
%locations

%type <real> NUMBER
%token <real> FLOAT;
%token <integer> INTEGER;
%token <text> TEXT;
%token LABEL_OPEN
%token LABEL_CLOSE
%token LABEL_OPEN_ELEMENTS
%token LABEL_CLOSE_ELEMENTS
%token MESH_FORMAT NODES PARAMETRIC_NODES PHYSICAL_NAMES ELEMENTS
%token EL_LINE2
%token EL_TRIANGLE3
%token EL_QUADRANGLE4
%token EL_TETRAHEDRON4
%token EL_HEXAHEDRON8
%token EL_PRISM6
%token EL_PYRAMID5
%token EL_LINE3
%token EL_TRIANGLE6
%token EL_QUADRANGLE9
%token EL_TETRAHEDRON10
%token EL_HEXAHEDRON27
%token EL_PRISM18
%token EL_PYRAMID14
%token EL_POINT
%token EL_QUADRANGLE8
%token EL_HEXAHEDRON20
%token EL_PRISM15
%token EL_PYRAMID13
%token EL_ITRIANGLE9
%token EL_TRIANGLE10
%token EL_ITRIANGLE12
%token EL_TRIANGLE15
%token EL_ITRIANGLE15
%token EL_TRIANGLE21
%token EL_EDGE4
%token EL_EDGE5
%token EL_EDGE6
%token EL_TETRAHEDRON20
%token EL_TETRAHEDRON35
%token EL_TETRAHEDRON56

%token TAG0 TAG1 TAG2 TAG3

%token OTHER

%start document

%%
document:
	| HeaderField NodesField ElementsField
	| HeaderField ParametricNodesField ElementsField
	| HeaderField PhysicalNamesField NodesField ElementsField
	| HeaderField PhysicalNamesField ParametricNodesField ElementsField
	;

HeaderField:	StartHeader HeaderValues EndHeader
	;

StartHeader:	LABEL_OPEN MESH_FORMAT '\n'
		;

HeaderValues:	NUMBER NUMBER  NUMBER '\n'
		{ /*TODO check version */ }
		;

EndHeader: LABEL_CLOSE MESH_FORMAT '\n'
		;

NodesField:	StartNodes NodesLinesCount NodesLines EndNodes
	;

StartNodes:	LABEL_OPEN NODES '\n'
	;

NodesLinesCount:	INTEGER '\n'
	{ // fem_model_increase_node_reserve(model,$1);
	}
	;

NodesLines:	
	| NodesLines NodesLine
	;

NodesLine:	INTEGER  NUMBER  NUMBER  NUMBER '\n'
	{ model.setNode($1, $2, $3, $4); }
	;

NUMBER:	FLOAT	{$$ = $1;}
	| INTEGER	{$$ = $1;}

EndNodes:	LABEL_CLOSE NODES '\n'
	;

ParametricNodesField:	StartParametricNodes ParametricNodesLinesCount ParametricNodesLines EndParametricNodes
	;

StartParametricNodes:	LABEL_OPEN PARAMETRIC_NODES '\n'
	;

ParametricNodesLinesCount:	INTEGER '\n'
	{ /*TODO implement this */ }
	;

ParametricNodesLines:	
	| ParametricNodesLines ParametricNodesLine
	;

ParametricNodesLine:	INTEGER  NUMBER  NUMBER  NUMBER INTEGER INTEGER '\n'
	{ /*TODO finish this: ./Geo/MVertex.cpp:74 */ }
	;

EndParametricNodes:	LABEL_CLOSE PARAMETRIC_NODES '\n'
	;

PhysicalNamesField:	StartPhysicalNames PhysicalNamesLinesCount PhysicalNamesLines EndPhysicalNames
	;

StartPhysicalNames:	LABEL_OPEN PHYSICAL_NAMES '\n'	{ /*TODO finish this */ }
	;

PhysicalNamesLinesCount:	INTEGER '\n'	{/*TODO finish this */}
	;

PhysicalNamesLines: 	INTEGER INTEGER TEXT '\n'	{/*TODO finish this*/}
	;

EndPhysicalNames:	LABEL_CLOSE PHYSICAL_NAMES '\n'	{/*TODO finish this*/}
	;

ElementsField: StartElements ElementsLinesCount ElementsLines EndElements
	;

StartElements:	LABEL_OPEN_ELEMENTS '\n'
	;

ElementsLinesCount: INTEGER '\n'
	{ //fem_model_increase_element_reserve(model, $1);
	}
	;

ElementsLines:
	| ElementsLines ElementLine
	;

ElementLine:	INTEGER EL_LINE2 Tags INTEGER INTEGER '\n'	{ 
	/*
	temp.clear(); temp.reserve(2);
	temp.push_back($4), temp.push_back($5); 
	model.pushElement(fem::Element::FE_LINE2,temp);
	*/
	}
	|	INTEGER EL_TRIANGLE3 Tags INTEGER INTEGER INTEGER '\n' {
	/*
	temp.clear(); temp.reserve(3);
	temp.push_back($4), temp.push_back($5), temp.push_back($6); 
	model.pushElement(fem::Element::FE_TRIANGLE3,temp);
	*/
	}
	|	INTEGER EL_QUADRANGLE4 Tags INTEGER INTEGER INTEGER INTEGER '\n' {
	/*
	temp.clear(); temp.reserve(4);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7);
	model.pushElement(fem::Element::FE_QUADRANGLE4,temp);
	*/
	}
	|	INTEGER EL_TETRAHEDRON4 Tags INTEGER INTEGER INTEGER INTEGER '\n' {
	temp.clear(); temp.reserve(4);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7);
	model.pushElement(fem::Element::FE_TETRAHEDRON4, temp); 
	}
	|	INTEGER EL_HEXAHEDRON8 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	temp.clear(); temp.reserve(8);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8);
	temp.push_back($9), temp.push_back($10), temp.push_back($11);
	model.pushElement(fem::Element::FE_HEXAHEDRON8, temp); 
	}
	|	INTEGER EL_PRISM6 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	temp.clear(); temp.reserve(6);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8);
	temp.push_back($9);
	model.pushElement(fem::Element::FE_PRISM6, temp); 
	}
	|	INTEGER EL_PYRAMID5 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	/*
	temp.clear(); temp.reserve(5);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8);
	model.pushElement(fem::Element::FE_PYRAMID5, temp); 
	*/
	}
	|	INTEGER EL_LINE3 Tags INTEGER  INTEGER  INTEGER  '\n' {
	/*
	temp.clear(); temp.reserve(3);
	temp.push_back($4), temp.push_back($5), temp.push_back($6);
	model.pushElement(fem::Element::FE_LINE3, temp); 
	*/
	}
	|	INTEGER EL_TRIANGLE6 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	/*
	temp.clear(); temp.reserve(6);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8);
	temp.push_back($9);
	model.pushElement(fem::Element::FE_TRIANGLE6, temp); 
	*/
	}
	|	INTEGER EL_QUADRANGLE9 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	/*
	temp.clear(); temp.reserve(9);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8);
	temp.push_back($9), temp.push_back($10), temp.push_back($11), temp.push_back($12);
	model.pushElement(fem::Element::FE_QUADRANGLE9, temp); 
	*/
	}
	|	INTEGER EL_TETRAHEDRON10 Tags INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER '\n' {
	temp.clear(); temp.reserve(10);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8);
	temp.push_back($9), temp.push_back($10), temp.push_back($11), temp.push_back($12), temp.push_back($13);
	model.pushElement(fem::Element::FE_TETRAHEDRON10, temp); 
	}
	|	INTEGER EL_HEXAHEDRON27 Tags INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER '\n' {
	temp.clear(); temp.reserve(27);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8);
	temp.push_back($9), temp.push_back($10), temp.push_back($11), temp.push_back($12), temp.push_back($13);
	temp.push_back($14), temp.push_back($15), temp.push_back($16), temp.push_back($17), temp.push_back($18);
	temp.push_back($19), temp.push_back($20), temp.push_back($21), temp.push_back($22), temp.push_back($23);
	temp.push_back($24), temp.push_back($25), temp.push_back($26), temp.push_back($27), temp.push_back($28);
	temp.push_back($29), temp.push_back($30);
	model.pushElement(fem::Element::FE_HEXAHEDRON27, temp); 
	}
	|	INTEGER EL_PRISM18 Tags INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER  '\n' {
	temp.clear(); temp.reserve(8);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8);
	temp.push_back($9), temp.push_back($10), temp.push_back($11), temp.push_back($12), temp.push_back($13);
	temp.push_back($14), temp.push_back($15), temp.push_back($16), temp.push_back($17), temp.push_back($18);
	temp.push_back($19), temp.push_back($20), temp.push_back($21);
	model.pushElement(fem::Element::FE_PRISM18, temp); 
	}
	|	INTEGER EL_PYRAMID14 Tags INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER  '\n' {
	/*
	temp.clear(); temp.reserve(14);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8);
	temp.push_back($9), temp.push_back($10), temp.push_back($11), temp.push_back($12), temp.push_back($13);
	temp.push_back($14), temp.push_back($15), temp.push_back($16), temp.push_back($17);
	model.pushElement(fem::Element::FE_PYRAMID14, temp); 
	*/
	}
	|	INTEGER EL_POINT Tags INTEGER  '\n' {
	/*
	temp.clear(); temp.reserve(1);
	temp.push_back($4);
	model.pushElement(fem::Element::FE_POINT,temp);
	*/
	}
	|	INTEGER EL_QUADRANGLE8 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	/*
	temp.clear(); temp.reserve(8);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8);
	temp.push_back($9), temp.push_back($10), temp.push_back($11);
	model.pushElement(fem::Element::FE_QUADRANGLE8, temp); 
	*/
	}
	|	INTEGER EL_HEXAHEDRON20 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	temp.clear(); temp.reserve(20);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8);
	temp.push_back($9), temp.push_back($10), temp.push_back($11), temp.push_back($12), temp.push_back($13);
	temp.push_back($14), temp.push_back($15), temp.push_back($16), temp.push_back($17), temp.push_back($18);
	temp.push_back($19), temp.push_back($20), temp.push_back($21), temp.push_back($22), temp.push_back($23);
	model.pushElement(fem::Element::FE_HEXAHEDRON20, temp); 
	}
	|	INTEGER EL_PRISM15 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	temp.clear(); temp.reserve(15);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8);
	temp.push_back($9), temp.push_back($10), temp.push_back($11), temp.push_back($12), temp.push_back($13);
	temp.push_back($14), temp.push_back($15), temp.push_back($16), temp.push_back($17), temp.push_back($18);
	model.pushElement(fem::Element::FE_PRISM15, temp); 
	}
	|	INTEGER EL_PYRAMID13 Tags  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	/*
	temp.clear(); temp.reserve(13);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8);
	temp.push_back($9), temp.push_back($10), temp.push_back($11), temp.push_back($12), temp.push_back($13);
	temp.push_back($14), temp.push_back($15), temp.push_back($16);
	model.pushElement(fem::Element::FE_PYRAMID13, temp); 
	*/
	}
	|	INTEGER EL_ITRIANGLE9 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	/*
	temp.clear(); temp.reserve( 9);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8);
	temp.push_back($9), temp.push_back($10), temp.push_back($11), temp.push_back($12);
	model.pushElement(fem::Element::FE_ITRIANGLE9, temp); 
	*/
	}
	|	INTEGER EL_TRIANGLE10 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	/*
	temp.clear(); temp.reserve(10);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8);
	temp.push_back($9), temp.push_back($10), temp.push_back($11), temp.push_back($12), temp.push_back($13);
	model.pushElement(fem::Element::FE_TRIANGLE10, temp); 
	*/
	}
	|	INTEGER EL_ITRIANGLE12 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	/*
	temp.clear(); temp.reserve(12);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8);
	temp.push_back($9), temp.push_back($10), temp.push_back($11), temp.push_back($12), temp.push_back($13);
	temp.push_back($14), temp.push_back($15);
	model.pushElement(fem::Element::FE_ITRIANGLE12, temp); 
	*/
	}
	|	INTEGER EL_TRIANGLE15 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	/*
	temp.clear(); temp.reserve(15);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8);
	temp.push_back($9), temp.push_back($10), temp.push_back($11), temp.push_back($12), temp.push_back($13);
	temp.push_back($14), temp.push_back($15), temp.push_back($16), temp.push_back($17), temp.push_back($18);
	model.pushElement(fem::Element::FE_TRIANGLE15, temp); 
	*/
	}
	|	INTEGER EL_ITRIANGLE15 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	/*
	temp.clear(); temp.reserve(15);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8);
	temp.push_back($9), temp.push_back($10), temp.push_back($11), temp.push_back($12), temp.push_back($13);
	temp.push_back($14), temp.push_back($15), temp.push_back($16), temp.push_back($17), temp.push_back($18);
	model.pushElement(fem::Element::FE_ITRIANGLE15, temp); 
	*/
	}
	|	INTEGER EL_TRIANGLE21 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	/*
	temp.clear(); temp.reserve(21);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8);
	temp.push_back($9), temp.push_back($10), temp.push_back($11), temp.push_back($12), temp.push_back($13);
	temp.push_back($14), temp.push_back($15), temp.push_back($16), temp.push_back($17), temp.push_back($18);
	temp.push_back($19), temp.push_back($20), temp.push_back($21), temp.push_back($22), temp.push_back($23);
	temp.push_back($24);
	model.pushElement(fem::Element::FE_TRIANGLE21, temp); 
	*/
	}
	|	INTEGER EL_EDGE4 Tags INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	/*
	temp.clear(); temp.reserve( 4);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7);
	model.pushElement(fem::Element::FE_EDGE4, temp); 
	*/
	}
	|	INTEGER EL_EDGE5 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	/*
	temp.clear(); temp.reserve( 5);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8);
	model.pushElement(fem::Element::FE_EDGE5, temp); 
	*/
	}
	|	INTEGER EL_EDGE6 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	/*
	temp.clear(); temp.reserve( 6);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8);
	temp.push_back($9);
	model.pushElement(fem::Element::FE_EDGE6, temp); 
	*/
	}
	|	INTEGER EL_TETRAHEDRON20 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	temp.clear(); temp.reserve(20);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8); 
	temp.push_back($9), temp.push_back($10), temp.push_back($11), temp.push_back($12), temp.push_back($13);
	temp.push_back($14), temp.push_back($15), temp.push_back($16), temp.push_back($17), temp.push_back($18); 
	temp.push_back($19), temp.push_back($20), temp.push_back($21), temp.push_back($22), temp.push_back($23);
	model.pushElement(fem::Element::FE_TETRAHEDRON20, temp); 
	}
	|	INTEGER EL_TETRAHEDRON35 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	temp.clear(); temp.reserve(35);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8); 
	temp.push_back($9), temp.push_back($10), temp.push_back($11), temp.push_back($12), temp.push_back($13);
	temp.push_back($14), temp.push_back($15), temp.push_back($16), temp.push_back($17), temp.push_back($18); 
	temp.push_back($19), temp.push_back($20), temp.push_back($21), temp.push_back($22), temp.push_back($23);
	temp.push_back($24), temp.push_back($25), temp.push_back($26), temp.push_back($27), temp.push_back($28); 
	temp.push_back($29), temp.push_back($30), temp.push_back($31), temp.push_back($32), temp.push_back($33);
	temp.push_back($34), temp.push_back($35), temp.push_back($36), temp.push_back($37), temp.push_back($38);
	model.pushElement(fem::Element::FE_TETRAHEDRON35, temp); 
	}
	|	INTEGER EL_TETRAHEDRON56 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	temp.clear(); temp.reserve(56);
	temp.push_back($4), temp.push_back($5), temp.push_back($6), temp.push_back($7), temp.push_back($8); 
	temp.push_back($9); temp.push_back($10); temp.push_back($11), temp.push_back($12), temp.push_back($13);
	temp.push_back($14), temp.push_back($15), temp.push_back($16), temp.push_back($17), temp.push_back($18); 
	temp.push_back($19), temp.push_back($20), temp.push_back($21), temp.push_back($22), temp.push_back($23);
	temp.push_back($24), temp.push_back($25), temp.push_back($26), temp.push_back($27), temp.push_back($28); 
	temp.push_back($29), temp.push_back($30), temp.push_back($31), temp.push_back($32), temp.push_back($33);
	temp.push_back($34), temp.push_back($35), temp.push_back($36), temp.push_back($37), temp.push_back($38); 
	temp.push_back($39), temp.push_back($40), temp.push_back($41), temp.push_back($42), temp.push_back($43);
	temp.push_back($44), temp.push_back($45), temp.push_back($46), temp.push_back($47), temp.push_back($48); 
	temp.push_back($49), temp.push_back($50), temp.push_back($51), temp.push_back($52), temp.push_back($53);
	temp.push_back($54), temp.push_back($55), temp.push_back($56), temp.push_back($57), temp.push_back($58); 
	temp.push_back($59);
	model.pushElement(fem::Element::FE_TETRAHEDRON56, temp); 
	}
	;

Tags:	TAG0	{ /*TODO finish this */}
	| TAG1 INTEGER	{ /*TODO finish this */}
	| TAG2 INTEGER INTEGER	{ /*TODO finish this */}
	| TAG3 INTEGER INTEGER INTEGER	{ /*TODO finish this */}
	;

EndElements:	LABEL_CLOSE_ELEMENTS '\n'
	;

%%


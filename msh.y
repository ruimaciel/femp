%{
#define YY_HEADER_EXPORT_START_CONDITIONS

#include <stdio.h>
#include "lex.msh_yy.h" /* for the lexer's start states */

#include <vector>

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

HeaderValues:	INTEGER INTEGER  INTEGER '\n'
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
	temp.clear(); temp.reserve(2);
	temp.reserve(2);
	temp[0] = $4, temp[1] = $5; 
	model.pushElement(fem::Element::FE_LINE2,temp);
	//fem_model_add_element(model, FE_LINE, $1, temp); 
	}
	|	INTEGER EL_TRIANGLE3 Tags INTEGER INTEGER INTEGER '\n' {
	temp.clear(); temp.reserve(3);
	temp[0] = $4, temp[1] = $5, temp[2] = $6; 
	model.pushElement(fem::Element::FE_TRIANGLE3,temp);
	}
	|	INTEGER EL_QUADRANGLE4 Tags INTEGER INTEGER INTEGER INTEGER '\n' {
	temp.clear(); temp.reserve(4);
	temp[0] = $4, temp[1] = $5, temp[2] = $6, temp[3] = $7;
	model.pushElement(fem::Element::FE_QUADRANGLE4,temp);
	}
	|	INTEGER EL_TETRAHEDRON4 Tags INTEGER INTEGER INTEGER INTEGER '\n' {
	temp.clear(); temp.reserve(4);
	temp[0] = $4, temp[1] = $5, temp[2] = $6, temp[3] = $7;
	model.pushElement(fem::Element::FE_TETRAHEDRON4, temp); 
	}
	|	INTEGER EL_HEXAHEDRON8 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	temp.clear(); temp.reserve(8);
	temp[0] = $4, temp[1] = $5, temp[2] = $6, temp[3] = $7, temp[4] = $8, temp[5] = $9, temp[6] = $10, temp[7] = $11;
	model.pushElement(fem::Element::FE_HEXAHEDRON8, temp); 
	}
	|	INTEGER EL_PRISM6 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	temp.clear(); temp.reserve(6);
	temp[0] = $4, temp[1] = $5, temp[2] = $6, temp[3] = $7, temp[4] = $8, temp[5] = $9;
	model.pushElement(fem::Element::FE_PRISM6, temp); 
	}
	|	INTEGER EL_PYRAMID5 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	temp.clear(); temp.reserve(5);
	temp[0] = $4, temp[1] = $5, temp[2] = $6, temp[3] = $7, temp[4] = $8;
	model.pushElement(fem::Element::FE_PYRAMID5, temp); 
	}
	|	INTEGER EL_LINE3 Tags INTEGER  INTEGER  INTEGER  '\n' {
	temp.clear(); temp.reserve(3);
	temp[0] = $4, temp[1] = $5, temp[2] = $6;
	model.pushElement(fem::Element::FE_LINE3, temp); 
	}
	|	INTEGER EL_TRIANGLE6 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	temp.clear(); temp.reserve(6);
	temp[0] = $4, temp[1] = $5, temp[2] = $6, temp[3] = $7, temp[4] = $8, temp[5] = $9;
	model.pushElement(fem::Element::FE_TRIANGLE6, temp); 
	}
	|	INTEGER EL_QUADRANGLE9 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	temp.clear(); temp.reserve(9);
	temp[0] = $4, temp[1] = $5, temp[2] = $6, temp[3] = $7, temp[4] = $8, temp[5] = $9, temp[6] = $10, temp[7] = $11, temp[8] = $12;
	model.pushElement(fem::Element::FE_QUADRANGLE9, temp); 
	}
	|	INTEGER EL_TETRAHEDRON10 Tags INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER '\n' {
	temp.clear(); temp.reserve(10);
	temp[0] = $4, temp[1] = $5, temp[2] = $6, temp[3] = $7, temp[4] = $8, temp[5] = $9, temp[6] = $10, temp[7] = $11, temp[8] = $12, temp[9] = $13;
	model.pushElement(fem::Element::FE_TETRAHEDRON10, temp); 
	}
	|	INTEGER EL_HEXAHEDRON27 Tags INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER '\n' {
	temp.clear(); temp.reserve(27);
	temp[0] = $4, temp[1] = $5, temp[2] = $6, temp[3] = $7, temp[4] = $8, temp[5] = $9, temp[6] = $10, temp[7] = $11, temp[8] = $12, temp[9] = $13;
	temp[10] = $14, temp[11] = $15, temp[12] = $16, temp[13] = $17, temp[14] = $18, temp[15] = $19, temp[16] = $20, temp[17] = $21, temp[18] = $22, temp[19] = $23;
	temp[20] = $24, temp[21] = $25, temp[22] = $26, temp[23] = $27, temp[24] = $28, temp[25] = $29, temp[26] = $30;
	model.pushElement(fem::Element::FE_HEXAHEDRON27, temp); 
	}
	|	INTEGER EL_PRISM18 Tags INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER  '\n' {
	temp.clear(); temp.reserve(8);
	temp[0] = $4, temp[1] = $5, temp[2] = $6, temp[3] = $7, temp[4] = $8, temp[5] = $9, temp[6] = $10, temp[7] = $11, temp[8] = $12, temp[9] = $13;
	temp[10] = $14, temp[11] = $15, temp[12] = $16, temp[13] = $17, temp[14] = $18, temp[15] = $19, temp[16] = $20, temp[17] = $21;
	model.pushElement(fem::Element::FE_PRISM18, temp); 
	}
	|	INTEGER EL_PYRAMID14 Tags INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER INTEGER  '\n' {
	temp.clear(); temp.reserve(14);
	temp[0] = $4, temp[1] = $5, temp[2] = $6, temp[3] = $7, temp[4] = $8, temp[5] = $9, temp[6] = $10, temp[7] = $11, temp[8] = $12, temp[9] = $13;
	temp[10] = $14, temp[11] = $15, temp[12] = $16, temp[13] = $17;
	model.pushElement(fem::Element::FE_PYRAMID14, temp); 
	}
	|	INTEGER EL_POINT Tags INTEGER  '\n' {
	temp.clear(); temp.reserve(1);
	temp[0] = $4;
	model.pushElement(fem::Element::FE_POINT,temp);
	}
	|	INTEGER EL_QUADRANGLE8 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	temp.clear(); temp.reserve(8);
	temp[0] = $4, temp[1] = $5, temp[2] = $6, temp[3] = $7, temp[4] = $8, temp[5] = $9, temp[6] = $10, temp[7] = $11;
	model.pushElement(fem::Element::FE_POINT,temp);
	model.pushElement(fem::Element::FE_QUADRANGLE8, temp); 
	}
	|	INTEGER EL_HEXAHEDRON20 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	temp.clear(); temp.reserve(20);
	temp[0] = $4, temp[1] = $5, temp[2] = $6, temp[3] = $7, temp[4] = $8, temp[5] = $9, temp[6] = $10, temp[7] = $11, temp[8] = $12, temp[9] = $13;
	temp[10] = $14, temp[11] = $15, temp[12] = $16, temp[13] = $17, temp[14] = $18, temp[15] = $19, temp[16] = $20, temp[17] = $21, temp[18] = $22, temp[19] = $23;
	model.pushElement(fem::Element::FE_PRISM18, temp); 
	}
	|	INTEGER EL_PRISM15 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	temp.clear(); temp.reserve(15);
	temp[0] = $4, temp[1] = $5, temp[2] = $6, temp[3] = $7, temp[4] = $8, temp[5] = $9, temp[6] = $10, temp[7] = $11, temp[8] = $12, temp[9] = $13;
	temp[10] = $14, temp[11] = $15, temp[12] = $16, temp[13] = $17, temp[14] = $18;
	model.pushElement(fem::Element::FE_PRISM15, temp); 
	}
	|	INTEGER EL_PYRAMID13 Tags  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	temp.clear(); temp.reserve(13);
	temp[0] = $4, temp[1] = $5, temp[2] = $6, temp[3] = $7, temp[4] = $8, temp[5] = $9, temp[6] = $10, temp[7] = $11, temp[8] = $12, temp[9] = $13;
	temp[10] = $14, temp[11] = $15, temp[12] = $16;
	model.pushElement(fem::Element::FE_PYRAMID13, temp); 
	}
	|	INTEGER EL_ITRIANGLE9 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	temp.clear(); temp.reserve( 9);
	temp[0] = $4, temp[1] = $5, temp[2] = $6, temp[3] = $7, temp[4] = $8, temp[5] = $9, temp[6] = $10, temp[7] = $11, temp[8] = $12;
	model.pushElement(fem::Element::FE_ITRIANGLE9, temp); 
	}
	|	INTEGER EL_TRIANGLE10 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	temp.clear(); temp.reserve(10);
	temp[0] = $4, temp[1] = $5, temp[2] = $6, temp[3] = $7, temp[4] = $8, temp[5] = $9, temp[6] = $10, temp[7] = $11, temp[8] = $12, temp[9] = $13;
	model.pushElement(fem::Element::FE_TRIANGLE10, temp); 
	}
	|	INTEGER EL_ITRIANGLE12 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	temp.clear(); temp.reserve(12);
	temp[0] = $4, temp[1] = $5, temp[2] = $6, temp[3] = $7, temp[4] = $8, temp[5] = $9, temp[6] = $10, temp[7] = $11, temp[8] = $12, temp[9] = $13;
	temp[0] = $14, temp[1] = $15;
	model.pushElement(fem::Element::FE_ITRIANGLE12, temp); 
	}
	|	INTEGER EL_TRIANGLE15 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	temp.clear(); temp.reserve(15);
	temp[0] = $4, temp[1] = $5, temp[2] = $6, temp[3] = $7, temp[4] = $8, temp[5] = $9, temp[6] = $10, temp[7] = $11, temp[8] = $12, temp[9] = $13;
	temp[10] = $14, temp[11] = $15, temp[12] = $16, temp[13] = $17, temp[14] = $18;
	model.pushElement(fem::Element::FE_TRIANGLE15, temp); 
	}
	|	INTEGER EL_ITRIANGLE15 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	temp.clear(); temp.reserve(15);
	temp[0] = $4, temp[1] = $5, temp[2] = $6, temp[3] = $7, temp[4] = $8, temp[5] = $9, temp[6] = $10, temp[7] = $11, temp[8] = $12, temp[9] = $13;
	temp[10] = $14, temp[11] = $15, temp[12] = $16, temp[13] = $17, temp[14] = $18;
	model.pushElement(fem::Element::FE_ITRIANGLE15, temp); 
	}
	|	INTEGER EL_TRIANGLE21 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	temp.clear(); temp.reserve(21);
	temp[0] = $4, temp[1] = $5, temp[2] = $6, temp[3] = $7, temp[4] = $8, temp[5] = $9, temp[6] = $10, temp[7] = $11, temp[8] = $12, temp[9] = $13;
	temp[10] = $14, temp[11] = $15, temp[12] = $16, temp[13] = $17, temp[14] = $18, temp[15] = $19, temp[16] = $20, temp[17] = $21, temp[18] = $22, temp[19] = $23;
	temp[20] = $24;
	model.pushElement(fem::Element::FE_TRIANGLE21, temp); 
	}
	|	INTEGER EL_EDGE4 Tags INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	temp.clear(); temp.reserve( 4);
	temp[0] = $4, temp[1] = $5, temp[2] = $6, temp[3] = $7;
	model.pushElement(fem::Element::FE_TRIANGLE21, temp); 
	}
	|	INTEGER EL_EDGE5 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	temp.clear(); temp.reserve( 5);
	temp[0] = $4, temp[1] = $5, temp[2] = $6, temp[3] = $7, temp[4] = $8;
	model.pushElement(fem::Element::FE_EDGE5, temp); 
	}
	|	INTEGER EL_EDGE6 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	temp.clear(); temp.reserve( 6);
	temp[0] = $4, temp[1] = $5, temp[2] = $6, temp[3] = $7, temp[4] = $8, temp[5] = $9;
	model.pushElement(fem::Element::FE_EDGE6, temp); 
	}
	|	INTEGER EL_TETRAHEDRON20 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	temp.clear(); temp.reserve(20);
	temp[0] = $4, temp[1] = $5, temp[2] = $6, temp[3] = $7, temp[4] = $8, temp[5] = $9, temp[6] = $10, temp[7] = $11, temp[8] = $12, temp[9] = $13;
	temp[10] = $14, temp[11] = $15, temp[12] = $16, temp[13] = $17, temp[14] = $18, temp[15] = $19, temp[16] = $20, temp[17] = $21, temp[18] = $22, temp[19] = $23;
	model.pushElement(fem::Element::FE_HEXAHEDRON27, temp); 
	}
	|	INTEGER EL_TETRAHEDRON35 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	temp.clear(); temp.reserve(35);
	temp[0] = $4, temp[1] = $5, temp[2] = $6, temp[3] = $7, temp[4] = $8, temp[5] = $9, temp[6] = $10, temp[7] = $11, temp[8] = $12, temp[9] = $13;
	temp[10] = $14, temp[11] = $15, temp[12] = $16, temp[13] = $17, temp[14] = $18, temp[15] = $19, temp[16] = $20, temp[17] = $21, temp[18] = $22, temp[19] = $23;
	temp[20] = $24, temp[21] = $25, temp[22] = $26, temp[23] = $27, temp[24] = $28, temp[25] = $29, temp[26] = $30, temp[27] = $31, temp[28] = $32, temp[29] = $33;
	temp[30] = $34, temp[31] = $35, temp[32] = $36, temp[33] = $37, temp[34] = $38;
	model.pushElement(fem::Element::FE_TETRAHEDRON35, temp); 
	}
	|	INTEGER EL_TETRAHEDRON56 Tags INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  INTEGER  '\n' {
	temp.clear(); temp.reserve(56);
	temp[0] = $4, temp[1] = $5, temp[2] = $6, temp[3] = $7, temp[4] = $8, temp[5] = $9, temp[6] = $10, temp[7] = $11, temp[8] = $12, temp[9] = $13;
	temp[10] = $14, temp[11] = $15, temp[12] = $16, temp[13] = $17, temp[14] = $18, temp[15] = $19, temp[16] = $20, temp[17] = $21, temp[18] = $22, temp[19] = $23;
	temp[20] = $24, temp[21] = $25, temp[22] = $26, temp[23] = $27, temp[24] = $28, temp[25] = $29, temp[26] = $30, temp[27] = $31, temp[28] = $32, temp[29] = $33;
	temp[30] = $34, temp[31] = $35, temp[32] = $36, temp[33] = $37, temp[34] = $38, temp[35] = $39, temp[36] = $40, temp[37] = $41, temp[38] = $42, temp[39] = $43;
	temp[40] = $44, temp[41] = $45, temp[42] = $46, temp[43] = $47, temp[44] = $48, temp[45] = $49, temp[46] = $50, temp[47] = $51, temp[48] = $52, temp[49] = $53;
	temp[50] = $54, temp[51] = $55, temp[52] = $56, temp[53] = $57, temp[54] = $58, temp[55] = $59;
	model.pushElement(fem::Element::FE_TETRAHEDRON35, temp); 
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


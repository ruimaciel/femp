%{
#include "msh.tab.h"

struct workaround { /* ambiguous grammar workaround */
	int in;	/* states if the ambiguous grammar workaround is in */
	int on;
	int count;	/* result count */
} w = {0,0,0};

#define DO_IT if(w.in) { \
if( (w.count == 0)&&(w.on))  {yy_push_state(s_element);} \
else w.on = 1; w.count++;} 


#define POST_ELEMENT { yy_pop_state(); yy_push_state(s_tag); w.count++;}
#define POST_TAG { yy_pop_state(); w.count++;}
%}
/*do nothing*/

%x s_element
%x s_tag
%option stack
%option prefix="msh_yy"
%option noyywrap
%option yylineno



dreal	(-?[0-9]*"."[0-9]+)
ereal	(-?[0-9]*"."[0-9]+[eE][+-]?[0-9]+)
real	{dreal}|{ereal}

%%
\n			{ w.count = 0; return '\n'; }
[ \t]+			{/*do nothing*/}
^\$			{ return (LABEL_OPEN); }
^\$End			{ return (LABEL_CLOSE); }
MeshFormat		{ return (MESH_FORMAT) ; }
Nodes			{ return (NODES); }
PhysicalNames		{ return (PHYSICAL_NAMES); }
ParametricNodes		{ return (PARAMETRIC_NODES); }
-?[0-9]+			{ DO_IT; sscanf(yytext,"%d",&msh_yylval.integer); return INTEGER; }
{real}			{ sscanf(yytext,"%lf",&msh_yylval.real); return FLOAT; }
\".*\"			{ /*TODO copy string*/ return (TEXT); }
^\$Elements		{ w.in = 1; w.on = 0; return (LABEL_OPEN_ELEMENTS); }
^\$EndElements		{ w.in = 0; return (LABEL_CLOSE_ELEMENTS); }
<s_element>"1 "		{ POST_ELEMENT; return (EL_LINE2); }
<s_element>"2 "		{ POST_ELEMENT; return (EL_TRIANGLE3); }
<s_element>"3 "		{ POST_ELEMENT; return (EL_QUADRANGLE4); }
<s_element>"4 "		{ POST_ELEMENT; return (EL_TETRAHEDRON4); }
<s_element>"5 "		{ POST_ELEMENT; return (EL_HEXAHEDRON8); }
<s_element>"6 "		{ POST_ELEMENT; return (EL_PRISM6); }
<s_element>"7 "		{ POST_ELEMENT; return (EL_PYRAMID5); }
<s_element>"8 "		{ POST_ELEMENT; return (EL_LINE3); }
<s_element>"9 "		{ POST_ELEMENT; return (EL_TRIANGLE6); }
<s_element>"10 "	{ POST_ELEMENT; return (EL_QUADRANGLE9); }
<s_element>"11 "	{ POST_ELEMENT; return (EL_TETRAHEDRON10); }
<s_element>"12 "	{ POST_ELEMENT; return (EL_HEXAHEDRON27); }
<s_element>"13 "	{ POST_ELEMENT; return (EL_PRISM18); }
<s_element>"14 "	{ POST_ELEMENT; return (EL_PYRAMID14); }
<s_element>"15 "	{ POST_ELEMENT; return (EL_POINT); }
<s_element>"16 "	{ POST_ELEMENT; return (EL_QUADRANGLE8); }
<s_element>"17 "	{ POST_ELEMENT; return (EL_HEXAHEDRON20); }
<s_element>"18 "	{ POST_ELEMENT; return (EL_PRISM15); }
<s_element>"19 "	{ POST_ELEMENT; return (EL_PYRAMID13); }
<s_element>"20 "	{ POST_ELEMENT; return (EL_ITRIANGLE9); }
<s_element>"21 "	{ POST_ELEMENT; return (EL_TRIANGLE10); }
<s_element>"22 "	{ POST_ELEMENT; return (EL_ITRIANGLE12); }
<s_element>"23 "	{ POST_ELEMENT; return (EL_TRIANGLE15); }
<s_element>"24 "	{ POST_ELEMENT; return (EL_ITRIANGLE15); }
<s_element>"25 "	{ POST_ELEMENT; return (EL_TRIANGLE21); }
<s_element>"26 "	{ POST_ELEMENT; return (EL_EDGE4); }
<s_element>"27 "	{ POST_ELEMENT; return (EL_EDGE5); }
<s_element>"28 "	{ POST_ELEMENT; return (EL_EDGE6); }
<s_element>"29 "	{ POST_ELEMENT; return (EL_TETRAHEDRON20); }
<s_element>"30 "	{ POST_ELEMENT; return (EL_TETRAHEDRON35); }
<s_element>"31 "	{ POST_ELEMENT; return (EL_TETRAHEDRON56); }

<s_tag>"0 "		{ POST_TAG; return (TAG0); }
<s_tag>"1 "		{ POST_TAG; return (TAG1); }
<s_tag>"2 "		{ POST_TAG; return (TAG2); }
<s_tag>"3 "		{ POST_TAG; return (TAG3); }

.	{ return (OTHER); }

%%


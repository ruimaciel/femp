#ifndef MSH_HPP
#define MSH_HPP

#include "parser.h++"

#include <libfemp/Element.h++>
#include <libfemp/SurfaceLoad.h++>
#include <libfemp/SurfaceLoadOperators/SurfaceLoadOperator.h++>

class MshParser
	: public Parser
{
protected:
	fem::SurfaceLoadOperator *surface_load_operator;

protected:
	enum TerminalToken 
	{
		TT_ERROR,
		TT_OPEN_MESH_FORMAT,
		TT_CLOSE_MESH_FORMAT,
		TT_OPEN_NODES,
		TT_CLOSE_NODES,
		TT_OPEN_ELEMENTS,
		TT_CLOSE_ELEMENTS,
		TT_OPEN_PHYSICAL_NAMES,
		TT_CLOSE_PHYSICAL_NAMES,
		TT_OPEN_NODE_DATA,
		TT_CLOSE_NODE_DATA,
		TT_OPEN_ELEMENT_DATA,
		TT_CLOSE_ELEMENT_DATA,
		TT_OPEN_ELEMENT_NODE_DATA,
		TT_CLOSE_ELEMENT_NODE_DATA,
		TT_INDEX,
		TT_NUMBER,

		// the element types
		TT_ELEMENT_LINE2,
		TT_ELEMENT_TRIANGLE3,
		TT_ELEMENT_QUADRANGLE4,
		TT_ELEMENT_TETRAHEDRON4,
		TT_ELEMENT_HEXAHEDRON8,
		TT_ELEMENT_PRISM6,
		TT_ELEMENT_PYRAMID5,
		TT_ELEMENT_LINE3,
		TT_ELEMENT_TRIANGLE6,
		TT_ELEMENT_QUADRANGLE9,
		TT_ELEMENT_TETRAHEDRON10,
		TT_ELEMENT_HEXAHEDRON27,
		TT_ELEMENT_PRISM18,
		TT_ELEMENT_PYRAMID14,
		TT_ELEMENT_POINT,
		TT_ELEMENT_QUADRANGLE8,
		TT_ELEMENT_HEXAHEDRON20,
		TT_ELEMENT_PRISM15,
		TT_ELEMENT_PYRAMID13,
		TT_ELEMENT_ITRIANGLE9,
		TT_ELEMENT_TRIANGLE10,
		TT_ELEMENT_ITRIANGLE12,
		TT_ELEMENT_TRIANGLE15,
		TT_ELEMENT_ITRIANGLE15,
		TT_ELEMENT_TRIANGLE21,
		TT_ELEMENT_EDGE4,
		TT_ELEMENT_EDGE5,
		TT_ELEMENT_EDGE6,
		TT_ELEMENT_TETRAHEDRON20,
		TT_ELEMENT_TETRAHEDRON35,
		TT_ELEMENT_TETRAHEDRON56,

		TT_0_TAGS,
		TT_1_TAGS,
		TT_2_TAGS,
		TT_3_TAGS,

		TT_EOL,
		TT_EOF,

		TT_VERSION_2_1,
		TT_VERSION_2_2,
		TT_MF_FILE_TYPE_ASCII,
		TT_MF_DATA_SIZE,
		TT_UNKNOWN_TOKEN,
		TT_LAST
	};

	enum NonTerminalToken 
	{
		NT_FIRST = TT_LAST,	// to avoid overlapping enum definitions
		NT_START,		// start symbol
		NT_DOCUMENT,

		NT_HEADER,
		NT_MF_VERSION_NUMBER,
		NT_MF_FILE_TYPE,
		NT_MF_DATA_SIZE,

		NT_NODES,	// node definition section
		NT_N_NUMBER_OF_NODES,
		NT_N_NUMBER_OF_NODES_SET,
		NT_N_NODE_DEFINITION,
		NT_N_NODE_DEFINITION_SET,
		NT_N_NODE_DEFINITION_FOLLOW,

		NT_ELEMENTS,
		NT_E_NUMBER_OF_ELEMENTS,
		NT_E_NUMBER_OF_ELEMENTS_SET,
		NT_E_ELEMENT_DEFINITION,
		NT_E_ELEMENT_DEFINITION_FOLLOW,
		NT_E_ELEMENT_TYPE,
		NT_E_ELEMENT_TYPE_SET_ELEMENT,
		NT_E_ELEMENT_TYPE_SET_FORCE,
		NT_E_TAGS,

		NT_E_TAGS_1_SET, 
		NT_E_TAGS_2_SET,
		NT_E_TAGS_3_SET,

		NT_ELEMENTS_SET,
		NT_ELEMENTS_FOLLOW,

		NT_NODE_DATA,
		NT_ELEMENT_DATA,
		NT_ELEMENT_NODE_DATA,

		// generic helper non-terminal states
		NT_COORDINATE,	// requires 3 floats, sets a Point with them
	};

	/** 
	enum that provides a descriptive label to every parser rule
	**/
	enum ParserRule 
	{
		PR_INVALID = 0,		// default value for the map, which means that this is an error
		PR_START,
		PR_DOCUMENT,
		PR_HEADER,
		PR_MF_VERSION_NUMBER_2_1,	
		PR_MF_VERSION_NUMBER_2_2,
		PR_MF_VERSION_NUMBER_ERROR,
		PR_MF_FILE_TYPE_ASCII,
		PR_MF_DATA_SIZE,

		PR_NODES,
		PR_N_NUMBER_OF_NODES,
		PR_N_NUMBER_OF_NODES_SET,	// set state
		PR_N_NODE_DEFINITION,
		PR_N_NODE_DEFINITION_SET,	// set state
		PR_N_NODE_DEFINITION_FOLLOW_1,
		PR_N_NODE_DEFINITION_FOLLOW_2,

		PR_ELEMENTS,
		PR_E_NUMBER_OF_ELEMENTS,
		PR_E_NUMBER_OF_ELEMENTS_SET,
		PR_E_ELEMENT_DEFINITION,
		PR_E_ELEMENT_DEFINITION_FOLLOW_1,
		PR_E_ELEMENT_DEFINITION_FOLLOW_2,

		// set surface loads
		PR_E_ELEMENT_TRIANGLE3,
		PR_E_ELEMENT_TRIANGLE6,
		PR_E_ELEMENT_QUADRANGLE4,
		PR_E_ELEMENT_QUADRANGLE8,
		PR_E_ELEMENT_QUADRANGLE9,

		PR_E_ELEMENT_HEXAHEDRON8,
		PR_E_ELEMENT_HEXAHEDRON20,
		PR_E_ELEMENT_HEXAHEDRON27,
		PR_E_ELEMENT_TETRAHEDRON4,
		PR_E_ELEMENT_TETRAHEDRON10,
		PR_E_ELEMENT_PRISM6,
		PR_E_ELEMENT_PRISM15,
		PR_E_ELEMENT_PRISM18,

		PR_E_ELEMENT_TYPE_SET_ELEMENT,	// set state
		PR_E_ELEMENT_TYPE_SET_FORCE,		// set state

		PR_ELEMENTS_SET,

		PR_ELEMENT_FOLLOW_1,
		PR_ELEMENT_FOLLOW_2,
		PR_ELEMENT_FOLLOW_3,
		PR_ELEMENT_FOLLOW_4,

		PR_E_TAGS_0, 
		PR_E_TAGS_1, 
		PR_E_TAGS_2,
		PR_E_TAGS_3,

		PR_E_TAGS_1_SET, 
		PR_E_TAGS_2_SET,
		PR_E_TAGS_3_SET,

		// primitive states
		PR_COORDINATE	// requires 3 floats, sets a Point with them
	};

	std::map< enum NonTerminalToken, std::map<enum TerminalToken, enum ParserRule> > table;
	std::stack<int>	ss;	// the LL parser symbol stack

	std::list<long>		index_list;	// used to store parsed indexes
	std::list<float>	float_list;	// used to store parsed indexes

	fem::Node		node;
	fem::Element		element;
	fem::SurfaceLoad	surface_load;
	fem::LoadPattern	load_pattern;

public:
	MshParser();

	enum Error::Type  parse(std::istream &file, fem::Model &model);

	enum Error::Type operator() (std::istream &file, fem::Model &model);

	/**
	sets the constant load operator, to state how to define the surface loads
	**/
	void setSurfaceLoadOperator(fem::SurfaceLoadOperator &surface_load_operator);

protected:
	enum TerminalToken lexer(std::istream &file);
	void setIndex();
	void setNumber();
	void setParserTable();
};


#endif

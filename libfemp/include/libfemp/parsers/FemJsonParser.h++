#ifndef FEM_JSON_PARSER_HPP
#define FEM_JSON_PARSER_HPP

#include <fstream>
#include <map>
#include <stack>
#include <string>
#include <vector>

#include <libfemp/Model.h++>

/**
Class developed to parse the fem.json file format
**/
class FemJsonParser {
public:
    FemJsonParser();

    void operator()(std::istream& file, fem::Model& model);

    /**
	class intended to provide the error message
	**/
    struct Error {
        enum Type {
            ERR_OK,
            ERR_INVALID_ELEMENT_REFERENCE,
            ERR_UNKNOWN
        } code;
        std::string message;
    } error;

    enum Error::Type parse(std::istream& file, fem::Model& model);

protected:
    // temp variables
    std::vector<double> temp_float;
    std::vector<unsigned long int> temp_natural;
    std::vector<size_t> reference;
    std::vector<fem::Point3D> temp_point;
    bool temp_bool;
    std::string temp_token;

    fem::Material temp_material;
    fem::Node temp_node;
    fem::Element temp_element;
    fem::NodeRestrictions temp_node_restrictions;
    fem::LoadPattern temp_load_pattern;

    std::string label;

protected:
    enum TerminalTokens {
        TT_UNKNOWN, // irrecognizable token

        TT_TEXT_STRING,
        TT_NATURAL_NUMBER,
        TT_FLOAT_NUMBER,
        TT_OBJECT_OPEN,
        TT_OBJECT_CLOSE,
        TT_ARRAY_OPEN,
        TT_ARRAY_CLOSE,
        TT_NAME_SEPARATOR, // :
        TT_VALUE_SEPARATOR, // ,
        TT_TRUE,
        TT_FALSE,
        TT_NULL,

        TT_LABEL_LABEL,
        TT_LABEL_FEM,
        TT_LABEL_VERSION,
        TT_LABEL_V1_0,
        TT_LABEL_TYPE,
        TT_LABEL_3D_SOLID,
        TT_LABEL_MATERIALS,
        TT_LABEL_E,
        TT_LABEL_NU,
        TT_LABEL_FY,
        TT_LABEL_LINEAR_ELASTIC,
        TT_LABEL_NODES,
        TT_LABEL_ELEMENTS,
        TT_LABEL_TETRAHEDRON4,
        TT_LABEL_TETRAHEDRON10,
        TT_LABEL_HEXAHEDRON8,
        TT_LABEL_HEXAHEDRON20,
        TT_LABEL_HEXAHEDRON27,
        TT_LABEL_PRISM6,
        TT_LABEL_PRISM15,
        TT_LABEL_PRISM18,
        TT_LABEL_MATERIAL,
        TT_LABEL_GROUPS,
        TT_LABEL_NODE_RESTRICTIONS,
        TT_LABEL_LOAD_PATTERNS,
        TT_LABEL_NODE,
        TT_LABEL_DX,
        TT_LABEL_DY,
        TT_LABEL_DZ,
        TT_LABEL_NODAL_LOADS,
        TT_LABEL_SURFACE_LOADS,
        TT_LABEL_DOMAIN_LOADS,
        TT_LABEL_TRIANGLE3,
        TT_LABEL_TRIANGLE6,
        TT_LABEL_QUADRANGLE4,
        TT_LABEL_QUADRANGLE8,
        TT_LABEL_QUADRANGLE9,
        TT_LABEL_ELEMENT,
        TT_LABEL_FORCE,

        TT_EOF, // marks the end of file

        TT_LAST // false token to be used in the definition of the non-terminal tokens
        // the artificial terminal tokens

    };

    enum NonTerminalTokens {
        NT_FIRST = TT_LAST, // to avoid overlapping enum definitions
        NT_LABEL,
        NT_LABEL_SET, // ghost state to set the label
        NT_VECTOR3D,
        NT_VECTOR3D_SET,
        NT_REFERENCE,
        NT_REFERENCE_SET,
        NT_MULTI_REFERENCE, // can be either a single reference(i.e., "node" : 1) or a sequential range (i.e., "node" : [1, 5])
        NT_MULTI_REFERENCE_SET,
        NT_REFERENCE_LIST,
        NT_REFERENCE_FOLLOW,
        NT_BOOLEAN,
        NT_NUMBER,
        NT_FLOAT_SET,
        NT_INT_TO_FLOAT_SET,

        NT_START,
        NT_DOCUMENT,
        NT_HEADER,
        NT_FORMAT_VERSION,
        NT_MODEL_TYPE,
        NT_MODEL_TYPE_SET,
        NT_MATERIAL_LIST,
        NT_MATERIAL,
        NT_MATERIAL_SET, // ghost state to set the material
        NT_MATERIAL_TYPE,
        NT_YOUNG_MODULUS,
        NT_YOUNG_MODULUS_SET,
        NT_POISSON_COEFFICIENT,
        NT_POISSON_COEFFICIENT_SET,
        NT_ELASTIC_LIMIT,
        NT_ELASTIC_LIMIT_SET,
        NT_MATERIAL_FOLLOW,
        NT_NODE_LIST,
        NT_NODE,
        NT_NODE_SET,
        NT_NODE_FOLLOW,
        NT_ELEMENT_LIST,
        NT_ELEMENT,
        NT_ELEMENT_SET,
        NT_ELEMENT_TYPE,
        NT_ELEMENT_HEXAHEDRON8,
        NT_ELEMENT_HEXAHEDRON20,
        NT_ELEMENT_HEXAHEDRON27,
        NT_ELEMENT_TETRAHEDRON4,
        NT_ELEMENT_TETRAHEDRON10,
        NT_ELEMENT_PRISM6,
        NT_ELEMENT_PRISM15,
        NT_ELEMENT_PRISM18,

        NT_ELEMENT_HEXAHEDRON8_SET,
        NT_ELEMENT_HEXAHEDRON20_SET,
        NT_ELEMENT_HEXAHEDRON27_SET,
        NT_ELEMENT_TETRAHEDRON4_SET,
        NT_ELEMENT_TETRAHEDRON10_SET,
        NT_ELEMENT_PRISM6_SET,
        NT_ELEMENT_PRISM15_SET,
        NT_ELEMENT_PRISM18_SET,

        NT_ELEMENT_TYPE_FOLLOW,
        NT_ELEMENT_MATERIAL,
        NT_ELEMENT_MATERIAL_SET,
        NT_ELEMENT_FOLLOW,
        NT_ELEMENT_LIST_FOLLOW,
        NT_EXTRA_DEFINITIONS,
        NT_GROUPS_LIST,
        NT_GROUPS_LIST_FOLLOW,
        NT_GROUPS_LIST_FOLLOW_FOLLOW,
        NT_GROUP_TYPE,
        NT_NODE_GROUP_LIST,
        NT_NODE_GROUP_LIST_FOLLOW,
        NT_NODE_GROUP,
        NT_NODE_GROUP_SET,
        NT_NODE_GROUP_FOLLOW,
        NT_NODE_GROUP_FOLLOW_FOLLOW,
        NT_NODE_GROUP_LIST_FOLLOW_FOLLOW,
        NT_ELEMENT_GROUP_LIST,
        NT_ELEMENT_GROUP_LIST_FOLLOW,
        NT_ELEMENT_GROUP,
        NT_ELEMENT_GROUP_SET,
        NT_ELEMENT_GROUP_FOLLOW,
        NT_ELEMENT_GROUP_FOLLOW_FOLLOW,
        NT_NODE_RESTRICTIONS_LIST,
        NT_NODE_RESTRICTIONS_LIST_FOLLOW,
        NT_NODE_RESTRICTIONS_LIST_FOLLOW_FOLLOW,
        NT_NODE_RESTRICTION,
        NT_NODE_REFERENCE,
        NT_NODE_REFERENCE_SET,
        NT_NODE_DOF,
        NT_NODE_DOF_DX,
        NT_NODE_DOF_DX_SET,
        NT_NODE_DOF_DX_FOLLOW,
        NT_NODE_DOF_DX_FOLLOW_FOLLOW,
        NT_NODE_DOF_DY,
        NT_NODE_DOF_DY_SET,
        NT_NODE_DOF_DY_FOLLOW,
        NT_NODE_DOF_DY_FOLLOW_FOLLOW,
        NT_NODE_DOF_DZ,
        NT_NODE_DOF_DZ_SET,
        NT_NODE_DOF_DZ_FOLLOW,
        NT_NODE_DOF_DZ_FOLLOW_FOLLOW,
        NT_NODE_RESTRICTION_SET,
        NT_NODE_RESTRICTION_FOLLOW,
        NT_LOAD_PATTERNS_LIST,
        NT_LOAD_PATTERNS_LIST_FOLLOW,
        NT_LOAD_PATTERN,
        NT_LOAD_PATTERN_SET,
        NT_LOAD_PATTERN_LABEL_FOLLOW,
        NT_NODAL_LOADS_LIST,
        NT_NODAL_LOAD,
        NT_NODAL_LOAD_SET,
        NT_NODAL_LOAD_FOLLOW,
        NT_NODAL_LOAD_FORCE,
        NT_NODAL_LOADS_LIST_FOLLOW,
        NT_SURFACE_LOADS_LIST,
        NT_SURFACE_LOAD,
        NT_SURFACE_LOAD_SET,
        NT_SURFACE_LOAD_TYPE,

        NT_SURFACE_TRIANGLE3_NODES,
        NT_SURFACE_TRIANGLE6_NODES,
        NT_SURFACE_QUADRANGLE4_NODES,
        NT_SURFACE_QUADRANGLE8_NODES,
        NT_SURFACE_QUADRANGLE9_NODES,

        NT_SURFACE_TRIANGLE3_FORCES,
        NT_SURFACE_TRIANGLE6_FORCES,
        NT_SURFACE_QUADRANGLE4_FORCES,
        NT_SURFACE_QUADRANGLE8_FORCES,
        NT_SURFACE_QUADRANGLE9_FORCES,

        NT_SURFACE_LOADS_LIST_FOLLOW,
        NT_SURFACE_LOADS_LIST_FOLLOW_FOLLOW,

        NT_SURFACE_LOAD_FOLLOW,
        NT_DOMAIN_LOADS_LIST,
        NT_DOMAIN_LOADS_LIST_FOLLOW,
        NT_DOMAIN_LOAD,
        NT_DOMAIN_LOAD_SET,
        NT_ELEMENT_REFERENCE,
        NT_DOMAIN_FORCE,
        NT_DOMAIN_LOAD_FOLLOW,
        NT_NODAL_LOADS_LIST_FOLLOW_FOLLOW,
        NT_LOAD_PATTERN_FOLLOW,
    };

    enum ParserRule {
        PR_INVALID = 0, // default value for the map, which means that this is an error

        PR_LABEL,
        PR_LABEL_SET, // ghost label
        PR_VECTOR3D,
        PR_VECTOR3D_SET,
        PR_REFERENCE_1,
        PR_REFERENCE_SET,
        PR_REFERENCE_ERROR,
        PR_MULTI_REFERENCE_1,
        PR_MULTI_REFERENCE_2,
        PR_MULTI_REFERENCE_SET,
        PR_REFERENCE_LIST_1,
        PR_REFERENCE_FOLLOW_1,
        PR_REFERENCE_FOLLOW_2,

        PR_BOOLEAN_TRUE,
        PR_BOOLEAN_FALSE,

        PR_NUMBER_1,
        PR_NUMBER_2,
        PR_FLOAT_SET, // ghost state, pushes the value of a previous float to a number
        PR_INT_TO_FLOAT_SET, // ghost state, pushes the value of an int to a temp float

        PR_START_1,
        PR_START_2,
        PR_DOCUMENT_1,
        PR_HEADER_1,
        PR_FORMAT_VERSION_1,
        PR_MODEL_TYPE_1,
        PR_MODEL_TYPE_SET, // ghost state, set the model type
        PR_MATERIAL_LIST_1,
        PR_MATERIAL_1,
        PR_MATERIAL_TYPE_1,
        PR_YOUNG_MODULUS_1,
        PR_YOUNG_MODULUS_SET, // ghost state, pushes te young modulus value to the temp material
        PR_POISSON_COEFFICIENT_1,
        PR_POISSON_COEFFICIENT_SET,
        PR_ELASTIC_LIMIT_1,
        PR_ELASTIC_LIMIT_SET,
        PR_MATERIAL_SET,
        PR_MATERIAL_FOLLOW_1,
        PR_MATERIAL_FOLLOW_2,
        PR_NODE_LIST_1,
        PR_NODE_1,
        PR_NODE_SET,
        PR_NODE_FOLLOW_1,
        PR_NODE_FOLLOW_2,
        PR_ELEMENT_LIST_1,
        PR_ELEMENT_1,
        PR_ELEMENT_SET_1,
        PR_ELEMENT_TYPE_1,
        PR_ELEMENT_TYPE_2,
        PR_ELEMENT_TYPE_3,
        PR_ELEMENT_TYPE_4,
        PR_ELEMENT_TYPE_5,
        PR_ELEMENT_TYPE_6,
        PR_ELEMENT_TYPE_7,
        PR_ELEMENT_TYPE_8,
        PR_ELEMENT_HEXAHEDRON8_1,
        PR_ELEMENT_HEXAHEDRON20_1,
        PR_ELEMENT_HEXAHEDRON27_1,
        PR_ELEMENT_TETRAHEDRON4_1,
        PR_ELEMENT_TETRAHEDRON10_1,
        PR_ELEMENT_PRISM6_1,
        PR_ELEMENT_PRISM15_1,
        PR_ELEMENT_PRISM18_1,
        PR_ELEMENT_HEXAHEDRON8_SET, // ghost state
        PR_ELEMENT_HEXAHEDRON20_SET, // ghost state
        PR_ELEMENT_HEXAHEDRON27_SET, // ghost state
        PR_ELEMENT_TETRAHEDRON4_SET, // ghost state
        PR_ELEMENT_TETRAHEDRON10_SET, // ghost state
        PR_ELEMENT_PRISM6_SET, // ghost state
        PR_ELEMENT_PRISM15_SET, // ghost state
        PR_ELEMENT_PRISM18_SET, // ghost state
        PR_ELEMENT_TYPE_FOLLOW_1,
        PR_ELEMENT_TYPE_FOLLOW_2,
        PR_ELEMENT_MATERIAL_1,
        PR_ELEMENT_MATERIAL_SET_1,
        PR_ELEMENT_FOLLOW_1,
        PR_ELEMENT_FOLLOW_2,
        PR_ELEMENT_LIST_FOLLOW_1,
        PR_ELEMENT_LIST_FOLLOW_2,
        PR_EXTRA_DEFINITIONS_1,
        PR_EXTRA_DEFINITIONS_2,
        PR_EXTRA_DEFINITIONS_3,
        PR_GROUPS_LIST_1,
        PR_GROUP_TYPE_1,
        PR_GROUP_TYPE_2,
        PR_GROUPS_LIST_FOLLOW_1,
        PR_GROUPS_LIST_FOLLOW_2,
        PR_GROUPS_LIST_FOLLOW_FOLLOW_1,
        PR_GROUPS_LIST_FOLLOW_FOLLOW_2,
        PR_NODE_GROUP_LIST_1,
        PR_NODE_GROUP_LIST_FOLLOW_1,
        PR_NODE_GROUP_LIST_FOLLOW_2,
        PR_NODE_GROUP_1,
        PR_NODE_GROUP_SET,
        PR_NODE_GROUP_FOLLOW_1,
        PR_NODE_GROUP_FOLLOW_2,
        PR_NODE_GROUP_FOLLOW_FOLLOW_1,
        PR_ELEMENT_GROUP_LIST_1,
        PR_ELEMENT_GROUP_LIST_FOLLOW_1,
        PR_ELEMENT_GROUP_1,
        PR_ELEMENT_GROUP_SET,
        PR_ELEMENT_GROUP_FOLLOW_1,
        PR_ELEMENT_GROUP_FOLLOW_2,
        PR_ELEMENT_GROUP_FOLLOW_FOLLOW_1,
        PR_NODE_RESTRICTIONS_LIST_1,
        PR_NODE_RESTRICTIONS_LIST_FOLLOW_1,
        PR_NODE_RESTRICTIONS_LIST_FOLLOW_2,
        PR_NODE_RESTRICTIONS_LIST_FOLLOW_FOLLOW_1,
        PR_NODE_RESTRICTION_1,
        PR_NODE_REFERENCE_1,
        PR_NODE_REFERENCE_SET,
        PR_NODE_DOF_1,
        PR_NODE_DOF_2,
        PR_NODE_DOF_3,
        PR_NODE_DOF_DX_1,
        PR_NODE_DOF_DX_SET,
        PR_NODE_DOF_DX_FOLLOW_1,
        PR_NODE_DOF_DX_FOLLOW_2,
        PR_NODE_DOF_DX_FOLLOW_3,
        PR_NODE_DOF_DX_FOLLOW_FOLLOW_1,
        PR_NODE_DOF_DX_FOLLOW_FOLLOW_2,
        PR_NODE_DOF_DX_FOLLOW_FOLLOW_3,
        PR_NODE_DOF_DY_1,
        PR_NODE_DOF_DY_SET,
        PR_NODE_DOF_DY_FOLLOW_1,
        PR_NODE_DOF_DY_FOLLOW_2,
        PR_NODE_DOF_DY_FOLLOW_FOLLOW_1,
        PR_NODE_DOF_DY_FOLLOW_FOLLOW_2,
        PR_NODE_DOF_DZ_1,
        PR_NODE_DOF_DZ_SET,
        PR_NODE_DOF_DZ_FOLLOW_1,
        PR_NODE_DOF_DZ_FOLLOW_FOLLOW_1,
        PR_NODE_RESTRICTION_SET,
        PR_NODE_RESTRICTION_FOLLOW_1,
        PR_NODE_RESTRICTION_FOLLOW_2,
        PR_LOAD_PATTERNS_LIST_1,
        PR_LOAD_PATTERNS_LIST_FOLLOW_1,
        PR_LOAD_PATTERN_1,
        PR_LOAD_PATTERN_SET,
        PR_LOAD_PATTERN_LABEL_FOLLOW_1,
        PR_LOAD_PATTERN_LABEL_FOLLOW_2,
        PR_LOAD_PATTERN_LABEL_FOLLOW_3,
        PR_NODAL_LOADS_LIST_1,
        PR_NODAL_LOAD_1,
        PR_NODAL_LOAD_SET,
        PR_NODAL_LOAD_FOLLOW_1,
        PR_NODAL_LOAD_FOLLOW_2,
        PR_NODAL_LOAD_FORCE_1,
        PR_NODAL_LOADS_LIST_FOLLOW_1,
        PR_NODAL_LOADS_LIST_FOLLOW_2,
        PR_SURFACE_LOADS_LIST_1,
        PR_SURFACE_LOAD_1,
        PR_SURFACE_LOAD_TYPE_1,
        PR_SURFACE_LOAD_TYPE_2,
        PR_SURFACE_LOAD_TYPE_3,
        PR_SURFACE_LOAD_TYPE_4,
        PR_SURFACE_LOAD_TYPE_5,

        PR_SURFACE_TRIANGLE3_NODES_1,
        PR_SURFACE_TRIANGLE6_NODES_1,
        PR_SURFACE_QUADRANGLE4_NODES_1,
        PR_SURFACE_QUADRANGLE8_NODES_1,
        PR_SURFACE_QUADRANGLE9_NODES_1,

        PR_SURFACE_TRIANGLE3_FORCES_1,
        PR_SURFACE_TRIANGLE6_FORCES_1,
        PR_SURFACE_QUADRANGLE4_FORCES_1,
        PR_SURFACE_QUADRANGLE8_FORCES_1,
        PR_SURFACE_QUADRANGLE9_FORCES_1,

        PR_SURFACE_LOADS_LIST_FOLLOW_1,
        PR_SURFACE_LOADS_LIST_FOLLOW_2,

        PR_SURFACE_LOADS_LIST_FOLLOW_FOLLOW_1,

        PR_SURFACE_LOAD_SET,
        PR_SURFACE_LOAD_FOLLOW_1,
        PR_SURFACE_LOAD_FOLLOW_2,
        PR_DOMAIN_LOADS_LIST_1,
        PR_DOMAIN_LOADS_LIST_FOLLOW_1,
        PR_DOMAIN_LOAD_1,
        PR_DOMAIN_LOAD_SET,
        PR_ELEMENT_REFERENCE_1,
        PR_DOMAIN_FORCE_1,
        PR_DOMAIN_LOAD_FOLLOW_1,
        PR_DOMAIN_LOAD_FOLLOW_2,
        PR_NODAL_LOADS_LIST_FOLLOW_FOLLOW_1,
        PR_NODAL_LOADS_LIST_FOLLOW_FOLLOW_2,
        PR_LOAD_PATTERN_FOLLOW_1,
        PR_LOAD_PATTERN_FOLLOW_2
    };

    std::map<enum NonTerminalTokens, std::map<enum TerminalTokens, enum ParserRule>> table;
    std::stack<int> ss; // the LL parser symbol stack

protected:
    /**
	 * Returns a terminal token by parsing the input stream
	@param file	opened text stream
	**/
    enum TerminalTokens lexer(std::istream& file);

    void setParserTable();

    /**
	Routine intended to make the re2c code more easily readable by putting the return procedures here
	**/
    TerminalTokens lexerReturnProcedures(TerminalTokens tt);

protected:
    char buffer[1024];

    // helper variables that are used by the lexer
    char* tok; // marks the start of the current token
    char* pos; // marks the current position
    char* marker;
    char* limit; // marks the string limit
    size_t line_number;

    /** 
	routine called by the lexer to fill the buffer by reading from the file
	**/
    void fill(std::istream& file);

    // temporary list for the passed strings
    std::stack<std::string> text_string_list;
    std::string current_section;
};

#endif

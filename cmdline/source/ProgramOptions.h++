#ifndef PROGRAM_OPTIONS_HPP
#define PROGRAM_OPTIONS_HPP

#include <string>
#include <map>

#include "fem/Analysis.h++"
#include "fem/Element.h++"


struct ProgramOptions
{
	// program options
	std::string input_file;	// the name of a file that will be read to input a model
	int digits10;	// default precision
	enum OPT_SOLVER { 
		OPT_S_CHOLESKY, // Cholesky solver
		OPT_S_CG, 	// conjugate gradient solver
		OPT_S_GAUSS	// gauss elimination solver
		} solver;
	bool output_fem;	// outputs the FEM equation along with the displacements

	std::map<enum fem::Element::Type, int> degree;	// stiffness matrix integration point degree for a particular element
	std::map<enum fem::Element::Type, int> ddegree;	// domain load integration point degree for a particular element


	// other info
	enum Option { 
		OPT_PARSER_ERROR,	// I screwed up with the parser
		OPT_ARGUMENTS_ERROR,	// the user screwed up the args
		OPT_HELP,
		OPT_VERSION,
		OPT_RUN
	};

	public:
	ProgramOptions();
	~ProgramOptions();


	enum Option setCommandLineOptions(int argc, char **argv, fem::Analysis &analysis);

	private:
		int integer;	// used to return an int
		fem::Element::Type element_type;	// used for generic elements

		// vars used by the lexer and parser
		char *p;	// lexer cursor
		char *token;	// marks the start of the current token
		char *q;	// YYMARKER
		int argn;	// current argument, must be less than argc

		enum Symbol {
			// the terminals
			S_HELP,
			S_VERSION,
			S_IPS,	// integration points command
			S_IPS_STIFFNESS,	// integration points for stiffness
			S_IPS_DOMAIN,	// integration points for domain
			S_OUTPUT_FEM_EQUATION,	// output FEM equation along with displacements
			S_SOLVER,		// specify what equation solver to use

			S_FE_ELEMENT,	// generic element

			S_FE_LINE2,
			S_FE_TRIANGLE3,
			S_FE_QUADRANGLE4,
			S_FE_TETRAHEDRON4,
			S_FE_HEXAHEDRON8,
			S_FE_PRISM6,
			S_FE_PYRAMID5,
			S_FE_LINE3,
			S_FE_TRIANGLE6,
			S_FE_QUADRANGLE9,
			S_FE_TETRAHEDRON10,
			S_FE_HEXAHEDRON27,
			S_FE_PRISM18,
			S_FE_PYRAMID14,
			S_FE_QUADRANGLE8,
			S_FE_HEXAHEDRON20,
			S_FE_PRISM15,
			S_FE_PYRAMID13,
			S_FE_ITRIANGLE9,
			S_FE_TRIANGLE10,
			S_FE_ITRIANGLE12,
			S_FE_TRIANGLE15,
			S_FE_ITRIANGLE15,
			S_FE_TRIANGLE21,
			S_FE_EDGE4,
			S_FE_EDGE5,
			S_FE_EDGE6,
			S_FE_TETRAHEDRON20,
			S_FE_TETRAHEDRON35,
			S_FE_TETRAHEDRON56,

			S_INTEGER,	// an integer

			S_SUBARG_SEPARATOR,	// character separating subarguments
			S_EOA,	// end of argument
			S_EOL,	// end of the command line

			// the non-terminals
			SN_START,	// the start non-terminal symbol
			SN_SET_OPTION,		// <set option>
			SN_SET_OPTION_FOLLOW,	// <set option follow>
			SN_SET_IPS, 		// <set IPs>
			SN_SET_IPS_FOLLOW, 	// <set IPs follow>
			SN_IPS_FIRST_ASSIGN, 	// <IPs first assignment>
			SN_IPS_FOLLOW_S_ASSIGN,		// <IPs follow stiffness assignment>
			SN_IPS_FOLLOW2_S_ASSIGN,	// <IPs follow2 stiffness assignment>
			SN_IPS_FOLLOW_D_ASSIGN,		// <IPs follow domain assignment>
			SN_IPS_FOLLOW2_D_ASSIGN,	// <IPs follow2 domain assignment>
			SN_SET_SOLVER_FOLLOW,		// <set solver follow>

			S_CHOLESKY, S_CG, S_GAUSS,	// the different linear system of equations solvers

			SN_END_FIELD,	// <end field>
			SN_EOS,	// <EO?>

			// The ghost symbols
			SG_IPS_STIFFNESS_ASSIGN, 	// <G IPs stiffness assign>
			SG_IPS_DOMAIN_ASSIGN, 	// <G IPs domain assign>
			SG_OUTPUT_EQUATION_ASSIGN,	// <G output equation assign>

			SG_SET_CHOLESKY, SG_SET_CG, SG_SET_GAUSS,	// set the different linear system of equations solvers

			S_UNKNOWN	// to sign off an error
		} symbol;

		void init_lexer_vars(char **argv);
	 	enum Symbol lexer(int argc, char **argv, int state = 0);
};

#endif

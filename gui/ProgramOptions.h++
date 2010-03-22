#ifndef OPTIONS_HPP
#define OPTIONS_HPP

/* this component aims to follow the Filesystem Hierarchy Standard */

/*
Each option has 4 levels
	1) default: the option's value wasn't explicitly set anywhere so the built-in, default value as assumed
	2) system: the option was set according to the options set from config files present in the /etc/femp directory
	3) local: from config files available at ~/.femp/ or to be saved in those config files
	4) options tweaked by the user in the current session that won't be saved
*/

#include <map>
#include <string>
#include <vector>
#include <iostream>	// for ostream


class ProgramOptions;

class Option
{
	public:
		enum Level {OPT_DEFAULT = 0, OPT_SYSTEM, OPT_LOCAL, OPT_TEMPORARY};
		enum Type {VAL_NUMBER = 0, VAL_STRING = 1, VAL_BOOL = 2, VAL_NUMBER_LIST};

	private:
		enum Level option_level:	2;
		enum Type type:	3;
		union u_value {
			double number;
			bool b;
		} value;
		std::string text;
		std::vector<double> number_list;

	public:
		friend class ProgramOptions;	// to grant access to the union
		friend std::ostream& operator << (std::ostream& os, ProgramOptions &prog);

		Option();
		~Option();

		void setOption(double, Level);
		void setOption(std::string, Level);
		void setOption(bool, Level);
		void setOption(std::vector<double>, Level);

		bool isNumber()	{ return type == VAL_NUMBER; }
		bool isString()	{ return type == VAL_STRING; }
		bool isBool()	{ return type == VAL_BOOL; }
		bool isNumberList()	{ return type == VAL_NUMBER_LIST; }

		double getNumber();
		std::string getString();
		bool getBool();	
		std::vector<double> getNumberList();	
};


class ProgramOptions
{
	private:
		std::map<std::string, class Option>	options_list;
		enum Option::Level option_level;	// default options level

	public:
		/*
		The constructor
		@param app the app name, needed for /etc/${app} and ~/.${app}
		*/
		ProgramOptions();
		~ProgramOptions();

		/*
		Parses options from a file
		@param file a valid path to the file
		@param level the defaulf options level
		@param prefix a pre-defined level
		*/
		void loadOptionsFromFile(std::istream& is, Option::Level level, std::string prefix = std::string());

		// set the current options level
		void setDefault()	{ option_level = Option::OPT_DEFAULT; }
		void setSystem()	{ option_level = Option::OPT_SYSTEM; }
		void setLocal()		{ option_level = Option::OPT_LOCAL; }
		void setTemporary()	{ option_level = Option::OPT_TEMPORARY; }

		// set the options
		void setOption(const std::string, long int);
		void setOption(const std::string, double);
		void setOption(const std::string, std::string);
		void setOption(const std::string, bool);
		void setOption(const std::string, std::vector<double>);

		// checks if a given option was set
		bool wasSet(const std::string) const;

		// automatically gets the option or, if it isn't set or if it's the wrong type, writes to stdout
		bool getOption(const std::string, long int &, long int);
		bool getOption(const std::string, double &, double);
		bool getOption(const std::string, std::string &, std::string);
		bool getOption(const std::string, bool &, bool);
		bool getOption(const std::string, std::vector<double> &, std::vector<double>);

		// generates an options file 
		//TODO implement an export mechanism that enables exporting in the full and compacted formats
		friend std::ostream& operator << (std::ostream& os, ProgramOptions &prog);

		// import file
		int importFile(std::istream &is, std::string prefix = std::string());

	private:
		class Parser
		{
			enum LEXER_TOKENS { LEX_UNKNOWN_TOKEN = 0,
				LEX_OPTION_NAME, 
				LEX_OPTION_SEPARATOR, 
				LEX_OPTION_ASSIGN,
				LEX_INDENT,
				LEX_STRING, 
				LEX_NUMBER,
				LEX_BOOL,
				LEX_OPEN_VECTOR,
				LEX_CLOSE_VECTOR,
				LEX_VECTOR_SEPARATOR,
				LEX_EOL,
				LEX_EOF,
				LEX_STREAM_ERROR,
				LEX_ERROR };

			// the parser buffer
			char buffer[1024];

			// the temp values extracted from the lexer
			union Option::u_value value;
			std::string text;
			std::vector<double> temp_number_list;

			// helper variables that are used by the lexer
			char *tok;	// marks the start of the current token
			char *pos; 	// marks the current position
			char *marker;	
			char *lim;	// marks the string limit
			int lex_state;	// lexer state, to avoid grammar ambiguities

			public:
				Parser();
				~Parser();

			private:
				void fill(std::istream &is);
				enum LEXER_TOKENS lexer(std::istream &is);

			public:
				int parse(ProgramOptions &op, std::istream &is, std::string prefix = std::string() );

				friend class ProgramOptions;
		};
};


#endif
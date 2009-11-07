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
#include <iostream>	// for ostream


class ProgramOptions
{
	private:
		class Option
		{
			private:
				unsigned int option_level:	2;
				unsigned int type:	2;
				union u_value {
					long int integer;
					double fp;
					const char *text;
				} value;

			public:
				friend class ProgramOptions;	// to grant access to the union

				Option();
				~Option();

				enum OPTIONS_LEVEL {OPT_DEFAULT = 0, OPT_SYSTEM, OPT_LOCAL, OPT_TEMPORARY};
				enum VALUE_TYPE {VAL_INTEGER = 0, VAL_FLOAT, VAL_STRING};

				void setOption(long int, OPTIONS_LEVEL);
				void setOption(double, OPTIONS_LEVEL);
				void setOption(std::string, OPTIONS_LEVEL);

				bool isInteger()	{ return type == VAL_INTEGER; }
				bool isFloat()	{ return type == VAL_FLOAT; }
				bool isString()	{ return type == VAL_STRING; }

				long int getInteger()	{ return value.integer; }
				double getFloat()	{ return value.fp; }
				std::string getString()	{ return std::string(value.text); }
		};

		std::map<std::string, Option> options_list;

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
		void loadOptionsFromFile(std::string file, Option::OPTIONS_LEVEL level, std::string prefix = std::string());

		// set the options
		void setOption(std::string, long int, Option::OPTIONS_LEVEL);
		void setOption(std::string, double, Option::OPTIONS_LEVEL);
		void setOption(std::string, std::string, Option::OPTIONS_LEVEL);

		// generates an options file 
		friend std::ostream& operator << (std::ostream& os, ProgramOptions &prog);


		enum LEXER_TOKENS {LEX_UNKNOWN_TOKEN = 0, LEX_OPTION_NAME, LEX_OPTION_SEPARATOR, 
		LEX_OPTION_ASSIGN, LEX_STRING, LEX_INTEGER, LEX_FLOAT, LEX_EOL, LEX_EOF, LEX_STREAM_ERROR, LEX_ERROR};

//	private:	// just to be tested in main()
		struct lexer_values
		{
			char buffer[1024];
			union u_value {
				long int integer;
				double fp;
				char *text;
			} value;
			char *tok;	// marks the start of the current token
			char *pos; 	// marks the current position
			char *marker;	
			char *lim;	// marks the string limit

			lexer_values();
			~lexer_values();
			void fill(std::istream &is);
		};
		enum LEXER_TOKENS lexer(struct lexer_values &v, std::istream &is);
};


#endif
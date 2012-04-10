#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QApplication>

// #include <ecl/ecl.h>
#include "MainWindow.h++"
#include "ProgramOptions.h++"

#include <string>
#include <iostream>
#include <fstream>

#include "parsers/MshParser.h++"
#include "fem/Model.h++"



Q_DECLARE_METATYPE(size_t);
Q_DECLARE_METATYPE(std::string);

int main(int argc, char *argv[])
{
	qRegisterMetaType<size_t>("size_t");
	qRegisterMetaType<std::string>("std::string");

	QApplication app(argc, argv);

	// register types

	MainWindow mainWin;
	mainWin.show();

	return app.exec();
	// */

	/*
	if(argc < 2)
	{
		std::cout << "usage: test <msh file name>" << std::endl;
		return 0;
	}

	// open a file 
	std::fstream file;
	fem::Model model;
	MshParser parser;

	file.open(argv[1], std::fstream::in);
	if(!file.good())
	{
		std::cerr << "error opening file: " << argv[2] << std::endl;
		return 1;
	}

	switch(parser(file, model))
	{
		case MshParser::Error::ERR_OK:
			std::cout << "All ended well" << std::endl;
			break;

		default:
			std::cout << "Unknown error: " << parser.error.message <<  std::endl;
			break;
	}

	file.close();
	*/
	return 0;
}


#include <iostream>

#include "Document.h++"
#include "fem/FemEquation.h++"
#include "fem/Model.h++"

int main(int argc, char **argv)
{
	using namespace std;
	Document document;

	// no arguments
	if (argc < 2)
	{
		cout << "usage: " << argv[0] << " <file.fem.json>" << endl;
		return 0;
	}

	// set file name
	Document::Error error = document.setFileName(argv[1]);
	if(error != Document::ERR_OK)
	{
		cerr << "Oops." << endl;
		return EXIT_FAILURE;
	}

	// load the model
	document.load();

	// generate the FEM equation
	fem::FemEquation fem;
	document.model.build_fem_equation(fem, document.model.load_pattern_list[0]);

	// all done
	return EXIT_SUCCESS;
}

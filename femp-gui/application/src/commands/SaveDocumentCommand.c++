#include <application/commands/SaveDocumentCommand.h++>

// libfemp includes
#include <libfemp/io/export/JsonExporter.h++>

// stl includes
#include <fstream>

gui::application::SaveDocumentCommand::SaveDocumentCommand(fem::Model& model, std::string file_name) : model(model), file_name(file_name) {}

void gui::application::SaveDocumentCommand::execute() {
	// check if if the given file_name exists
	std::ofstream out;
	out.open(file_name, std::ios::out | std::ios::trunc);

	JsonExporter exporter;
	exporter.output(out, model);

	// cleanup and exit
	// TODO see KDE/ext4 row on proper unix file_name writing
	out.flush();
	out.close();
}
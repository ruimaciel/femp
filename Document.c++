#include "Document.h++"

#include <QTextStream>

#include "parsers/json.h"


Document::Document()
{
	unsaved = false;
	file_name = NULL;
}


Document::Document(const Document &copied)
{
	this->unsaved = copied.unsaved;
	if(copied.file_name != NULL)
	{
		this->file_name = new QString;
		*this->file_name = *copied.file_name;
	}
	this->model = copied.model;
	this->document_type = copied.document_type;
}


Document::~Document()
{
	if(file_name != NULL)
		delete file_name;
}


void Document::clear()
{
	unsaved = false;
	delete file_name;
	document_type = TYPE_NONE;
	model.clear();
}


enum Document::Error Document::setFileName(QString new_file)
{
	if(this->file_name == NULL)
		this->file_name = new QString;
	*this->file_name = new_file;

	//TODO perform checks on the file_name

	return ERR_NONE;
}


enum Document::Error Document::load()
{
	QFile file;
	//TODO check if path exists
	if(file_name == NULL)
		return ERR_NONEXISTENT_FILE;

	file.setFileName(*file_name);
	if(!file.exists())
		return ERR_NONEXISTENT_FILE;

	// sets up all variables
	model.clear();

	//load the project files
	//TODO finish this 
	unsaved = false;
	return ERR_NONE;
}


enum Document::Error Document::save()
{
	QFile file;
	//TODO check version

	// check if if the given file_name exists
	if(file_name == NULL)
		return ERR_NONEXISTENT_FILE;
	qWarning("Document:save(): %s", qPrintable(*file_name));

	file.setFileName(*file_name);

	if( !file.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		return ERR_WRITING_FILE;
	}
	QTextStream out(&file);
	out << "{";
	// dump the header field
	out << "\"fem\":\n";
	out << "\t{";
	out << "\t\"version\": \"1.0\",\n";
	out << "\t\"type\": ";
	switch(document_type)
	{
		case TYPE_SOLID3D:
			out << "\"solid3d\"\n";
			break;

		default:
			out << "\"unknown\"\n";	// this should be seen as an error
			break;
	}

	//TODO complete rest of field
	out << "\t},\n";

	// dump the materials list
	out << "\"materials\":\n";
	out << "\t},\n";

	// dump the nodes list
	out << "\"nodes\":\n";
	out << "\t},\n";

	// dump the elements list
	out << "\"elements\":\n";
	out << "\t},\n";

	// dump the loads list
	out << "\"loads\":\n";
	out << "\t},\n";

	out << "}\n";

	// cleanup and exit
	//TODO see KDE/ext4 row on proper unix file_name writing
	file.flush();
	file.close();

	unsaved = false;
	return ERR_NONE;
}



#include "Document.h++"

#include <QTextStream>

#include "parsers/json.h"


Document::Document()
{
	edited = false;
	document_file = NULL;
}


Document::Document(const Document &copied)
{
	this->edited = copied.edited;
	if(copied.document_file != NULL)
	{
		this->document_file = new QString;
		*this->document_file = *copied.document_file;
	}
	this->model = copied.model;
	this->document_type = copied.document_type;
}


Document::~Document()
{
	if(document_file != NULL)
		delete document_file;
}


void Document::clear()
{
	edited = false;
	delete document_file;
	document_type = TYPE_NONE;
	model.clear();
}


enum Document::Error Document::setFileName(QString file)
{
	if(this->document_file == NULL)
		this->document_file = new QString;
	*this->document_file = file;

	//TODO perform checks on the document_file

	return ERR_NONE;
}


enum Document::Error Document::load()
{
	QFile file;
	//TODO check if path exists
	if(document_file == NULL)
		return ERR_NONEXISTENT_FILE;

	file.setFileName(*document_file);
	if(!file.exists())
		return ERR_NONEXISTENT_FILE;

	// sets up all variables
	model.clear();

	//load the project files
	//TODO finish this 
	return ERR_NONE;
}


enum Document::Error Document::save()
{
	QFile file;
	//TODO check version

	// check if if the given document_file exists
	if(document_file == NULL)
		return ERR_NONEXISTENT_FILE;
	qWarning("Document:save(): %s", qPrintable(*document_file));

	file.setFileName(*document_file);

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
	//TODO see KDE/ext4 row on proper unix document_file writing
	file.flush();
	file.close();

	return ERR_NONE;
}



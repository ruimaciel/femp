#include "Document.h++"

#include <QTextStream>

#include <iostream>
#include <fstream>

#include <libfemp/Model.h++>
#include <libfemp/parsers/fem_msh.h++>
#include <libfemp/parsers/json.h>
#include <libfemp/parsers/MshParser.h++>
#include <libfemp/export/JsonExporter.h++>


Document::Document()
{
	m_unsaved = false;
	file_name = nullptr;

	m_documentType = TYPE_SOLID3D;	// nasty hack due to poor design
}


Document::Document(const Document & copied)
{
	this->m_unsaved = copied.m_unsaved;
	if (copied.file_name != nullptr) {
		this->file_name = new QString;
		*this->file_name = *copied.file_name;
	}
	else
	{
		this->file_name = nullptr;
	}
	this->m_documentType = copied.m_documentType;
}


Document::~Document()
{
	if (file_name != nullptr)
		delete file_name;
}


void
Document::clear()
{
	m_unsaved = false;
	if (file_name != nullptr) {
		delete file_name;
		file_name = nullptr;
	}
	m_documentType = TYPE_NONE;
	this->m_project.clear();
}


enum Document::Error
		Document::setFileName(QString new_file)
{
	if (this->file_name == nullptr)
		this->file_name = new QString;
	*this->file_name = new_file;

	// check if file exists
	QFile           file;
	file.setFileName(*file_name);

	return ERR_OK;
}


QString
Document::getFileName() const
{
	if(this->file_name == nullptr)
	{
		return QString();
	}
	else
	{
		return *this->file_name;
	}
}


enum Document::Error
		Document::save()
{
	// TODO check version

	// check if if the given file_name exists
	if (file_name == nullptr) {
		return ERR_FILE_NOT_FOUND;
	}

	std::ofstream out;
	out.open(file_name->toStdString(), std::ios::out | std::ios::trunc);

	JsonExporter exporter;
	fem::Model &model = this->m_project.getModel();
	exporter.output(out, model);

	// cleanup and exit
	// TODO see KDE/ext4 row on proper unix file_name writing
	out.flush();
	out.close();

	m_unsaved = false;
	return ERR_OK;
}



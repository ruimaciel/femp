#include "Document.h++"

#include <QTextStream>

#include <iostream>
#include <fstream>

#include <libfemp/Model.h++>
#include <libfemp/parsers/fem_msh.h++>
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
	return this->file_name == nullptr ? QString() : *this->file_name;
}


void
Document::setProjectType(Document::Type type)
{
	m_documentType = type;
}


fem::Project &
Document::getProject()
{
	return this->m_project;
}


void
Document::setUnsaved(bool unsaved)
{
	m_unsaved = unsaved;
}


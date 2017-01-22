#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QDir>	// for the project path
#include <string>
#include <list>

#include "Project.h++"


class Document
{
public:
	enum Type { TYPE_NONE, TYPE_SOLID3D};
	enum Error {ERR_OK, 
		ERR_FILE_NOT_FOUND,	// path to project file doesn't exist
		ERR_FILE_OPEN,		// file.open() failed
		ERR_INVALID_FILE,	// path doesn't point to a valid project file
		ERR_PARSER_ERROR,	// the parser stumbled on a formatting error
		ERR_WRITING_FILE,	// error while writing file
		ERR_UNKNOWN		//
		};

protected:
	bool unsaved;	// true if this document suffered changes that are saveable
	Type document_type;	// specifies the model type

public:
	QString *file_name;	// path for the project's directory
	fem::Project project;	// the FEM project

public:
	Document();
	Document(const Document &copied);
	~Document();

	void clear();	// clears/frees everything

	/*!
	 * Sets the file name
	 */
	enum Error setFileName(QString file);	// points to a file

	/*!
	 * Returns a QString with the file name
	 */
	QString getFileName() const;

	void setProjectType(Type type)	{ document_type = type; }


	/*!
	 * Returns a reference to the Project object
	 */
	fem::Project &getProject() 	{ return this->project; }

	/**
	Saves the project in it's path
	**/
	enum Error save();

	void setUnsaved()	{unsaved = true; }
};


#endif

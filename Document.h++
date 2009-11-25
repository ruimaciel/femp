#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include <QDir>	// for the project path
#include <string>

#include "fem/Model.h++"


class Document
{
	public:
		enum Type { TYPE_NONE, TYPE_SOLID3D};
		enum Error {ERR_NONE, 
			ERR_NONEXISTENT_FILE,	// path to project dir doesn't exist
			ERR_INVALID_FILE,	// path doesn't point to a valid project file
			ERR_PARSER_ERROR,	// the parser stumbled on a formatting error
			ERR_WRITING_FILE	// error while writing file
			};

	private:
		bool edited;	// true if this document suffered changes that are saveable
		QString *document_file;	// path for the project's directory
		Type document_type;

	public:
		fem::Model model;	// the FEM model

	public:
		Document();
		Document(const Document &copied);
		~Document();

		void clear();	// clears/frees everything
		enum Error setFileName(QString file);	// points to a file
		void setProjectType(Type type)	{ document_type = type; }
		enum Error load();	// loads the project
		enum Error save();	// saves project in it's path
};


#endif

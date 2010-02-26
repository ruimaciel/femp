#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include <QDir>	// for the project path
#include <string>

#include "fem/Model.h++"


class Document
{
	public:
		enum Type { TYPE_NONE, TYPE_SOLID3D};
		enum Error {ERR_OK, 
			ERR_FILE_NOT_FOUND,	// path to project file doesn't exist
			ERR_FILE_OPEN,		// file.open() failed
			ERR_INVALID_FILE,	// path doesn't point to a valid project file
			ERR_PARSER_ERROR,	// the parser stumbled on a formatting error
			ERR_WRITING_FILE	// error while writing file
			};

	private:
		bool unsaved;	// true if this document suffered changes that are saveable
		Type document_type;

	public:
		QString *file_name;	// path for the project's directory
		fem::Model model;	// the FEM model


		// data structures for storing selected objects
		std::map<size_t,bool> selected_nodes;

	public:
		Document();
		Document(const Document &copied);
		~Document();

		void clear();	// clears/frees everything
		enum Error setFileName(QString file);	// points to a file
		void setProjectType(Type type)	{ document_type = type; }
		enum Error load();	// loads the project
		enum Error save();	// saves project in it's path
		enum Error importMesh(QString file_name);

		// object selection routines
		void selectNode(const size_t &node);
		void deselectNode(const size_t &node);
		void deselectAll();
};


#endif

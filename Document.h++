#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP


#include <string>

#include "fem/Model.h++"


class Document
{
	public:
		enum Type { TYPE_NONE, TYPE_SOLID3D};
		enum Error {ERR_NONE, ERR_INVALID_PATH};

	private:
		bool edited;	// true if this document suffered changes that are saveable
		std::string location;	// path for the project's directory
		Type document_type;

	public:
		fem::Model model;	// the FEM model

	public:
		Document();
		Document(const Document &copied);
		~Document();

		// sets up a blank document
		void initialize(Type type, std::string path);
	
		// clears/frees everything
		void clear();
		enum Error loadNewProject(std::string path); // loads a project from a new location
		enum Error load();	// loads the project
		enum Error save();	// saves project in it's path
};


#endif

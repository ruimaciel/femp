#include "Document.h++"

Document::Document()
{
}

Document::Document(const Document &copied)
{
	this->edited = copied.edited;
	this->location = copied.location;
	this->model = copied.model;
	this->document_type = copied.document_type;
}


Document::~Document()
{
}


void Document::initialize(Type type, std::string path)
{
	edited = false;
	location = path;
	document_type = type;
}


void Document::clear()
{
	edited = false;
	location.clear();
	document_type = TYPE_NONE;
	model.clear();
}


enum Document::Error Document::loadNewProject(std::string path)
{
	//TODO check if path exists

	location = path;

	// loads the project if it was a local project
	return this->load();
}



enum Document::Error Document::load()
{
	this->clear();
	//TODO check if path exists

	//TODO finish this
	//TODO save index.json
	//TODO materials.json
	//TODO model.json
	//TODO load.json

	return ERR_NONE;
}


enum Document::Error Document::save()
{
	//TODO check if path exists
	if(location.empty())
		return ERR_INVALID_PATH;

	//TODO save index.json
	//TODO materials.json
	//TODO model.json
	//TODO load.json

	return ERR_NONE;
}

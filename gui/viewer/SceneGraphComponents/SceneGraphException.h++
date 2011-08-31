#ifndef SCENE_GRAPH_EXCEPTION
#define SCENE_GRAPH_EXCEPTION

#include <string>
#include <stdexcept>
#include <iostream>

/**
  * class SceneGraphException
  * This class is intended to be the base calss for all exceptions thrown by scene graph routines
  **/
class SceneGraphException
	: public std::runtime_error
{
	public:
		explicit SceneGraphException(const std::string &message): std::runtime_error(std::string("scene graph: "+message)) { std::cerr << this->what() << std::endl; }
};



#endif

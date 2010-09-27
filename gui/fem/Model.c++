#include "Model.h++"
#include <algorithm>

#include <cstdlib>
#include <cstring>

#include <vector>
#include <stack>


namespace fem
{

Model::Model()
{
	default_material = 0;
}


Model::~Model()
{
}


void Model::clear()
{
	node_list.clear();
	element_list.clear();
	material_list.clear();
	node_restrictions_list.clear();
	load_pattern_list.clear();
}


void Model::setNode(size_t ref, double x, double y, double z)
{
	Node n;
	n.set(x,y,z);
	this->node_list[ref] = n;
}


void Model::setNode(size_t ref, fem::point p)
{
	Node n;
	n.x(p.x());
	n.y(p.y());
	n.z(p.z());
	this->node_list[ref] = n;
}


void Model::pushElement(fem::Element e)
{
	e.material = default_material;
	this->element_list.push_back(e);
}


void Model::pushElement(fem::Element::Type type, std::vector<size_t> nodes)
{
	fem::Element e;
	e.set(type,nodes);

	this->pushElement(e);
}


enum Model::Error Model::pushNodeRestrictions(size_t pos, fem::NodeRestrictions nr)
{
	// check if node is set
	if(node_list.find(pos) == node_list.end())
		return ERR_INVALID_NODE_REFERENCE;

	//TODO perform aditional error checking

	// push node restrictions object
	node_restrictions_list[pos] = nr;

	// everything went smoothly
	return ERR_OK;
}


enum Model::Error Model::pushLoadPattern(fem::LoadPattern lp)
{
	//TODO perform error checks

	load_pattern_list.push_back(lp);

	return ERR_OK;
}


enum Model::Error Model::sanity_check()
{
	// check if the Element's nodes are right
	for( std::vector<Element>::iterator it = element_list.begin(); it != element_list.end(); it++)
	{
		// check if the referenced material exists
		if(material_list.size() > (size_t)it->material)
			return ERR_INVALID_MATERIAL_REFERENCE;

		// check node's type
		switch(it->type)
		{
			case Element::FE_LINE2:
				if(it->nodes.size() != 2)
				{
					return ERR_NODE_NUMBER;
				}
				break;

			case Element::FE_TETRAHEDRON4:
				if(it->nodes.size() != 4)
				{
					return ERR_NODE_NUMBER;
				}
				break;

			case Element::FE_TETRAHEDRON10:
				if(it->nodes.size() != 10)
				{
					return ERR_NODE_NUMBER;
				}
				break;


			case Element::FE_HEXAHEDRON8:
				if(it->nodes.size() != 8)
				{
					return ERR_NODE_NUMBER;
				}
				break;

			case Element::FE_HEXAHEDRON20:
				if(it->nodes.size() != 20)
				{
					return ERR_NODE_NUMBER;
				}
				break;

			case Element::FE_HEXAHEDRON27:
				if(it->nodes.size() != 27)
				{
					return ERR_NODE_NUMBER;
				}
				break;

			default:
				return ERR_UNSUPPORTED_ELEMENT;
				break;
		}

		// run a sanity check on the node's references
		for(std::vector<size_t>::iterator n = it->nodes.begin(); n != it->nodes.end(); n++)
		{
			if(node_list.find(*n) == node_list.end())
				return ERR_ELEMENT_NODE_REFERENCE;
		}
	}

	//test node_restrictions_list
	//TODO finish this
	return ERR_OK;
}


enum Model::Error Model::import_json(FILE *file)
{
	using namespace std;

	assert(file != NULL);

	json_t         *root = NULL;

		// parses the document from the file stream
	switch (json_stream_parse(file, &root)) {
		case JSON_OK:
			// all went well
			break;

		default:
			return ERR_PARSER;
			break;
	}

		// JSON document successfully parsed. Now let's extract stuff from it
	std::stack < json_t * >cursor;
	std::stack < int >state;	// the parser's states

		// temporary variables used to build the document
	fem::Material 	material;
	fem::Element 	element;
	fem::NodeRestrictions 	node_restrictions;
	fem::LoadPattern 	load_pattern;
	fem::SurfaceLoad	surface_load;

	size_t          ref;
	std::vector < size_t > refs;
	fem::point v;
	std::vector < fem::point > vs;

		// initializing the parser
	cursor.push(root);
	state.push(0);		// starting state

#define ERROR()	{std::cout << "Model::import_json() State " << state.top() << std::endl; goto error;}
#define CURSOR_PUSH(TYPE) { if(cursor.top()->child == NULL) ERROR(); if (cursor.top()->child->type != TYPE) ERROR(); cursor.push(cursor.top()->child);}
#define CURSOR_VERIFY_TEXT(TEXT)	{if(cursor.top()->text == NULL) ERROR(); if(strcmp(cursor.top()->text, TEXT) != 0) ERROR();}
#define CURSOR_NEXT()	{if(cursor.top()->next == NULL) ERROR(); cursor.top() = cursor.top()->next;}
#define CURSOR_NEXT_TEST(TYPE)	{CURSOR_NEXT(); if(cursor.top()->type != TYPE) ERROR() }
#define CURSOR_VERIFY_LABEL_TEXT(LABEL, VALUE) CURSOR_VERIFY_TEXT(LABEL); CURSOR_PUSH(JSON_STRING); CURSOR_VERIFY_TEXT(VALUE); cursor.pop();

#define DECHO()	{ /* std::cerr << "State " << state.top() << std::endl;*/ }


	while (state.size() > 0) 
	{
		switch (state.top()) 
		{
			case 0:
				DECHO();
				// point cursor to the first child node
				CURSOR_PUSH(JSON_STRING);	

				// set the state stack
				state.pop();

				state.push(25);	// OtherFields
				state.push(1);	// MandatoryFields
				break;

			case 1:		// MandatoryFields -> Header Materials
				DECHO();
				// Nodes Surfaces Elements
				state.pop();

				state.push(18);	// Elements
				state.push(11);	// Nodes
				state.push(6);	// Materials
				state.push(2);	// Header
				break;

			case 2:		// Header -> VersionNumber FemModelType
				DECHO();

				CURSOR_VERIFY_TEXT("fem");	// header label must be "fem"

				CURSOR_PUSH(JSON_OBJECT);	
				CURSOR_PUSH(JSON_STRING);	

				// set the state stack
				state.pop();

				state.push(5);	// EndHeader
				state.push(4);	// FemModelType
				state.push(3);	// VersionNumber
				break;

			case 3:		// VersionNumber -> "version": "1.0"
				DECHO();
				CURSOR_VERIFY_TEXT("version");	// header label must be
				// "fem"
				CURSOR_PUSH(JSON_STRING);	
				CURSOR_VERIFY_TEXT("1.0");	// header label must be "fem"

				// reposition the cursor
				cursor.pop();	
				CURSOR_NEXT();	
				state.pop();
				break;

			case 4:		// <FemModelType> -> "type": "3D solid"
				DECHO();
				CURSOR_VERIFY_TEXT("type");	// header label must be "fem"
				CURSOR_PUSH(JSON_STRING);	// "version": -> "1.0"

				//TODO support more types 
				CURSOR_VERIFY_TEXT("3D solid");	// header label must be

					// reposition the cursor
				cursor.pop();

				state.pop();
				break;

			case 5:		// EndHeader
				DECHO();
				cursor.pop();	
				cursor.pop();
				if (cursor.top()->next == NULL)
					ERROR();	// must have a followup field
				cursor.top() = cursor.top()->next;	
				CURSOR_VERIFY_TEXT("materials");	// header label must be "fem"
				CURSOR_PUSH(JSON_ARRAY);	

				state.pop();
				break;

			case 6:		// Materials
				DECHO();
				CURSOR_PUSH(JSON_OBJECT);	

				state.pop();

				state.push(9);	// <MaterialsFollow>
				state.push(7);	// <Material>
				break;

			case 7:		// Material
				DECHO();
				CURSOR_PUSH(JSON_STRING);
				CURSOR_VERIFY_LABEL_TEXT("type", "linear elastic");
				material.type = fem::Material::MAT_LINEAR_ELASTIC;

				CURSOR_NEXT();
				CURSOR_VERIFY_TEXT("label");
				CURSOR_PUSH(JSON_STRING);
				material.label = cursor.top()->text;
				cursor.pop();

				CURSOR_NEXT();
				CURSOR_VERIFY_TEXT("E");
				CURSOR_PUSH(JSON_NUMBER);
				material.E = atof(cursor.top()->text);
				cursor.pop();

				CURSOR_NEXT();
				CURSOR_VERIFY_TEXT("nu");
				CURSOR_PUSH(JSON_NUMBER);
				material.nu = atof(cursor.top()->text);
				cursor.pop();

				CURSOR_NEXT();
				CURSOR_VERIFY_TEXT("fy");
				CURSOR_PUSH(JSON_NUMBER);
				material.fy = atof(cursor.top()->text);
				cursor.pop();

				// update field
				state.pop();

				state.push(8);	// EndMaterial
				break;

			case 8:		// EndMaterial
				DECHO();
				if (cursor.top()->next != NULL)
					ERROR();
				cursor.pop();
				cursor.pop();

				// Material field is complete. Push material to the list
				this->material_list.push_back(material);

				state.pop();
				break;

			case 9:		// MaterialsFollow
				DECHO();
				// test the FIRST of fury
				if (cursor.top()->next == NULL) 
				{
					state.pop();

					state.push(10);	// EndMaterialsFollow
				} 
				else 
				{
					cursor.top() = cursor.top()->next;

					state.pop();

					state.push(9);	// MaterialsFollow
					state.push(7);	// Material
				}
				break;

			case 10:		// EndMaterialsFollow
				DECHO();
				// TODO
				cursor.pop();	
				if (cursor.top()->next == NULL)
					ERROR();	// must have a followup field
				cursor.top() = cursor.top()->next;	
				CURSOR_VERIFY_TEXT("nodes");	// header label must be
				// "nodes"
				CURSOR_PUSH(JSON_ARRAY);	

				state.pop();
				break;

			case 11:		// Nodes
				DECHO();
				CURSOR_PUSH(JSON_ARRAY);	
				state.pop();

				state.push(13);	// NodeFollow
				state.push(12);	// Node
				break;

			case 12:		// Node
				DECHO();
				CURSOR_PUSH(JSON_NUMBER);	// "nodes": [ [ -> 1, [
				state.pop();

				state.push(16);	// EndNode
				state.push(15);	// Coordinate
				state.push(14);	// NodeReference
				break;

			case 13:		// NodeFollow
				DECHO();
				// TODO test the FIRST of fury
				if (cursor.top()->next == NULL) {
					state.pop();

					state.push(17);	// EndNodes
				} else {
					CURSOR_NEXT_TEST(JSON_ARRAY);
					state.pop();

					state.push(13);	// NodeFollow
					state.push(12);	// Node
				}
				break;

			case 14:		// NodeReference
				DECHO();
				ref =  strtoul(cursor.top()->text, NULL, 0);

				CURSOR_NEXT();
				if (cursor.top()->type != JSON_ARRAY)
					goto error;
				state.pop();
				break;

			case 15:		// Coordinate
				DECHO();
				CURSOR_PUSH(JSON_NUMBER);

				// get the vector components
				v.x(atof(cursor.top()->text));

				CURSOR_NEXT_TEST(JSON_NUMBER);
				v.y(atof(cursor.top()->text));
				
				CURSOR_NEXT_TEST(JSON_NUMBER);
				v.z(atof(cursor.top()->text));

				if (cursor.top()->next != NULL)
					goto error;
				cursor.pop();

				state.pop();
				break;

			case 16:		// EndNode
				DECHO();
				// TODO finish
				this->setNode(ref, v);

				cursor.pop();

				state.pop();
				break;

			case 17:		// EndNodes
				DECHO();
				// TODO finish
				cursor.pop();	
				cursor.pop();
				if (cursor.top()->next == NULL)
					ERROR();	// must have a followup field
				cursor.top() = cursor.top()->next;	
				CURSOR_VERIFY_TEXT("elements");	// header label must be "nodes"
				CURSOR_PUSH(JSON_ARRAY);	

				state.pop();
				break;

			case 18:		// Elements
				DECHO();
				CURSOR_PUSH(JSON_OBJECT);	

				state.pop();

				state.push(20);	// ElementFollow
				state.push(19);	// Element
				break;

			case 19:		// Element
				DECHO();
				// TODO finish
				CURSOR_PUSH(JSON_STRING);	
				CURSOR_VERIFY_TEXT("type");

				CURSOR_PUSH(JSON_STRING);	
				// "tetrahedron"

				// clear the temp element
				element.nodes.clear();

				state.pop();

				state.push(23);	// MaterialReference
				switch (fem::Element::extractType(cursor.top()->text)) 
				{
					//TODO add more element definitions
					case fem::Element::FE_TETRAHEDRON4:
						element.type = fem::Element::FE_TETRAHEDRON4;
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(21);	// ElementFirstNode
						break;

					case fem::Element::FE_TETRAHEDRON10:
						element.type = fem::Element::FE_TETRAHEDRON10;
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(21);	// ElementFirstNode
						break;

					case fem::Element::FE_HEXAHEDRON8:
						element.type = fem::Element::FE_HEXAHEDRON8;
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(21);	// ElementFirstNode
						break;

					case fem::Element::FE_HEXAHEDRON20:
						element.type = fem::Element::FE_HEXAHEDRON20;
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(21);	// ElementFirstNode
						break;

					case fem::Element::FE_HEXAHEDRON27:
						element.type = fem::Element::FE_HEXAHEDRON27;
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(21);	// ElementFirstNode
						break;

					case fem::Element::FE_PRISM6:
						element.type = fem::Element::FE_PRISM6;
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(22);	// ElementNode
						state.push(21);	// ElementFirstNode
						break;

					default:
						std::cout << "unsupported element: " << state.
							top() << std::endl;
						goto unknown_error;
						break;
				}

				cursor.pop();	
				CURSOR_NEXT_TEST(JSON_STRING);
				CURSOR_VERIFY_TEXT("nodes");
				CURSOR_PUSH(JSON_ARRAY);
				CURSOR_PUSH(JSON_NUMBER);
				break;

			case 20:		// ElementsFollow
				DECHO();
				// TODO
				if (cursor.top()->next != NULL) {
					CURSOR_NEXT_TEST(JSON_OBJECT);

					state.pop();

					state.push(20);	// ElementsFollow
					state.push(19);	// Element
				} else {
					state.pop();

					state.push(24);	// EndElements
				}
				break;

			case 21:		// ElementFirstNode
				DECHO();
				// TODO
				element.nodes.push_back(strtoul(cursor.top()->text, NULL, 0));

				state.pop();
				break;

			case 22:		// ElementNextNode
				DECHO();
				CURSOR_NEXT_TEST(JSON_NUMBER);

				element.nodes.push_back(strtoul(cursor.top()->text, NULL, 0));

				state.pop();
				break;

			case 23:		// MaterialReference
				DECHO();
				cursor.pop();
				cursor.pop();
				if (cursor.top()->next == NULL) 
				{
					cursor.pop();
				} 
				else 
				{
					CURSOR_NEXT_TEST(JSON_STRING);
					CURSOR_VERIFY_TEXT("material");
					CURSOR_PUSH(JSON_NUMBER);
					this->setDefaultMaterial(strtoul(cursor.top()->text, NULL, 0));
					cursor.pop();
					cursor.pop();
				}

				// push element
				this->pushElement(element);

				state.pop();
				break;

			case 24:	// EndElements
				DECHO();
				// TODO finish
				cursor.pop();	
				cursor.pop();

				state.pop();
				break;


			case 25:	// OtherFields
				DECHO();
				// TODO finish
				// test the FIRST
				if (cursor.top()->next == NULL) 
				{
					// TODO
					// no node restrictions
					// no load patterns
					// no combinations

					// reached the end of the document
					return ERR_OK;
				} 
				else 
				{
					cursor.top() = cursor.top()->next;	

					// verify first
					if (strcmp(cursor.top()->text, "node restrictions") == 0) {
						CURSOR_PUSH(JSON_ARRAY);	
						CURSOR_PUSH(JSON_OBJECT);	

						state.pop();

						state.push(29);	// AfterNodeRestrictions
						state.push(26);	// NodeRestrictions
					} else if (strcmp(cursor.top()->text, "load patterns") == 0) 
					{
						// TODO
						CURSOR_PUSH(JSON_ARRAY);	

						state.pop();

						state.push(30);	// LoadPatterns
					} else if (strcmp(cursor.top()->text, "load combinations") == 0) 
					{
						// TODO
						return ERR_OK;
					} else 
					{
						ERROR();
					}
				}
				break;

			case 26:		// NodeRestrictions
				DECHO();
				// TODO finish

				state.pop();

				state.push(28);	// NodeRestrictionFollow
				state.push(27);	// NodeRestriction
				break;

			case 27:		// NodeRestriction
				DECHO();
				// TODO finish
				CURSOR_PUSH(JSON_STRING);	
				CURSOR_VERIFY_TEXT("node");
				CURSOR_PUSH(JSON_NUMBER);	

				// set the temps
				node_restrictions.reset();

				ref = strtoul(cursor.top()->text, NULL, 0);

				cursor.pop();
				CURSOR_NEXT_TEST(JSON_STRING);

				if (strcmp(cursor.top()->text, "dx") == 0) 
				{
					switch(cursor.top()->child->type)
					{
						case JSON_TRUE:
							node_restrictions.setdx();
							break;

						case JSON_FALSE:
							break;

						default:
							ERROR();
							break;
					}

					if (cursor.top()->next == NULL)
					{
						// set the node restrictions
						this->pushNodeRestrictions(ref, node_restrictions);

						cursor.pop();	

						state.pop();
						break;
					}
					CURSOR_NEXT_TEST(JSON_STRING);
				}

				if (strcmp(cursor.top()->text, "dy") == 0) {
					switch(cursor.top()->child->type)
					{
						case JSON_TRUE:
							node_restrictions.setdy();
							break;

						case JSON_FALSE:
							break;

						default:
							ERROR();
							break;
					}


					if (cursor.top()->next == NULL)
					{
						// set the node restrictions
						this->pushNodeRestrictions(ref, node_restrictions);

						cursor.pop();	

						state.pop();
						break;
					}
					CURSOR_NEXT_TEST(JSON_STRING);
				}

				if (strcmp(cursor.top()->text, "dz") == 0) {
					switch(cursor.top()->child->type)
					{
						case JSON_TRUE:
							node_restrictions.setdz();
							break;

						case JSON_FALSE:
							break;

						default:
							ERROR();
							break;
					}


					if (cursor.top()->next == NULL)
					{
						// set the node restrictions
						this->pushNodeRestrictions(ref, node_restrictions);

						cursor.pop();	

						state.pop();
						break;
					}
				}

				if (cursor.top()->next != NULL)
					ERROR();

				// set the node restrictions
				//this->pushNodeRestrictions(ref, node_restrictions);

				cursor.pop();	

				state.pop();
				break;

			case 28:		// NodeRestrictionFollow
				DECHO();
				// TODO finish
				if (cursor.top()->next == NULL) {	// EndNodeRestriction
					cursor.pop();	
					cursor.pop();	// "node restrictions" JSON_ARRAY JSON_OBJECT

					state.pop();
				} 
				else 
				{
					CURSOR_NEXT();
					state.pop();

					state.push(28);	// NodeRestrictionsFollow
					state.push(27);	// NodeRestriction
				}
				break;

			case 29:		// AfterNodeRestrictions
				DECHO();
				// TODO
				if (cursor.top()->next == NULL) {
					// EOF
					return ERR_OK;
				}

				CURSOR_NEXT_TEST(JSON_STRING);

				if (strcmp(cursor.top()->text, "load patterns") == 0) 
				{
					CURSOR_PUSH(JSON_ARRAY);
					state.pop();

					state.push(30);	// LoadPatterns
				} 
				else if (strcmp(cursor.top()->text, "load combinations") == 0) 
				{
					// TODO
					return ERR_UNKNOWN;
				} 
				else 
				{
					ERROR();
				}

				break;


			case 30:		// LoadPatterns
				DECHO();
				// TODO 
				CURSOR_PUSH(JSON_OBJECT);	

				state.pop();

				state.push(52);	// LoadPatternFollow
				state.push(31);	// LoadPattern
				break;

			case 31:		// LoadPattern
				DECHO();
				// TODO
				CURSOR_PUSH(JSON_STRING);	
				CURSOR_VERIFY_TEXT("label");
				CURSOR_PUSH(JSON_STRING);	
				load_pattern.clear();
				load_pattern.label = cursor.top()->text;

				cursor.pop();	
				CURSOR_NEXT_TEST(JSON_STRING);	


				if (strcmp(cursor.top()->text, "nodal loads") == 0) {
					// TODO
					CURSOR_PUSH(JSON_ARRAY);	
					CURSOR_PUSH(JSON_OBJECT);	

					state.pop();

					state.push(35);	// AfterNodalLoads
					state.push(32);	// NodalLoads
				} 
				else if (strcmp(cursor.top()->text, "node displacements") == 0) 
				{
					// TODO
					CURSOR_PUSH(JSON_ARRAY);	
					CURSOR_PUSH(JSON_OBJECT);	

					state.pop();

					state.push(36);	// NodeDisplacements
				}
			       	else if (strcmp(cursor.top()->text, "domain loads") == 0) 
				{
					// TODO
					CURSOR_PUSH(JSON_ARRAY);	
					CURSOR_PUSH(JSON_OBJECT);	

					state.pop();

					state.push(40);	// DomainLoads
				} 
				else if (strcmp(cursor.top()->text, "surface loads") == 0) 
				{
					// TODO
					CURSOR_PUSH(JSON_ARRAY);	
					CURSOR_PUSH(JSON_OBJECT);	

					state.pop();

					state.push(44);	// SurfaceLoads
				} 
				else 
				{
					ERROR();
				}
				break;


			case 32:		// NodalLoads
				DECHO();
				state.pop();

				state.push(34);	// NodalLoadFollow
				state.push(33);	// NodalLoad
				break;

			case 33:		// NodalLoad
				DECHO();
				CURSOR_PUSH(JSON_STRING);	

				CURSOR_VERIFY_TEXT("node");
				CURSOR_PUSH(JSON_NUMBER);	

				ref = strtoul(cursor.top()->text, NULL, 0);

				cursor.pop();	
				CURSOR_NEXT_TEST(JSON_STRING);
				CURSOR_VERIFY_TEXT("force");
				CURSOR_PUSH(JSON_ARRAY);	

				state.pop();
				state.push(15);	// Coordinate
				break;

			case 34:	// NodalLoadFollow
				DECHO();
				//TODO
				load_pattern.addNodalLoad(ref, v);

				cursor.pop();	// JSON_OBJECT -> "force" JSON_ARRAY
				cursor.pop();	// -> JSON_OBJECT "force"

				// Test the FIRST
				if(cursor.top()->next == NULL)
				{
					state.pop();
				}
				else
				{
					CURSOR_NEXT_TEST(JSON_OBJECT);
					state.pop();

					state.push(34);	// NodalLoadFollow
					state.push(33);	// NodalLoad
				}
				break;

			case 35:	// AfterNodalLoads
				DECHO();
				//TODO
				cursor.pop();	// JSON_OBJECT -> "load patterns" JSON_ARRAY
				cursor.pop();	// -> "nodal loads"

				if(cursor.top()->next == NULL)
				{
					//TODO finish this
					state.pop();
				}
				else
				{
					CURSOR_NEXT_TEST(JSON_STRING);
					if (strcmp(cursor.top()->text, "node displacements") == 0) 
					{
						// TODO
						CURSOR_PUSH(JSON_ARRAY);	
						CURSOR_PUSH(JSON_OBJECT);	// "node displacements" JSON_ARRAY JSON_OBJECT

						state.pop();

						state.push(39);	// AfterNodeDisplacements
						state.push(36);	// NodeDisplacements
					} 
					else if (strcmp(cursor.top()->text, "domain loads") == 0) 
					{
						// TODO
						CURSOR_PUSH(JSON_ARRAY);	
						CURSOR_PUSH(JSON_OBJECT);	

						state.pop();

						state.push(43);	// AfterDomainLoads
						state.push(40);	// DomainLoads
					} 
					else if (strcmp(cursor.top()->text, "surface loads") == 0) 
					{
						// TODO
						CURSOR_PUSH(JSON_ARRAY);	
						CURSOR_PUSH(JSON_OBJECT);	

						state.pop();

						state.push(51);	// AfterSurfaceLoads
						state.push(44);	// SurfaceLoads
					} 
					else 
					{
						ERROR();
					}
				}
				break;

			case 36:	// NodeDisplacements
				DECHO();
				state.pop();

				state.push(38);	// NodeDisplacementFollow
				state.push(37);	// NodeDisplacement
				break;

			case 37:	// NodeDisplacement
				DECHO();

				CURSOR_PUSH(JSON_STRING);
				CURSOR_VERIFY_TEXT("node");
				CURSOR_PUSH(JSON_NUMBER);
				
				ref = strtoul(cursor.top()->text, NULL, 0);
				cursor.pop();

				CURSOR_NEXT_TEST(JSON_STRING);

				//TODO add support for node displacements
				state.pop();
				break;

			case 38:	// NodeDisplacementFollow
				DECHO();
				//TODO  add support for node displacements

				cursor.pop();	// -> JSON_OBJECT "node"

				// Test the FIRST
				if(cursor.top()->next == NULL)
				{
					state.pop();
				}
				else
				{
					CURSOR_NEXT_TEST(JSON_OBJECT);
					state.pop();

					state.push(38);	// NodeDisplacementFollow
					state.push(37);	// NodeDisplacement
				}
				break;

			case 39:	// AfterNodeDisplacements
				DECHO();
				//TODO
				cursor.pop();
				cursor.pop();	// -> "node displacement"

				if(cursor.top()->next == NULL)
				{
					//TODO finish this
					state.pop();
				}
				else
				{
					CURSOR_NEXT_TEST(JSON_STRING);
					if (strcmp(cursor.top()->text, "domain loads") == 0) 
					{
						// TODO
						CURSOR_PUSH(JSON_ARRAY);	
						CURSOR_PUSH(JSON_OBJECT);	

						state.pop();

						state.push(43);	// AfterDomainLoads
						state.push(40);	// DomainLoads
					} 
					else if (strcmp(cursor.top()->text, "surface loads") == 0) 
					{
						// TODO
						CURSOR_PUSH(JSON_ARRAY);	
						CURSOR_PUSH(JSON_OBJECT);	

						state.pop();

						state.push(51);	// AfterSurfaceLoads
						state.push(44);	// SurfaceLoads
					} 
					else 
					{
						ERROR();
					}
				}
				break;

			case 40:	// DomainLoads
				DECHO();
				state.pop();

				state.push(42);	// DomainLoadsFollow
				state.push(41);	// DomainLoad
				break;


			case 41:	// DomainLoad
				DECHO();

				CURSOR_PUSH(JSON_STRING);
				CURSOR_VERIFY_TEXT("element");
				CURSOR_PUSH(JSON_NUMBER);
				
				ref = strtoul(cursor.top()->text, NULL, 0);
				cursor.pop();

				CURSOR_NEXT_TEST(JSON_STRING);
				CURSOR_VERIFY_TEXT("force");
				CURSOR_PUSH(JSON_ARRAY);

				state.pop();
				state.push(15);	// Coordinates
				break;

			case 42:	// DomainLoadsFollow
				DECHO();
				//TODO
				load_pattern.addDomainLoad(ref, v);

				cursor.pop();	// JSON_OBJECT -> "force" JSON_ARRAY
				cursor.pop();	// -> JSON_OBJECT "force"

				// Test the FIRST
				if(cursor.top()->next == NULL)
				{
					state.pop();
				}
				else
				{
					CURSOR_NEXT_TEST(JSON_OBJECT);
					state.pop();

					state.push(42);	// DomainLoadsFollow
					state.push(41);	// DomainLoad
				}
				break;

			case 43:	// AfterDomainLoads
				DECHO();
				//TODO
				cursor.pop();
				cursor.pop();	// -> "domain loads"

				if(cursor.top()->next == NULL)
				{
					//TODO finish this
					state.pop();
				}
				else
				{
					CURSOR_NEXT_TEST(JSON_STRING);
					if (strcmp(cursor.top()->text, "surface loads") == 0) 
					{
						// TODO
						CURSOR_PUSH(JSON_ARRAY);	
						CURSOR_PUSH(JSON_OBJECT);	

						state.pop();

						state.push(51);	// AfterSurfaceLoads
						state.push(44);	// SurfaceLoads
					} 
					else 
					{
						ERROR();
					}
				}
				break;

			case 44:	// SurfaceLoads
				DECHO();
				state.pop();

				state.push(50);	// SurfaceLoadsFollow
				state.push(45);	// SurfaceLoad
				break;

			case 45:		// SurfaceLoad
				DECHO();
				// TODO finish
				CURSOR_PUSH(JSON_STRING);	
				CURSOR_VERIFY_TEXT("type");

				CURSOR_PUSH(JSON_STRING);	

				// clear the temp surface load
				surface_load.clear();

				state.pop();

				switch (fem::Element::extractType(cursor.top()->text)) 
				{
					//TODO add more element definitions
					case fem::Element::FE_TRIANGLE3:
						surface_load.type = fem::Element::FE_TRIANGLE3;
						state.push(49);	// SurfaceNextForce
						state.push(49);	// SurfaceNextForce
						state.push(48);	// SurfaceFirstForce

						state.push(47);	// SurfaceNextNode
						state.push(47);	// SurfaceNextNode
						state.push(46);	// SurfaceFirstNode
						break;

					case fem::Element::FE_TRIANGLE6:
						surface_load.type = fem::Element::FE_TRIANGLE6;
						state.push(49);	// SurfaceNextForce
						state.push(49);	// SurfaceNextForce
						state.push(49);	// SurfaceNextForce
						state.push(49);	// SurfaceNextForce
						state.push(49);	// SurfaceNextForce
						state.push(48);	// SurfaceFirstForce

						state.push(47);	// SurfaceNextNode
						state.push(47);	// SurfaceNextNode
						state.push(47);	// SurfaceNextNode
						state.push(47);	// SurfaceNextNode
						state.push(47);	// SurfaceNextNode
						state.push(46);	// SurfaceFirstNode
						break;

					case fem::Element::FE_QUADRANGLE4:
						surface_load.type = fem::Element::FE_QUADRANGLE4;
						state.push(49);	// SurfaceNextForce
						state.push(49);	// SurfaceNextForce
						state.push(49);	// SurfaceNextForce
						state.push(48);	// SurfaceFirstForce

						state.push(47);	// SurfaceNextNode
						state.push(47);	// SurfaceNextNode
						state.push(47);	// SurfaceNextNode
						state.push(46);	// SurfaceFirstNode
						break;

					case fem::Element::FE_QUADRANGLE8:
						surface_load.type = fem::Element::FE_QUADRANGLE8;
						state.push(49);	// SurfaceNextForce
						state.push(49);	// SurfaceNextForce
						state.push(49);	// SurfaceNextForce
						state.push(49);	// SurfaceNextForce
						state.push(49);	// SurfaceNextForce
						state.push(49);	// SurfaceNextForce
						state.push(49);	// SurfaceNextForce
						state.push(48);	// SurfaceFirstForce

						state.push(47);	// SurfaceNextNode
						state.push(47);	// SurfaceNextNode
						state.push(47);	// SurfaceNextNode
						state.push(47);	// SurfaceNextNode
						state.push(47);	// SurfaceNextNode
						state.push(47);	// SurfaceNextNode
						state.push(47);	// SurfaceNextNode
						state.push(46);	// SurfaceFirstNode
						break;

					case fem::Element::FE_QUADRANGLE9:
						surface_load.type = fem::Element::FE_QUADRANGLE8;
						state.push(49);	// SurfaceNextForce
						state.push(49);	// SurfaceNextForce
						state.push(49);	// SurfaceNextForce
						state.push(49);	// SurfaceNextForce
						state.push(49);	// SurfaceNextForce
						state.push(49);	// SurfaceNextForce
						state.push(49);	// SurfaceNextForce
						state.push(49);	// SurfaceNextForce
						state.push(48);	// SurfaceFirstForce

						state.push(47);	// SurfaceNextNode
						state.push(47);	// SurfaceNextNode
						state.push(47);	// SurfaceNextNode
						state.push(47);	// SurfaceNextNode
						state.push(47);	// SurfaceNextNode
						state.push(47);	// SurfaceNextNode
						state.push(47);	// SurfaceNextNode
						state.push(47);	// SurfaceNextNode
						state.push(46);	// SurfaceFirstNode
						break;

					default:
						std::cout << "unsupported element: " << state.
							top() << std::endl;
						goto unknown_error;
						break;
				}

				cursor.pop();	
				CURSOR_NEXT_TEST(JSON_STRING);
				CURSOR_VERIFY_TEXT("nodes");
				CURSOR_PUSH(JSON_ARRAY);
				CURSOR_PUSH(JSON_NUMBER);
				break;

			case 46:	// SurfaceFirstNode
				DECHO();

				
				surface_load.nodes.push_back(strtoul(cursor.top()->text, NULL, 0));

				state.pop();
				break;

			case 47:	// SurfaceNextNode
				DECHO();
				CURSOR_NEXT_TEST(JSON_NUMBER);

				surface_load.nodes.push_back(strtoul(cursor.top()->text, NULL, 0));

				state.pop();
				break;

			case 48:	// SurfaceFirstForce
				DECHO();
				if(cursor.top()->next != NULL)	ERROR();
				cursor.pop();	// JSON_ARRAY JSON_NUMBER
				cursor.pop();	// "nodes" JSON_ARRAY JSON_NUMBER

				CURSOR_NEXT_TEST(JSON_STRING);
				CURSOR_VERIFY_TEXT("forces");
				CURSOR_PUSH(JSON_ARRAY);

				CURSOR_PUSH(JSON_ARRAY);
				CURSOR_PUSH(JSON_NUMBER);

				
				v.x(atof(cursor.top()->text));
				CURSOR_NEXT_TEST(JSON_NUMBER);
				
				v.y(atof(cursor.top()->text));
				CURSOR_NEXT_TEST(JSON_NUMBER);
				
				v.z(atof(cursor.top()->text));

				surface_load.surface_forces.push_back(v);

				state.pop();
				break;

			case 49:	//SurfaceNextForce
				DECHO();

				cursor.pop();

				CURSOR_NEXT_TEST(JSON_ARRAY);
				CURSOR_PUSH(JSON_NUMBER);
				
				v.x(atof(cursor.top()->text));
				CURSOR_NEXT_TEST(JSON_NUMBER);
				
				v.y(atof(cursor.top()->text));
				CURSOR_NEXT_TEST(JSON_NUMBER);
				
				v.z(atof(cursor.top()->text));

				surface_load.surface_forces.push_back(v);

				state.pop();
				break;

			case 50:	// SurfaceLoadsFollow
				DECHO();
				if(cursor.top()->next != NULL) ERROR();
				cursor.pop();
				if(cursor.top()->next != NULL) ERROR();
				cursor.pop();
				cursor.pop();
				if(cursor.top()->next != NULL) ERROR();

				load_pattern.addSurfaceLoad(surface_load);
				cursor.pop();
				if(cursor.top()->next != NULL) 
				{
					CURSOR_NEXT_TEST(JSON_OBJECT);

					state.pop();

					state.push(50);	// SurfaceLoadsFollow
					state.push(45);	// SurfaceLoad
				}
				else
				{
					cursor.pop();	// JSON_ARRAY JSON_OBJECT
					cursor.pop();	// "surface loads" JSON_ARRAY JSON_OBJECT

					state.pop();
				}
				break;

			case 51:	// AfterSurfaceLoads
				DECHO();
				
				if(cursor.top()->next != NULL) ERROR();
				cursor.pop();	// JSON_OBJECT "surface loads" JSON_ARRAY

				state.pop();
				break;

			case 52:	// LoadPatternFollow
				DECHO();
				//TODO
				this->pushLoadPattern(load_pattern);

				// Test the FIRST
				if(cursor.top()->next == NULL)
				{
					state.pop();
				}
				else
				{
					CURSOR_NEXT_TEST(JSON_OBJECT);
					state.pop();

					state.push(52);	// LoadPatternFollow
					state.push(31);	// LoadPattern
				}
				break;

			default:
				std::cout << "unsupported state: " << state.top() << std::endl;
				goto unknown_error;	// common way to handle all parser errors
				break;
		}
	}

		// free memory, go home
	json_free_value(&root);
	return ERR_OK;

error:
	return ERR_PARSER;

unknown_error:		// some programming error happened
	return ERR_UNKNOWN;

	//TODO undef all macros
#undef ERROR
#undef CURSOR_PUSH
#undef CURSOR_VERIFY_TEXT
#undef CURSOR_NEXT
#undef CURSOR_NEXT_TEST
#undef CURSOR_VERIFY_LABEL_TEXT

}


void Model::text_dump() const
{
	using namespace std;

	cout << "Nodes\n";
	for(map<size_t, Node>::const_iterator i = node_list.begin(); i != node_list.end(); i++)
	{
		cout << i->first << ", " << i->second << "\n";
	}
}


}

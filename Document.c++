#include "Document.h++"

#include <QTextStream>

#include <stack>

#include "fem_msh.h++"
#include "parsers/json.h"


Document::Document()
{
    unsaved = false;
    file_name = NULL;
}


Document::Document(const Document & copied)
{
    this->unsaved = copied.unsaved;
    if (copied.file_name != NULL) {
	this->file_name = new QString;
	*this->file_name = *copied.file_name;
    }
    this->model = copied.model;
    this->document_type = copied.document_type;
}


Document::~Document()
{
    if (file_name != NULL)
	delete          file_name;
}


void
                Document::clear()
{
    unsaved = false;
    if (file_name != NULL) {
	delete file_name;
	file_name = NULL;
    }
    document_type = TYPE_NONE;
    model.clear();
}


enum Document::Error
Document::setFileName(QString new_file)
{
    if (this->file_name == NULL)
	this->file_name = new QString;
    *this->file_name = new_file;

    // check if file exists
    QFile           file;
    file.setFileName(*file_name);
    if (!file.exists()) {
	delete(this->file_name);
	this->file_name = NULL;
	return ERR_FILE_NOT_FOUND;
    }
    // TODO perform checks on the file_name

    return ERR_OK;
}


enum Document::Error Document::load()
{
	QFile           file;
	// TODO check if path exists
	if (file_name == NULL)
		return ERR_FILE_NOT_FOUND;

	file.setFileName(*file_name);
	if (!file.exists())
		return ERR_FILE_NOT_FOUND;

	// sets up all variables
	model.clear();

	// load the project files
	// file exists, now open it and parse it
	if (file.open(QIODevice::ReadOnly | QIODevice::Text) == false) {
		return ERR_FILE_OPEN;
	}
	// read the file
	json_t         *root = NULL;
	FILE           *f = fdopen(file.handle(), "r");
	switch (json_stream_parse(f, &root)) {
		case JSON_OK:
			// all went well
			break;

		default:
			return ERR_PARSER_ERROR;
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
	QString         text;

	// initializing the parser
	cursor.push(root);
	state.push(0);		// starting state

#define ERROR()	{std::cout << "State " << state.top() << std::endl; goto error;}
#define CURSOR_PUSH(TYPE) { if(cursor.top()->child == NULL) ERROR(); if (cursor.top()->child->type != TYPE) ERROR(); cursor.push(cursor.top()->child);}
#define CURSOR_VERIFY_TEXT(TEXT)	{if(cursor.top()->text == NULL) ERROR(); if(strcmp(cursor.top()->text, TEXT) != 0) ERROR();}
#define CURSOR_NEXT()	{if(cursor.top()->next == NULL) ERROR(); cursor.top() = cursor.top()->next;}
#define CURSOR_NEXT_TEST(TYPE)	{CURSOR_NEXT(); if(cursor.top()->type != TYPE) ERROR() }
#define CURSOR_VERIFY_LABEL_TEXT(LABEL, VALUE) CURSOR_VERIFY_TEXT(LABEL); CURSOR_PUSH(JSON_STRING); CURSOR_VERIFY_TEXT(VALUE); cursor.pop();

#define DECHO()	{ std::cerr << "State " << state.top() << std::endl; }


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
				this->document_type = TYPE_SOLID3D;

				// reposition the cursor
				cursor.pop();

				state.pop();

				// reposition the cursor
				break;

			case 5:		// EndHeader
				DECHO();
				cursor.pop();	
				cursor.pop();
				if (cursor.top()->next == NULL)
					ERROR();	// must have a followup field
				cursor.top() = cursor.top()->next;	
				CURSOR_VERIFY_TEXT("materials");	// header label must be
				// "fem"
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
				material.label.fromUtf8(cursor.top()->text);
				cursor.pop();

				CURSOR_NEXT();
				CURSOR_VERIFY_TEXT("E");
				CURSOR_PUSH(JSON_NUMBER);
				material.E = QString(cursor.top()->text).toDouble();
				cursor.pop();

				CURSOR_NEXT();
				CURSOR_VERIFY_TEXT("nu");
				CURSOR_PUSH(JSON_NUMBER);
				material.nu = QString(cursor.top()->text).toDouble();
				cursor.pop();

				CURSOR_NEXT();
				CURSOR_VERIFY_TEXT("fy");
				CURSOR_PUSH(JSON_NUMBER);
				material.fy = QString(cursor.top()->text).toDouble();
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
				this->model.material_list.push_back(material);

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
				text = cursor.top()->text;
				ref = text.toULongLong();

				CURSOR_NEXT();
				if (cursor.top()->type != JSON_ARRAY)
					goto error;
				state.pop();
				break;

			case 15:		// Coordinate
				DECHO();
				CURSOR_PUSH(JSON_NUMBER);

				// get the vector components
				text = cursor.top()->text;
				v.x(text.toDouble());
				CURSOR_NEXT_TEST(JSON_NUMBER);
				text = cursor.top()->text;
				v.y(text.toDouble());
				CURSOR_NEXT_TEST(JSON_NUMBER);
				text = cursor.top()->text;
				v.z(text.toDouble());

				if (cursor.top()->next != NULL)
					goto error;
				cursor.pop();

				state.pop();
				break;

			case 16:		// EndNode
				DECHO();
				// TODO finish
				model.setNode(ref, v);

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
				text = cursor.top()->text;
				element.nodes.push_back(text.toULongLong());

				state.pop();
				break;

			case 22:		// ElementNextNode
				DECHO();
				CURSOR_NEXT_TEST(JSON_NUMBER);

				text = cursor.top()->text;
				element.nodes.push_back(text.toULongLong());

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
					text = cursor.top()->text;
					model.setDefaultMaterial(text.toULongLong());
					cursor.pop();
					cursor.pop();
				}

				// push element
				model.pushElement(element);

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

				text = cursor.top()->text;
				ref = text.toULongLong();

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
						model.pushNodeRestrictions(ref, node_restrictions);

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
						model.pushNodeRestrictions(ref, node_restrictions);

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
				}

				if (cursor.top()->next != NULL)
					ERROR();

				// set the node restrictions
				model.pushNodeRestrictions(ref, node_restrictions);

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

				if (strcmp(cursor.top()->text, "load patterns") == 0) {
					CURSOR_PUSH(JSON_ARRAY);	


					state.pop();

					state.push(30);	// LoadPatterns
				} else if (strcmp(cursor.top()->text, "load combinations") ==
						0) {
					// TODO
					return ERR_OK;
				} else {
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

					state.push(39);	// DomainLoads
				} 
				else if (strcmp(cursor.top()->text, "surface loads") == 0) 
				{
					// TODO
					CURSOR_PUSH(JSON_ARRAY);	
					CURSOR_PUSH(JSON_OBJECT);	

					state.pop();

					state.push(35);	// SurfaceLoads
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

				text = cursor.top()->text;
				ref = text.toULongLong();

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
				text = cursor.top()->text;
				ref = text.toULongLong();
				cursor.pop();

				CURSOR_NEXT_TEST(JSON_STRING);


				// CURSOR_VERIFY_TEXT("node");
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
				text = cursor.top()->text;
				ref = text.toULongLong();
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

				text = cursor.top()->text;
				surface_load.node_reference.push_back(text.toULongLong());

				state.pop();
				break;

			case 47:	// SurfaceNextNode
				DECHO();
				CURSOR_NEXT_TEST(JSON_NUMBER);

				text = cursor.top()->text;
				surface_load.node_reference.push_back(text.toULongLong());

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
				text = cursor.top()->text;
				v.x(text.toDouble());
				CURSOR_NEXT_TEST(JSON_NUMBER);
				text = cursor.top()->text;
				v.y(text.toDouble());
				CURSOR_NEXT_TEST(JSON_NUMBER);
				text = cursor.top()->text;
				v.z(text.toDouble());

				surface_load.surface_forces.push_back(v);

				state.pop();
				break;

			case 49:	//SurfaceNextForce
				DECHO();

				cursor.pop();

				CURSOR_NEXT_TEST(JSON_ARRAY);
				CURSOR_PUSH(JSON_NUMBER);
				text = cursor.top()->text;
				v.x(text.toDouble());
				CURSOR_NEXT_TEST(JSON_NUMBER);
				text = cursor.top()->text;
				v.y(text.toDouble());
				CURSOR_NEXT_TEST(JSON_NUMBER);
				text = cursor.top()->text;
				v.z(text.toDouble());

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
				model.pushLoadPattern(load_pattern);

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

	unsaved = false;
	return ERR_OK;

error:
	return ERR_PARSER_ERROR;

unknown_error:		// some programming error happened
	return ERR_UNKNOWN;

	//TODO undef all macros
#undef CURSOR_PUSH
#undef CURSOR_VERIFY_TEXT
}


enum Document::Error Document::save()
{
	QFile           file;
	// TODO check version

	// check if if the given file_name exists
	if (file_name == NULL)
		return ERR_FILE_NOT_FOUND;

	file.setFileName(*file_name);

	if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) 
	{
		return ERR_WRITING_FILE;
	}
	QTextStream     out(&file);
	out << "{";
	// dump the header field
	out << "\"fem\":\n";
	out << "\t{";
	out << "\t\"version\": \"1.0\",\n";
	out << "\t\"type\": ";

	switch (document_type) 
	{
		case TYPE_SOLID3D:
			out << "\"3D solid\"\n";
			break;

		default:
			out << "\"unknown\"\n";	// this should be seen as an error
			break;
	}
	out << "\t},\n";

	// dump the materials list
	out << "\"materials\": [";
	for (std::vector < fem::Material >::iterator it =
			model.material_list.begin(); it != model.material_list.end();
			it++) {
		// to print the comman between entries and avoiding printing it
		// after the last
		if (it != model.material_list.begin())
			out << ",\n\t";
		else
			out << "\n\t";
		switch (it->type) {
			case fem::Material::MAT_LINEAR_ELASTIC:
				out << "{\"type\":" << "\"linear elastic\", \"label\": \"" <<
					it->label << "\", \"E\":" << it->E << ",\"nu\":" << it->
					nu << ", \"fy\": " << it->fy << "}";
				break;

			default:
				qWarning("defaulted while outputting");
				break;
		}
	}
	out << "\t],\n";

	// dump the nodes list
	out << "\"nodes\":[";
	for (std::map < size_t, fem::Node >::iterator it =
			model.node_list.begin(); it != model.node_list.end(); it++) {
		if (it != model.node_list.begin())
			out << ",\n\t";
		else
			out << "\n\t";
		out << "[" << it->first << ",[" << it->
			second.data[0] << "," << it->second.data[1] << "," << it->
			second.data[2] << "]]";

	}
	out << "\n\t],\n";

	// dump the elements list
	out << "\"elements\":[";
	int             material = 0;
	for (std::vector < fem::Element >::iterator it =
			model.element_list.begin(); it != model.element_list.end(); it++)
	{
		if (it != model.element_list.begin())
			out << ",\n\t";
		else
			out << "\n\t";
		out << "{\"type\":";
		// get the name of the element
		switch (it->type) {
			/*
			 * case fem::Element::FE_LINE2: out << "\"line2\", "; break;
			 * 
			 * case fem::Element::FE_TRIANGLE3: out << "\"triangle3\", ";
			 * break; 
			 */

			case fem::Element::FE_TETRAHEDRON4:
				out << "\"tetrahedron4\", ";
				break;

			case fem::Element::FE_HEXAHEDRON8:
				out << "\"hexahedron8\", ";
				break;

			case fem::Element::FE_TETRAHEDRON10:
				out << "\"tetrahedron10\", ";
				break;

				/*
				 * case fem::Element::FE_HEXAHEDRON20: out <<
				 * "\"hexahedron20\", "; break; 
				 */

			case fem::Element::FE_HEXAHEDRON20:
				out << "\"hexahedron28\", ";
				break;

			case fem::Element::FE_PRISM6:
				out << "\"prism6\", ";
				break;

			default:
				// TODO finish this
				out << "\"default\", ";
				qWarning("element defaulted");
				break;
		}
		// output the element's nodes
		out << "\"nodes\":[";
		for (std::vector < size_t >::iterator n = it->nodes.begin();
				n != it->nodes.end(); n++) {
			if (n != it->nodes.begin())
				out << ",";
			out << *n;
		}
		out << "]";
		// output the element's material
		if ((it->material != material)
				|| (it == model.element_list.begin())) {
			material = it->material;
			out << ", \"material\": " << material;
		}
		out << "}";
	}
	out << "\n\t],\n";

	// dump the load restrictions list
	out << "\"node restrictions\": [";
	for (std::map < size_t, fem::NodeRestrictions >::iterator it =
			model.node_restrictions_list.begin();
			it != model.node_restrictions_list.end(); it++) {
		// TODO test this
		if (it != model.node_restrictions_list.begin())
			out << ",";
		out << "\n\t\t";
		out << "{ \"node\":" << it->first;
		if (it->second.dx() == true)
			out << ", \"dx\":true";
		if (it->second.dy() == true)
			out << ", \"dy\":true";
		if (it->second.dz() == true)
			out << ", \"dz\":true";
		out << "}";
	}

	if(!model.load_pattern_list.empty())
	{
		out << "\n\t],\n";

		// dump the load patterns list
		out << "\"load patterns\":[";
		for (std::vector < fem::LoadPattern >::iterator it = model.load_pattern_list.begin(); it != model.load_pattern_list.end(); it++) 
		{
			if (it != model.load_pattern_list.begin())
				out << ",";
			out << "\n\t\t{";
			out << "\t\"label\": \"" << it->label << "\"";
			// take care of the nodal loads
			if (!it->nodal_loads.empty()) {
				out << ",\n\t\t";
				out << "\"nodal loads\":[";
				for (std::map < size_t, fem::NodalLoad >::iterator n =
						it->nodal_loads.begin(); n != it->nodal_loads.end(); n++)
				{
					if (n != it->nodal_loads.begin())
						out << ",";
					out << "\n\t\t\t{";
					out << "\"node\":" << n->first;
					out << ", \"force\":" << "[" << n->second.force.
						x() << ", " << n->second.force.
						y() << ", " << n->second.force.z() << "]}";
				}
				out << "\n\t\t]";
			}
			// take care of the nodal displacements
			if (!it->nodal_displacements.empty()) {
				out << ",\n\t\t";
				out << "\"node displacements\":[";
				for (std::map < size_t, fem::NodalDisplacement >::iterator n =
						it->nodal_displacements.begin();
						n != it->nodal_displacements.end(); n++) {
					if (n != it->nodal_displacements.begin())
						out << ",";
					out << "\n\t\t\t{";
					out << "\"node\":" << n->first;
					out << ", \"displacement\":" << "[" << n->
						second.displacement.data[0] << ", " << n->second.
						displacement.data[1] << ", " << n->second.
						displacement.data[2] << "]}";
				}
				out << "\n\t\t]";
			}

			// take care of the domain displacements
			if (!it->domain_loads.empty()) 
			{
				out << ",\n\t\t";
				out << "\"domain loads\":[";
				for (std::map < size_t, fem::DomainLoad >::iterator n = it->domain_loads.begin(); n != it->domain_loads.end(); n++) 
				{
					if (n != it->domain_loads.begin())
						out << ",";
					out << "\n\t\t\t{";
					out << "\"element\":" << n->first;
					out << ", ";
					out << "\"force\": [" << n->second.force.x() << "," << n-> second.force.y() << "," << n->second.force.z() << "]";
					out << "}";
				}
				out << "\n\t\t\t]\n";
			}

			// take care of the surface loads
			if (!it->surface_loads.empty())
			{
				out << ",\n\t\t";
				out << "\"surface loads\":[";
				for(std::vector<fem::SurfaceLoad>::iterator n = it->surface_loads.begin(); n != it->surface_loads.end(); n++)
				{
					if (n != it->surface_loads.begin())
						out << ",";
					out << "\n\t\t\t{";
					out << "\"type\": ";
					switch(n->type)
					{
						case fem::Element::FE_TRIANGLE3:
							out << "\"triangle3\"";
							break;

						case fem::Element::FE_TRIANGLE6:
							out << "\"triangle6\"";
							break;

						case fem::Element::FE_QUADRANGLE4:
							out << "\"quadrangle4\"";
							break;

						case fem::Element::FE_QUADRANGLE8:
							out << "\"quadrangle8\"";
							break;

						case fem::Element::FE_QUADRANGLE9:
							out << "\"quadrangle9\"";
							break;

						default:
							out << "\"unknown\"";
							break;
					}
					out << ", ";

					out << "\"nodes\": [";
					for(std::vector<size_t>::iterator i = n->node_reference.begin(); i != n->node_reference.end(); i++)
					{
						if (i != n->node_reference.begin())
							out << ",";
						out << *i;
					}
					out << "], ";
					out << "\"forces\": [";

					for(std::vector<fem::point>::iterator i = n->surface_forces.begin(); i != n->surface_forces.end(); i++)
					{
						if (i != n->surface_forces.begin())
							out << ",";
						out << "[";
						out << i->x();
						out << ",";
						out << i->y();
						out << ",";
						out << i->z();
						out << "]";
					}
					out << "]";
					out << "}";
				}
				out << "\n\t\t\t]\n";
			}

			out << "\t\t}\n";
		}
		out << "\t]\n";
	}


	/*
	// dump the load combinations list
	out << "\"combinations\":[";
	// TODO finish combinations
	out << "\t]\n";
	 */

	out << "}\n";		// final, closing bracket

	// cleanup and exit
	// TODO see KDE/ext4 row on proper unix file_name writing
	file.flush();
	file.close();

	unsaved = false;
	return ERR_OK;
}


enum Document::Error Document::importMesh(QString file_name)
{
	QFile           mesh_file;

	mesh_file.setFileName(file_name);
	if (!mesh_file.open(QIODevice::ReadOnly | QIODevice::Text)) {	// failed 
		// 
		// to 
		// open 
		// file
		return ERR_FILE_OPEN;
	}
	// TODO import mesh from a Gmsh file
	FILE           *f = fdopen(mesh_file.handle(), "r");
	fem_model_import_msh(f, model);
	mesh_file.close();

	return ERR_OK;
}


void Document::selectNode(const size_t & node)
{
	selected_nodes[node] = true;
}


void Document::deselectNode(const size_t & node)
{
	selected_nodes.erase(node);
}


void Document::deselectAll()
{
	selected_nodes.clear();
}

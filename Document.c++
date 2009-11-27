#include "Document.h++"

#include <QTextStream>

#include "parsers/json.h"


Document::Document()
{
	unsaved = false;
	file_name = NULL;
}


Document::Document(const Document &copied)
{
	this->unsaved = copied.unsaved;
	if(copied.file_name != NULL)
	{
		this->file_name = new QString;
		*this->file_name = *copied.file_name;
	}
	this->model = copied.model;
	this->document_type = copied.document_type;
}


Document::~Document()
{
	if(file_name != NULL)
		delete file_name;
}


void Document::clear()
{
	unsaved = false;
	delete file_name;
	document_type = TYPE_NONE;
	model.clear();
}


enum Document::Error Document::setFileName(QString new_file)
{
	if(this->file_name == NULL)
		this->file_name = new QString;
	*this->file_name = new_file;

	//TODO perform checks on the file_name

	return ERR_NONE;
}


enum Document::Error Document::load()
{
	QFile file;
	//TODO check if path exists
	if(file_name == NULL)
		return ERR_NONEXISTENT_FILE;

	file.setFileName(*file_name);
	if(!file.exists())
		return ERR_NONEXISTENT_FILE;

	// sets up all variables
	model.clear();

	//load the project files
	//TODO finish this 
	unsaved = false;
	return ERR_NONE;
}


enum Document::Error Document::save()
{
	QFile file;
	//TODO check version

	// check if if the given file_name exists
	if(file_name == NULL)
		return ERR_NONEXISTENT_FILE;
	qWarning("Document:save(): %s", qPrintable(*file_name));

	file.setFileName(*file_name);

	if( !file.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		return ERR_WRITING_FILE;
	}
	QTextStream out(&file);
	out << "{";
	// dump the header field
	out << "\"fem\":\n";
	out << "\t{";
	out << "\t\"version\": \"1.0\",\n";
	out << "\t\"type\": ";
	switch(document_type)
	{
		case TYPE_SOLID3D:
			out << "\"solid3d\"\n";
			break;

		default:
			out << "\"unknown\"\n";	// this should be seen as an error
			break;
	}
	out << "\t},\n";

	// dump the materials list
	out << "\"materials\": [";
	for(std::vector<fem::Material>::iterator it = model.material_list.begin(); it != model.material_list.end(); it++)
	{
		// to print the comman between entries and avoiding printing it after the last
		if(it != model.material_list.begin())
			out << ",\n\t";
		else
			out << "\n\t";
		switch(it->type)
		{
			case fem::Material::MAT_LINEAR_ELASTIC:
				out << "{\"type\":" << "\"linear elastic\", \"label\": \"" << it->label << "\", \"E\":" << it->E << ",\"nu\":" << it->nu << ", \"fy\": " << it->fy << "}";
				break;

			default:
				qWarning("defaulted while outputting");
				break;
		}
	}
	out << "\t],\n";

	// dump the nodes list
	out << "\"nodes\":[";
	for(std::map<size_t,fem::Node>::iterator it = model.node_list.begin(); it != model.node_list.end(); it++)
	{
		if(it != model.node_list.begin())
			out << ",\n\t";
		else
			out << "\n\t";
		out << "[" << it->first << ",[" << it->second.data[0] << "," << it->second.data[1] << "," << it->second.data[2] << "]]";

	}
	out << "\n\t],\n";

	// dump the elements list
	out << "\"elements\":[";
	int material = 0;
	for(std::vector<fem::Element>::iterator it = model.element_list.begin(); it != model.element_list.end(); it++)
	{
		if(it != model.element_list.begin())
			out << ",\n\t";
		else
			out << "\n\t";
		out << "{\"type\":";
		// get the name of the element
		switch(it->type)
		{
			case fem::Element::FE_LINE2:
				out << "\"line2\", ";
				break;

			case fem::Element::FE_TRIANGLE3:
				out << "\"triangle3\", ";
				break;

			case fem::Element::FE_TETRAHEDRON4:
				out << "\"tetrahedron4\", ";
				break;

			case fem::Element::FE_HEXAHEDRON8:
				out << "\"hexahedron8\", ";
				break;

			case fem::Element::FE_TETRAHEDRON10:
				out << "\"tetrahedron10\", ";
				break;

			case fem::Element::FE_HEXAHEDRON20:
				out << "\"hexahedron20\", ";
				break;

			default:
				//TODO finish this
				out << "\"default\", ";
				qWarning("element defaulted");
				break;
		}
		// output the element's nodes
		out << "\"nodes\":[";
		for(std::vector<size_t>::iterator n = it->nodes.begin(); n != it->nodes.end(); n++)
		{
			if(n != it->nodes.begin())
				out << ",";
			out << *n;
		}
		out << "]";
		// output the element's material
		if( (it->material != material) || (it == model.element_list.begin()) )
		{
			material = it->material;
			out << ", \"material\": " << material;
		}
		out << "}";
	}
	out << "\n\t],\n";

	// dump the load restrictions list
	out << "\"node restrictions\": [";
	for(std::map<size_t,fem::NodeRestrictions>::iterator it = model.node_restrictions_list.begin(); it != model.node_restrictions_list.end(); it++)
	{
		//TODO test this
		if(it != model.node_restrictions_list.begin())
			out << ",";
		out << "\n\t";
		out << "{ \"node\":" << it->first;
		/*
		out << ", displacement:[" ;
		out << (it->second.dx? "true,": "false,");
		out << (it->second.dy? "true,": "false,");
		out << (it->second.dz? "true]": "false]");
		*/
		if(it->second.dx() == true)
			out << ", \"dx\":true";
		if(it->second.dy() == true)
			out << ", \"dy\":true";
		if(it->second.dz() == true)
			out << ", \"dz\":true";
		out << "}";
	}

	out << "\n\t],\n";

	// dump the load patterns list
	out << "\"load patterns\":[";
	for(std::vector<fem::LoadPattern>::iterator it = model.load_pattern_list.begin(); it != model.load_pattern_list.end(); it++)
	{
		if(it != model.load_pattern_list.begin())
			out << ",";
		out << "\n\t{";
		out << "\t\"label\": \"" << it->label; 
		// take care of the nodal loads
		if( !it->nodal_loads.empty() )
		{
			out << "\",\n\t";
			out << "\"node loads\":[";
			for(std::map<size_t,fem::NodalLoad>::iterator n = it->nodal_loads.begin(); n != it->nodal_loads.end(); n++)
			{
				if(n != it->nodal_loads.begin())
					out << ",";
				out << "\n\t\t{";
				out << "\"node\":" << n->first;
				out << ", \"force\":" << "[" << n->second.force.x() << ", " << n->second.force.y() << ", " << n->second.force.z() << "]}";
			}
			out << "\n\t]";
		}

		// take care of the nodal displacements
		if( !it->nodal_displacements.empty() )
		{
			out << "\",\n\t";
			out << "\"node displacements\":[";
			for(std::map<size_t,fem::NodalDisplacement>::iterator n = it->nodal_displacements.begin(); n != it->nodal_displacements.end(); n++)
			{
				if(n != it->nodal_displacements.begin())
					out << ",";
				out << "\n\t\t{";
				out << "\"node\":" << n->first;
				out << ", \"displacement\":" << "[" << n->second.displacement.data[0] << ", " << n->second.displacement.data[1] << ", " << n->second.displacement.data[2] << "]}";
			}
			out << "\n\t]";
		}


		// take care of the domain displacements
		if( !it->domain_loads.empty() )
		{
			out << ",\n\t";
			out << "\"domain loads\":[";
			for(std::map<size_t,fem::DomainLoad>::iterator n = it->domain_loads.begin(); n != it->domain_loads.end(); n++)
			{
				if(n != it->domain_loads.begin())
					out << ",";
				out << "\n\t\t{";
				out << "\"node\":" << n->first;
				out << ", \"force\":" << "[" << n->second.force.data[0] << ", " << n->second.force.data[1] << ", " << n->second.force.data[2] << "]}";
			}
			out << "\n\t]";
		}

		// take care of the surface loads
		//TODO finish surface loads

		out << "}";
	}
	out << "\n\t],\n";


	// dump the load combinations list
	out << "\"combinations\":[";
	//TODO finish combinations
	out << "\t]\n";

	out << "}\n";	// final, closing bracket

	// cleanup and exit
	//TODO see KDE/ext4 row on proper unix file_name writing
	file.flush();
	file.close();

	unsaved = false;
	return ERR_NONE;
}



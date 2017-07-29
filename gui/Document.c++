#include "Document.h++"

#include <QTextStream>

#include <iostream>
#include <fstream>

#include <libfemp/Model.h++>
#include <libfemp/parsers/fem_msh.h++>
#include <libfemp/parsers/json.h>
#include <libfemp/parsers/MshParser.h++>


Document::Document()
{
	unsaved = false;
	file_name = NULL;

	document_type = TYPE_SOLID3D;	// nasty hack due to poor design
}


Document::Document(const Document & copied)
{
	this->unsaved = copied.unsaved;
	if (copied.file_name != NULL) {
		this->file_name = new QString;
		*this->file_name = *copied.file_name;
	}
	else
	{
		this->file_name = NULL;
	}
	this->document_type = copied.document_type;
}


Document::~Document()
{
	if (file_name != NULL)
		delete file_name;
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
	this->project.clear();
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


QString
Document::getFileName() const
{
	if(this->file_name == NULL)
	{
		return QString();
	}
	else
	{
		return *this->file_name;
	}
}


enum Document::Error 
Document::save()
{
	//TODO drop support for Qt's text stream objects in favour of standard containers

	QFile           file;
	fem::Model &model = this->project.getModel();

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
	out << "{\n";
	// dump the header field
	out << "\t\"fem\": {\n";
	out << "\t\t\"version\": \"1.0\",\n";
	out << "\t\t\"type\": ";

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
	out << "\t\"materials\": [";
	for (std::vector < fem::Material >::iterator it = model.material_list.begin(); it != model.material_list.end(); it++) 
	{
		// to print the comman between entries and avoiding printing it
		// after the last
		if (it != model.material_list.begin())
			out << ",\n\t";
		else
			out << "\n\t";
		switch (it->type) {
			case fem::Material::MAT_LINEAR_ELASTIC:
				out << "\t{\"type\":" << "\"linear elastic\", \"label\": \"" << QString::fromStdString(it->label) << "\", \"E\":" << it->E << ",\"nu\":" << it-> nu << ", \"fy\": " << it->fy << "}";
				break;

			default:
				qWarning("defaulted while outputting");
				break;
		}
	}
	out << "\n\t],\n";

	// dump the nodes list
	out << "\t\"nodes\":[";
	for (std::map < fem::node_ref_t, fem::Node >::iterator it = model.node_list.begin(); it != model.node_list.end(); it++) 
	{
		if (it != model.node_list.begin())
			out << ",\n\t";
		else
			out << "\n\t";
		out << "\t[\t" << it->first << ",[\t" << it-> second.data[0] << ",\t" << it->second.data[1] << ",\t" << it-> second.data[2] << "\t]]";

	}
	out << "\n\t],\n";

	// dump the elements list
	out << "\t\"elements\":[";
	fem::material_ref_t material = 0;
	for (std::vector < fem::Element >::iterator it = model.element_list.begin(); it != model.element_list.end(); it++)
	{
		if (it != model.element_list.begin())
			out << ",\n\t\t";
		else
			out << "\n\t\t";
		out << "{\"type\":";
		// get the name of the element
		switch (it->type) 
		{
			case fem::Element::FE_TETRAHEDRON4:
				out << "\"tetrahedron4\", ";
				break;

			case fem::Element::FE_TETRAHEDRON10:
				out << "\"tetrahedron10\", ";
				break;

			case fem::Element::FE_HEXAHEDRON8:
				out << "\"hexahedron8\", ";
				break;

			case fem::Element::FE_HEXAHEDRON20: 
				out << "\"hexahedron20\", "; 
				break; 

			case fem::Element::FE_HEXAHEDRON27:
				out << "\"hexahedron27\", ";
				break;

			case fem::Element::FE_PRISM6:
				out << "\"prism6\", ";
				break;

			case fem::Element::FE_PRISM15:
				out << "\"prism15\", ";
				break;

			case fem::Element::FE_PRISM18:
				out << "\"prism18\", ";
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
	out << "\n\t]";

	if(model.m_node_groups.size() > 0 && model.m_node_groups.size() > 0 )
	{
		out << ",\n";
		out << "\n\t";
		out << "\"groups\": {";
		if(model.m_node_groups.size() > 0)
		{
			// output node groups
			out << "\n\t\t";
			out << "\"nodes\": [";
			out << "\n\t\t\t";

			for(std::vector<fem::NodeGroup>::iterator n = model.m_node_groups.begin(); n != model.m_node_groups.end(); ++n)
			{
				out << "{";
				out << "\n\t\t\t\t";
				out << "\"label\": \"" << QString::fromStdString(n->label) << "\",";
				out << "\n\t\t\t\t";
				out << "\"nodes\": [";
				fem::NodeGroup::const_iterator i = n->begin();
				out << *i;
				++i;
				for(; i != n->end(); i++)
				{
					out << "," << *i;
				}
				out << "]";
				out << "\n\t\t\t";
				out << "}";
				out << "\n\t\t\t";
			}

			// iterate each group
			out << "\n\t\t";
			out << "]";
			if(model.m_element_groups.size() > 0)
				out << ",";
		}

		if(model.m_element_groups.size() > 0)
		{
			// output element groups
			out << "\n\t\t";
			out << "\"elements\": [";
			out << "\n\t\t\t";

			for(std::vector<fem::ElementGroup>::iterator n = model.m_element_groups.begin(); n != model.m_element_groups.end(); ++n)
			{
				out << "{";
				out << "\n\t\t\t\t";
				out << "\"label\": \"" << QString::fromStdString(n->label) << "\",";
				out << "\n\t\t\t\t";
				out << "\"nodes\": [";
				fem::ElementGroup::const_iterator i = n->begin();
				out << *i;
				++i;
				for(; i != n->end(); i++)
				{
					out << "," << *i;
				}
				out << "]";
				out << "\n\t\t\t";
				out << "}";
				out << "\n\t\t\t";
			}

			// iterate each group
			out << "\n\t\t";
			out << "]";
		}
		out << "\n\t";
		out << "}";

	}

	if(!model.node_restrictions_list.empty())
	{
		out << ",\n\n";
		// dump the load restrictions list
		out << "\t\"node restrictions\": [";
		for (std::map < fem::node_restriction_ref_t, fem::NodeRestrictions >::iterator it = model.node_restrictions_list.begin(); it != model.node_restrictions_list.end(); it++) 
		{
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
		out << "\n\t]";
	}

	if(!model.load_pattern_list.empty())
	{
		out << ",\n\n";

		// dump the load patterns list
		out << "\t\"load patterns\":[";
		for (std::vector < fem::LoadPattern >::iterator it = model.load_pattern_list.begin(); it != model.load_pattern_list.end(); it++) 
		{
			if (it != model.load_pattern_list.begin())
				out << ",";
			out << "\n\t\t{";
			out << "\n\t\t\t";
			out << "\"label\": \"" << QString::fromStdString(it->label) << "\"";
			// take care of the nodal loads
			if (!it->nodal_loads.empty()) {
				out << ",\n\t\t\t";
				out << "\"nodal loads\":[\n";
				for (std::map < size_t, fem::NodalLoad >::iterator n = it->nodal_loads.begin(); n != it->nodal_loads.end(); n++)
				{
					if (n != it->nodal_loads.begin())
						out << ",\n";
					out << "\t\t\t\t{";
					out << "\"node\":" << n->first;
					out << ", \"force\":" << "[" << n->second.force.  x() << ", " << n->second.force.  y() << ", " << n->second.force.z() << "]}";
				}
				out << "\n\t\t\t]\n";
			}

			/*
			//TODO rethink the NodeDisplacement class

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
					out << ", \"displacement\":" << "[" << n-> second.displacement.data[0] << ", " << n->second.  displacement.data[1] << ", " << n->second.  displacement.data[2] << "]}";
				}
				out << "\n\t\t]";
			}
			*/

			// take care of the domain displacements
			if (!it->domain_loads.empty()) 
			{
				out << ",\n\t\t\t";
				out << "\"domain loads\":[";
				for (std::map < size_t, fem::DomainLoad >::iterator n = it->domain_loads.begin(); n != it->domain_loads.end(); n++) 
				{
					if (n != it->domain_loads.begin())
						out << ",";
					out << "\n\t\t\t\t{";
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
				out << ",\n\t\t\t";
				out << "\"surface loads\":[";
				for(std::vector<fem::SurfaceLoad>::iterator n = it->surface_loads.begin(); n != it->surface_loads.end(); n++)
				{
					if (n != it->surface_loads.begin())
						out << ",";
					out << "\n\t\t\t\t{";
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
					for(std::vector<size_t>::iterator i = n->nodes.begin(); i != n->nodes.end(); i++)
					{
						if (i != n->nodes.begin())
							out << ",";
						out << *i;
					}
					out << "], ";
					out << "\"forces\": [";

					for(std::vector<fem::Point>::iterator i = n->surface_forces.begin(); i != n->surface_forces.end(); i++)
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

	out << "\n}\n";		// final, closing bracket

	// cleanup and exit
	// TODO see KDE/ext4 row on proper unix file_name writing
	file.flush();
	file.close();

	unsaved = false;
	return ERR_OK;
}



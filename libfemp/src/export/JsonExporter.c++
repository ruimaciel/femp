#include <libfemp/export/JsonExporter.h++>

void JsonExporter::output(std::ostream& out, const fem::Model& model)
{
    out << "{\n";

    // dump the header field
    out << "\t\"fem\": {\n";
    out << "\t\t\"version\": \"1.0\",\n";
    out << "\t\t\"type\": \"3D solid\"\n";

    out << "\t},\n";

    // dump the materials list
    out << "\t\"materials\": [";
    auto material_list = model.getMaterialList();

    for (std::vector<fem::Material>::const_iterator material = material_list.begin(); material != material_list.end(); material++) {
        // to print the comman between entries and avoiding printing it
        // after the last
        if (material != material_list.begin()) {
            out << ",";
        }
        out << "\n\t";

        out << "\t{\"type\":"
            << "\"linear elastic\", \"label\": \"" << material->getLabel() << "\", \"E\":" << material->getYoungsModulus() << ",\"nu\":" << material->getPoissonRatio() << "}";
    }
    out << "\n\t],\n";

    // dump the nodes list
    out << "\t\"nodes\":[";
    auto node_list = model.getNodeMap();
    for (std::map<fem::node_ref_t, fem::Node>::const_iterator it = node_list.begin(); it != node_list.end(); it++) {
        if (it != node_list.begin()) {
            out << ",";
        }
        out << "\n\t";
        out << "\t[\t" << it->first << ",[\t" << it->second.data[0] << ",\t" << it->second.data[1] << ",\t" << it->second.data[2] << "\t]]";
    }
    out << "\n\t],\n";

    // dump the elements list
    out << "\t\"elements\":[";
    fem::material_ref_t material = 0;
    auto element_list = model.getElementList();
    for (std::vector<fem::Element>::const_iterator element = element_list.begin(); element != element_list.end(); element++) {
        if (element != model.element_list.begin()) {
            out << ",";
        }
        out << "\n\t\t";
        out << "{\"type\":";
        // get the name of the element
        switch (element->type) {
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
            //			qWarning("element defaulted");
            break;
        }

        // output the element's nodes
        out << "\"nodes\":[";
        for (std::vector<size_t>::const_iterator n = element->nodes.begin();
             n != element->nodes.end(); n++) {
            if (n != element->nodes.begin())
                out << ",";
            out << *n;
        }

        out << "]";
        // output the element's material
        if ((element->material != material)
            || (element == model.element_list.begin())) {
            material = element->material;
            out << ", \"material\": " << material;
        }
        out << "}";
    }
    out << "\n\t]";

    //TODO refactor this part
    auto node_groups = model.getNodeGroups();
    auto element_groups = model.getElementGroups();
    if (node_groups.size() > 0) {
        out << ",\n";
        out << "\n\t";
        out << "\"groups\": {";
        auto node_groups = model.getNodeGroups();
        if (node_groups.size() > 0) {
            // output node groups
            out << "\n\t\t";
            out << "\"nodes\": [";
            out << "\n\t\t\t";

            for (auto node_group : node_groups) {
                out << "{";
                out << "\n\t\t\t\t";
                out << "\"label\": \"" << node_group.getLabel() << "\",";
                out << "\n\t\t\t\t";
                out << "\"nodes\": [";
                fem::NodeGroup::const_iterator i = node_group.begin();
                out << *i;
                ++i;
                for (; i != node_group.end(); i++) {
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
            if (element_groups.size() > 0)
                out << ",";
        }

        if (element_groups.size() > 0) {
            // output element groups
            out << "\n\t\t";
            out << "\"elements\": [";
            out << "\n\t\t\t";

            for (auto element_group : element_groups) {
                out << "{";
                out << "\n\t\t\t\t";
                out << "\"label\": \"" << element_group.getLabel() << "\",";
                out << "\n\t\t\t\t";
                out << "\"nodes\": [";
                fem::ElementGroup::const_iterator i = element_group.begin();
                out << *i;
                ++i;
                for (; i != element_group.end(); i++) {
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

    if (!model.node_restrictions_list.empty()) {
        out << ",\n\n";
        // dump the load restrictions list
        out << "\t\"node restrictions\": [";
        auto node_restrictions_list = model.getNodeRestrictions();
        for (std::map<fem::node_restriction_ref_t, fem::NodeRestrictions>::const_iterator it = node_restrictions_list.begin(); it != node_restrictions_list.end(); it++) {
            // TODO test this
            if (it != node_restrictions_list.begin())
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

    if (!model.load_pattern_list.empty()) {
        out << ",\n\n";

        // dump the load patterns list
        out << "\t\"load patterns\":[";
        for (std::vector<fem::LoadPattern>::const_iterator it = model.load_pattern_list.begin(); it != model.load_pattern_list.end(); it++) {
            if (it != model.load_pattern_list.begin())
                out << ",";
            out << "\n\t\t{";
            out << "\n\t\t\t";
            out << "\"label\": \"" << it->getLabel() << "\"";
            // take care of the nodal loads
            if (!it->nodal_loads.empty()) {
                out << ",\n\t\t\t";
                out << "\"nodal loads\":[\n";
                for (std::map<size_t, fem::NodalLoad>::const_iterator n = it->nodal_loads.begin(); n != it->nodal_loads.end(); n++) {
                    if (n != it->nodal_loads.begin())
                        out << ",\n";
                    out << "\t\t\t\t{";
                    out << "\"node\":" << n->first;
                    out << ", \"force\":"
                        << "[" << n->second.force.x() << ", " << n->second.force.y() << ", " << n->second.force.z() << "]}";
                }
                out << "\n\t\t\t]\n";
            }

            // take care of the domain displacements
            if (!it->domain_loads.empty()) {
                out << ",\n\t\t\t";
                out << "\"domain loads\":[";
                for (std::map<size_t, fem::DomainLoad>::const_iterator n = it->domain_loads.begin(); n != it->domain_loads.end(); n++) {
                    if (n != it->domain_loads.begin())
                        out << ",";
                    out << "\n\t\t\t\t{";
                    out << "\"element\":" << n->first;
                    out << ", ";
                    out << "\"force\": [" << n->second.force.x() << "," << n->second.force.y() << "," << n->second.force.z() << "]";
                    out << "}";
                }
                out << "\n\t\t\t]\n";
            }

            // take care of the surface loads
            if (!it->surface_loads.empty()) {
                out << ",\n\t\t\t";
                out << "\"surface loads\":[";
                for (std::vector<fem::SurfaceLoad*>::const_iterator surface_load_iter = it->surface_loads.begin(); surface_load_iter != it->surface_loads.end(); surface_load_iter++) {
                    if (surface_load_iter != it->surface_loads.begin())
                        out << ",";

                    fem::SurfaceLoad* surface_load = *surface_load_iter;

                    out << "\n\t\t\t\t{";
                    out << "\"type\": ";
                    switch (surface_load->type) {
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

                    auto surface_load_nodes = surface_load->getNodeReferences();
                    for (std::vector<size_t>::const_iterator i = surface_load_nodes.begin(); i != surface_load_nodes.end(); i++) {
                        if (i != surface_load_nodes.begin())
                            out << ",";
                        out << *i;
                    }
                    out << "], ";
                    out << "\"forces\": [";

                    for (std::vector<fem::Point3D>::const_iterator i = surface_load->surface_forces.begin(); i != surface_load->surface_forces.end(); i++) {
                        if (i != surface_load->surface_forces.begin())
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

    out << "\n}\n"; // final, closing bracket
}

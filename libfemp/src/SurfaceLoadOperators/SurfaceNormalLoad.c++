#include <iostream>
#include <libfemp/Point3D.h++>
#include <libfemp/SurfaceLoadOperators/SurfaceNormalLoad.h++>
#include <libfemp/elements/BaseElement.h++>
#include <libfemp/loads/Quadrangle4.h++>
#include <libfemp/loads/Quadrangle8.h++>
#include <libfemp/loads/Quadrangle9.h++>
#include <libfemp/loads/Triangle3.h++>
#include <libfemp/loads/Triangle6.h++>

namespace fem {

SurfaceNormalLoad::SurfaceNormalLoad() { this->m_magnitude = 1.0f; }

void SurfaceNormalLoad::setLoadMagnitude(float const& magnitude) { this->m_magnitude = magnitude; }

void SurfaceNormalLoad::operator()(fem::SurfaceLoad& surface_load, fem::Model& model) {
	fem::SurfaceLoad* load = nullptr;  // used to store a pointer to the current object: nasty hack due
									   // to the way fem::Element was done

	fem::Triangle3 m_tri3;
	fem::Triangle6 m_tri6;
	fem::Quadrangle4 m_quad4;
	fem::Quadrangle8 m_quad8;
	fem::Quadrangle9 m_quad9;

	// set the element
	switch (surface_load.getType()) {
		case Element::FE_TRIANGLE3:
			load = &m_tri3;
			surface_load.surface_forces.resize(3);
			break;

		case Element::FE_TRIANGLE6:
			load = &m_tri6;
			surface_load.surface_forces.resize(6);
			break;

		case Element::FE_QUADRANGLE4:
			load = &m_quad4;
			surface_load.surface_forces.resize(4);
			break;

		case Element::FE_QUADRANGLE8:
			load = &m_quad8;
			surface_load.surface_forces.resize(8);
			break;

		case Element::FE_QUADRANGLE9:
			load = &m_quad9;
			surface_load.surface_forces.resize(9);
			break;

		default:  // if this part was reached then something is broken
			std::cerr << "SurfaceNormalLoad(): invalid surface load type" << std::endl;
			return;
			break;
	}

	/**
		for each node that defines the surface, define a normal vector and
		set the force accordingly
		**/
	using namespace std;
	auto coordinates = load->getLocalCoordinates();
	for (unsigned int i = 0; i < surface_load.getNodeAmount(); i++) {
		cout << "node " << i << " at " << coordinates[i] << "\n";

		auto dNdcsi = load->getdNdcsi(coordinates[i]);
		auto dNdeta = load->getdNdeta(coordinates[i]);

		fem::Point3D dPdcsi, dPdeta;
		dPdcsi.zero();
		dPdeta.zero();

		for (unsigned int n = 0; n < surface_load.getNodeAmount(); n++) {
			const fem::Point3D p = model.getNode(surface_load.getNode(n));
			cout << "Point : " << p << "\n";
			dPdcsi += dNdcsi[n] * p;
			dPdeta += dNdeta[n] * p;
		}

		fem::Point3D f = cross_product(dPdcsi, dPdeta);
		cout << "cross( " << dPdcsi << "," << dPdeta << ")\n";

		f.normalize();
		f *= m_magnitude;

		// set the force
		surface_load.surface_forces[i] = f;

		cout << "force: " << f << endl;
	}
}

}  // namespace fem

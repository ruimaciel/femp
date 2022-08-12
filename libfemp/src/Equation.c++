#include <libfemp/Equation.h++>

namespace fem {

Equation::Equation() {}

size_t Equation::size() const { return f.size(); }

void Equation::setProblemSize(size_t size) {
	f.resize(size);
	d.resize(size);
	K.resize(size, size);
}

}  // namespace fem

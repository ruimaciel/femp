#ifndef FEMP_GLOBALDOF_HPP
#define FEMP_GLOBALDOF_HPP

// libfemp includes
#include <libfemp/Node.h++>

namespace fem {

enum class ParameterType { dx, dy, dz };

/**
 * Data type that represents a global degree-of-freedom (DoF)
 */
class GlobalDof {
	protected:
	Node m_node;
	ParameterType m_parameter_type;

	public:
	GlobalDof(Node const& node, ParameterType& parameter_type);

	/**
	 * Returns the node associated with this GlobalDof
	 */
	Node getNode() const;

	/**
	 * Returns the parameter type that defines this GlobalDof
	 */
	ParameterType getParameterType() const;

	/**
	 * Coppy assignment operator
	 */
	GlobalDof& operator=(const GlobalDof& copied);

	/**
	 * Relational order operator
	 */
	friend bool operator==(const GlobalDof& lhs, const GlobalDof& rhs);
	friend bool operator!=(const GlobalDof& lhs, const GlobalDof& rhs);
	friend bool operator<(const GlobalDof& lhs, const GlobalDof& rhs);
};

}  // namespace fem

#endif

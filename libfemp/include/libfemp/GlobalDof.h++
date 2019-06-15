#ifndef FEMP_GLOBAL_DOF_HPP
#define FEMP_GLOBAL_DOF_HPP

#include <libfemp/Node.h++>

namespace fem {

enum class ParameterType {
    dx,
    dy,
    dz
};

/**
 * Data type that represents a global degree-of-freedom (DoF)
 **/
class GlobalDof {
protected:
    Node m_node;
    ParameterType m_parameter_type;

public:
    GlobalDof(Node const& node, ParameterType& parameter_type);

    /**
	 * returns the node associated with this GlobalDof
	 **/
    Node getNode() const;

    /** 
	 * returns the parameter type that defines this GlobalDof
	 **/
    ParameterType getParameterType() const;

    /**
	 * Coppy assignment operator
	 **/
    GlobalDof& operator=(const GlobalDof& copied);

    /**
	 * Relational order operator
	 **/
    friend bool operator==(const GlobalDof& lhs, const GlobalDof& rhs);
    friend bool operator!=(const GlobalDof& lhs, const GlobalDof& rhs);
    friend bool operator<(const GlobalDof& lhs, const GlobalDof& rhs);
};

} // namespace fem

#endif

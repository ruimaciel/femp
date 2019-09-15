#ifndef FEMP_NODE_RESTRICTIONS_HPP
#define FEMP_NODE_RESTRICTIONS_HPP

namespace fem {

using node_restriction_ref_t = unsigned int;

/**
 * Prescribes a zero displacement on a degree of freedom
 */
class NodeRestrictions {
public:
    NodeRestrictions();
    NodeRestrictions(const NodeRestrictions&);

    void setdx();
    void setdy();
    void setdz();

    bool dx() const;
    bool dy() const;
    bool dz() const;

    /**
     * Returns true if there isn't a restriction set
     */
    bool free() const;

    void reset();

private:
    bool m_dof[3]; // specifies the node displacement restrictions along the XX, YY and ZZ axis
};

} // namespace fem

#endif

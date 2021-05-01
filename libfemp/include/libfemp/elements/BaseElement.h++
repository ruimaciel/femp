#ifndef FEMP_BASE_ELEMENT_HPP
#define FEMP_BASE_ELEMENT_HPP

#include <boost/tuple/tuple.hpp>
#include <cmath>
#include <map>
#include <vector>

#include <Eigen/Sparse>

#include <libfemp/Material.h++>
#include <libfemp/Node.h++>
#include <libfemp/Point3D.h++>

namespace fem {

class Model; // forward declaration

/**
 * Base class for all classes which are used to describe specific FEM element types
 */
class BaseElement {
public:
    using MatrixDataType = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>;

    /**
     * introduced to facilitate merging BaseElement with Element. remove this
    */
    enum ElementFamily {
        EF_TRIANGLE = 0,
        EF_QUADRILATERAL = 1,
        EF_TETRAHEDRON = 2,
        EF_PRISM = 3,
        EF_PYRAMID = 4,
        EF_HEXAHEDRON = 5,
        EF_INVALID
    };

public: // WARNING: deprecated. to be removed.
    std::map<int, std::vector<boost::tuple<fem::Point3D, double>>> ipwpl; // integration points/weights pair list

protected:
    std::vector<fem::Point3D> coordinates;
    material_ref_t m_material; // reference to a material in Model's material map

public: // merging with fem::Element
    std::vector<node_ref_t> nodes; // nodes that define this element

public:
    virtual ~BaseElement();

    material_ref_t getMaterialRef() const;

    /**
     * Returns the total number of degrees of freedom
     */
    virtual unsigned int getDofAmount() const = 0;

    /**
     * return the number of nodes that an element of this particular type has
     * @return	the number of nodes
     */
    virtual int getNodeAmount() const = 0;

    /**
     * return a vector with the value of each basis function evaluated at a point
     **/
    virtual std::vector<double> getN(const Point3D& p) = 0;

    /**
     * return a vector with the value of the derivative of each basis function wrt csi evaluated at a point
     * @param p a point
     * @return vector with dN/dcsi values
     */
    virtual std::vector<double> getdNdcsi(const Point3D& p) = 0;

    /**
     * return a vector with the value of the derivative of each basis function wrt eta evaluated at a point
     * @param p a point
     * @return vector with dN/deta values
     */
    virtual std::vector<double> getdNdeta(const Point3D& p) = 0;

    /**
     * return a vector with the value of the derivative of each basis function wrt zeta evaluated at a point
     * @param p a point
     * @return vector with dN/dzeta values
     */
    virtual std::vector<double> getdNdzeta(const Point3D& p) = 0;

    /**
     * Returns the element's stiffness matrix
     * @param model a fem::Model object
     * @return stiffness matrix
     */
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> getStiffnessMatrix(fem::Model& model);

    /**
     * Returns a vector with the reference IDs of all nodes associated with the element
     */
    virtual std::vector<size_t> getNodeReferences() const;

    virtual std::vector<fem::Point3D> getLocalCoordinates() = 0;

public: //WARNING: BaseElement member functions are deprecated
    /**
     * Returns a list of quadrature rules
     */
    virtual std::vector<boost::tuple<fem::Point3D, double>> getStiffnessQuadratureRule() = 0;
    virtual std::vector<boost::tuple<fem::Point3D, double>> getDomainQuadratureRule() = 0;

protected:
    Eigen::Matrix<double, 6, 6> generateConstitutiveRelationsMatrix(const Material& material) const;

protected: // WARNING: to be removed
    /**
     * Gauss-Legendre integration function, gauleg, from "Numerical Recipes in C"
     * (Cambridge Univ. Press) by W.H. Press, S.A. Teukolsky, W.double. Vetterling, and
     * B.P. Flannery
     * @param x	array of double, stores the abcissa of the integration Point
     * @param w	array of double, stores the weights of the integration points
     * @param n	the number of Gauss points
     */
    void gauleg(double x[], double w[], int n);
};

} // namespace fem

#endif

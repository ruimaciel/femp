#include <libfemp/Material.h++>

namespace fem {

Material::Material(std::string label, double youngsModulus, double poissonRatio)
    : m_label(label)
    , m_E(youngsModulus)
    , m_nu(poissonRatio)
{
}

std::string Material::getLabel() const
{
    return m_label;
}

double Material::getYoungsModulus() const
{
    return m_E;
}

double Material::getPoissonRatio() const
{
    return m_nu;
}

} // namespace fem

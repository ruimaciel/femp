#include <libfemp/ElementResults/ElementResults.h++>

namespace fem {

void ElementResults::resize(unsigned int size)
{
    stresses.resize(size);
    strains.resize(size);
    von_mises.resize(size);
}

std::ostream&
operator<<(std::ostream& os, ElementResults const& element_results)
{
    os << "\t strain:\n";

    for (const Strains<double> i : element_results.strains) {
        os << "\t\te_11: " << i.e11;
        os << "\te_22: " << i.e22;
        os << "\te_33: " << i.e33;
        os << "\te_12: " << i.e12;
        os << "\te_23: " << i.e23;
        os << "\te_13: " << i.e13;
        os << "\n";
    }
    os << "\t stress:\n";

    for (const Stresses<double> i : element_results.stresses) {
        os << "\t\ts_11: " << i.s11;
        os << "\ts_22: " << i.s22;
        os << "\ts_33: " << i.s33;
        os << "\ts_12: " << i.s12;
        os << "\ts_23: " << i.s23;
        os << "\ts_13: " << i.s13;
        os << "\n";
    }
    os << "\t von mises:\n";

    for (double i : element_results.von_mises) {
        os << "\t\tv: " << i;
        os << "\n";
    }

    // code useful for debugging: remove later
    os << "\t eigen stuff\n";
    for (int i = 0; i < 3; i++) {
        os << "\t\teve" << i << " = [";
        os << element_results.eig_vec[0][i] << ", " << element_results.eig_vec[1][i] << ", " << element_results.eig_vec[2][i] << "]', ";
        os << "eva" << i << " = ";
        os << element_results.eig_val[i] << "\n";
    }

    os << "T = [";
    os << element_results.stresses[4].s11 << " " << element_results.stresses[4].s12 << " " << element_results.stresses[4].s13 << ";\n";
    os << element_results.stresses[4].s12 << " " << element_results.stresses[4].s22 << " " << element_results.stresses[4].s23 << ";\n";
    os << element_results.stresses[4].s13 << " " << element_results.stresses[4].s23 << " " << element_results.stresses[4].s33 << "]\n";

    os << std::endl;
    return os;
}

} // fem

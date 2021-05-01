#ifndef LIBLA_OUTPUT_HPP
#define LIBLA_OUTPUT_HPP

#include <iostream>

namespace lalib {

#ifdef LIBLA_MATRIX_DENSE_STATIC_HPP

template <typename scalar, size_t t_rows, size_t t_columns>
std::ostream& operator<<(std::ostream& out, DenseStaticMatrix<scalar, t_rows, t_columns> m)
{
    using namespace std;

    for (size_t i = 0; i < t_rows; i++) {
        out << "[\t" << m.value(i, 0);
        for (size_t j = 1; j < t_columns; j++) {
            out << ",\t" << m.value(i, j);
        }
        out << "]" << endl;
    }
    return out;
}

#endif

#ifdef LIBLA_MATRIX_HPP
template <typename scalar, template <typename> class MatrixStoragePolicy>
std::ostream& operator<<(std::ostream& out, Matrix<scalar, MatrixStoragePolicy>& m)
{
    using namespace std;

    for (size_t i = 0; i < m.rows(); i++) {
        out << "[\t" << m.value(i, 0);
        for (size_t j = 1; j < m.columns(); j++) {
            out << ",\t" << m.value(i, j);
        }
        out << "]" << endl;
    }
    return out;
}

template <typename scalar, template <typename> class MatrixStoragePolicy>
void dump_octave(std::ostream& out, std::string name, Matrix<scalar, MatrixStoragePolicy>& m)
{
    using namespace std;

    out << "# Created by lalib\n";
    out << "# name: " << name << "\n";
    out << "# type: matrix\n";
    out << "# rows: " << m.rows() << "\n";
    out << "# columns: " << m.columns() << "\n";

    for (size_t j = 0; j < m.columns(); j++) {
        for (size_t i = 0; i < m.rows(); i++) {
            out << " " << m.value(i, j);
        }
        out << "\n";
    }
    out << endl;
}

template <typename scalar, template <typename> class VectorStoragePolicy>
void dump_octave(std::ostream& out, std::string name, Vector<scalar, VectorStoragePolicy>& v)
{
    using namespace std;

    out << "# Created by lalib\n";
    out << "# name: " << name << "\n";
    out << "# type: matrix\n";
    out << "# rows: " << v.size() << "\n";
    out << "# columns: 1\n";
    for (size_t i = 0; i < v.size(); i++) {
        out << " " << v.value(i) << "\n";
    }
    out << endl;
}

#endif

#ifdef LIBLA_VECTOR_HPP
template <typename scalar, template <typename> class VectorStoragePolicy>
std::ostream& operator<<(std::ostream& out, Vector<scalar, VectorStoragePolicy> v)
{
    using namespace std;

    for (size_t i = 0; i < v.size(); i++) {
        out << "[\t" << v.value(i) << "\t]" << endl;
    }
    return out;
}

#endif
}

#endif

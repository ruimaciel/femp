#ifndef LALIB_MATRIX_STORAGE_POLICY_SPARSE_CRS_HPP
#define LALIB_MATRIX_STORAGE_POLICY_SPARSE_CRS_HPP

#include <assert.h>
#include <iostream> // debug only
#include <vector>

namespace lalib {

/**
SparseCRS: a storage policy class for the Matrix host class.
This class implements the interface for the sparse Compressed Row Storage (CRS) sparse matrix format
http://netlib.org/linalg/html_templates/node91.html#SECTION00931100000000000000
**/
template <typename scalar>
class SparseCRS {
public:
    struct Data {
        size_t t_columns; // number of columns

        std::vector<scalar> values;
        std::vector<size_t> column_index;
        std::vector<size_t> row_pointer;
    } data;

public:
    SparseCRS(const size_t rows = 0, const size_t columns = 0);
    ~SparseCRS(){};

    size_t rows() { return data.row_pointer.size() - 1; };
    size_t columns() { return data.t_columns; };

    /*
		Returns the value in [row,column] 
		*/
    scalar value(const size_t row, const size_t column);

    scalar& operator()(const size_t row, const size_t column);

    void resize(const size_t row, const size_t column);

    void dump();
};

template <typename scalar>
SparseCRS<scalar>::SparseCRS(const size_t rows, const size_t columns)
{
    resize(rows, columns);

    //TESTING CODE
    /*
	data.values.resize(12);
	data.column_index.resize(12);
	data.row_pointer.resize(5);

	scalar Ax [ ] = { 2., 3., 3., -1., 4., 4., -3., 1., 2., 2., 6., 1.} ;
	size_t Ai [ ] = { 0, 1, 0, 2, 4, 1, 2, 3, 4, 2, 1, 4} ;
	size_t Ap [ ] = { 0, 2, 5, 9, 10, 12} ;

	for(int i = 0; i < 5; i++)
		data.row_pointer[i] = Ap[i];
	for(int i = 0; i < 12; i++)
	{
		data.column_index[i] = Ai[i];
		data.values[i] = Ax[i];
	}

	data.t_columns = 5;
	// */
}

template <typename scalar>
scalar SparseCRS<scalar>::value(const size_t row, const size_t column)
{
    using namespace std;

    assert(row < this->rows());
    assert(column < this->columns());

    size_t i = data.row_pointer[row];

    if (column == data.column_index[i])
        return data.values[i];

    if (column < data.column_index[i])
        return 0;

    for (i = data.row_pointer[row]; i < data.row_pointer[row + 1]; i++) {
        if (data.column_index[i] < column)
            continue;

        if (data.column_index[i] == column)
            return data.values[i];

        break;
    }
    return 0;
}

template <typename scalar>
scalar& SparseCRS<scalar>::operator()(const size_t row, const size_t column)
{
    //TODO finish this
    using namespace std;

    assert(row < this->rows());
    assert(column < this->columns());

    if (column == data.column_index[data.row_pointer[row]])
        return data.values[data.row_pointer[row]];

    // the first element in this row has a greater column index than the one being referenced
    if (data.column_index[data.row_pointer[row]] > column) {
        vector<size_t>::iterator col = data.column_index.begin();
        advance(col, data.row_pointer[row]);
        data.column_index.insert(col, column);

        typename vector<scalar>::iterator val = data.values.begin();
        advance(val, data.row_pointer[row]);
        data.values.insert(val, 9);

        for (size_t i = row + 1; i < data.row_pointer.size(); i++) {
            data.row_pointer[i]++;
        }

        return data.values[data.row_pointer[row]];
    }

    // the first element in this row has an inferior column index.  Search for the first superior instance, insert a new element and reference it
    size_t j;
    for (j = data.row_pointer[row]; j < data.row_pointer[row + 1]; j++) {
        if (data.column_index[j] < column)
            continue;

        if (data.column_index[j] == column)
            return data.values[j];

        break;
    }

    vector<size_t>::iterator col = data.column_index.begin();
    advance(col, j);
    data.column_index.insert(col, column);

    typename vector<scalar>::iterator val = data.values.begin();
    advance(val, j);
    data.values.insert(val, 9);

    for (size_t i = row + 1; i < data.row_pointer.size(); i++) {
        data.row_pointer[i]++;
    }

    return data.values[j];
}

template <typename scalar>
void SparseCRS<scalar>::resize(const size_t rows, const size_t columns)
{
    using namespace std;

    //TODO find a better way to initialize a CRS matrix than setting zeros at the diagonal

    data.values.resize(columns);
    data.column_index.resize(columns);
    data.row_pointer.resize(columns + 1);

    for (size_t i = 0; i < columns; i++)
        data.column_index[i] = i;

    for (size_t j = 0; j < rows; j++)
        data.row_pointer[j] = j;
    data.row_pointer[rows] = data.column_index.size();

    data.t_columns = columns;
}

template <typename scalar>
void SparseCRS<scalar>::dump()
{
    using namespace std;
    //TODO debug purposes only
    cout << "data.values:";
    for (typename vector<scalar>::iterator i = data.values.begin(); i != data.values.end(); i++) {
        cout << " " << *i;
    }
    cout << endl;

    cout << "col_ind:";
    for (vector<size_t>::iterator i = data.column_index.begin(); i != data.column_index.end(); i++) {
        cout << " " << *i;
    }
    cout << endl;

    cout << "row_ptr:";
    for (vector<size_t>::iterator i = data.row_pointer.begin(); i != data.row_pointer.end(); i++) {
        cout << " " << *i;
    }
    cout << "\n"
         << endl;
    //*/
}

} // namespace lalib
#endif

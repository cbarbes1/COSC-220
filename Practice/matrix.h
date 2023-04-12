#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class matrix {
public:
	matrix(int numRows = 1, int numCols = 1, const T &initVal = T());
	vector<T>& operator[](int i);
	const vector<T>& operator[](int i) const;
	int rows() const;
	int cols() const;
	void resize(int numRows, int numCols);

private:
	int nRows;
	int nCols;
	vector<vector<T> > mat;
};

// Constructor.
// Postcondition: create array having numRows x numCols elements
// all of whose elements have value initVal
template<typename T>
matrix<T>::matrix(int numRows, int numCols, const T &initVal) :
		nRows(numRows), nCols(numCols), mat(numRows,
				vector<T>(numCols, initVal)) {
}

// Index operator.
// Precondition: 0 <= i < nRows. a violation of this
// precondition throws the indexRangeError exception.
// Postcondition: if the operator is used on the left-hand
// side of an assignment statement, an element of row i
// is changed.
// Non-constant version. provides general access to matrix
// elements.
template<typename T>
vector<T>& matrix<T>::operator[](int i) {
	if (i < 0 || i >= nRows)
		return mat[0];

	return mat[i];
}

// Constant version.  can be used with a constant object.
// does not allow modification of a matrix element
// version for constant objects
template<typename T>
const vector<T>& matrix<T>::operator[](int i) const {
	if (i < 0 || i >= nRows)
		return mat[0];

	return mat[i];
}

// return number of rows
template<typename T>
int matrix<T>::rows() const {
	return nRows;
}

// Return number of columns
template<typename T>
int matrix<T>::cols() const {
	return nCols;
}

// Modify the matrix size.
// Postcondition: the matrix has size numRows x numCols.
// any new elements are filled with the default value of type T.
template<typename T>
void matrix<T>::resize(int numRows, int numCols) {
	// handle case of no size change with a return
	if (numRows == nRows && numCols == nCols)
		return;

	// assign the new matrix size
	nRows = numRows;
	nCols = numCols;

	// resize to nRows rows
	mat.resize(nRows);

	// resize each row to have nCols columns
	for (int i = 0; i < nRows; i++)
		mat[i].resize(nCols);
}

#endif	// MATRIX_H

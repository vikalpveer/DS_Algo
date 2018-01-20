#include "matrix.h"

// Constructor for matrix. Initialize matrix with 0ss
template <class T>
Matrix<T>::Matrix(const int r, const int c) : Row(r), Col(c) {
	std::vector<T> rowV(Row, 0);
	M = std::vector<std::vector<T> >(Col, rowV);
}

// Draws the matrix

template <class T>
void Matrix<T>::draw() {
	std::cout << "\n";

	for(int i = 0 ; i < Row; i++) {
		 for(int j = 0; j < Col; j++) {
			 std::cout << M[j][i]<< "|";
		 }
		 std::cout << "\n";
	}
}


// Sets a matrix row "n" (n is 1 based here) to a vector v. v must be the same size as Col.
template <class T>
void Matrix<T>::setRow(const int n, const std::vector<T> v) {


	if(n < 1 || n > Row) {
		std::cout <<" index is more than the row size of the matrix \n";
		return;
	}
	if(v.size() != Col) {
		std::cout <<"num of element in row is not equal to matrix size \n";
		return ;
	}

	typename std::vector<T>::const_iterator it;
	int i =0;
	for(it = v.begin(); it != v.end(); it++) {
		M[i++][n - 1] = *it;
	}
}

// Fill matrix elements with a random values between 1 and 50.

template <class T>
void Matrix<T>::randomize() {

	std::map<int, int>m;
	for (int i = 0; i < Row; i ++) {
		for(int j = 0; j < Col; j ++) {
			int k = rand()%50;
			if(m.find(k) == m.end()) {
				M[j][i] = k;
				m[k] = true;
			}
		}
	}
}

template <class T> 
const T& Matrix<T>::getElement(const int i, const int j) const {
	return M[j][i];
}

template class Matrix<int>;
template class Matrix<char>;

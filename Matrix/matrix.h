#include <iostream>
#include <vector>
#include <list>
#include <map>

template <class T>
class Matrix {
	std::vector<std::vector<T> >M;
	const int Row;
    const int Col;
	public :
	    Matrix(const int r, const int c);
		// draw matrix
		void draw();
        // sets a given row n with the vecor v.
		void setRow(const int n,const std::vector<T> v);
		// Fill array with random variables.
		void randomize();

		// return element for a given row/column
		const T& getElement(const int i, const int j) const;
};


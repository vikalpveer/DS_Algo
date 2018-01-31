// Search in a row wise and column wise sorted matrix
// Given an n x n matrix and a number x, find position 
// of x in the matrix if it is present in it. Else print “Not Found”. i
// In the given matrix, every row and column is sorted in increasing order. 
// The designed algorithm should have linear time complexity. 
// https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix.
// NOTE : Matrix is NOT strictly sorted


#include "matrix.h"

void find(int x, const Matrix<int> &m, int nRow, int nCol) {
    for(int i = nCol - 1; i >=0; i--) {
		int j;
		for(j = 0; j<  nRow; j++) {
			int temp = m.getElement(j, i);
			if(temp == x) {
			    std::cout <<"Element found at index :"<<j << ","<<i <<"\n";
				return;
			}
			if(temp < x)
			    continue;
			else
			    break;
		}
		if(j == nRow) 
		    break;
	}
	std::cout <<"NOT FOUND \n";
}

int main() {

	Matrix<int>m(4,4);

	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	m.setRow(1,v);

	v.clear();

	v.push_back(15);
	v.push_back(25);
	v.push_back(35);
	v.push_back(45);

	m.setRow(2,v);

	v.clear();

	v.push_back(27);
	v.push_back(29);
	v.push_back(37);
	v.push_back(48);

	m.setRow(3,v);

	v.clear();

	v.push_back(32);
	v.push_back(33);
	v.push_back(39);
	v.push_back(50);

	m.setRow(4,v);

	m.draw();

	// function 

	find(21, m, 4, 4);
}



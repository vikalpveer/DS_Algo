// The program should print the matrix in spiral form.
//https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/

#include "matrix.h"


// 1  2  3  4
// 5  6  7  8
// 9 10 11 12
// 13 14 15 16
//
// Output 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
void print_spiral(const Matrix <int> &M, int nRow, int nCol) {

	int row = 0;
	int col = 0;
	int firstCol = 0;
	int firstRow = 0;
	while(nRow > firstRow && nCol > firstCol) {

		// Move right
		if( row == firstRow && col < nCol) {
			std::cout << M.getElement(firstRow, col) <<" ";
			col++;
			if(col == nCol) {
				 firstRow++;
		         row = firstRow;
			}
			continue;
		}
		// go Down;

		if(col == nCol && row < nRow) {
			std::cout << M.getElement(row, nCol -1) << " ";
			row++;
			if(row == nRow) {
				nCol--;
				col = nCol;
			}
			continue;
		}

		// Move left
		if(row == nRow && col > firstCol) {
			std::cout << M.getElement(nRow -1, col - 1) <<" ";
			col--;
			if(col == firstCol) {
				nRow--;
				row = nRow;
			}
			continue;
		}
		
		// Move up
		if(col == firstCol && row > firstRow) {
			std::cout << M.getElement(row -1 , firstCol) <<" ";
			row--;
			if(row == firstRow) {
				firstCol++;
				col = firstCol;
			}
			continue;
		}
	}
}


int main() {
	Matrix <int>m(4,3);

	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	m.setRow(1, v);
	v.clear();

	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	m.setRow(2, v);
	v.clear();

	v.push_back(7);
	v.push_back(8);
	v.push_back(9);

	m.setRow(3, v);
	v.clear();

	v.push_back(10);
	v.push_back(11);
	v.push_back(12);

	m.setRow(4, v);
	v.clear();

	m.draw();

	std::cout<<"\n";

	print_spiral(m, 4,3);
}




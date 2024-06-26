#pragma once

//DO NOT CHANGE THIS PART
#include <stdlib.h>

typedef int TElem;
#define NULL_TELEM 0

class Matrix {

private:
	
	TElem* value;
	int* column;
	int* row;
	int* previos;
	int* next;
	int size;
	int head;
	int tail;
	int capacity;
	int nrC;
	int nrL;
	int isEmpty;

	void resize();
	int FindItem(int i, int j) const;

public:
	//constructor
	Matrix(int nrLines, int nrCols);

	//returns the number of lines
	int nrLines() const;

	//returns the number of columns
	int nrColumns() const;

	//returns the element from line i and column j (indexing starts from 0)
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem element(int i, int j) const;

	//modifies the value from line i and column j
	//returns the previous value from the position
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem modify(int i, int j, TElem e);

	~Matrix();
};

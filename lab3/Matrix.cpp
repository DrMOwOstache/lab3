#include "Matrix.h"
#include <exception>
using namespace std;


Matrix::Matrix(int nrLines, int nrCols) {
	this->nrC = nrCols;
	this->nrL = nrLines;
	this->capacity = nrCols * nrLines;
	this->value = new int[nrLines];

	for (int i = 0; i < capacity; i++)
		this->value[i] = 0;

	this->column = new int[nrLines];
	this->row = new int[nrLines];

	this->next = new int [nrLines];
	this->previos = new int[nrLines];

	this->head = -1;
	this->tail = -1;
	this->next[0] = -1;
	this->previos[0] = -1;
	this->isEmpty = 0;
}


int Matrix::nrLines() const {
	return nrL;
}


int Matrix::nrColumns() const {
	return nrC;
}


TElem Matrix::element(int i, int j) const {

	if (i > nrL || i < 0 || j<0 || j>nrC || tail == -1)
		throw exception();
	else
	{
		int ind = head;
		while (ind != tail)
		{
			if (column[ind] == j && row[ind] == head)
				return value[ind];
			ind = next[ind];
		}
	}

	return NULL_TELEM;
}

TElem Matrix::modify(int i, int j, TElem e) {
	//TODO - Implementation
	return NULL_TELEM;
}



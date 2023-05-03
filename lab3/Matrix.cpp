#include "Matrix.h"
#include <exception>
using namespace std;


void Matrix::resize()
{

}

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
	this->size = 0;
}


int Matrix::nrLines() const {
	return nrL;
}


int Matrix::nrColumns() const {
	return nrC;
}


TElem Matrix::element(int i, int j) const {
	
	int ind = FindItem(i, j);
	if (ind != -1)
		return value[ind];
	return NULL_TELEM;
}

TElem Matrix::modify(int i, int j, TElem e) {
	int ind = FindItem(i, j);
	if (ind != -1)
	{
		TElem aux = value[ind];
		value[ind] = e;
		return aux;
	}
	else
	{
		ind = head;
		while (row[next[ind]] < i)
			ind = next[ind];
		while (column[next[ind]] < j)
			ind = next[ind];
		value[isEmpty] = e;
		next[isEmpty] = next[ind];
		previos[isEmpty] = ind;
		previos[next[ind]] = isEmpty;
		next[ind] = isEmpty;
		size++;
		
		if (size == capacity)
		{
			resize();
			isEmpty = size;
		}
		else
		{
			while (value[isEmpty] != 0)
				isEmpty++;
		}
	}

	return NULL_TELEM;
}

int Matrix::FindItem(int i, int j) const
{
	if (i > nrL || i < 0 || j<0 || j>nrC || tail == -1)
		throw exception();
	else
	{
		if (column[tail] == j && row[tail] == head)
			return tail;
		int ind = head;
		while (ind != tail)
		{
			if (column[ind] == j && row[ind] == head)
				return ind;
			ind = next[ind];
		}
	}
	return -1;
}

Matrix::~Matrix()
{
	if (value != nullptr)
	{
		delete[] value;
		delete[] next;
		delete[] previos;
		delete[] column;
		delete[] row;
		head = -1;
		tail = -1;
		capacity = 0;
		nrC = 0;
		nrL = 0;
		size = 0;
	}
}



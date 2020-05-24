#include "PBM.h"

PBM::PBM()
{
	this->magicNumber = "P1";
	this->rows = 6;
	this->cols = 10;
	
	this->initPixelMatrix();
}

PBM::PBM(const PBM& other)
{
	this->copy(other);
}

PBM& PBM::operator=(const PBM& other)
{
	if (this != &other) {
		this->copy(other);
	}

	return *this;
}

void PBM::setRows(const size_t rows)
{
	this->rows = rows;
}

void PBM::setCols(const size_t cols)
{
	this->cols = cols;
}

void PBM::setPixelMatrix(const Vector<Vector<size_t>> pixelMatrix)
{

}

void PBM::initPixelMatrix()
{

}


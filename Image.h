#pragma once
#include <iostream>
#include "Pixel.h"
#include "String.h"
#include "Vector.h"

class Image {
protected:
	String magicNumber; // open image.pbm
	size_t rows, cols = 0;
	Vector<Vector<size_t>> pixelMatrix;

	void copy(const Image& other) {
		this->magicNumber = other.magicNumber;
		this->rows = rows;
		this->cols = cols;
		this->pixelMatrix = other.pixelMatrix;
	}
public:
	const String& getMagicNumber() const { return this->magicNumber; };
	size_t getRows() const { return this->rows; };
	size_t getCols() const { return this->cols; };
	const Vector<Vector<size_t>>& getPixelMatrix() const { return this->pixelMatrix; };

	void setMagicNumber(const String& magicNumber) { this->magicNumber = magicNumber; };
	virtual void setRows(const size_t rows) = 0;
	virtual void setCols(const size_t cols) = 0;
	virtual void setPixelMatrix(const Vector<Vector<size_t>> pixelMatrix) = 0; 

	virtual void initPixelMatrix() = 0;
};
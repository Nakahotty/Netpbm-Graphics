#pragma once
#include <iostream>
#include "Pixel.h"
#include "Session.h"
#include "String.h"
#include "Vector.h"

class Image {
protected:
	String magicNumber;
	size_t cols = 0, rows = 0;
	Vector<Vector<size_t>> pixelMatrix;

	void copy(const Image& other) {
		this->magicNumber = other.magicNumber;
		this->rows = rows;
		this->cols = cols;
		this->pixelMatrix = other.pixelMatrix;
	}
public:
	Image() : cols(0), rows(0) {}

	const String& getMagicNumber() const { return this->magicNumber; };
	size_t getRows() const { return this->rows; };
	size_t getCols() const { return this->cols; };
	const Vector<Vector<size_t>>& getPixelMatrix() const { return this->pixelMatrix; };

	void setMagicNumber(const String& magicNumber) { this->magicNumber = magicNumber; };
	void setPixelMatrix(const Vector<Vector<size_t>> pixelMatrix) { this->pixelMatrix = pixelMatrix; };
	
	virtual void setRows(const size_t rows) = 0;
	virtual void setCols(const size_t cols) = 0;
	
	void initPixelMatrix();
	virtual void clearPixelMatrix() = 0;
	virtual void formatPixelMatrix() = 0;

	// Operations 
	virtual void grayscale() = 0;
	virtual void monochrome() = 0;
	virtual void negative() = 0;
	virtual void rotate(const String& direction) = 0;
	virtual void rotateRight() = 0;
	virtual void rotateLeft() = 0;
	virtual void undo() = 0;
	virtual void add(const Image& image) = 0;
	virtual void session_info() = 0;
	virtual void _switch(const Session& session) = 0;
	virtual void collage(const String& direction, const Image& image1, const Image& image2, Image* outImage) = 0;
	
	// File input and output
	virtual ostream& saveImage(ostream& out) const = 0;
	virtual ifstream& loadImage(ifstream& in) = 0;
	
	void print() const;
};
#pragma once
#include "Image.h"

class PPM : public Image {
private:
	size_t maxValue;
public:
	PPM();
	PPM(const PPM& other);
	PPM& operator =(const PPM& other);

	void setRows(const size_t rows);
	void setCols(const size_t cols);

	void initMatrix(Vector<Vector<size_t>>& v);
	void initPixelMatrix();
	void clearPixelMatrix();
	void formatPixelMatrix();
	void formatPixelMatrix(size_t r, size_t c);
	void formatTransposedRight();
	void formatTransposedLeft();
	bool isTransposed();
	void print() const;

	// Operations
	void grayscale();
	void monochrome();
	void negative();
	void rotate(const String& direction);
	void rotateRight();
	void rotateLeft();
	void undo();

	void previousState();

	// File input and output
	ostream& saveImage(ostream& out);
	ifstream& loadImage(ifstream& in);
};
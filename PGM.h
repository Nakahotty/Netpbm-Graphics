#pragma once
#include "Image.h"

class PGM : public Image {
private:
	size_t maxValue;
	size_t pixelValue;
public:
	PGM();
	PGM(const PGM& other);
	PGM& operator =(const PGM& other);

	void setRows(const size_t rows);
	void setCols(const size_t cols);

	void initMatrix(Vector<Vector<size_t>>& v);
	void clearPixelMatrix();
	void formatPixelMatrix();
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
	void collage(const String& direction, const Image& image1, const Image& image2, Image* outImage);

	void previousState();

	// File input and output
	ostream& saveImage(ostream& out) const;
	ifstream& loadImage(ifstream& in);
};
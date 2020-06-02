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

	void initPixelMatrix();
	void formatPixelMatrix();
	void print() const;

	// Operations
	void grayscale();
	void monochrome();
	void negative();
	void rotate(const String& direction);
	void undo();
	void add(const Image& image);
	void session_info();
	void _switch(const Session& session);
	void collage(const String& direction, const Image& image1, const Image& image2, Image* outImage);

	// File input and output
	ostream& saveImage(ostream& out) const;
	ifstream& loadImage(ifstream& in);
};
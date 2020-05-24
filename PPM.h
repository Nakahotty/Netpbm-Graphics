#pragma once
#include "Image.h"

class PPM : public Image {
private:
public:
	PPM();
	PPM(const PPM& other);
	PPM& operator =(const PPM& other);

	void setRows(const size_t rows);
	void setCols(const size_t cols);
	void setPixelMatrix(const Vector<Vector<size_t>> pixelMatrix);

	void initPixelMatrix();
};
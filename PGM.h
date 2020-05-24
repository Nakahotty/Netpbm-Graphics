#pragma once
#include "Image.h"

class PGM : public Image {
private:
public:
	PGM();
	PGM(const PGM& other);
	PGM& operator =(const PGM& other);

	void setRows(const size_t rows);
	void setCols(const size_t cols);
	void setPixelMatrix(const Vector<Vector<size_t>> pixelMatrix);

	void initPixelMatrix();
};
#pragma once
#include "Image.h"

class PBM : public Image {
private:
public:
	PBM(); 
	PBM(const PBM& other);
	PBM& operator =(const PBM& other);

	void setRows(const size_t rows);
	void setCols(const size_t cols);
	void setPixelMatrix(const Vector<Vector<size_t>> pixelMatrix);

	void initPixelMatrix();
};
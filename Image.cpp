#include "Image.h"

void Image::print() const
{
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			cout << pixelMatrix[i][j] << " ";
		}

		cout << endl;
	}
}

void Image::initPixelMatrix()
{
	for (size_t i = 0; i < rows; i++) {
		pixelMatrix.push_back(Vector<size_t>());

		for (size_t j = 0; j < cols; j++) {
			pixelMatrix[i].push_back(0);
		}
	}
}

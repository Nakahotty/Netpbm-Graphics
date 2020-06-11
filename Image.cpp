#include "Image.h"

void Image::print() const {}

void Image::initPixelMatrix()
{
	for (size_t i = 0; i < rows; i++) {
		pixelMatrix.push_back(Vector<size_t>());

		for (size_t j = 0; j < cols; j++) {
			pixelMatrix[i].push_back(0);
		}
	}

	for (size_t i = 0; i < rows; i++) {
		previousPixelMatrix.push_back(Vector<size_t>());

		for (size_t j = 0; j < cols; j++) {
			previousPixelMatrix[i].push_back(0);
		}
	}
}

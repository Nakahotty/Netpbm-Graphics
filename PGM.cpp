#include "PGM.h"

PGM::PGM()
{
	this->magicNumber = "P2";
	this->rows = 7;
	this->cols = 24;
	this->maxValue = 15;

	this->initPixelMatrix();
}

PGM::PGM(const PGM& other)
{
	this->copy(other);
	this->maxValue = other.maxValue;
}

PGM& PGM::operator=(const PGM& other)
{
	if (this != &other) {
		this->copy(other);
		this->maxValue = other.maxValue;
	}

	return *this;
}

void PGM::setRows(const size_t rows)
{
	this->rows = rows;
}

void PGM::setCols(const size_t cols)
{
	this->cols = cols;
}

void PGM::formatPixelMatrix()
{
	size_t pixelValue = maxValue;

	// P
	for (size_t j = 0; j < 4; j++) {
		pixelMatrix[1][19 + j] = pixelValue;
		pixelMatrix[3][19 + j] = pixelValue;

		pixelMatrix[j + 2][19] = pixelValue;

		if (j == 3)
			pixelMatrix[2][19 + j] = pixelValue;
	}

	pixelValue -= 4;

	// E E
	for (size_t j = 0; j < 4; j++) {
		pixelMatrix[1][13 + j] = pixelValue;
		pixelMatrix[5][13 + j] = pixelValue;
	}

	for (size_t k = 2; k < 5; k++) {
		pixelMatrix[k][13] = pixelValue;

		if (k == 3) {
			pixelMatrix[k][14] = pixelValue;
			pixelMatrix[k][15] = pixelValue;
		}
	}

	pixelValue -= 4;

	// FIXXXXXXXXX

	for (size_t j = 0; j < 4; j++) {
		pixelMatrix[1][7 + j] = pixelValue;
		pixelMatrix[5][7 + j] = pixelValue;
	}

	for (size_t k = 2; k < 5; k++) {
		pixelMatrix[k][7] = pixelValue;

		if (k == 3) {
			pixelMatrix[k][7 + 1] = pixelValue;
			pixelMatrix[k][7 + 2] = pixelValue;
		}
	}

	pixelValue -= 4;


	// F
	for (size_t j = 1; j < 5; j++) {
		pixelMatrix[1][j] = pixelValue;
		pixelMatrix[j][1] = pixelValue;

		if (j == 3) {
			pixelMatrix[j][2] = pixelValue;
			pixelMatrix[j][3] = pixelValue;
		}

		if (j == 4) {
			pixelMatrix[j + 1][1] = pixelValue;
		}
	}	
}

void PGM::print() const
{
	cout << this->magicNumber << endl;
	cout << "# Shows the word FEEP" << endl;
	cout << this->cols << " " << this->rows << endl;
	cout << this->maxValue << endl;

	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			if (pixelMatrix[i][j] >= 10)
				cout << pixelMatrix[i][j] << " ";
			else 
				cout << pixelMatrix[i][j] << "  ";
		}

		cout << endl;
	}
}

void PGM::grayscale()
{

}

void PGM::monochrome()
{

}

void PGM::negative() {

}

void PGM::rotate(const String& direction) {

}

void PGM::undo() {

}

void PGM::add(const Image& image) {

}

void PGM::session_info() {

}

void PGM::_switch(const Session& session) {

}

void PGM::collage(const String& direction, const Image& image1, const Image& image2, Image* outImage) {

}

ostream& PGM::saveImage(ostream& out) const
{
	out << this->magicNumber << endl;
	out << this->rows << " " << this->cols << endl;
	out << this->maxValue << endl;

	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			if (pixelMatrix[i][j] >= 10)
				out << pixelMatrix[i][j] << " ";
			else
				out << pixelMatrix[i][j] << "  ";
		}

		out << endl;
	}

	return out;
}

ifstream& PGM::loadImage(ifstream& in)
{
	in >> this->magicNumber;
	in >> this->rows;
	in.seekg(1, ios::cur);
	in >> this->cols;
	in.seekg(2, ios::cur);
	in >> this->maxValue;

	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			in >> pixelMatrix[i][j];

			if (pixelMatrix[i][j] >= 10) 
				in.seekg(1, ios::cur);
			else 
				in.seekg(2, ios::cur);
		}

		in.seekg(2, ios::cur);
	}

	return in;
}

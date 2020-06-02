#include "PPM.h"

PPM::PPM()
{
	this->magicNumber = "P3";
	this->rows = 2;
	this->cols = 3;
	this->maxValue = 255;

	this->initPixelMatrix();
}

PPM::PPM(const PPM& other)
{
	this->copy(other);
	this->maxValue = other.maxValue;
}

PPM& PPM::operator=(const PPM& other)
{
	if (this != &other) {
		this->copy(other);
		this->maxValue = other.maxValue;
	}

	return *this;
}

void PPM::setRows(const size_t rows)
{
	this->rows = rows;
}

void PPM::setCols(const size_t cols)
{
	this->cols = cols;
}


void PPM::initPixelMatrix()
{
	size_t size = rows * cols;

	for (size_t i = 0; i < size; i++) {
		pixelMatrix.push_back(Vector<size_t>());

		for (size_t j = 0; j < 3; j++) {
			pixelMatrix[i].push_back(0);
		}
	}
}

void PPM::formatPixelMatrix()
{
	size_t size = rows * cols;

	// For RED,GREEN,BLUE
	for (size_t i = 0; i < 3; i++) {
		pixelMatrix[i][i] = maxValue;
	}

	// For YELLOW 
	for (size_t i = 0; i < 2; i++) {
		pixelMatrix[size - 3][i] = maxValue;
	}

	// For WHITE
	for (size_t i = 0; i < 3; i++) {
		pixelMatrix[size - 2][i] = maxValue;
	}
		 
}

void PPM::print() const
{
	cout << this->magicNumber << endl;
	cout << this->cols << " " << this->rows << endl;
	cout << this->maxValue << endl;
	cout << "# The part bellow includes RGB triplets" << endl;

	size_t size = rows * cols;
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < 3; j++) {
			if (pixelMatrix[i][j] == 0)
				cout << "  " << pixelMatrix[i][j] << " ";
			else 
				cout << pixelMatrix[i][j] << " ";
		}
		
		cout << endl;
	}
}

void PPM::grayscale()
{

}

void PPM::monochrome()
{

}

void PPM::negative() {

}

void PPM::rotate(const String& direction) {

}

void PPM::undo() {

}

void PPM::add(const Image& image) {

}

void PPM::session_info() {

}

void PPM::_switch(const Session& session) {

}

void PPM::collage(const String& direction, const Image& image1, const Image& image2, Image* outImage) {

}

ostream& PPM::saveImage(ostream& out) const
{
	out << this->magicNumber << endl;
	out << this->cols << " " << this->rows << endl;
	out << this->maxValue << endl;

	size_t size = rows * cols;
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < 3; j++) {
			if (pixelMatrix[i][j] == 0)
				out << "  " << pixelMatrix[i][j] << " ";
			else
				out << pixelMatrix[i][j] << " ";
		}

		out << endl;
	}

	return out;
}

ifstream& PPM::loadImage(ifstream& in)
{
	in >> this->magicNumber;
	in >> this->rows;
	in.seekg(1, ios::cur);
	in >> this->cols;
	in.seekg(1, ios::cur);
	in >> this->maxValue;

	size_t size = rows * cols;
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < 3; j++) {
			in >> pixelMatrix[i][j];

			if (pixelMatrix[i][j] == maxValue && pixelMatrix[i][j+1] == 0)
				in.seekg(3, ios::cur);
			else
				in.seekg(1, ios::cur);
		}

		in.seekg(2, ios::cur);
	}

	return in;
}

#include "PBM.h"

PBM::PBM()
{
	this->magicNumber = "P1";
	this->rows = 10;
	this->cols = 6;
	
	this->initPixelMatrix();
}

PBM::PBM(const PBM& other)
{
	this->copy(other);
}

PBM& PBM::operator=(const PBM& other)
{
	if (this != &other) {
		this->copy(other);
	}

	return *this;
}

void PBM::setRows(const size_t rows)
{
	this->rows = rows;
}

void PBM::setCols(const size_t cols)
{
	this->cols = cols;
}

void PBM::formatPixelMatrix()
{
	for (size_t i = 0; i < rows; i++) {
		if (i < 7)
			pixelMatrix[i][4] = 1;
	}

	for (size_t i = 1; i < 4; i++) {
		pixelMatrix[7][i] = 1;
	}

	pixelMatrix[6][0] = 1;
}

void PBM::print() const
{
	cout << this->magicNumber << endl;
	cout << "# Shows the letter J" << endl;
	cout << this->cols << " " << this->rows << endl;
	Image::print();
}

void PBM::grayscale()
{

}

void PBM::monochrome()
{

}

void PBM::negative() {

}

void PBM::rotate(const String& direction) {

}

void PBM::undo() {

}

void PBM::add(const Image& image) {

}

void PBM::session_info() {

}

void PBM::_switch(const Session& session) {

}

void PBM::collage(const String& direction, const Image& image1, const Image& image2, Image* outImage) {

}

ostream& PBM::saveImage(ostream& out) const
{
	out << magicNumber << endl;
	out << cols << " " << rows << endl;

	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			out << pixelMatrix[i][j] << " ";
		}

		out << endl;
	}

	return out;
}

ifstream& PBM::loadImage(ifstream& in)
{
	in >> magicNumber;
	in >> cols;
	in.seekg(1, ios::cur);
	in >> rows;
	in.seekg(2, ios::cur);

	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			in >> pixelMatrix[i][j];
			in.seekg(1, ios::cur);
		}

		in.seekg(2, ios::cur);
	}

	return in;
}


#include "PBM.h"

PBM::PBM()
{
	this->magicNumber = "P1";
	this->rows = 10;
	this->cols = 6;
	
	this->initPixelMatrix();
	this->formatPixelMatrix();
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

void PBM::initMatrix(Vector<Vector<size_t>>& v)
{
	for (size_t i = 0; i < rows; i++) {
		v.push_back(Vector<size_t>());

		for (size_t j = 0; j < cols; j++) {
			v[i].push_back(0);
		}
	}
}

void PBM::clearPixelMatrix()
{
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			pixelMatrix[i][j] = 0;
		}
	}
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

void PBM::formatPixelMatrix(size_t r, size_t c)
{
	// 1st image
	for (size_t i = 0; i < r; i++) {
		if (i < 7)
			pixelMatrix[i][4] = 1;
	}


	for (size_t i = 1; i < 4; i++) {
		pixelMatrix[7][i] = 1;
		pixelMatrix[7][i] = 1;
	}

	pixelMatrix[6][0] = 1;

	// 2nd image
	for (size_t i = 0; i < r; i++) {
		if (i < 7)
			pixelMatrix[i][10] = 1;
	}

	for (size_t i = 1; i < 4; i++) {
		pixelMatrix[7][i+6] = 1;
		pixelMatrix[7][i+6] = 1;
	}

	pixelMatrix[6][6] = 1;
}

void PBM::formatTransposedRight()
{
	for (size_t i = 0; i < rows; i++) {
		if (i < 7)
			pixelMatrix[4][i] = 1;
	}

	for (size_t i = 1; i < 4; i++) {
		pixelMatrix[i][7] = 1;
	}

	pixelMatrix[0][6] = 1;
}

void PBM::formatTransposedLeft()
{
	for (size_t i = 0; i < cols; i++) {
		if (i < 7)
			pixelMatrix[4][i] = 1;
	}

	for (size_t i = 1; i < 4; i++) {
		pixelMatrix[i][7] = 1;
	}

	pixelMatrix[0][6] = 1;
}

bool PBM::isTransposed()
{
	return this->rows == 6 || this->cols == 10;
}

void PBM::print() const
{
	cout << this->magicNumber << endl;
	cout << "# Shows the letter J" << endl;
	cout << this->cols << " " << this->rows << endl;
	
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			cout << pixelMatrix[i][j] << " ";
		}

		cout << endl;
	}
}

// Both do not effect the image in this format
void PBM::grayscale() {}
void PBM::monochrome() {}

void PBM::negative() {
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			if (pixelMatrix[i][j] == 0)
				pixelMatrix[i][j] = 1;
			else
				pixelMatrix[i][j] = 0;
		}
	}
}

void PBM::rotate(const String& direction) {
	if (strcmp(direction.c_str(), "right") == 0) {
		rotateRight();
	}
	else if (strcmp(direction.c_str(), "left") == 0) {
		rotateLeft();
	}
	else {
		throw exception("Invalid command entered!");
	}
}

void PBM::rotateRight()
{
	size_t temp = rows;
	rows = cols;
	cols = temp;

	if (!isTransposed()) {
		this->initPixelMatrix();
		this->clearPixelMatrix();
		this->formatPixelMatrix();
	}
	else {

		Vector<Vector<size_t>> newPixels;
		this->initMatrix(newPixels);

		this->pixelMatrix = newPixels;
		this->formatTransposedRight();
	}

}

void PBM::rotateLeft()
{
	size_t temp = rows;
	rows = cols;
	cols = temp;

	if (!isTransposed()) {
		this->initPixelMatrix();
		this->clearPixelMatrix();
		this->formatPixelMatrix();
	}
	else {

		Vector<Vector<size_t>> newPixels;
		this->initMatrix(newPixels);

		this->pixelMatrix = newPixels;
		this->formatTransposedRight();
	}
}

void PBM::undo() {
	if (isTransposed())
		this->previousState();
}

void PBM::previousState() {
	this->rotateRight();
}

ostream& PBM::saveImage(ostream& out)
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


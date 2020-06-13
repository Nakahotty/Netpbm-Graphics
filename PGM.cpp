#include "PGM.h"

PGM::PGM()
{
	this->magicNumber = "P2";
	this->rows = 7;
	this->cols = 24;
	this->maxValue = 15;
	this->pixelValue = maxValue;

	this->initPixelMatrix();
	this->formatPixelMatrix();
}

PGM::PGM(const PGM& other)
{
	this->copy(other);
	this->maxValue = other.maxValue;
	this->pixelValue = maxValue;
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

void PGM::initMatrix(Vector<Vector<size_t>>& v)
{
	for (size_t i = 0; i < rows; i++) {
		v.push_back(Vector<size_t>());

		for (size_t j = 0; j < cols; j++) {
			v[i].push_back(0);
		}
	}
}

void PGM::clearPixelMatrix()
{
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			pixelMatrix[i][j] = 0;
		}
	}
}

void PGM::formatPixelMatrix()
{
	pixelValue = maxValue;

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

void PGM::formatPixelMatrix(size_t r, size_t c)
{
	// For collab we add the second picture by adding it 24 pixels away from the start
	pixelValue = maxValue;

	// P
	for (size_t j = 0; j < 4; j++) {
		pixelMatrix[1][24 + 19 + j] = pixelValue;
		pixelMatrix[3][24 + 19 + j] = pixelValue;

		pixelMatrix[j + 2][24 + 19] = pixelValue;

		if (j == 3)
			pixelMatrix[2][24 + 19 + j] = pixelValue;
	}

	pixelValue -= 4;

	// E E
	for (size_t j = 0; j < 4; j++) {
		pixelMatrix[1][24+13 + j] = pixelValue;
		pixelMatrix[5][24+13 + j] = pixelValue;
	}

	for (size_t k = 2; k < 5; k++) {
		pixelMatrix[k][24+13] = pixelValue;

		if (k == 3) {
			pixelMatrix[k][24+14] = pixelValue;
			pixelMatrix[k][24+15] = pixelValue;
		}
	}

	pixelValue -= 4;

	for (size_t j = 0; j < 4; j++) {
		pixelMatrix[1][24 + 7 + j] = pixelValue;
		pixelMatrix[5][24 + 7 + j] = pixelValue;
	}

	for (size_t k = 2; k < 5; k++) {
		pixelMatrix[k][24 + 7] = pixelValue;

		if (k == 3) {
			pixelMatrix[k][24 + 7 + 1] = pixelValue;
			pixelMatrix[k][24 + 7 + 2] = pixelValue;
		}
	}

	pixelValue -= 4;


	// F
	for (size_t j = 1; j < 5; j++) {
		pixelMatrix[1][24+j] = pixelValue;
		pixelMatrix[j][24+1] = pixelValue;

		if (j == 3) {
			pixelMatrix[j][24+2] = pixelValue;
			pixelMatrix[j][24+3] = pixelValue;
		}

		if (j == 4) {
			pixelMatrix[j + 1][24+1] = pixelValue;
		}
	}
}

void PGM::formatTransposedRight()
{
	pixelValue = maxValue;

	// P
	for (size_t j = 0; j < 4; j++) {
		pixelMatrix[19+j][1] = pixelValue;
		pixelMatrix[19+j][3] = pixelValue;

		pixelMatrix[19][j+2] = pixelValue;

		if (j == 3)
			pixelMatrix[19+j][2] = pixelValue;
	}

	pixelValue -= 4;

	// E E
	for (size_t j = 0; j < 4; j++) {
		pixelMatrix[13+j][1] = pixelValue;
		pixelMatrix[13+j][5] = pixelValue;
	}

	for (size_t k = 2; k < 6; k++) {
		pixelMatrix[13][k] = pixelValue;

		if (k == 3) {
			pixelMatrix[14][k] = pixelValue;
			pixelMatrix[15][k] = pixelValue;
		}
	}

	pixelValue -= 4;

	for (size_t j = 0; j < 4; j++) {
		pixelMatrix[7+j][1] = pixelValue;
		pixelMatrix[7+j][5] = pixelValue;
	}

	for (size_t k = 2; k < 5; k++) {
		pixelMatrix[7][k] = pixelValue;

		if (k == 3) {
			pixelMatrix[8][k] = pixelValue;
			pixelMatrix[9][k] = pixelValue;
		}
	}

	pixelValue -= 4;

	// F
	for (size_t j = 1; j < 5; j++) {
		pixelMatrix[j][1] = pixelValue;
		pixelMatrix[1][j] = pixelValue;

		if (j == 3) {
			pixelMatrix[2][j] = pixelValue;
			pixelMatrix[3][j] = pixelValue;
		}

		if (j == 4) {
			pixelMatrix[1][j+1] = pixelValue;
		}
	}
}

void PGM::formatTransposedLeft()
{
	pixelValue = maxValue;

	// P
	for (size_t j = 0; j < 4; j++) {
		pixelMatrix[19 + j][1] = pixelValue;
		pixelMatrix[19 + j][3] = pixelValue;

		pixelMatrix[19][j + 2] = pixelValue;

		if (j == 3)
			pixelMatrix[19 + j][2] = pixelValue;
	}

	pixelValue -= 4;

	// E E
	for (size_t j = 0; j < 4; j++) {
		pixelMatrix[13 + j][1] = pixelValue;
		pixelMatrix[13 + j][5] = pixelValue;
	}

	for (size_t k = 2; k < 6; k++) {
		pixelMatrix[13][k] = pixelValue;

		if (k == 3) {
			pixelMatrix[14][k] = pixelValue;
			pixelMatrix[15][k] = pixelValue;
		}
	}

	pixelValue -= 4;

	for (size_t j = 0; j < 4; j++) {
		pixelMatrix[7 + j][1] = pixelValue;
		pixelMatrix[7 + j][5] = pixelValue;
	}

	for (size_t k = 2; k < 5; k++) {
		pixelMatrix[7][k] = pixelValue;

		if (k == 3) {
			pixelMatrix[8][k] = pixelValue;
			pixelMatrix[9][k] = pixelValue;
		}
	}

	pixelValue -= 4;

	// F
	for (size_t j = 1; j < 5; j++) {
		pixelMatrix[j][1] = pixelValue;
		pixelMatrix[1][j] = pixelValue;

		if (j == 3) {
			pixelMatrix[2][j] = pixelValue;
			pixelMatrix[3][j] = pixelValue;
		}

		if (j == 4) {
			pixelMatrix[1][j + 1] = pixelValue;
		}
	}
}

bool PGM::isTransposed()
{
	return this->rows == 24 || this->cols == 7;
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

void PGM::grayscale() {}

void PGM::monochrome()
{
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			if (pixelMatrix[i][j] <= maxValue / 2)
				pixelMatrix[i][j] = 0;
			else 
				pixelMatrix[i][j] = maxValue;
		}
	}
}

void PGM::negative() {
	if (pixelMatrix[0][0] == maxValue - pixelMatrix[0][0]) {
		this->clearPixelMatrix();
		this->formatPixelMatrix();
	}
	else {
		for (size_t i = 0; i < rows; i++) {
			for (size_t j = 0; j < cols; j++) {
				pixelMatrix[i][j] = maxValue - pixelMatrix[i][j];
			}
		}
	}
}

void PGM::previousState() {
	this->initPixelMatrix();
	this->clearPixelMatrix();
	this->formatPixelMatrix();
}

void PGM::rotate(const String& direction) {
	if (strcmp(direction.c_str(), "right") == 0) {
		this->rotateRight();
	}
	else if (strcmp(direction.c_str(), "left") == 0) {
		this->rotateLeft();
	}
	else {
		throw exception("Invalid command entered!");
	}
}

void PGM::rotateRight()
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

void PGM::rotateLeft()
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
		this->formatTransposedLeft();
	}
}

void PGM::undo() {
	this->previousState();
}

ostream& PGM::saveImage(ostream& out)
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

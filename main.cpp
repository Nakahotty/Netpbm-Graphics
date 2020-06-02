#include <fstream>
#include "PBM.h"
#include "ConsoleEngine.h"

int main() {
	PPM image;
	image.formatPixelMatrix();

	ofstream out("image.ppm");
	ifstream in("image.ppm");

	image.saveImage(out);
	image.loadImage(in);

	image.print();
}
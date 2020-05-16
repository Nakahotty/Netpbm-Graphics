#pragma once
#include "Image.h"

class PGM : public Image {
private:
public:
	PGM();
	PGM(const PGM& other);
	PGM& operator =(const PGM& other);
	~PGM();
};
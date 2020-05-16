#pragma once
#include "Image.h"

class PPM : public Image {
private:
public:
	PPM();
	PPM(const PPM& other);
	PPM& operator =(const PPM& other);
	~PPM();
};
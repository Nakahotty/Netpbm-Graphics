#pragma once
#include "Image.h"

class PBM : public Image {
private:
public:
	PBM(); 
	PBM(const PBM& other);
	PBM& operator =(const PBM& other);
	~PBM();
};
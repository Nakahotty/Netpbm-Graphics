#pragma once
#include "Vector.h"
#include "String.h"
#include "Image.h"

class Image;

class Session {
private:
	size_t ID;
	Vector<String> transformations;
	Vector<String> directories;
	Vector<Image*> images;
public:
	Session();
	Session(const size_t id);
	size_t getID() const;

	void addImage(Image* img);
	void addDirectory(const String& directory);
	void session_info();
	void _switch(const Session& other);
	void getImagesInSession() const;
	void saveImages(ofstream& out);
	void loadImages(ifstream& in);
	

	void addTransform(const String& transform);
	void removeTransform(const String& transform);
	void transformImages(const String& transform);
};
#include "Session.h"

Session::Session() {
	this->ID = 1;
}

Session::Session(const size_t id)
{
	this->ID = id;
}

size_t Session::getID() const
{
	return this->ID;
}

void Session::addImage(Image* img)
{
	this->images.push_back(img);
}

void Session::addDirectory(const String& directory) {
	this->directories.push_back(directory);
}

void Session::session_info()
{
	cout << "Pending transformations: ";
	transformations.print();
}

void Session::_switch(const Session& other)
{

}

void Session::getImagesInSession() const
{
	size_t size = directories.getSize();
	for (size_t i = 0; i < size; i++) {
		cout << directories[i] << " ";
	}
	cout << endl;
}

void Session::saveImages(ofstream& out)
{
	size_t size = images.getSize();
	for (size_t i = 0; i < size; i++) {
		out.close();
		out.open(directories[i].c_str());
		images[i]->saveImage(out);
	}
}

void Session::loadImages(ifstream& in)
{
	size_t size = images.getSize();
	for (size_t i = 0; i < size; i++) {
		in.open(directories[i].c_str());
		images[i]->loadImage(in);
	}
}

void Session::addTransform(const String& transform)
{
	this->transformations.push_back(transform);
}

void Session::removeTransform(const String& transform)
{
	this->transformations.pop_by_data(transform);
}

void Session::transformImages(const String& transform)
{
	size_t size = images.getSize();
	if (strcmp(transform.c_str(), "grayscale") == 0) {
		for (size_t i = 0; i < size; i++) {
			this->images[i]->grayscale();
		}

		this->addTransform("grayscale");
	}
	else if (strcmp(transform.c_str(), "rotate right") == 0) {
		for (size_t i = 0; i < size; i++) {
			this->images[i]->rotateRight();
		}

		this->addTransform("rotate right");
	}
	else if (strcmp(transform.c_str(), "rotate left") == 0) {
		for (size_t i = 0; i < size; i++) {
			this->images[i]->rotateLeft();
		}

		this->addTransform("rotate left");
	}
	else if (strcmp(transform.c_str(), "monochrome") == 0) {
		for (size_t i = 0; i < size; i++) {
			this->images[i]->monochrome();
		}

		this->addTransform("monochrome");
	}
	else if (strcmp(transform.c_str(), "negative") == 0) {
		for (size_t i = 0; i < size; i++) {
			this->images[i]->negative();
		}

		this->addTransform("negative");
	}
	else {
		cout << "Wrong transformation entered!" << endl;
	}
}



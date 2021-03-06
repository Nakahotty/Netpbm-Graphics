#include "ConsoleEngine.h"
#include <iostream>

using namespace std;

void ConsoleEngine::run() {
	bool exited = 0;
	
	Image* image = nullptr;
	Image* collageImg = nullptr;
	Session s;

	// Files
	ofstream out;
	ifstream in;
	String fileNameOpened;
	String fileName;

	do {
		cin >> cmd;
		Vector<String> arguments = split(cmd);

		switch (checkOperation(cmd)) {
		case 1:
			// Load
			if (arguments.getSize() > 1 && !(arguments[1] == '\0')) {
				fileName = arguments[1];
				fileNameOpened = fileName;

				size_t imageFormatID = checkImageFormat(fileName);

				matchFormat(imageFormatID, image);

				if (image != nullptr) {
					if (in.is_open() || out.is_open()) {
						cout << "File already loaded!" << endl;
					}
					else {
						out.open(fileName.c_str(), ios::app);
						in.open(fileName.c_str());

						if (!(is_empty(in))) {
							image->loadImage(in);
							in.close();
						}
						else {
							image->saveImage(out);
						}

						if (out.is_open()) {
							cout << "Session with ID: " << s.getID() << " started" << endl;
							s.addImage(image);
							s.addDirectory(fileName);
							cout << "Image \"" << fileName << "\" added" << endl;
						}
					}
				}
			}
			else {
				cout << "Missing or invalid arguments!" << endl;
			}

			break;
		case 2:
			// Close
			if (arguments.getSize() > 1 && !(arguments[1] == '\0')) {
				fileName = arguments[1];

				if (out.is_open()) {
					cout << "Closing file " << fileName << "..." << endl;
					out.close();
				}
				else {
					cout << "No file is opened!" << endl;
				}

			}
			else {
				cout << "Missing arguments!" << endl;
			}

			break;
		case 3:
			// Save
			if (out.is_open()) {
				cout << "Saving files..." << endl;
				s.saveImages(out);
			}
			else {
				cout << "No file is opened" << endl;
			}

			break;
		case 4:
			// Save as
			fileName = arguments[1];

			if (arguments.getSize() > 1 && !(arguments[1] == '\0')) {
				cout << "Saving files..." << endl;
				s.saveImages(out);
			}
			else {
				cout << "Missing arguments!" << endl;
			}

			break;
		case 5:
			// Help
			cout << "The following commands are supported: " << endl;
			cout << "open <file> - Opens <file>" << endl;
			cout << "close - Closes currently oppened file" << endl;
			cout << "save - Saves the currently oppened file" << endl;
			cout << "saveas <file> - Saves the currently oppened file in <file>" << endl;
			cout << "help - Prints this information" << endl;
			cout << "exit - Exits the program" << endl;
			cout << "checkin <room> <from> <to> <note> <guests> - Registration in <room> in the period <from> <to> with <guests>" << endl;
			cout << "availability <date> - Checks room availability on <date>" << endl;
			cout << "checkout <room> - Checks out guests from <room>" << endl;
			cout << "find <beds> <from> <to> - Finds available room with <beds> in the period <from> <to>" << endl;
			cout << "find! <beds> <from> <to> - Finds urgent search for a special guest with <beds> in the period" << endl;
			cout << "unavailable <room> <from> <to> <note> - Setting <room> as unavailable for period <from> <to>" << endl;
			break;
		case 6:
			// Exit
			cout << "Exiting the program..." << endl;
			exited = 1;
			break;
		case 7:
			// Grayscale
			if (out.is_open()) {
				String transformation = arguments[0];
				s.transformImages(transformation);
			}
			else {
				cout << "You have to open a file to enter this command!" << endl;
			}

			break;
		case 8:
			// Monochrome
			if (out.is_open()) {
				String transformation = arguments[0];
				s.transformImages(transformation);
			}
			else {
				cout << "You have to open a file to enter this command!" << endl;
			}

			break;
		case 9:
			// Negative
			if (out.is_open()) {
				String transformation = arguments[0];
				s.transformImages(transformation);
			}
			else {
				cout << "You have to open a file to enter this command!" << endl;
			}

			break;
		case 10:
			// Rotate
			if (out.is_open()) {
				String rotation = arguments[0] + " " + arguments[1];
				cout << rotation << endl;
				s.transformImages(rotation);
			}
			else {
				cout << "You have to open a file to enter this command!" << endl;
			}

			break;
		case 11:
			// Undo
			if (out.is_open()) {
				String transformation = arguments[0];
				s.transformImages(transformation);
			}
			else {
				cout << "You have to open a file to enter this command!" << endl;
			}

			break;
		case 12:
			// Add
			if (out.is_open()) {
				Image* added_img = nullptr;
				fileName = arguments[1];
				cout << fileName << endl;
				s.addDirectory(fileName);

				size_t addedImgID = checkImageFormat(fileName);
				matchFormat(addedImgID, added_img);

				s.addImage(added_img);
				cout << "Image \"" << fileName << "\" added" << endl;
			}
			else {
				cout << "You have to open a file to enter this command!" << endl;
			}

			break;
		case 13:
			// Session info
			if (out.is_open()) {
				s.session_info();
			}
			else {
				cout << "You have to open a file to enter this command!" << endl;
			}

			break;
		case 14:
			// Switch
			if (out.is_open()) {

			}
			else {
				cout << "You have to open a file to enter this command!" << endl;
			}


			break;
		case 15:
			// Collage

			if (out.is_open()) {
				String filename1 = arguments[1];
				String filename2 = arguments[2];
				String filename3 = arguments[3];
				ofstream collage_out(filename3.c_str());

				size_t imageFormatID1 = checkImageFormat(filename1);
				size_t imageFormatID2 = checkImageFormat(filename2);
				size_t imageFormatID3 = checkImageFormat(filename3);

				Vector<Image*> imgs = s.getImages();
				Image* img1 = imgs[0]; Image* img2 = imgs[1];

				matchFormat(imageFormatID1, img1);
				matchFormat(imageFormatID2, img2);
				matchFormat(imageFormatID3, collageImg);
				
				String magicNum1 = img1->getMagicNumber();
				String magicNum2 = img2->getMagicNumber();
				String magicNum3 = collageImg->getMagicNumber();

				if (magicNum1 == magicNum2 && magicNum2 == magicNum3) {
					s.collage(img1, img2, collageImg);
					collageImg->saveImage(collage_out);
				}
					
				else 
					cout << "Cannot make a collage from different types!" << endl;
			}
			else {
				cout << "You have to open a file to enter this command!" << endl;
			}

			break;
		case 16:
			// Loaded images
			if (out.is_open()) {
				s.getImagesInSession();
			}
			else {
				cout << "You have to open a file to enter this command!" << endl;
			}
			break;
		default:
			cout << "Invalid command entered!" << endl;
			break;
		}
	} while (!exited);
}


String ConsoleEngine::subString(String text, size_t startPosition, size_t endPosition) {
	String result;
	for (size_t i = 0; i < endPosition - startPosition; i++) {
		result = result + text[startPosition + i];
	}

	result[endPosition - startPosition] = 0;
	return result;
}

size_t ConsoleEngine::countLetters(String text, char letter)
{
	size_t counter = 0;
	size_t length = text.length();
	for (size_t i = 0; i < length; i++) {
		if (text[i] == letter)
			counter++;
	}

	return counter;
}

size_t ConsoleEngine::indexOf(String text, char letter)
{
	size_t length = text.length();
	for (size_t i = 0; i < length; i++) {
		if (text[i] == letter) {
			return i;
		}
	}

	return -1;
}

Vector<String> ConsoleEngine::split(String text)
{
	Vector<String> result;
	size_t spaces = countLetters(text, ' ');

	while (spaces) {
		result.push_back(subString(text, 0, indexOf(text, ' ')));
		text = subString(text, indexOf(text, ' ') + 1, text.length() + 1);
		spaces--;
	}

	result.push_back(text);
	return result;
}

size_t ConsoleEngine::toInt(String txt)
{
	int sum = 0;
	return sum;
}

size_t ConsoleEngine::checkOperation(String cmd) {
	Vector<String> cmdParts = split(cmd);

	for (size_t i = 0; i < 16; i++) {
		if (cmdParts[0] == commands_arr[i]) {
			return i + 1;
		}

	}

	return -1;
}

void ConsoleEngine::matchFormat(size_t formatID, Image*& image)
{
	switch (formatID) {
	case 0:
		image = nullptr;
		cout << "File format must be ppm, pbm or pgm!" << endl;
		break;
	case 1:
		image = new PBM();
		break;
	case 2:
		image = new PGM();
		break;
	case 3:
		image = new PPM();
		break;
	default:
		image = nullptr;
		cout << "Something went wrong while reading format!" << endl;
		break;
	}
}

String ConsoleEngine::getImageFormat(const String& fileName) const
{
	String format;
	size_t length = fileName.length();
	for (size_t i = 4; i > 0; i--) {
		format = format + fileName[length - i];
	}

	return format;
}

size_t ConsoleEngine::checkImageFormat(const String& filename)
{
	PBM pbm; PGM pgm; PPM ppm;
	String format = getImageFormat(filename);
	
	if (format == ".pbm")
		return 1;
	else if (format == ".pgm")
		return 2;
	else if (format == ".ppm")
		return 3;
	else
		return 0;
}

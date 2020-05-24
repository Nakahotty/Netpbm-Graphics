#include "ConsoleEngine.h"
#include <iostream>

using namespace std;

void ConsoleEngine::run() {
	bool exited = 0;
	// Image image;

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
			// Open
			if (arguments.getSize() > 1 && !(arguments[1] == '\0')) {
				fileName = arguments[1];
				fileNameOpened = fileName;

				if (in.is_open() || out.is_open()) {
					cout << "File already opened!" << endl;
				}
				else {
					out.open(fileName.c_str(), ios::app);
					in.open(fileName.c_str());

					if (!(is_empty(in))) {
						// image.load(in)
						in.close();
					}
					else {
						// image.save(out)
					}

					if (out.is_open()) {
						cout << "Opening file " << fileName << "..." << endl;
					}
				}
			}
			else {
				cout << "Missing arguments!" << endl;
			}

			break;
		case 2:
			// Close
			if (arguments.getSize() > 1 && !(arguments[1] == '\0')) {
				fileName = arguments[1];

				// нулирай хотела
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
				cout << "Saving file..." << endl;
				out.close();

				out.open(fileNameOpened.c_str(), ios::trunc);
				// image.save(out)
			}
			else {
				cout << "No file is opened" << endl;
			}

			break;
		case 4:
			// Save as
			fileName = arguments[1];

			if (arguments.getSize() > 1 && !(arguments[1] == '\0')) {
				cout << "Saving file as" << fileName << "..." << endl;
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
				
			}
			else {
				cout << "You have to open a file to enter this command!" << endl;
			}

			break;
		case 8:
			// Monochrome
			if (out.is_open()) {
				
			}
			else {
				cout << "You have to open a file to enter this command!" << endl;
			}

			break;
		case 9:
			// Negative
			if (out.is_open()) {

			}
			else {
				cout << "You have to open a file to enter this command!" << endl;
			}

			break;
		case 10:
			// Rotate
			if (out.is_open()) {

			}
			else {
				cout << "You have to open a file to enter this command!" << endl;
			}

			break;
		case 11:
			// Undo
			if (out.is_open()) {

			}
			else {
				cout << "You have to open a file to enter this command!" << endl;
			}

			break;
		case 12:
			// Add
			if (out.is_open()) {

			}
			else {
				cout << "You have to open a file to enter this command!" << endl;
			}

			break;
		case 13:
			// Session info
			if (out.is_open()) {

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

	for (size_t i = 0; i < 15; i++) {
		if (cmdParts[0] == commands_arr[i]) {
			return i + 1;
		}

	}

	return -1;
}

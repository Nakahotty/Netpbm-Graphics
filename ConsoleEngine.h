#include "Operation.h"
#include "String.h"
#include "Vector.h"
#include "PBM.h"
#include "PGM.h"
#include "PPM.h"

class ConsoleEngine {
private:
	String cmd;
	Vector<String> commands;

	// 15 commands
	String commands_arr[16] = { "load", "close", "save", "saveas", "help", "exit",
								"grayscale", "monochrome", "negative", "rotate", "undo", "add", "session_info", "switch", "collage", "loaded_images"};

	void initCommands() {
		for (size_t i = 0; i < 16; i++) {
			commands.push_back(commands_arr[i]);
		}
	}
public:
	ConsoleEngine() {
		initCommands();
	}

	// Starting the image app
	void run();

	// Handling text
	size_t countLetters(String text, char letter);
	size_t indexOf(String text, char letter);
	static String subString(String text, size_t startPosition, size_t endPosition);
	Vector<String> split(String text);
	size_t toInt(String txt);

	// For switch
	size_t checkOperation(String cmd);
	bool is_empty(ifstream& pFile)
	{
		return pFile.peek() == ifstream::traits_type::eof();
	}
	
	void matchFormat(size_t formatID, Image*& image);
	String getImageFormat(const String& fileName) const;
	size_t checkImageFormat(const String& filename);
};
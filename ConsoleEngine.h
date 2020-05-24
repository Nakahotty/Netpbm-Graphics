#include "Operation.h"
#include "String.h"
#include "Vector.h"
#include "Image.h"

class ConsoleEngine {
private:
	String cmd;
	Vector<String> commands;

	// 13 commands
	String commands_arr[15] = { "open", "close", "save", "saveas", "help", "exit",
								"grayschale", "monochrome", "negative", "rotate", "undo", "add", "session_info", "switch", "collage"};

	void initCommands() {
		for (size_t i = 0; i < 15; i++) {
			commands.push_back(commands_arr[i]);
		}
	}
public:
	ConsoleEngine() {
		initCommands();
	}

	// Starting the hotel app
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
};
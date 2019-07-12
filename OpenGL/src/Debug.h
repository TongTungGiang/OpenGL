#ifndef DEBUG_H
#define DEBUG_H

#ifdef _WIN32
#include <windows.h>

#define RED (FOREGROUND_INTENSITY | FOREGROUND_RED)
#define GREEN (FOREGROUND_INTENSITY | FOREGROUND_GREEN)
#define YELLOW (FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN)
#define BLUE (FOREGROUND_INTENSITY | FOREGROUND_BLUE)
#define MAGENTA (FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE)
#define CYAN (FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE)
#define WHITE (FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)
#else
// On Linux, use ANSI escape sequence for colored text
#define ESCAPE   "\x1B[0m"

#define RED      "\x1B[31m"
#define GREEN    "\x1B[32m"
#define YELLOW   "\x1B[33m"
#define BLUE     "\x1B[34m"
#define MAGENTA  "\x1B[35m"
#define CYAN     "\x1B[36m"
#define WHITE    "\x1B[37m"

//#define RED(x) KRED << x << RST
//#define GREEN(x) KGRN << x << RST
//#define YELLOW(x) KYEL << x << RST
//#define BLUE(x) KBLU << x << RST
//#define MAGENTA(x) KMAG << x << RST
//#define CYAN(x) KCYN << x << RST
//#define WHITE(x) KWHT << x << RST

#define BOLD(x) "\x1B[1m" << x << RST
#define UNDERLINE(x) "\x1B[4m" << x << RST
#endif // _WIN32

#include <string>
#include <map>

enum class DebugConsoleColor
{
	Red,
	Green,
	Yellow,
	Blue,
	Magenta,
	Cyan,
	White
};

class Debug
{

public:

	static void Log(std::string content, DebugConsoleColor color = DebugConsoleColor::White);

	static void LogWarning(std::string content);

	static void LogError(std::string content);

private:

#ifdef _WIN32
	static std::map<DebugConsoleColor, WORD> debugColorMap;
#else
	static std::map<DebugConsoleColor, std::string> debugColorMap;
#endif

};

#endif // DEBUG_H

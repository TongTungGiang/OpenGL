#include "Debug.h"

#include <iostream>

using namespace std;


#ifdef _WIN32
map<DebugConsoleColor, WORD> Debug::debugColorMap =
{
	{ DebugConsoleColor::Red, RED },
	{ DebugConsoleColor::Green, GREEN },
	{ DebugConsoleColor::Yellow, YELLOW },
	{ DebugConsoleColor::Blue, BLUE },
	{ DebugConsoleColor::Magenta, MAGENTA },
	{ DebugConsoleColor::Cyan, CYAN },
	{ DebugConsoleColor::White, WHITE }
};
#else
map<DebugConsoleColor, string> Debug::debugColorMap =
{
	{ DebugConsoleColor::Red, RED },
	{ DebugConsoleColor::Green, GREEN },
	{ DebugConsoleColor::Yellow, YELLOW },
	{ DebugConsoleColor::Blue, BLUE },
	{ DebugConsoleColor::Magenta, MAGENTA },
	{ DebugConsoleColor::Cyan, CYAN },
	{ DebugConsoleColor::White, WHITE }
};
#endif // _WIN32

void Debug::Log(std::string content, DebugConsoleColor color)
{
#ifdef _WIN32
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), debugColorMap[color]);
	cout << content << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
#else
	cout << debugColorMap[color] << content << ESCAPE << endl;
#endif // _WIN32
}


void Debug::LogError(std::string content)
{
#ifdef _WIN32
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
	cout << content << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
#else
	cout << RED << content << ESCAPE << endl;
#endif // _WIN32
}


void Debug::LogWarning(std::string content)
{
#ifdef _WIN32
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	cout << content << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
#else
	cout << YELLOW << content << ESCAPE << endl;
#endif // _WIN32
}

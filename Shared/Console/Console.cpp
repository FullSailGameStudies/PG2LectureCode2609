#include "Console.h"
#include <iostream>

const std::string Console::ESC = "\x1B";
int Console::windowWidth = 100, Console::windowHeight = 50;

void Console::ResizeWindow(int width, int height)
{
	windowWidth = width;
	windowHeight = height;
	std::cout << ESC << "[8;" << height << ";" << width << "t";
}
void Console::Reset()
{
	std::cout << ESC << "[0m";
}

void Console::Clear()
{
	std::cout << ESC << "[2J" << ESC << "[H"; //clears the screen and moves the cursor to the top-left
}

void Console::SetCursorPosition(int x, int y)
{
	std::cout << ESC << "[" << y << ";" << x << "H";
}

void Console::SetCursorLeft(int x)
{
	std::cout << ESC << "[" << x << "G";
}

void Console::SetForegroundColor(ConsoleColor foreColor)
{
	std::cout << ESC << "[" << foreColor + 30 << "m";
}

void Console::SetForegroundColor(int r, int g, int b)
{
	std::cout << ESC << "[38;2;" << r << ";" << g << ";" << b << "m";
}

void Console::SetBackgroundColor(ConsoleColor backColor)
{
	std::cout << ESC << "[" << backColor + 40 << "m";
}

void Console::SetBackgroundColor(int r, int g, int b)
{
	std::cout << ESC << "[48;2;" << r << ";" << g << ";" << b << "m";
}
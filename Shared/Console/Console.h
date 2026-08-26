#pragma once
#include <string>
#include <iostream>

enum ConsoleColor
{
    Black,
    Red,
    Green,
    Yellow,
    Blue,
    Magenta,
    Cyan,
    White,
    Default = 9
};

class Console
{
public:
    static void ResizeWindow(int width, int height);
    static int GetWindowWidth() { return windowWidth; }
    static int GetWindowHeight() { return windowHeight; }
    static void SetCursorPosition(int x, int y);
    static void SetCursorLeft(int x);
    static void SetForegroundColor(ConsoleColor foreColor);
    static void SetForegroundColor(int r, int g, int b);
    static void SetBackgroundColor(ConsoleColor backColor);
    static void SetBackgroundColor(int r, int g, int b);
    static void Reset();
    static void Clear();

    template <typename T> static void Write(const T& message);
    template <typename T> static void Write(const T& message, ConsoleColor foreColor, ConsoleColor backColor = ConsoleColor::Black);
    template <typename T> static void WriteLine(const T& message);
    template <typename T> static void WriteLine(const T& message, ConsoleColor foreColor, ConsoleColor backColor = ConsoleColor::Black);


private:
    static const std::string ESC;

    static int windowWidth, windowHeight;
};


template<typename T>
inline void Console::Write(const T& message)
{
    static_assert(!std::is_class_v<T> || (std::is_class_v<T> && std::is_same_v<std::string, T>), "Console::Write cannot print a vector or struct. You must access the items inside the object to print them.");
    std::cout << message;
}

template<typename T>
inline void Console::Write(const T& message, ConsoleColor foreColor, ConsoleColor backColor)
{
    static_assert(!std::is_class_v<T> || (std::is_class_v<T> && std::is_same_v<std::string, T>), "Console::Write cannot print a vector or struct. You must access the items inside the object to print them.");
    SetForegroundColor(foreColor);
    SetBackgroundColor(backColor);
    std::cout << message;
    Reset();
}

template<typename T>
inline void Console::WriteLine(const T& message)
{
    static_assert(!std::is_class_v<T> || (std::is_class_v<T> && std::is_same_v<std::string, T>), "Console::WriteLine cannot print a vector or struct. You must access the items inside the object to print them.");
    std::cout << message << std::endl;
}

template<typename T>
inline void Console::WriteLine(const T& message, ConsoleColor foreColor, ConsoleColor backColor)
{
    static_assert(!std::is_class_v<T> || (std::is_class_v<T> && std::is_same_v<std::string, T>), "Console::WriteLine cannot print a vector or struct. You must access the items inside the object to print them.");
    SetForegroundColor(foreColor);
    SetBackgroundColor(backColor);
    std::cout << message;
    Reset();
    std::cout << std::endl;
}
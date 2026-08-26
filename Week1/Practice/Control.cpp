#include "Control.h"
#include "Console.h"


/*
	(Day 01) Practice 05: defining methods

	Definitions to add:
		AddKey. Add the string parameter to the keys_ vector.
		Show. Loop over the keys_ vector and print the items. 

*/
void Control::AddKey(std::string key)
{
	keys_.push_back(key);
}

void Control::AddKeys(const std::vector<std::string>& keys)
{
	for (auto& key : keys)
	{
		keys_.push_back(key);
	}
}

void Control::Show()
{
	Console::Write(action_, ConsoleColor::Yellow);
	Console::SetCursorLeft(15);
	std::string lastKey = keys_.back();
	for (auto& key : keys_)
	{
		Console::Write(key, ConsoleColor::Cyan);
		if (key != lastKey)
			std::cout << ", ";
	}
	std::cout << "\n";
}

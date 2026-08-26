#include "DayCode.h"
#include <iostream>

void DayCode::ShowMenu(const std::string& title, const std::vector<std::string>& menuOptions)
{
	std::cout << "\n\n" << title << "\n";
	for (auto& option : menuOptions)
	{
		std::cout << option << "\n";
	}
	std::cout << "\nSelect an option: \n";
}
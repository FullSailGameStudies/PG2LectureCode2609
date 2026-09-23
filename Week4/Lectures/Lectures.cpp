#include <iostream>
#include "Console.h"
#include "Day10.h"
#include "Day11.h"
#include "Input.h"
#include <fstream>


int main(int argc, char* args[])
{
	//3 basic File I/O Steps:
	//1) open the file
	//	where the file is? how you're opening it? did it succeed?
	//2) write/read the file
	//3) CLOSE the file
	
	std::string fileName = "2609.csv";
	std::string path = "C:\\temp\\2609\\";
	std::string finalPath = path + fileName;
	char delimiter = '$';
	
	//1) open the file
	//this will attempt to open the file
	//it will NOT work if the path does not exists
	//if the file does not exists, it will create it
	//if the file does exists, it will overwrite the data
	std::ofstream outFile(finalPath);
	if (outFile.is_open())
	{
		//2) write to the file
		// << - insertion operator
		outFile << "Batman rules!" << delimiter << 5;
		outFile << delimiter << 13.7 << delimiter << true;
		outFile << "\n" << "Aquaman smells like fish.";
	}
	else
	{
		std::cout << finalPath << " could not be opened.\n";
	}
	//3) CLOSE the file
	//files are SYSTEM resources
	//the OS can have only a few thousand files open
	//good practice: close the file ASAP
	outFile.close();


    std::string hello = "Hello Week 4!";
    for (auto& ch : hello)
    {
        Console::Write(ch, (ConsoleColor)(rand() % 7 + 1));
    }
    std::cout << "\n";

	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Part A-1: Read CSV file",
		"2. Part A-2: Write CSV file",
		"3. Part B: Serialize/Deserialize objects",
		"4. Exit" };

	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			Day10::PartA_1();
			break;
		}
		case 2:
		{
			Day10::PartA_2();
			break;
		}
		case 3:
		{
			Day11::PartB();
			break;
		}

		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());

	return 0;
}
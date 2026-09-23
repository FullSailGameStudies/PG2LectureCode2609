#include <iostream>
#include "Console.h"
#include "Day10.h"
#include "Day11.h"
#include "Input.h"
#include <fstream>
#include <sstream>
#include <Player.h>
#include <filesystem>

namespace fs = std::filesystem;


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


	path = "C:\\temp";
	if (fs::exists(path) and fs::is_directory(path))
	{
		for (const auto& entry : fs::directory_iterator(path))
		{
			auto directoryItem = entry.path();
			if (directoryItem.extension() == ".zip")
				std::cout << directoryItem << '\n';
		}
	}
	else
	{
		std::cout << finalPath << " is NOT valid.\n";
	}


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


	//READING csv
	//ifstream class: 'i' stands for input (reading)
	std::ifstream inFile(finalPath);
	if (inFile.is_open())
	{
		//use std::getline to read data from the file
		std::string line;
		//reads the stream until it encounters a '\n' OR the end of the stream
		std::getline(inFile, line);
		std::cout << line << "\n";

		//parse the string to get the data
		//use std::getline to read data from a string
		std::string data;
		std::stringstream lineStream(line);
		//read the stream until it encounters the delimiter OR the end the stream
		std::getline(lineStream, data, delimiter);
		std::cout << data << "\n";

		std::getline(lineStream, data, delimiter);
		int iData = std::stoi(data);
		std::cout << iData << "\n";

		std::getline(lineStream, data, delimiter);
		double dData = std::stod(data);
		std::cout << dData << "\n";

		//try-catch:
		//  put your code that MIGHT throw an exception in a try block
		//  then write 1 or more catch blocks to handle the possible exception(s)

		std::getline(lineStream, data, delimiter);
		try
		{
			bool bData = std::stoi(data);
			std::cout << bData << "\n";
		}
		catch (const std::exception& ex)
		{
			std::cout << "Error processing boolean. " << data << "\n";
			std::cout << ex.what() << "\n";
		}


		std::getline(inFile, line);
		std::cout << line << "\n";

	}
	else
	{
		std::cout << finalPath << " could not be opened.\n";
	}
	inFile.close();




	Player p1;
	p1.MoveDown();
	p1.MoveDown();
	p1.MoveDown();
	p1.MoveLeft();
	p1.MoveLeft();

	//Serializing: (saving the state of the object)
	//1) a function in the Player class to save the data to a ofstream
	fileName = "save1.csv";
	finalPath = path + fileName;
	std::ofstream playerSaveFile(finalPath);
	if (playerSaveFile.is_open())
	{
		//call the serialize method on the object
		p1.SerializeCSV(playerSaveFile, delimiter);
	}
	else
	{
		std::cout << finalPath << " could not be opened.\n";
	}
	playerSaveFile.close();

	std::ifstream playerLoadFile(finalPath);
	if (playerLoadFile.is_open())
	{
		std::string playerLine;
		std::getline(playerLoadFile, playerLine);
		Player p2(playerLine, delimiter);

		int px, py;
		p2.GetPosition(px, py);
		std::cout << "p2: " << px << ", " << py << "\n";

		//p2 dies and needs respawning
		std::string spawn = "100,-50";
		p2.DeserializeCSV(spawn, ',');
		p2.GetPosition(px, py);
		std::cout << "p2: " << px << ", " << py << "\n";
	}
	else
	{
		std::cout << finalPath << " could not be opened.\n";
	}
	playerLoadFile.close();



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
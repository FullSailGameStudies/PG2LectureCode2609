#include "Player.h"
#include "Console.h"
#include <iomanip>
#include <sstream>

//
// Part B-1.2
//

//
// Part B-2.2
//

void Player::SerializeCSV(std::ofstream& outFile, char delimiter) const
{
	//write out the fields to the ofstream separating them with the delimiter
	outFile << worldX << delimiter << worldY;
}

void Player::DeserializeCSV(const std::string& line, char delimiter)
{
	//parse the line for the worldX and worldY
	std::stringstream lineStream(line);
	std::string data;

	std::getline(lineStream, data, delimiter);
	worldX = std::stoi(data);

	std::getline(lineStream, data, delimiter);
	worldY = std::stoi(data);
}

void Player::Info()
{
	Console::SetCursorPosition(0, 12);
	std::cout << "POSITION: " << std::setw(7) << std::right << worldX << "," << worldY;
}
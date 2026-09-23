#pragma once
#include <fstream>
#include <string>

class Player
{
public:

	Player() : worldX(0), worldY(0) {}

	//
	// Part B-1.1
	//

	//
	// Part B-2.1
	//
	
	//
	// Part B-2.3
	//


	void MoveLeft() { worldX--; }
	void MoveRight() { worldX++; }
	void MoveUp() { worldY--; }
	void MoveDown() { worldY++; }

	void GetPosition(int& x, int& y)
	{
		x = worldX;
		y = worldY;
	}

	void SerializeCSV(std::ofstream& outFile, char delimiter) const;

	//2 functions to handle Deserializing:
	//  1) a Deserialize function
	//  2) a constructor that calls Deserialize
	void DeserializeCSV(const std::string& csvData, char delimiter);
	Player(const std::string& csvData, char delimiter)
	{
		DeserializeCSV(csvData, delimiter);
	}

	void Info();
private:
	int worldX, worldY;
};


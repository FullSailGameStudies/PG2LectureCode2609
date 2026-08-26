#include "Grouper.h"



void Grouper::MakeRedLights(std::vector<Light>& lights)
{
	for (int row = 0; row < 48; row++)
	{
		for (int col = 0; col < 48; col++)
		{
			lights.push_back({ rand() % 255, 0, 0 });//red
		}
	}
}

void Grouper::MakeGreenLights(std::vector<Light>& lights)
{
	float totalLights = 51;
	int color = 0;
	for (int index = 0; index < totalLights; index++)
	{
		lights.push_back({ 0, color, 0 });//green
		color += 5;
	}
}
void Grouper::MakeLights(std::vector<Light>& lights)
{
	for (int row = 0; row < 12; row++)
	{
		for (int col = 0; col < 12; col++)
		{
			int randVal = rand() % 100;
			if (randVal < 25)
				lights.push_back({ 0, rand() % 255, 0 });//green
			else if (randVal > 75)
				lights.push_back({ 0, 0, rand() % 255 });//blue
			else
				lights.push_back({ rand() % 255, 0, 0 });//red
		}
	}
}

void Grouper::DrawLights(const Map& map, const std::vector<Light>& lights, int columnRange, int& col, int& row)
{
	for (auto& light : lights)
	{
		map.DrawCell(col, row, light.red, light.green, light.blue);
		col++;
		if (col >= columnRange)
		{
			col = 0;
			row++;
		}
	}
}
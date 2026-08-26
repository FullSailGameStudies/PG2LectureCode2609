#pragma once
#include <vector>
#include "PG2Graphics.h"
class Map
{
public:

	Map(SDL_Renderer* renderer, int cellSize) : renderer_(renderer), cellSize_(cellSize), cols_(10), rows_(10) {	}
	Map(SDL_Renderer* renderer, int cellSize, int columns, int rows) : renderer_(renderer), cellSize_(cellSize), cols_(columns), rows_(rows) {	}
	void DrawMap2D() const;
	void DrawCell(int col, int row, int red, int green, int blue) const;
	void DrawCell(int col, int row, PG2Texture* tex, float scale = 1) const;

	static void DrawMap2D(SDL_Renderer* renderer, int cellSize, const std::vector<int>& map);
	static void RandomizeMap(std::vector<int>& map, int mapSize = 10, int maxToChange = 5);
	static void DrawCell(SDL_Renderer* renderer, int cellSize, int col, int row, int red, int green, int blue);

	std::vector<int> mapData;
private:
	SDL_Renderer* renderer_;
	int cellSize_;
	int cols_, rows_;

};


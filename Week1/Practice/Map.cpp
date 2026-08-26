#include "Map.h"

void Map::DrawMap2D() const
{
	int x, y, xo, yo;
	SDL_Rect box;
	int cells = 10;
	//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_SetRenderDrawColor(renderer_, 0x48, 0x6F, 0x3B, 0xFF);
	for (y = 0; y < rows_; y++)
	{
		for (x = 0; x < cols_; x++)
		{
			if (mapData[y * cols_ + x] == 1)
				SDL_SetRenderDrawColor(renderer_, 0x7F, 0x7F, 0x7F, 0xFF);
			else if (mapData[y * cols_ + x] == 2)
				SDL_SetRenderDrawColor(renderer_, 0xD9, 0xD6, 0x02, 0xFF);
			else
				SDL_SetRenderDrawColor(renderer_, 0x48, 0x6F, 0x3B, 0xFF);
			//draw a box with a "border"
			xo = x * cellSize_; yo = y * cellSize_;
			box.x = xo + 1;
			box.y = yo + 1;
			box.w = cellSize_ - 1;
			box.h = cellSize_ - 1;
			SDL_RenderFillRect(renderer_, &box);
		}
	}
}

void Map::DrawCell(int col, int row, int red, int green, int blue) const
{
	int xo, yo;
	SDL_Rect box;
	SDL_SetRenderDrawColor(renderer_, red, green, blue, 0xFF);
	xo = col * cellSize_; yo = row * cellSize_;
	box.x = xo + 1;
	box.y = yo + 1;
	box.w = cellSize_ - 1;
	box.h = cellSize_ - 1;
	SDL_RenderFillRect(renderer_, &box);
}

void Map::DrawCell(int col, int row, PG2Texture* tex, float scale) const
{
	int width = tex->Width();
	int height = tex->Height();
	tex->Render(static_cast<int>(col * width * scale), static_cast<int>(row * width * scale), scale);
}

void Map::DrawMap2D(SDL_Renderer* renderer, int cellSize, const std::vector<int>& map)
{
	int x, y, xo, yo;
	SDL_Rect box;
	int cells = 10;
	//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_SetRenderDrawColor(renderer, 0x48, 0x6F, 0x3B, 0xFF);
	for (y = 0; y < cells; y++)
	{
		for (x = 0; x < cells; x++)
		{
			if (map[y * cells + x] == 1)
				SDL_SetRenderDrawColor(renderer, 0x7F, 0x7F, 0x7F, 0xFF);
			else if (map[y * cells + x] == 2)
				SDL_SetRenderDrawColor(renderer, 0xD9, 0xD6, 0x02, 0xFF);
			else
				SDL_SetRenderDrawColor(renderer, 0x48, 0x6F, 0x3B, 0xFF);
			//draw a box with a "border"
			xo = x * cellSize; yo = y * cellSize;
			box.x = xo + 1;
			box.y = yo + 1;
			box.w = cellSize - 1;
			box.h = cellSize - 1;
			SDL_RenderFillRect(renderer, &box);
		}
	}

}

void Map::DrawCell(SDL_Renderer* renderer, int cellSize, int col, int row, int red, int green, int blue)
{
	int xo, yo;
	SDL_Rect box;
	SDL_SetRenderDrawColor(renderer, red, green, blue, 0xFF);
	xo = col * cellSize; yo = row * cellSize;
	box.x = xo + 1;
	box.y = yo + 1;
	box.w = cellSize - 1;
	box.h = cellSize - 1;
	SDL_RenderFillRect(renderer, &box);
}


/*
	(Day 03) Practice 02: default parameters

	Add a default parameter for the max number of tiles to change.
	Set the default value to 5.
	Change the code to use the new parameter to control the loop.
*/
void Map::RandomizeMap(std::vector<int>& map, int mapSize, int maxToChange)
{
	maxToChange = std::min(8, maxToChange);
	int num2s = 1, x, y;
	while (num2s < maxToChange)
	{
		x = rand() % mapSize;
		y = rand() % mapSize;
		if (map[y * mapSize + x] == 0)
		{
			num2s++;
			map[y * mapSize + x] = 2;
		}
	}

}

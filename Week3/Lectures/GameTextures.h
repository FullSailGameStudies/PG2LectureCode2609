#pragma once
#include "PG2Graphics.h"
#include <SDL_ttf.h>
#include <vector>
#include <map>

//enum MatchingCard
//{
//	Chicken, Creeper, Skeleton, Steve, Villager, Zombie, Mooshroom, Chest, Grass, LASTCARD
//};


struct pos
{
	int x, y;
};

class Number
{
public:
	Number(SDL_Texture* texture, int width, int height) : texture_(texture), width_(width), height_(height) {}
	~Number()
	{
		//free();
	}
	void free();

	SDL_Texture* Texture() const { return texture_; }
	int Width() const { return width_; }
	int Height() const { return height_; }

private:
	//Image dimensions
	int width_;
	int height_;
	SDL_Texture* texture_;

};

enum ScoreTexture
{
	Player1 = 11, Player2, Separator, Winner, Tie
};


class GameTextures
{
public:
	static void Initialize(SDL_Renderer* renderer);
	static void Cleanup();
	static void RenderNumber(int number, int x, int y, int cellSize, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	static void ScoreItemSize(int number, int& width, int& height);
	static void RenderImage(std::string face, std::string suit, int x, int y, float scale = 1.0f, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	static pos CardSize(float scale = 1.0f);
private:
	static bool loadRenderedText();
	static void loadImageTextures();
	static void free();

	static SDL_Renderer* renderer_;
	static TTF_Font* font_;

	static int markedIndex_;

	//The actual hardware texture
	static std::vector<Number> scoreTextures_;
	static PG2Texture* cardsSpriteSheet_;

	static int start, cardWidth, cardHeight;
	static std::map<std::string, pos> suitStarts;
};


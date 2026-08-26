#pragma once
#include "PG2Texture.h"

class PG2Graphics
{
public:
	PG2Graphics(int width, int height) : screenWidth_(width), screenHeight_(height) { }

	bool Init(const std::string& windowTitle = "PG2");
	void Close();

	bool LoadMedia(PG2Texture& texture, const std::string& path);

	/*
		(Day 03) Practice 01: default parameters

		make all the params to ClearScreen have a default value rgb (0) and alpha (255)
	*/
	void ClearScreen(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha);
	void Present();
	void Focus();

	SDL_Renderer* Renderer() const { return renderer_; }

	int Width() const  { return screenWidth_; }
	int Height() const { return screenHeight_; }

private:
	SDL_Window* win_ = NULL;
	SDL_Renderer* renderer_ = NULL;

	int screenWidth_ = 640;
	int screenHeight_ = 480;

};


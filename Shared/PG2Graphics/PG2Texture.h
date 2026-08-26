#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

class PG2Texture
{
public:
	PG2Texture(SDL_Renderer* gRenderer);
	~PG2Texture();

	void Render(int x, int y, float scale = 1, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void Render(SDL_Rect* srcRect = NULL, SDL_Rect* dstRect = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	bool LoadFromFile(std::string path);
	bool LoadTextureFromURL(const std::string& url);

#if defined(SDL_TTF_MAJOR_VERSION)
	bool LoadFromRenderedText(std::string textureText, SDL_Color textColor);
#endif

	void Color(Uint8 red, Uint8 green, Uint8 blue);
	void BlendMode(SDL_BlendMode blending);
	void Alpha(Uint8 alpha);

	int Width() const  { return width_; }
	int Height() const { return height_; }

private:

	void FreeResources();

	SDL_Texture* texture_;
	SDL_Renderer* renderer_;

	int width_;
	int height_;
};
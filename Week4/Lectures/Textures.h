#pragma once
#include <vector>
#include "SubTexture.h"
#include "PG2Graphics.h"
class Textures
{
public:
	Textures() : maxWidth_(0), maxHeight_(0), scale_(0), spriteSheet_(nullptr)
	{

	}
	~Textures()
	{
		if (spriteSheet_ != nullptr)
		{
			delete spriteSheet_;
		}
	}
	bool LoadSubtextures();

	int Count() const { return static_cast<int>(subTextures_.size()); }
	int MaxWidth() const { return maxWidth_; }
	int MaxHeight() const { return maxHeight_; }

	float GetScale(int screen_width, int screen_height) 
	{ 
		if(scale_ == 0 && maxWidth_ > 0 && maxHeight_ > 0)
		{
			scale_ = std::min(((float)screen_width / 9) / maxWidth_, ((float)screen_height / 5) / maxHeight_);
		}

		return scale_; 
	}

	bool LoadSpritesheet(SDL_Renderer* renderer);
	SDL_Rect GetTextureSource(int index);
	void Render(SDL_Rect* texSrc, SDL_Rect* dest, SDL_RendererFlip flip);

private:
	std::vector<SubTexture> subTextures_;
	std::string imageFile_;
	int maxWidth_;
	int maxHeight_;
	float scale_;
	PG2Texture* spriteSheet_;
};


#include "PG2Texture.h"
#include <curl/curl.h>
#include <vector>

PG2Texture::PG2Texture(SDL_Renderer* renderer) : renderer_(renderer), texture_(NULL), width_(0), height_(0)
{
}

PG2Texture::~PG2Texture()
{
	FreeResources();
}


// Callback for libcurl to write data into a vector
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
	size_t totalSize = size * nmemb;
	std::vector<unsigned char>* buffer = static_cast<std::vector<unsigned char>*>(userp);
	buffer->insert(buffer->end(), (unsigned char*)contents, (unsigned char*)contents + totalSize);
	return totalSize;
}

// Load image from URL into SDL_Texture
bool PG2Texture::LoadTextureFromURL(const std::string& url) {
	std::vector<unsigned char> imageBuffer;

	CURL* curl = curl_easy_init();
	if (!curl) {
		printf("Failed to initialize curl\n");
		return false;
	}

	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &imageBuffer);
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

	CURLcode res = curl_easy_perform(curl);
	curl_easy_cleanup(curl);

	if (res != CURLE_OK) {
		printf("Unable to load image %s! curl_easy_perform Error: %s\n", url.c_str(), curl_easy_strerror(res));
		return false;
	}

	SDL_RWops* rw = SDL_RWFromConstMem(imageBuffer.data(), static_cast<int>(imageBuffer.size()));
	if (!rw) {
		printf("SDL_RWFromConstMem failed\n");
		return false;
	}

	SDL_Surface* surface = IMG_Load_RW(rw, 1); // 1 = auto free rw
	if (!surface) {
		printf("IMG_Load_RW failed. Unable to load image %s! SDL_image Error: %s\n", url.c_str(), IMG_GetError());
		return false;
	}

	texture_ = SDL_CreateTextureFromSurface(renderer_, surface);
	if (texture_ == NULL)
	{
		printf("Unable to create texture from %s! SDL Error: %s\n", url.c_str(), SDL_GetError());
	}
	else
	{
		width_ = surface->w;
		height_ = surface->h;
	}
	SDL_FreeSurface(surface);

	return texture_ != NULL;
}


bool PG2Texture::LoadFromFile(std::string path)
{
	FreeResources();

	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	else
	{
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0xFF, 0xFF, 0xFF));//change the RGB to set the transparent color

		newTexture = SDL_CreateTextureFromSurface(renderer_, loadedSurface);
		if (newTexture == NULL)
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		else
		{
			width_ = loadedSurface->w;
			height_ = loadedSurface->h;
		}

		SDL_FreeSurface(loadedSurface);
	}

	texture_ = newTexture;
	return texture_ != NULL;
}

#if defined(SDL_TTF_MAJOR_VERSION)
bool PG2Texture::LoadFromRenderedText(std::string textureText, SDL_Color textColor)
{
	free();

	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
	if (textSurface != NULL)
	{
		mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
		if (mTexture == NULL)
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		else
		{
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface(textSurface);
	}
	else
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());


	return mTexture != NULL;
}
#endif

void PG2Texture::FreeResources()
{
	if (texture_ != NULL)
	{
		SDL_DestroyTexture(texture_);
		texture_ = NULL;
		width_ = 0;
		height_ = 0;
	}
}

void PG2Texture::Color(Uint8 red, Uint8 green, Uint8 blue)
{
	//Modulate texture rgb
	SDL_SetTextureColorMod(texture_, red, green, blue);
}

void PG2Texture::BlendMode(SDL_BlendMode blending)
{
	//Set blending function
	SDL_SetTextureBlendMode(texture_, blending);
}

void PG2Texture::Alpha(Uint8 alpha)
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod(texture_, alpha);
}

void PG2Texture::Render(int x, int y, float scale, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	//scale is used to change the size of the resulting image
	//	scale < 1 will make the image smaller
	//	scale > 1 will make the image bigger
	SDL_Rect renderQuad = { x, y, static_cast<int>(width_ * scale), static_cast<int>(height_ * scale) };

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	//clip is the source rect
	//renderQuad is the destination rect
	SDL_RenderCopyEx(renderer_, texture_, clip, &renderQuad, angle, center, flip);
}

void PG2Texture::Render(SDL_Rect* srcRect, SDL_Rect* dstRect, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	//Render to screen
	//clip is the source rect
	//renderQuad is the destination rect
	SDL_RenderCopyEx(renderer_, texture_, srcRect, dstRect, angle, center, flip);
}
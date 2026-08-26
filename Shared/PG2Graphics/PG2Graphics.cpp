#include "PG2Graphics.h"
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <curl/curl.h>
#include <stdio.h>
#include <string>

bool PG2Graphics::Init(const std::string& windowTitle)
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		win_ = SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth_, screenHeight_, SDL_WINDOW_SHOWN);
		if (win_ == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create v-synced renderer for window
			renderer_ = SDL_CreateRenderer(win_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (renderer_ == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(renderer_, 0xFF, 0xFF, 0xFF, 0xFF);

				int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}

				CURLcode curlInit = curl_global_init(CURL_GLOBAL_DEFAULT);
				if (curlInit != CURLE_OK) {
					printf("curl_global_init() failed\n");
					success = false;
				}

				//Initialize SDL_mixer
				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
				{
					printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
					success = false;
				}

				if (TTF_Init() == -1)
				{
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}


bool PG2Graphics::LoadMedia(PG2Texture& texture, const std::string& path)
{
	bool success = true;

	if (!texture.LoadFromFile(path))
	{
		printf("Failed to load texture!\n");
		success = false;
	}

	return success;
}


void PG2Graphics::Close()
{
	SDL_DestroyRenderer(renderer_);
	SDL_DestroyWindow(win_);
	win_ = NULL;
	renderer_ = NULL;

	TTF_Quit();
	Mix_CloseAudio();
	Mix_Quit();
	curl_global_cleanup();
	IMG_Quit();
	SDL_Quit();
}

void PG2Graphics::ClearScreen(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha)
{
	SDL_SetRenderDrawColor(renderer_, red, green, blue, alpha);
	SDL_RenderClear(renderer_);
}

void PG2Graphics::Present()
{
	SDL_RenderPresent(renderer_);
}

void PG2Graphics::Focus()
{
	SDL_RaiseWindow(win_);
}

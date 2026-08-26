#include <iostream>
#include <fstream>
#include <sstream>
#include "Console.h"
#include "Day11.h"
#include <iomanip>
#include "PG2Graphics.h"
#include "Textures.h"
#include "Player.h"
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;

void SavePosition(const Player& player, std::string fileName, char delimiter)
{
	//
	// Part B-1.3
	//
}
void LoadPosition(Player& player, std::string fileName, char delimiter)
{
	//
	// Part B-2.4
	//
}
void Day11::PartB()
{
	//Screen dimension constants
	const int SCREEN_WIDTH = 450;
	const int SCREEN_HEIGHT = 450;

	srand(static_cast<unsigned int>(time(NULL)));

	PG2Graphics engine(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!engine.Init("Part B"))
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		std::string robotFileName = "robot.csv";
		char delimiter = '^';
		std::cout << "\n\nPart B\n";
		std::vector<std::string> menuOptions{
			"Arrow keys to move robot", "1. Serialize robot", "2. Deserialize robot",
			"ESC. Exit" };
		for (auto& option : menuOptions)
		{
			std::cout << option << "\n";
		}
		std::cout << "\nSelect an option: \n";

		Player robbie;
		Textures textures;
		if (textures.LoadSubtextures())
		{
			if (textures.LoadSpritesheet(engine.Renderer()))
			{
				float scale = 1;

				bool walkingLeft = false, walkingRight = false;

				int platformHeight = 30;
				SDL_Rect idleSrc = textures.GetTextureSource(0);
				int w = idleSrc.w;
				int h = idleSrc.h;
				SDL_Rect robotDest{ SCREEN_WIDTH / 2 - w / 2, SCREEN_HEIGHT - h - platformHeight, w, h };
				int walkingState = 0;
				int walkingIndex = 36;

				double maxDuration = 150;
				double timeBuffer = 0;
				double timeElapsed = 0;

				bool quit = false;
				SDL_Event e;
				while (!quit)
				{
					double elapsedNano = 0;
					auto t1 = Clock::now();

					while (SDL_PollEvent(&e) != 0)
					{
						if (e.type == SDL_QUIT || (e.key.keysym.sym == SDLK_ESCAPE && e.type == SDL_KEYUP))
						{
							quit = true;
						}

						else if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
						{
							switch (e.key.keysym.sym)
							{
							case SDLK_a:
							case SDLK_LEFT:
							{
								walkingLeft = true;
								break;
							}
							case SDLK_d:
							case SDLK_RIGHT:
							{
								walkingRight = true;
								break;
							}
							}
						}
						else if (e.type == SDL_KEYUP && e.key.repeat == 0)
						{
							switch (e.key.keysym.sym)
							{
							case SDLK_a:
							case SDLK_LEFT:
							{
								walkingLeft = false;
								break;
							}
							case SDLK_d:
							case SDLK_RIGHT:
							{
								walkingRight = false;
								break;
							}
							case SDLK_KP_1:
							case SDLK_1: //save robot
							{
								// serialize the Player
								SavePosition(robbie, robotFileName, delimiter);
								robbie.Info();
								break;
							}
							case SDLK_KP_2:
							case SDLK_2: //load robot
							{
								// deserialize the Player
								LoadPosition(robbie, robotFileName, delimiter);
								robbie.Info();
								break;
							}
							}
						}
					}
					timeBuffer = timeBuffer + timeElapsed;

					engine.ClearScreen(50, 150, 50, 255);

					//draw platform
					SDL_SetRenderDrawColor(engine.Renderer(), 75, 75, 75, 255);
					SDL_Rect rect = { 0, SCREEN_HEIGHT - platformHeight, SCREEN_WIDTH, platformHeight };
					SDL_RenderFillRect(engine.Renderer(), &rect);


					if (walkingLeft || walkingRight)
					{
						SDL_Rect walkingSrc = textures.GetTextureSource(walkingIndex + walkingState);
						textures.Render(&walkingSrc, &robotDest, (walkingLeft) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);

						// update the animation
						if (timeBuffer > maxDuration) {
							timeBuffer = 0;
							walkingState++;
							if (walkingLeft) robbie.MoveLeft();
							else if (walkingRight) robbie.MoveRight();

							if (walkingState >= 8)//TODO: fix magic number
								walkingState = 0;
						}
						robbie.Info();
					}
					else
					{
						walkingState = 0;
						textures.Render(&idleSrc, &robotDest, SDL_FLIP_NONE);
					}
					engine.Present();


					auto t2 = Clock::now();

					elapsedNano = (double)(std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count());

					if (elapsedNano > 0) {
						double diff = ((1000000000.f / 30.f) - elapsedNano) / 1000000.f;

						if (diff > 0) {
							SDL_Delay((Uint32)diff);
						}
					}

					auto t3 = Clock::now();

					timeElapsed = (double)(std::chrono::duration_cast<std::chrono::nanoseconds>(t3 - t1).count()) / 1000000.f;

				}

			}
		}
	}
	engine.Close();
}

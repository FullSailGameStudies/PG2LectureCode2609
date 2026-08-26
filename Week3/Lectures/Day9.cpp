#include "Day9.h"
#include <iostream>
#include "Console.h"
#include "Input.h"
#include <GameTextures.h>


const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 550;
void Day9::PartC_1()
{
	std::string hello = "Hello Day 9!";
	for (auto& ch : hello)
	{
		Console::Write(ch, (ConsoleColor)(rand() % 7 + 1));
	}
	std::cout << "\n";


	//
	// TODO: Part C-3.1 Create a BlackjackHand class
	//

	PG2Graphics engine(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!engine.Init("Part C-1"))
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		GameTextures::Initialize(engine.Renderer());

		std::vector<std::string> menuOptions{
			"1. Create a BlackjackHand",
			"0. Exit" };
		ShowMenu("Day 9", menuOptions);



		engine.ClearScreen(50, 150, 50, 255);
		engine.Present();
		bool quit = false;
		SDL_Event e;
		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT || (e.key.keysym.sym == SDLK_ESCAPE && e.type == SDL_KEYUP))
				{
					quit = true;
				}
				else if (e.type == SDL_KEYUP && e.key.repeat == 0)
				{
					switch (e.key.keysym.sym)
					{
					case SDLK_KP_1:
					case SDLK_1:
					{
						float scale = 1.0F;
						engine.ClearScreen(50, 150, 50, 255);

						//
						// TODO: Part C-3.2 Create BlackjackDeck and BlackjackHand objects
						//		 Deal 2 cards to the BlackjackHand
						//


						pos cardSize = GameTextures::CardSize(scale);
						int x = 5;
						int y = 5;

						//
						// TODO: Part C-3.3 call GameTextures::RenderImage on each of the Card objects in the hand
						//
						int cardCount = 0;

						//Update screen
						engine.Present();
						break;
					}
					case SDLK_KP_0:
					case SDLK_0:
					{
						quit = true;
						break;
					}

					}
				}
			}

		}
		GameTextures::Cleanup();
	}
	engine.Close();

}

#include "Day4.h"
#include <iostream>
#include <string>
#include <vector>
#include <string_view>
#include "Console.h"
#include "Input.h"
#include <PG2Graphics.h>
#include <chrono>
#include <thread>
#include "Light.h"
#include "Grouper.h"
#include "Map.h"
#include "Sorter.h"

const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 480;
void Pyramid(SDL_Renderer* renderer, int size, int x, int y)
{
}
void Day4::RecursionExample()
{
	//Screen dimension constants

	srand(static_cast<unsigned int>(time(NULL)));

	PG2Graphics engine(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!engine.Init("Part A-1.4"))
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		Console::WriteLine("Part A-1.4 Goal: recursion", ConsoleColor::Green);
		Console::WriteLine("Build a colorful pyramid.");

		int midX = SCREEN_WIDTH / 2;
		int midY = SCREEN_HEIGHT / 2;
		int size = 0;

		Console::WriteLine("\nPress space to run...");
		engine.ClearScreen(0, 0, 0, 0xFF);
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
				else if (e.type == SDL_KEYUP && e.key.repeat == 0 && e.key.keysym.sym == SDLK_SPACE)
				{
					Console::Write("running...");
					Pyramid(engine.Renderer(), size, midX, midY);
					Console::WriteLine("DONE!");
				}
			}

		}
	}
	engine.Close();
}

//
// Part A-1.1
//
void Day4::PartA_1_1()
{
	char c[] = { '\n', 66, 65, 84, 77, 65, 78, 33, 33 };
	for (auto ch : c) std::cout << ch;

}




//
// Part A-1.2
//
void Day4::PartA_1_2()
{
	std::cout << "\n";
}



//
// Part A-1.3
//
void Day4::PartA_1_3()
{
	std::string sentence = "The quick brown fox jumps over the lazy dog";
	int index = 0;
	Console::Write(' ');
	Console::WriteLine(sentence.substr(0, index + 1));
}






void ShowMenu()
{
	std::cout << "\n\nLab 2 Menu: \n";
	std::vector<std::string> menuOptions{ "1. Unsorted Lights", "2. Sort Lights", "3. Exit" };
	for (auto& option : menuOptions)
	{
		std::cout << option << "\n";
	}
	std::cout << "\nSelect an option: \n";
}


//
// Part A-2
//
void Day4::PartA_2()
{
	ShowMenu();


	//Screen dimension constants
	const int SCREEN_WIDTH = 480;
	const int SCREEN_HEIGHT = 480;

	srand(static_cast<unsigned int>(time(NULL)));

	PG2Graphics engine(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!engine.Init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		Grouper grouper;

		std::vector<Light> redLights;
		redLights.reserve(48 * 48);
		grouper.MakeRedLights(redLights);

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
					case SDLK_1: //shows the unsorted vector
					{
						Map screenMap(engine.Renderer(), 10);
						engine.ClearScreen(50, 50, 50, 255);

						int column = 0, row = 0, columnRange = 48;
						grouper.DrawLights(screenMap, redLights, columnRange, column, row);

						//Update screen
						engine.Present();
						ShowMenu();
						break;
					}
					case SDLK_KP_2:
					case SDLK_2: //sort the lights
					{
						Sorter sorter;
						std::vector<Light> redLightsCopy = redLights;
						//
						// Lecture: after adding BubbleSort to the Sorter class, call BubbleSort here to sort the redLightsCopy vector
						//

						Map screenMap(engine.Renderer(), 10);
						engine.ClearScreen(50, 50, 50, 255);

						int column = 0, row = 0, columnRange = 48;
						grouper.DrawLights(screenMap, redLightsCopy, columnRange, column, row);

						//Update screen
						engine.Present();
						ShowMenu();
						break;
					}
					case SDLK_KP_3:
					case SDLK_3://exit
						quit = true;
						break;

					}
				}
			}
		}
	}
	engine.Close();

}
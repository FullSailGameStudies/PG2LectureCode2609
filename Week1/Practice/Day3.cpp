#include "Day3.h"
#include <string>
#include <Console.h>
#include <Input.h>
#include "Player.h"
#include "Map.h"

void Day3::PartC_1()
{
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
		Console::Write("Part C-1 Goal: Default Parameters", ConsoleColor::Green);
		Console::WriteLine("Modify the ShiftColors method.");
		Console::WriteLine("\t Give the channelToShift parameter a default value of RED.");
		Console::WriteLine("After the 'engine.Preset();' line, write an if-else.");
		Console::WriteLine("\tIf the channel is red, then call ShiftColors but don't pass the channel.");
		Console::WriteLine("\tElse call ShiftColors and pass the channel.\n");

		std::vector<std::string> menuOptions{ "1. Reds", "2. Greens", "3. Blues", "4. Exit" };
		for (auto& option : menuOptions)
		{
			std::cout << option << "\n";
		}
		std::cout << "\nEnter a number to shift that color.\n";

		std::vector<Target> lights;
		lights.reserve(48 * 48);
		std::vector<int> offsets;
		offsets.reserve(48 * 48);
		MakeLights(lights, offsets);

		ColorChannel channel = ColorChannel::RED;

		Map map(engine.Renderer(), 10);

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
					case SDLK_1://Reds
						channel = ColorChannel::RED;
						break;
					case SDLK_KP_2:
					case SDLK_2://Greens
						channel = ColorChannel::GREEN;
						break;
					case SDLK_KP_3:
					case SDLK_3://Blues
						channel = ColorChannel::BLUE;
						break;
					case SDLK_KP_4:
					case SDLK_4://all
						quit = true;
						break;
					}
				}
			}

			engine.ClearScreen(0, 0, 0, 0xFF);

			for (auto& target : lights)
			{
				map.DrawCell(target.col, target.row, target.red, target.green, target.blue);
			}

			//Update screen
			engine.Present();

			//
			// Part C-1.2: call the method
			//

		}
	}
	engine.Close();
}

void Day3::PartC_2()
{
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
		Console::Write("Part C-2 Goal: copying vectors", ConsoleColor::Green);
		Console::WriteLine("Copy the lights vector to the other vector variables after the call to MakeLights.");
		Console::WriteLine("Call RemoveLights for each of the 'no' vectors. EX: call RemoveLights on noGreens.");
		Console::WriteLine("\tMake sure the second parameter uses the color you want to remove.");
		Console::WriteLine("Update the switch cases to make a copy of the appropriate no color vector. Assign it to the current vector.\n");

		std::vector<std::string> menuOptions{ "1. No Reds", "2. No Greens", "3. No Blues", "4. All Colors", "5. Exit" };
		for (auto& option : menuOptions)
		{
			std::cout << option << "\n";
		}
		std::cout << "\nEnter a number to show the lights.\n";

		std::vector<Target> lights, noGreens, noBlues, noReds, current;
		MakeLights(lights);
		current = lights;
		//
		// Part C-2.1: copy the vector
		//

		Map map(engine.Renderer(), 10);

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
					//
					// Part C-2.2: copy the vector
					//
					switch (e.key.keysym.sym)
					{
					case SDLK_KP_1:
					case SDLK_1://noReds
						break;
					case SDLK_KP_2:
					case SDLK_2://noGreens
						break;
					case SDLK_KP_3:
					case SDLK_3://noBlues
						break;
					case SDLK_KP_4:
					case SDLK_4://all
						break;
					case SDLK_KP_5:
					case SDLK_5://exit
						quit = true;
						break;
					}
				}
			}

			engine.ClearScreen(0, 0, 0, 0xFF);

			for (auto& target : current)
			{
				map.DrawCell(target.col, target.row, target.red, target.green, target.blue);
			}

			//Update screen
			engine.Present();
		}
	}
	engine.Close();
}

void Day3::ShiftColor(std::vector<Target>& lights, std::vector<int>& offsets, ColorChannel channelToShift)
{
	int color = 0;
	for (int i = 0; i < lights.size(); i++)
	{
		switch (channelToShift)
		{
		case RED:
			color = lights[i].red;
			break;
		case GREEN:
			color = lights[i].green;
			break;
		case BLUE:
			color = lights[i].blue;
			break;
		default:
			break;
		}

		color += offsets[i];
		if (color > 255)
		{
			color = 255;
			offsets[i] = -offsets[i];
		}
		else if (color < 0)
		{
			color = 0;
			offsets[i] = -offsets[i];
		}


		switch (channelToShift)
		{
		case RED:
			lights[i].red = color;
			break;
		case GREEN:
			lights[i].green = color;
			break;
		case BLUE:
			lights[i].blue = color;
			break;
		default:
			break;
		}
	}
}

void Day3::RemoveLights(std::vector<Target>& lights, ColorChannel channelToRemove)
{
	for (int i = static_cast<int>(lights.size()) - 1; i >= 0; i--)
	{
		switch (channelToRemove)
		{
		case RED:
			if (lights[i].red > 0)
				lights.erase(lights.begin() + i);
			break;
		case GREEN:
			if (lights[i].green > 0)
				lights.erase(lights.begin() + i);
			break;
		case BLUE:
			if (lights[i].blue > 0)
				lights.erase(lights.begin() + i);
			break;
		default:
			break;
		}
	}
}

void Day3::MakeLights(std::vector<Target>& lights)
{
	for (int row = 0; row < 48; row++)
	{
		for (int col = 0; col < 48; col++)
		{
			int randVal = rand() % 100;
			if (randVal < 25)
				lights.push_back({ col, row, 0, rand() % 255, 0 });//green
			else if (randVal > 75)
				lights.push_back({ col, row, 0, 0, rand() % 255 });//blue
			else
				lights.push_back({ col, row, rand() % 255, 0, 0 });//red
		}
	}
}

void Day3::MakeLights(std::vector<Target>& lights, std::vector<int>& offsets, int offset)
{
	for (int row = 0; row < 48; row++)
	{
		for (int col = 0; col < 48; col++)
		{
			int randVal = rand() % 100;
			if (randVal < 25)
				lights.push_back({ col, row, 0, rand() % 255, 0 });//green
			else if (randVal > 75)
				lights.push_back({ col, row, 0, 0, rand() % 255 });//blue
			else
				lights.push_back({ col, row, rand() % 255, 0, 0 });//red

			offsets.push_back(rand() % offset + 1);
		}
	}
}

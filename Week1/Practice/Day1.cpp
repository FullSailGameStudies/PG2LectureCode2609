#include "Day1.h"
#include <string>
#include <vector>
#include <Console.h>
#include <Input.h>
#include "Player.h"
#include "Map.h"
#include "Target.h"

void Day1::PartA_1_1()
{
	//Screen dimension constants
	const int SCREEN_WIDTH = 750;
	const int SCREEN_HEIGHT = 750;

	srand(static_cast<unsigned int>(time(NULL)));

	PG2Graphics engine(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!engine.Init("Part A-1.1"))
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		Console::Write("Part A-1.1 Goal: ", ConsoleColor::Green);
		Console::WriteLine("Before the while loop, move the player to the yellow square.");
		Console::WriteLine("HINT: explore the Player.h file to see what methods could be used.");

		PG2Texture oreTexture(engine.Renderer());
		if (!oreTexture.LoadFromFile("diamonds.png"))
		{
			Console::WriteLine("\n\nFAILED to load diamonds.png", ConsoleColor::Red);
		}
		oreTexture.BlendMode(SDL_BLENDMODE_NONE);

		float scale = 0.25f;
		Player player(&engine, scale, 1, 1);
		if (!player.IsValid())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			Map map(engine.Renderer(), player.Size());// , 10, 1);
			map.mapData =
			{
				1,1,1,1,1,1,1,1,1,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,1,1,1,1,1,1,1,1,1
			};

			Target target{ 7, 1, 0xD9, 0xD6, 0x02 };

			player.SetMap(map.mapData, 10, 10);

			bool quit = false;
			SDL_Event e;


			//
			//Part A-1.1: move player to a predefined Target spot (get target's location, player.move)
			// 		HINT: explore the Player.h file to see what methods could be used.
			//


			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT || (e.key.keysym.sym == SDLK_ESCAPE && e.type == SDL_KEYUP))
					{
						quit = true;
					}
				}

				engine.ClearScreen(0, 0, 0, 0xFF); 

				map.DrawMap2D();
				//map.DrawCell(target.col, target.row, target.red, target.green, target.blue);
				map.DrawCell(target.col, target.row, &oreTexture, 1);

				player.Render();

				//Update screen
				engine.Present();
			}
		}
	}
	engine.Close();
}

void Day1::PartA_1_2()
{
	//Screen dimension constants
	const int SCREEN_WIDTH = 750;
	const int SCREEN_HEIGHT = 750;

	srand(static_cast<unsigned int>(time(NULL)));

	PG2Graphics engine(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!engine.Init("Part A-1.2"))
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		Console::Write("Part A-1.2 Goal: ", ConsoleColor::Green);
		Console::WriteLine("Before the while loop, move the player to the yellow square.");
		Console::WriteLine("HINT: explore the Player.h file to see what methods could be used.");

		float scale = 0.25f;
		Player player(&engine, scale, 1, 1);
		if (!player.IsValid())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			PG2Texture oreTexture(engine.Renderer());
			if (!oreTexture.LoadFromFile("diamonds.png"))
			{
				Console::WriteLine("\n\nFAILED to load diamonds.png", ConsoleColor::Red);
			}
			oreTexture.BlendMode(SDL_BLENDMODE_NONE);
			Map map(engine.Renderer(), player.Size());// , 1, 10);
			map.mapData =
			{
				1,1,1,1,1,1,1,1,1,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,1,1,1,1,1,1,1,1,1
			};

			Target target{ 1, 5, 0xD9, 0xD6, 0x02 };

			player.SetMap(map.mapData, 10, 10);

			bool quit = false;
			SDL_Event e;


			//
			//Part A-1.2: move player to a predefined Target spot (get target's location, player.move)
			// 		HINT: explore the Player.h file to see what methods could be used.
			//


			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT || (e.key.keysym.sym == SDLK_ESCAPE && e.type == SDL_KEYUP))
					{
						quit = true;
					}
				}

				engine.ClearScreen(0, 0, 0, 0xFF); 

				map.DrawMap2D();
				//map.DrawCell(target.col, target.row, target.red, target.green, target.blue);
				map.DrawCell(target.col, target.row, &oreTexture, 1);

				player.Render();

				//Update screen
				engine.Present();
			}
		}
	}
	engine.Close();
}

void Day1::PartA_1_3()
{
	//Screen dimension constants
	const int SCREEN_WIDTH = 750;
	const int SCREEN_HEIGHT = 750;

	srand(static_cast<unsigned int>(time(NULL)));

	PG2Graphics engine(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!engine.Init("Part A-1.3"))
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		Console::Write("Part A-1.3 Goal: ", ConsoleColor::Green);
		Console::WriteLine("Before the while loop, move the player to the yellow square.");
		Console::WriteLine("HINT: explore the Player.h file to see what methods could be used.");

		float scale = 0.25f;
		Player player(&engine, scale, 1, 1);
		if (!player.IsValid())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			Map map(engine.Renderer(), player.Size());
			map.mapData =
			{
				1,1,1,1,1,1,1,1,1,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,1,1,1,1,1,1,1,1,1
			};

			Target target{ 7, 6, 0xD9, 0xD6, 0x02 };
			PG2Texture oreTexture(engine.Renderer());
			if (!oreTexture.LoadFromFile("diamonds.png"))
			{
				Console::WriteLine("\n\nFAILED to load diamonds.png", ConsoleColor::Red);
			}
			oreTexture.BlendMode(SDL_BLENDMODE_NONE);

			player.SetMap(map.mapData, 10, 10);

			bool quit = false;
			SDL_Event e;


			//
			//Part A-1.3: move player to a predefined Target spot 
			//      get target variable's location (col and row fields) EX: target.col
			//      the player is at col 1 and row 1
			//      use the move methods of the player
			// 		HINT: explore the Player.h file to see what methods could be used.
			//


			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT || (e.key.keysym.sym == SDLK_ESCAPE && e.type == SDL_KEYUP))
					{
						quit = true;
					}
				}

				engine.ClearScreen(0, 0, 0, 0xFF); 

				map.DrawMap2D();
				//map.DrawCell(target.col, target.row, target.red, target.green, target.blue);
				map.DrawCell(target.col, target.row, &oreTexture, 1);

				player.Render();

				//Update screen
				engine.Present();
			}
		}
	}
	engine.Close();
}


//
// Part A-2.2: create the DEFINITION for CreateTargets_PartA_2
//

void Day1::PartA_2()
{
	//Screen dimension constants
	const int SCREEN_WIDTH = 750;
	const int SCREEN_HEIGHT = 750;

	srand(static_cast<unsigned int>(time(NULL)));

	PG2Graphics engine(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!engine.Init("Part A-2"))
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		Console::Write("Part A-2 Goal: ", ConsoleColor::Green);
		Console::WriteLine("Add a method called CreateTargets_PartA_2.");
		Console::WriteLine("Add the declaration to the Day1.h and the definition to the Day1.cpp.");
		Console::WriteLine("\tThe method should have 2 int parameters: mapSize and colorRange.");
		Console::WriteLine("\tThe method should return a vector that holds Target.");
		Console::WriteLine("\tInside the method, create a vector of 10 Target objects with random positions and colors.");
		Console::WriteLine("\tUse rand() % mapSize and rand() % colorRange to pick the random position and color.");
		Console::WriteLine("In PartA_2() method, before the loop call CreateTargets_PartA_2 and store the returned vector into a variable.");
		Console::WriteLine("In PartA_2() method, inside the loop add another loop to call map.DrawCell for each target inside the vector. Do this after the call to Map::DrawMap2D.");
		Console::WriteLine("\tThe 1st argument is the column. The 2nd argument is the row.");
		Console::WriteLine("\tGet the col and row from each target.");
		Console::WriteLine("\tPass the oreTexture as the 3rd argument.");
		Console::WriteLine("\tPass 1 as the 4th argument.");

		int mapSize = 10;
		//use rand() % mapSize to generate the col and row.
		Target example;
		example.col = rand() % mapSize;
		example.row = rand() % mapSize;

		//use rand() % colorRange to generate each color component (red, green, and blue)
		int colorRange = 255;
		example.red = rand() % colorRange;
		example.green = rand() % colorRange;
		example.blue = rand() % colorRange;

		//
		// Part A-2.3: Call CreateTargets_PartA_2 and store the returned vector into the "targets" variable.
		//
		std::vector<Target> targets;

		float scale = 0.25f;
		Player player(&engine, scale, 1, 1);
		if (!player.IsValid())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			Map map(engine.Renderer(), player.Size());
			map.mapData =
			{
				1,1,1,1,1,1,1,1,1,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,1,1,1,1,1,1,1,1,1
			};
			//Target target{ 7,6,0xD9, 0xD6, 0x02 };
			PG2Texture oreTexture(engine.Renderer());
			if (!oreTexture.LoadFromFile("diamonds.png"))
			{
				Console::WriteLine("\n\nFAILED to load diamonds.png", ConsoleColor::Red);
			}
			oreTexture.BlendMode(SDL_BLENDMODE_NONE);

			player.SetMap(map.mapData, 10, 10);

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
				}

				engine.ClearScreen(0, 0, 0, 0xFF); 

				map.DrawMap2D();

				for (auto& target : targets)
				{
					map.DrawCell(target.col, target.row, &oreTexture);
				}

				//Update screen
				engine.Present();
			}
		}
	}
	engine.Close();
}
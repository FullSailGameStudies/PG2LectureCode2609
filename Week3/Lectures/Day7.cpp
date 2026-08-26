#include "Day7.h"
#include <iostream>
#include "Console.h"
#include "Input.h"
#include <GameTextures.h>


/*              CLASSESS

            ╔═════╗ ╔═════════╗
            ║class║ ║SomeClass║
            ╚═════╝ ╚═════════╝
                │          │
             ┌──┘          │
        ┌────▼─────┐   ┌───▼───┐
        │ Keyword  │   │ Class │
        │          │   │  Name │
        └──────────┘   └───────┘

        FIELDS - the data of the class

        METHODS - the behavior of the class (what the class can do)

        SPECIAL METHODS:
            Getters/Setters - the gatekeepers of the fields
            CONSTRUCTORS - the initializer of the class
            DESTRUCTORS - destroys allocated memory.





    ╔══════════════════╗
    ║ ACCESS MODIFIERS ║ - determines who can see it
    ╚══════════════════╝
        public: EVERYONE can see it
        private: ONLY this class can see it  (default)
        protected: this class and all its descendent classes can see it

*/

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 550;
void Day7::PartA_1()
{
    std::string hello = "Hello Day 7!";
    for (auto& ch : hello)
    {
        Console::Write(ch, (ConsoleColor)(rand() % 7 + 1));
    }
    std::cout << "\n";


	//
	// TODO: Part A-1.1 Create a Card class
	//
	 
	
	//
	// TODO: Part A-2.1 Create a Deck class
	//



	PG2Graphics engine(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!engine.Init("Part A-1"))
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		GameTextures::Initialize(engine.Renderer());

		std::vector<std::string> menuOptions{
			"1. Create a Card", "2. Create a Deck", 
			"0. Exit" };
		ShowMenu("Day 7", menuOptions);



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
						// TODO: Part A-1.2 Create a Card object
						//


						pos cardSize = GameTextures::CardSize(scale);
						int x = 5;
						int y = 5;

						//
						// TODO: Part A-1.3  call GameTextures::RenderImage with the Card object
						//


						//Update screen
						engine.Present();
						break;
					}
					case SDLK_KP_2:
					case SDLK_2:
					{
						float scale = 1.0F;
						engine.ClearScreen(50, 150, 50, 255);

						//
						// TODO: Part A-2.2 Create a Deck object
						//


						pos cardSize = GameTextures::CardSize(scale);
						int x = 5;
						int y = 5;

						//
						// TODO: Part A-2.3  call GameTextures::RenderImage on each of the Card objects in the deck
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
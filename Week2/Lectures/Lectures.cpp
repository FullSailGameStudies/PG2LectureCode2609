#include <iostream>
#include "Console.h"
#include "Day4.h"
#include "Day5.h"
#include "Day6.h"
#include <Input.h>
#include <map>

void SomeFunc(int num)
{
	//all recursive functions REQUIRE an exit condition
	//some code to prevent the recursive case
	if(num < 500)//loops while this condition is TRUE
	{
		num++;
		std::cout << num << "\n";
		SomeFunc(num);//recursive case (when a function calls itself)
	}
}

int main(int argc, char* args[])
{
	//maps need 2 types: type of the keys and the type of the values
	//std::string is the key type (name of the menu item)
	//float is the value type (price of the menu item)
	std::map<std::string, float> menu;

	//2 ways to add items to a map
	//1) "easy" way    map[key] = value;
	menu["Pepperoni Pizza"] = 8.99f;
	menu["Meat Lovers Pizza"] = 12.99f;
	menu["Breadsticks"] = 3.99f;

	//keys are unique
	menu["Pepperoni Pizza"] = 9.99f;//overwrites the value

	//2) "not as easy" way  map.insert(key-value-pair);
	std::pair<std::string, float> menuPair = std::make_pair("Salad", 6.99f);
	menu.insert(menuPair);
	//std::pair objects have 2 parts:
	// first and second
	menuPair.second = 5.99f;
	std::pair<std::map<std::string,float>::iterator,bool> itemInserted = menu.insert(menuPair);//will NOT overwrite if the key-value pair is already in the map
	//first is the iterator to the key-value pair in the map
	//second is whether it was inserted or not
	if (itemInserted.second) //if it was inserted
	{
		std::cout << menuPair.first << " was inserted.\n";
	}
	else
	{
		std::cout << menuPair.first << " is already on the menu and it costs ";
		std::map<std::string, float>::iterator menuIter = itemInserted.first;
		float price = menuIter->second;
		std::cout << price << "\n";
	}


	std::string menuItem = "Pepperoni Pizza";
	float itemPrice = menu[menuItem];//it uses binary search to find it!!
	std::cout << menuItem << " costs " << itemPrice << "\n";
	menuItem = "Dino Nuggs"; 
	itemPrice = menu[menuItem];//map will add it with a default value
	std::cout << menuItem << " costs " << itemPrice << "\n";



	for (int i = 0; i < 10; ++i)
	{
		int num = 5;
		std::cout << num << "\n";
	}
	SomeFunc(5);
	srand(static_cast<unsigned int>(time(NULL)));

	std::string hello = "Hello Week 2!";
	for (auto& ch : hello)
	{
		Console::Write(ch, (ConsoleColor)(rand() % 7 + 1));
	}
	std::cout << "\n";

	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Recursion Example\n",
		"2. Part A-1.1: Recursion (Bats)",
		"3. Part A-1.2: Recursion (Reverse Word)",
		"4. Part A-1.3: Recursion (Reverse words in a sentence)\n",
		"5. Part A-2: Sorting\n",
		"6. Part B-1: Linear Search\n",
		"7. Part B-2: Maps",
		"8. Part B-3: Find in Maps",
		"9. Part C-1: Erase from Maps",
		"10. Exit" };


	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			Day4::RecursionExample();
			break;
		}
		case 2:
		{
			Day4::PartA_1_1();
			break;
		}
		case 3:
		{
			Day4::PartA_1_2();
			break;
		}
		case 4:
		{
			Day4::PartA_1_3();
			break;
		}
		case 5:
		{
			Day4::PartA_2();
			break;
		}
		case 6:
		{
			Day5::PartB_1();
			break;
		}
		case 7:
		{
			Day5::PartB_2(1);
			break;
		}
		case 8:
		{
			Day5::PartB_2(2);
			break;
		}
		case 9:
		{
			Day6::PartC_1();
			break;
		}

		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());

	return 0;
}
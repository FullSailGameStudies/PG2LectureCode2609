#include <iostream>
#include "Console.h"
#include "Day7.h"
#include "Day8.h"
#include "Day9.h"
#include "Input.h"
#include <Player.h>
#include "Color.h"
#include <Weapon.h>
#include <Pistol.h>

int Add(int n1, int n2) { return n1 + n2; }
int Add(float n3, float n4) { return n3 + n4; }

int main(int argc, char* args[])
{
	int sum = Add(5.0f, 6.0);
	sum = Add(5, 6);
	Weapon wpn(10, 100);
	Pistol pewpew(20,50,2,10);
	Pistol p2(20,50,3,10);
	//we can overload the + operator
	Pistol combine = pewpew + p2;//pewpew.Add(p2)


	//I need showMe to also show the Pistol info
	//I need to "OVERRIDE" what showMe does for the Pistol class
	//OVERRIDE: (run-time polymorphism)
	//1) go to the base class and mark the method as 'virtual'
	//2) add a method to the derived class that has the same signature
	//		as the base method
	pewpew.showMe();

	Color clr;
	clr.red = clr.green = clr.blue = clr.alpha = 255;//white

	Color redColor;
	redColor.red = 255;
	redColor.alpha = 255;

	//anytime you create a variable of a class,
	//you are calling a constructor (ctor)
	Player p1(100, "BruceW");
	std::cout << p1.GamerTag() << " Health: " << p1.GetHealth() << "\n";

    std::string hello = "Hello Week 3!";
    for (auto& ch : hello)
    {
        Console::Write(ch, (ConsoleColor)(rand() % 7 + 1));
    }
    std::cout << "\n";

	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Part A-1: Create Class",//classes + inheritance + override?
		"2. Part B-1: Inheritance, Polymorphism",//no pointers
		"3. Part C-1: Pointers",//pointers
		"4. Exit" };

	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			Day7::PartA_1();
			break;
		}
		case 2:
		{
			Day8::PartB_1();
			break;
		}
		case 3:
		{
			Day9::PartC_1();
			break;
		}

		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());


	return 0;
}
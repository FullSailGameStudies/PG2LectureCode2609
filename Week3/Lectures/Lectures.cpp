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
#include <Knife.h>
#include "Car.h"

int Add(int n1, int n2) { return n1 + n2; }
int Add(float n3, float n4) { return n3 + n4; }

void Counter()
{
	//the first time it creates the variable
	//after that, it looks up the variable in static memory
	//variables in static memory stay there for the lifetime
	//of the application (however long the app is running)
	static int i = 0;
	std::cout << i << " ";
	i++;
}

int main(int argc, char* args[])
{

	Car myRide(1988, "Ford", "Mustang GT 5.0");
	Car calebsRide(2001, "Ford", "Ranger");
	myRide.vehicleInformation();
	calebsRide.vehicleInformation();
	Car::reporting();

	for (int i = 0; i < 10; i++)
	{
		Counter();
	}

	int sum = Add(5.0f, 6.0);
	sum = Add(5, 6);
	//Weapon wpn(10, 100);
	Pistol pewpew(20,50,2,10);
	Pistol p2(20,50,3,10);
	//we can overload the + operator
	Pistol combine = pewpew + p2;//pewpew.Add(p2)

	Knife stabby(3, 10, true);

	//UPCASTING
	//	cast from a DERIVED type (Knife) to a BASE type (Weapon)
	//	ALWAYS safe b/c the compiler knows that knife inherits from weapon
	//	KNIFE is-a WEAPON
	Weapon* currentWeapon = &stabby;//point it to the knife instead of copying the knife
	currentWeapon = &pewpew;

	std::vector<Weapon*> inventory;
	//we lose the specific information for each object
	inventory.push_back(&pewpew);//copies the POINTER to pewpew 
	inventory.push_back(&stabby);//copied the POINTER to stabby
	std::cout << "\n\nJohn Wick's Inventory:\n";
	for (auto& weapon : inventory)
	{
		//RUNTIME polymorphism
		weapon->showMe();
	}
	std::cout << "\n\nEND of inventory\n\n";


	//I need showMe to also show the Pistol info
	//I need to "OVERRIDE" what showMe does for the Pistol class
	//OVERRIDE: (run-time polymorphism)
	//1) go to the base class and mark the method as 'virtual'
	//2) add a method to the derived class that has the same signature
	//		as the base method
	pewpew.showMe();


	int n5 = 10;
	int& n5Ref = n5;
	int* n5Ptr;
	n5Ptr = &n5;//& means 'address-of'
	std::cout << n5Ref << "\n";
	std::cout << n5Ptr << "\n";
	std::cout << *n5Ptr << "\n";//* means 'dereference'

	currentWeapon = &pewpew;
	//how do I access the Pistol parts?
	//use the '->' notation
	//another way to dereference the pointer
	currentWeapon->showMe();
	pewpew.showMe();
	//it can only point to a Pistol object
	//currentWeapon = &n5;



	Color clr;
	clr.red = clr.green = clr.blue = clr.alpha = 255;//white

	Color redColor;
	redColor.red = 255;
	redColor.alpha = 255;

	//anytime you create a variable of a class,
	//you are calling a constructor (ctor)
	Player p1(100, "BruceW");//on the stack
	std::cout << p1.GamerTag() << " Health: " << p1.GetHealth() << "\n";

	//p2 is on the stack
	//player object it points to is on the heap
	Player* player2 = new Player(75, "Hero Brine");//on the heap

	//EVERY '=new' requires a corresponding 'delete'
	//if you don't you've leaked memory
	delete player2;//deallocate the object but we still have the pointer to the memory address
	player2 = nullptr;
	if (player2 != nullptr)
	{
		player2->SetHealth(100);
	}


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
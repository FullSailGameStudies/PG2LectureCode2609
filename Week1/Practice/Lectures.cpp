#include "Day1.h"
#include "Day2.h"
#include "Day3.h"
#include <Console.h>
#include <Input.h>

//REASONS to use references:
//1) give a different scope access to my variable(s)
void Incrementer(int& vNum)//pass by reference (ALIAS)
{
	vNum++;
}

//2) use references to prevent copies
//		copies are 'expensive'
//	when? if the parameter is a class, use &

//all default params must appear at the end of the parameter list
void Printer(const std::vector<int>& numbers, int top = 0)
{
	//range-based for loop (foreach)
	//auto IS ALLOWED in PG2!!!
	//use & to prevent a copy
	int count = 0;
	for (const int& nummy : numbers)
	{
		std::cout << nummy << "\n";
		if (top != 0 && count >= top)
			break;
	}
}

void Info(const std::vector<int>& nums)
{
	//size() - # of items in the vector
	//capacity() - length of the internal array
	//size <= capacity
	//ex: fuel tank.
	//when you add something that would make
	//the size > capacity, the vector must
	//resize its internal array
	//	it creates a new array with more space
	//	copies all of the items from the old array to the new
	//	then adds the new item to the new array
	std::cout << "size: " << nums.size() << "\tCapacity: " << nums.capacity() << "\n";
}

const float PI = 3.1415;
int main(int argc, char* args[])
{
	std::vector<int> numbers;//same as resize
	numbers.reserve(10);//sets the capacity
	//numbers.resize(10);//sets the size!
	Info(numbers);
	for (int i = 0; i < 10; i++)
	{
		numbers.push_back(i);
		Info(numbers);
	}
	const int nConst = 15;

	//copying vectors
	//3 ways:
	std::vector<int> numbers2 = numbers;
	std::vector<int> numbers3(numbers);
	std::vector<int> numbers4;
	numbers4.reserve(numbers.size());
	for (int i = 0; i < numbers.size(); i++)
	{
		numbers4.push_back(numbers[i]);
	}

	std::vector<int> nummies;
	int nummySize = rand();
	std::cout << nummySize << "\n";
	for (int i = 0; i < nummySize; i++)
	{
		nummies.push_back(rand());
	}
	Printer(nummies, 10);//set top to 10

	auto bIT = nummies.begin();//get an iterator to the first item
	int firstNummy = *bIT;//dereference the iterator to access the item
	//loop using iterators
	for (auto it = nummies.begin(); it != nummies.end(); it++)
	{
		//use * to access the item it points to
		std::cout << *it << "\n";
	}

	std::vector<int> nums{ 1,2,2,3,4,5,5,5 };
	Printer(nums);//set top to 0
	//                   { 1,2,3,4,5,5,5}
	//erase all 2's
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 2)
		{
			auto it = nums.begin() + i;//get the iterator to the item
			nums.erase(it);//use the iterator to erase the item
			//move the index backwards
			i--;
		}
	}
	//OR...
	for (int i = 0; i < nums.size();)
	{
		if (nums[i] == 2)
		{
			auto it = nums.begin() + i;//get the iterator to the item
			nums.erase(it);//use the iterator to erase the item
		}
		else {//only increment i when you do NOT erase
			i++;
		}
	}
	//OR...
	//reverse for loop
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		if (nums[i] == 2)
		{
			auto it = nums.begin() + i;//get the iterator to the item
			nums.erase(it);//use the iterator to erase the item
		}
	}
	//OR...
	for (auto it = nums.begin(); it != nums.end(); )
	{
		if (*it == 2)
		{
			it = nums.erase(it);
		}
		else
			it++;
	}

	Printer(nums);

	int vNum = 5;
	//MUST be initialized when creating
	int& numRef = vNum;//'points' numRef to vNum
	numRef++;
	std::cout << vNum << "\n";
	int vNum2 = 10;
	//cannot RESEAT the reference
	//can't point it to another variable
	numRef = vNum2;//only copies vNum2 to numRef (and vNum)
	Incrementer(vNum);
	std::cout << vNum << "\n";


	Day2 day2;

	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Part A-1.0: Calling static methods",
		"2. Part A-1.1: calling non-static methods",
		"3. Part A-1.2: calling non-static methods",
		"4. Part A-1.3: calling non-static methods",
		"5. Part A-1.4: Return Values",
		"6. Part A-1.5: Passing arguments",
		"7. Part A-2: Creating methods\n",
		"8. Part B-1: Pass by reference",
		"9. Part B-2: Const",
		"10. Part B-3: Erasing in a loop\n",
		"11. Part C-1: Default Parameters",
		"12. Part C-2: Copying Vectors\n",
		"13. Exit" };


	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			//
			// part A-1.0: calling methods on the Console class to print messages.
			//
			//	Use Console::Write and Console::WriteLine to print several lines of text (whatever you want to say)
			//  Experiment with changing the colors.
			//  Open the Console.h file (look in Misc/Console in Solution Explorer) to see how the methods are declared.
			//			

			Console::Write("Batman is the best! ", ConsoleColor::Cyan);
			Console::WriteLine("Aquaman smells like fish.", ConsoleColor::Green, ConsoleColor::Yellow);
			Console::WriteLine(5); 
			
			break;
		}
		case 2:
		{
			Day1::PartA_1_1();
			break;
		}
		case 3:
		{
			Day1::PartA_1_2();
			break;
		}
		case 4:
		{
			Day1::PartA_1_3();
			break;
		}
		case 5:
		{
			//
			// part A-1.4: Getting return values
			//	Ask the user to enter their name. Print the name.
			// 
			//	Open Lectures.cpp.
			//	Add code here to call Input::GetString.
			//	Store the result in a string variable.
			//	Print the name that the user enters.
			//	Open the Input.h file(look in Misc / Input in Solution Explorer) to see how the GetString is declared.
			//
			std::string supe = Input::GetString("What is your favorite superhero? ");
			Console::WriteLine("Your favorite is " + supe + "?! Weird.\n");

			break;
		}
		case 6:
		{
			//
			// part A-1.5: passing arguments
			//	Ask the user for their age. A minimum age would be 0 and a maximum age would be 120.
			// 
			//	Open Lectures.cpp.
			//	Add code here to call Input::GetInteger.
			//	Store the result in an int variable.
			//	Print the age that the user enters.
			//	Open the Input.h file(look in Misc / Input in Solution Explorer) to see how the GetInteger is declared.
			//
			break;
		}
		case 7:
		{
			Day1::PartA_2();
			break;
		}
		case 8:
		{
			day2.PartB();
			break;
		}
		case 9:
		{
			day2.PartB(2);
			break;
		}
		case 10:
		{
			day2.PartB(3);
			break;
		}
		case 11:
		{
			Day3::PartC_1();
			break;
		}
		case 12:
		{
			Day3::PartC_2();
			break;
		}
		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());

	return 0;
}


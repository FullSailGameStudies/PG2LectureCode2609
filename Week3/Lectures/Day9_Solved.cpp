// Day09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include ".\Solved\Car_Solved.h"
#include "Polymorphism.h"
#include <vector>
#include <Weapon.h>
#include <SOLVED/Pistol.h>

namespace SOLVED
{
    void Day9()
    {
        /*
            ╔══════════════════╗
            ║  Static Members  ║
            ╚══════════════════╝

            When calling a non-static method on a class, you must use a variable of that class.
            That's because the variable is passed in as the 'this' parameter.

            Static methods do not have a 'this' parameter therefore you call them on the
            class name itself.

            That's also why static methods cannot access non-static members.

        */
        Car myRide(1988, "Ford", "Mustang GT 5.0");
        Car::reporting();
        std::cout << myRide.vehicleInformation();//calling non-static methods. myRide is passed in for 'this'

        /*

            CHALLENGE:
            Add a static method to the Car class that returns an instance of the Car class.

        */
        Car myOtherRide = Car::BuildCar(1988, "Delorean", "DMC-10");




		/*
			╔════════════╗
			║ Unique_ptr ║
			╚════════════╝

			Using unique pointers w/ overridden methods


			╔═══════════╗
			║ UPCASTING ║ - casting a derived type variable to a base type variable
			╚═══════════╝

			This is ALWAYS safe.


			To maintain the original object, we need a pointer though.
			If not, then we're just calling the copy constructor of the base class
			and lose all the info of the derived.

			Unique pointers owns and manages an object through a pointer.
			std::unique_ptr<derived> pDerived = std::make_unique<derived>("Gotham", 5);


			You can UPCAST by using the base type in the unique_ptr.
			std::unique_ptr<base> pBase = std::make_unique<derived>("Gotham", 5);
			  OR
			std::unique_ptr<base> pBase = std::move(pDerived); https://learn.microsoft.com/en-us/cpp/standard-library/utility-functions?view=msvc-170&redirectedfrom=MSDN&f1url=%3FappId%3DDev16IDEF1%26l%3DEN-US%26k%3Dk(std%253A%253Amove)%3Bk(move)%3Bk(DevLang-C%252B%252B)%3Bk(TargetOS-Windows)%26rd%3Dtrue#move

		*/
		derived der1("Gotham", 1);//stack instance
		der1.print();
		base b1 = der1;//COPIED der1 to a new object, b1.
		b1.print();

		std::unique_ptr<derived> pDerived = std::make_unique<derived>("Gotham", 1);
		pDerived->print();


		std::unique_ptr<base> pBase = std::move(pDerived);//upcasting. ALWAYS safe


		/*

			CHALLENGE:
			Create a vector that holds unique pointers of Weapon.
			Create instances of Weapon and Pistol using make_unique.
			Add them to the vector.

			Loop over the vector and call showMe on each weapon.

		*/
		std::vector<std::unique_ptr<Weapon>> backpack;

		backpack.push_back(std::make_unique<Weapon>(rand(), rand()));
		backpack.push_back(std::make_unique<Weapon>(rand(), rand()));
		backpack.push_back(std::make_unique<Weapon>(rand(), rand()));
		backpack.push_back(std::make_unique<Pistol>(rand(), rand(), rand(), rand()));
		backpack.push_back(std::make_unique<Pistol>(rand(), rand(), rand(), rand()));
		backpack.push_back(std::make_unique<Pistol>(rand(), rand(), rand(), rand()));
		backpack.push_back(std::make_unique<Pistol>(rand(), rand(), rand(), rand()));
		std::cout << "\n\n---Weapons---\n";
		for (auto& weapon : backpack)
			weapon->showMe();
    }
}
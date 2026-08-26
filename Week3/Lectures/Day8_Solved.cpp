// Day08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include "Inheritance.h"
#include "Polymorphism.h"
#include ".\SOLVED\FlyingCar.h"
#include <vector>
#include ".\SOLVED\Pistol.h"

namespace SOLVED
{
	void Day8()
	{
		/*
			Inheritance

									╔═════════╗     ╔══════════╗
							 class  ║SomeClass║  :  ║OtherClass║
									╚═════════╝     ╚══════════╝
										 │                │
										 └──┐             └──┐
									   ┌────▼────┐      ┌────▼────┐
									   │ Derived │      │  Base   │
									   │  Class  │      │  Class  │
									   └─────────┘      └─────────┘

				Access modes:
					public inheritance:
					protected inheritance:
					private inheritance: (default if not specified)



					CONSTRUCTORS: the derived constructor must call a base constructor
					public SomeClass(.....) : baseClass(....)


			CHALLENGE:

				add a new class, Pistol, that derives from Weapon.
				Pistol should have fields with getters/setters for rounds and magCapacity.
				Add a constructor that calls the base constructor

		*/
		FlyingCar jetsons(5000, 2050, "Tesla", "XPlane");


		/*

			COMPILE-TIME Polymorphism

			Method Overloading:
				- changing the number of parameters
				- changing the types of the parameters



			CHALLENGE:
				Add an OVERLOAD of the calcDamage method in the Weapon class.
				The overload should take an int parameter called modifier
				to increase the damage when calculating the damage.

		*/





		/*

			COMPILE-TIME Polymorphism

			Operator Overloading
			overload the + in the Pistol class to add 2 pistols
				- it sets the magCapacity to the max of the 2 pistols
				- adds the # of rounds from both pistols. should not exceed the magCapacity.

		*/






		/*

			RUNTIME Polymorphism

			╔═════════════╗
			║ OVERRIDING  ║ - changing the behavior of a base method
			╚═════════════╝

			1) add 'virtual' to the base method
			2) add a method to the derived class that has the same signature as the base.
				OPTIONALLY put 'override' on the derived method


			FULLY OVERRIDING:
				not calling the base method from the derived method

			EXTENDING:
				calling the base method from the derived method
				to call the base method...  baseClassName::method(...)



			CHALLENGE:
				Override Weapon's showMe method in the Pistol class.
				In Pistol's version, call the base version then print out the rounds and magCapacity



		*/




	}

}
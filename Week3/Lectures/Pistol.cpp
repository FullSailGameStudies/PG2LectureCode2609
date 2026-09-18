#include "Pistol.h"
#include <iostream>

//we have to call the Weapon ctor
//we use the member intialization list

//there is an ORDER to the ctor calls:
//	base ctor FIRST then the derived ctor
Pistol::Pistol(int range, int damage, int rounds, int magCap) :
	Weapon(range, damage), //call the weapon ctor
	mRounds(rounds),
	mMagCapacity(magCap)
{
	//do NOT duplicate what the Weapon ctor does

}

int Pistol::calcDamage()
{
	return Weapon::calcDamage();
}

void Pistol::showMe()
{
	//What kind of override do we need?
	//	FULL override (we ONLY want the new logic)
	//		this means we do NOT call the base method
	// 
	//  EXTENSION override (we want the base logic + new logic)
	//		this means we call the base method at some point

	std::cout << "PISTOL: " << mRounds << " / " << mMagCapacity << " ";
	Weapon::showMe();//call the base method
}

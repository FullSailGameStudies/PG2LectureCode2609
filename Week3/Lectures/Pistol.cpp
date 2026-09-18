#include "Pistol.h"

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

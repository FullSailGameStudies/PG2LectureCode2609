#pragma once
#include "Weapon.h"

//OOP Terms:
//  IS-A relationship
//		EX: Pistol IS-A Weapon
//
// EVERYTHING that is in Weapon is now in Pistol
class Pistol : public Weapon
{
public:
	//the compiler can't create the default ctor
	//because the weapon class does NOT have a default ctor
	//so the compiler "deletes" the default ctor
	//Therefore, we MUST create a ctor

	//child ctors MUST call a parent ctor
	Pistol(int range, int damage, int rounds, int magCap);

	Pistol operator+(Pistol& other)
	{
		Pistol p3(range(), damage(), mRounds + other.mRounds, mMagCapacity);
		return p3;
	}

	void showMe();

	int Rounds() const { return mRounds; }
	void Rounds(int rounds)
	{
		if (rounds >= 0 and rounds <= mMagCapacity)
		{
			mRounds = rounds;
		}
	}
	int MagCapacity() const { return mMagCapacity; }
	void MagCapacity(int magCapacity)
	{
		if (magCapacity > 0 and magCapacity <= 32)
		{
			mMagCapacity = magCapacity;
		}
	}

private:
	int mRounds, mMagCapacity;

};


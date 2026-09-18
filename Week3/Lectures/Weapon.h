#pragma once
class Weapon
{
private:
	int mRange;
	int mDamage;

public:
	Weapon(int range, int damage);

	virtual void showMe();
	virtual int calcDamage() = 0;//makes this function a pure virtual function
	//AND makes the class an Abstract Base Class
	//that means I cannot create a Weapon object by itself
	//all descendent classes that should not be abstract
	// MUST override the calcDamage method

	int range() const
	{
		return mRange;
	}
	int damage() const
	{
		return mDamage;
	}
};


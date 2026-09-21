#pragma once
class Weapon
{
private:
	int mRange;
	int mDamage;

public:
	Weapon(int range, int damage);

	//destructor (runs when the object is destroyed)
	//	when is it destroyed?
	//    for stack variables, when they go out scope
	//	  for heap variables, when 'delete' is called on them
	//  purpose? to free up resources
	// the compiler gives us a default IF we don't write one
	// there can be ONLY 1 destructor
	// for polymorphic situations, the base destructor needs to be virtual
	virtual ~Weapon() = default;

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


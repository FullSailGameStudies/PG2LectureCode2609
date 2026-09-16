#pragma once
//only #include what this file needs to compile
#include <string>

//class declaration:
//  what the class can DO (member functions)
//  what describes the class (data members)
class Player
{
	//access modifiers:
	// control what other code can access
	//you can have any number of these

public:
	//ALL code can see it

	//constructors:
	//  IF you do not create a ctor for your class,
	//		the compiler will create a default ctor for you
	//  IF you create a ctor for your class,
	//		the compiler will NOT create a default ctor for you
	//  - purpose: to initialize the fields of the class
	//  - can have as many as needed
	//  - they can have any access modifier
	//	- they MUST be named the same as the class
	//  - they can NOT have any return type specified (not even void)
	Player(int health, const std::string& gamerTag);

	//getters and setters
	//the "gatekeepers" of your data. they control the access
	//to the fields
	// are usually DEFINED in the header b/c the compiler
	//		can optimize their usage
	//
	//getters (accessors)
	//  return type matches the type of the field
	//  usually no parameters
	//  they are 'const' functions (they should not change the object)
	int GetHealth() const
	{
		return health_;
	}

	//setters (mutators)
	//  return type is usually void
	//  usually at least 1 parameter that's the same type as the field
	//  can't be const b/c they need to update the field
	//  usually some validation on the parameter to ensure
	//		that the field isn't set to a value that is invalid
	void SetHealth(int health)
	{
		//the validation logic
		if (health >= 0 and health <= 100)
		{
			health_ = health;
		}
	}

	//alternative naming (more "modern")
	const std::string& GamerTag() const { return gamerTag_; }
	void GamerTag(const std::string& gamerTag)
	{
		if (gamerTag.size() > 0 && gamerTag.size() < 32)
		{
			gamerTag_ = gamerTag;
		}
	}

protected:
	//this class and all descendents of this class
	//can see it

private: //is the default
	//ONLY this class can see it*
	//   * - there are some exceptions to this rule

	//FIELDS:
	//  data members of the class
	//  probably should be private (protect the data!!)
	//  naming convention:
	//		camelCasingNamingConvention
	//		we add something to make fields standout
	//		from other variables
	//		ex: m_iHealth, m_health, mHealth, _health, health_
	//		RULE: be consistent. ONLY USE ONE way
	int health_;
	std::string gamerTag_;

};


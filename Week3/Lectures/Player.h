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


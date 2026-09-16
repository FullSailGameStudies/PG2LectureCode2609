#include "Player.h"

//use the member initialization list to initialize the fields
//  it is the preferred way to initialize your fields
//	sometimes, it is the ONLY way to initialize your fields
Player::Player(int health, const std::string& gamerTag) :
	//fields are initialized FIRST in the member initialization list
	health_(health),
	gamerTag_(gamerTag)
	//references and const fields
	//MUST be initialized here

	//also, for types that DON'T have a default ctor,
	//they must be initialized here too
{
	//health_ = health;
	//gamerTag_ = gamerTag;//it is initialized twice!
}

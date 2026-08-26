#include "Zombie.h"

Zombie::Zombie(PG2Texture* texture, PG2Graphics* engine, float scale) :
	GameObject(texture, engine, scale)
{
}

Zombie::Zombie(PG2Graphics* engine, float scale, int xPos, int yPos) :
	GameObject(engine, "zombie.png", scale, xPos, yPos)
{
	//future: add zombie sounds?
}

Zombie::~Zombie()
{
	FreeResources();
}

void Zombie::FreeResources()
{
	//future: release zombie sounds?
}
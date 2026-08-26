#pragma once
#include "GameObject.h"
#include <vector>
#include <string>

class Zombie : public GameObject
{
public:
	Zombie(PG2Texture* texture, PG2Graphics* engine, float scale = 1);
	Zombie(PG2Graphics* engine, float scale = 1, int xPos = 0, int yPos = 0);
	~Zombie();

private:
	void FreeResources() override;
};


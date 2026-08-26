#pragma once
#include "Light.h"
#include "Map.h"
#include <map>

class Grouper
{
public:


	void MakeRedLights(std::vector<Light>& lights);
	void MakeGreenLights(std::vector<Light>& lights);
	void MakeLights(std::vector<Light>& lights);
	void DrawLights(const Map& map, const std::vector<Light>& lights, int columnRange, int& col, int& row);
private:

};


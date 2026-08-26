#pragma once
#include <vector>
#include "Target.h"

enum ColorChannel
{
	RED, GREEN, BLUE
};
class Day3
{
public:
	static void PartC_1();
	static void PartC_2();

private:
	//
	// Part C-1.1: add a default value
	//
	static void ShiftColor(std::vector<Target>& lights, std::vector<int>& offsets, ColorChannel channelToShift);

	static void MakeLights(std::vector<Target>& lights);
	static void MakeLights(std::vector<Target>& lights, std::vector<int>& offsets, int offset = 5);

	static void RemoveLights(std::vector<Target>& lights, ColorChannel channelToRemove);
};

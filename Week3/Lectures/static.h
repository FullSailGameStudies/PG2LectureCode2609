#pragma once

#include <iostream>


void demo()
{
	static int count = 0; //created once
	std::cout << count << " ";
	count++;
}
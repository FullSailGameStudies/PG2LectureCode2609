#pragma once
#include <string>
#include <vector>
class Control
{
public:
	Control(std::string action) : action_(action) {}

	/*
		(Day 01) Practice 04: declaring methods

		Declarations to add:
			AddKey. String parameter.
			Show. no parameters

	*/
	void AddKey(std::string key);
	void Show();


	/*
		(Day 02) Practice 02: const parameters

		modify AddKeys to make the parameter const & 

	*/
	void AddKeys(const std::vector<std::string>& keys);

private:
	std::string action_;
	std::vector<std::string> keys_;
};


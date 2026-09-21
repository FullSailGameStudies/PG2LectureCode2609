#pragma once
#include <string>
#include <iostream>

class Car
{
public:
	Car() : mMake("Ford"), mModel("A"), mModelYear(1908), mFuelLevel(0), mMaxFuelLevel(15)
	{
		mNumberOfCarsMade++;

	}

	Car(int year, std::string make, std::string model)
		: mModelYear(year), mMake(make), mModel(model), mFuelLevel(0), mMaxFuelLevel(15)
	{
		mNumberOfCarsMade++;
	}

	//NON-static member function
	//it does NOT mean that each object
	//has its own copy of this function
	//
	std::string vehicleInformation();

	void refuel()
	{
		mFuelLevel = mMaxFuelLevel;
	}

	//STATIC member functions
	//they do NOT have a 'this' parameter
	//static functions can ONLY access other static members
	//static functions can NOT access non-static members
	static void reporting()
	{
		//std::cout << "Model year: " << mModelYear << "\n"; //ERROR! cannot access non-static members
		std::cout << "Number of cars made: " << mNumberOfCarsMade << "\n";
	}

	//getter (accessor)
	int modelYear() const
	{
		return mModelYear;
	}

	//setter (mutator)
	void modelYear(int newModelYear)
	{
		if (newModelYear > 1908 && newModelYear < 2100)
		{
			mModelYear = newModelYear;
		}
	}

private:
	//NON-static data members
	//EACH car object, has its own set
	//of these variables
	//object-level data
	int mModelYear;
	std::string mModel;
	std::string mMake;

	int mFuelLevel;
	int mMaxFuelLevel;

	//STATIC data member
	//there is ONLY ONE of these
	//for ALL objects
	//class level data, not object level
	static int mNumberOfCarsMade; //shared by ALL cars
};


#include "Car.h"


//initialize explicitly using the class name scoping
int Car::mNumberOfCarsMade = 0;


std::string Car::vehicleInformation()
{
	return std::to_string(mModelYear) + " " + mMake + " " + mModel;
}

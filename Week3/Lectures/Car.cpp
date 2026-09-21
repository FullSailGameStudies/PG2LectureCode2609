#include "Car.h"


//initialize explicitly using the class name scoping
int Car::mNumberOfCarsMade = 0;


//there is only 1 copy of this code in memory
//how does this code get the correct year+make+model?
//there is a HIDDEN parameter called `this`
//`this` is a pointer to the object that the function
//was called on
// 
//non-static functions can access both static AND non-static members
std::string Car::vehicleInformation()
{
	return std::to_string(this->mModelYear) + " " + 
		this->mMake + " " + this->mModel;
}

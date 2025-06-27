#ifndef GROUNDVEHICLE_H
#define GROUNDVEHICLE_H

#include "Vehicle.h"

class GroundVehicle : public Vehicle {
private:
	int timeToRest;
	double firstRest;
	double secondRest;
	double otherRest;
	double restTime(int numberOfRests);
public:
	GroundVehicle(int speed, int timeToRest, int firstRest, int secondRest, int otherRest, int distance, std::string name) :
		Vehicle(speed, "ground", distance, name),
		timeToRest (timeToRest),
		firstRest(firstRest),
		secondRest(secondRest),
		otherRest(otherRest)
	{}
	double getRaceTime();
};

#endif
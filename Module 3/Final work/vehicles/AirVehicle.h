#ifndef AIRVEHICLE_H
#define AIRVEHICLE_H

#include "Vehicle.h"

class AirVehicle : public Vehicle {

public:
	AirVehicle(int speed, int distance, std::string name) :
		Vehicle(speed, "air", distance, name)
	{}
	double getRaceTime();
};

#endif
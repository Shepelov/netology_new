#ifndef BROOM_H
#define BROOM_H

#include "AirVehicle.h"

class Broom : public AirVehicle {
public:
	Broom (int distance) :
		AirVehicle(20, reductionDistance(distance), "Метла")
	{}
	int reductionDistance(int distance);
};

#endif
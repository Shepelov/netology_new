#ifndef EAGLE_H
#define EAGLE_H

#include "AirVehicle.h"

class Eagle : public AirVehicle {
public:
	Eagle (int distance) :
		AirVehicle(8, reductionDistance(distance), "Орел")
	{}
	int reductionDistance(int distance);
};

#endif
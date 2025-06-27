#include "AirVehicle.h"

double AirVehicle::getRaceTime() {
	double time = getDistance() / getSpeed();

	return time;
}
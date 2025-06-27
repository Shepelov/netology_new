#include "Vehicle.h"

double Vehicle::getSpeed() {
	return speed;
}

int Vehicle::getDistance() {
	return distance;
}

bool Vehicle::regist() {
	if (registered == false) {
		registered = true;
		return true;
	}
	else {
		return false;
	}
}

std::string Vehicle::getName() {
	return name;
}
#include "GroundVehicle.h"

double GroundVehicle::getRaceTime() {
	double time = getDistance() / getSpeed();
	int numberOfRests = static_cast<int>(time) / timeToRest;
	if (static_cast<int>(time) % timeToRest == 0) { //исключаем отдых на финише
		numberOfRests--;
	}
	time = time + restTime(numberOfRests);

	return time;
}

double GroundVehicle::restTime(int numberOfRests) {
	switch (numberOfRests) {
	case 0:
		return 0;
	case 1:
		return firstRest;
	case 2:
		return firstRest + secondRest;
	default:
		return firstRest + secondRest + otherRest * (numberOfRests - 2);
	}
}
#ifndef CAMEL_H
#define CAMEL_H

#include "GroundVehicle.h"

class Camel : public GroundVehicle {
public:
	Camel(int distance) : GroundVehicle(10, 30, 5, 8, 8, distance, "Βεπαδώδ") {}
};

#endif
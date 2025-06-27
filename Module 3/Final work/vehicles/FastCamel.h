#ifndef FASTCAMEL_H
#define FASTCAMEL_H

#include "GroundVehicle.h"

class FastCamel : public GroundVehicle {
public:
	FastCamel(int distance) : GroundVehicle(40, 10, 5, 6.5, 8, distance, "Верблюд-быстроход") {}
};

#endif
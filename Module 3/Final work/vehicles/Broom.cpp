#include "Broom.h"

int Broom::reductionDistance(int distance) {
	return distance * (1.0 - distance / 100000.0);
}
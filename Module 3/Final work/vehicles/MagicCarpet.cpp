#include "MagicCarpet.h"

int MagicCarpet::reductionDistance(int distance) {
	if (distance < 1000) {
		return distance;
	}

	else if (distance < 5000) {
		return distance * 0.97;
	}

	else if (distance < 10000) {
		return distance * 0.9;
	}

	else {
		return distance * 0.95;
	}
}
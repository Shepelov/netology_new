#ifndef RHOMB_H
#define RHOMB_H

class Rhomb : public Quadangle {
public:
	Rhomb(int a, int A, int B)
		: Quadangle(a, a, a, a, A, B, A, B, "Ромб") {}
};

#endif
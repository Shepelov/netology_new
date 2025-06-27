#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
private:
	std::string type;
	bool registered;
	int speed;
	int distance;
	std::string name;
public:
	Vehicle(int speed, std::string type, int distance, std::string name) {
		this->speed = speed;
		this->type = type;
		this->registered = false;
		this->distance = distance;
		this->name = name;
		}
	double getSpeed();
	int getDistance();
	std::string getName();
	bool regist();
};

#endif
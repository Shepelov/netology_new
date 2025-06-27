#include "Counter.h"

#include <iostream>

void Counter::setStartValue(int value) {
	count = value;
}

void Counter::decrease() {
	--count;
}

void Counter::increase() {
	++count;
}

void Counter::show() {
	std::cout << count << std::endl;
}
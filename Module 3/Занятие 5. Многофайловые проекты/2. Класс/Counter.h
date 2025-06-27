#ifndef COUNTER_H
#define COUNTER_H

class Counter
{
private:
	int count{0};
public:
	void setStartValue(int value);
	void decrease();
	void increase();
	void show();
};

#endif
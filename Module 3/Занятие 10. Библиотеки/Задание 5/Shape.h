#ifndef SHAPE_H
#define SHAPE_H
class Shape
{
private:
	int sides;
public:
	Shape(int sides) : sides(sides) {}
	virtual void print_info() {}
};
#endif
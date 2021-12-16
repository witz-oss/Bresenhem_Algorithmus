#pragma once
#include "Frame.h"
#include "Shape.h"
class Kreis : public Shape
{
public:
	Kreis(int, int, int);									// start_x, start_y, diametr
	void draw(Frame*);
	void move(int, int);
private:
	int start_x{};
	int start_y{};
	int diametr{};
};


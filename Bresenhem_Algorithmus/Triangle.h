#pragma once
#include "Frame.h"
#include "Shape.h"
#include "Line.h"
class Triangle : public Shape
{
public:
	Triangle() = delete;
	Triangle(int, int, int, int, int);						// start_x, start_y, len1, len2, len3
	//~Triangle();
	void fehlendePunkte();
	void draw(Frame*)const;
	void move(int, int);
private:
	int start_x{};
	int start_y{};
	int end_y{};
	int spitze_x{};
	int spitze_y{};
	int len1{};
	int len2{};
	int len3{};
};


#include "Line.h"

Line::Line(int start_x, int start_y, int end_x, int end_y)
{
	this->start_x = start_x;
	this->start_y = start_y;
	this->end_x = end_x;
	this->end_y = end_y;

	if (start_y > end_y)												// immer von links nach rechts
	{
		swap(&start_x, &end_x);
		swap(&start_y, &end_y);
	}
}

void Line::set(int start_x, int start_y, int end_x, int end_y)
{
	// soll da Frame::reset() ausgerufen sein ?
	this->start_x = start_x;					
	this->start_y = start_y;					
	this->end_x = end_x;
	this->end_y = end_y;

	return;
}

void Line::draw(Frame* frm)const										
{
	int stepX{ start_x < end_x ? 1 : -1 };
	int stepY{ start_y < end_y ? 1 : -1 };
	int deltaY{ end_y - start_y };
	int deltaX{ end_x - start_x };
	int error{};
	if (deltaX < 0)
		deltaX *= -1;
	if (deltaY < 0)
		deltaY *= -1;

	int drawX{ start_x };
	int drawY{ start_y };

	if (deltaY > deltaX)
	{
		error = deltaY / 2;
		while (drawX != end_x || drawY != end_y + 1)		// (20, 5, 5, 30) start_x, start_y, end_x, end_y
		{
			frm->put_point(drawX, drawY);
			drawY++;
			error -= deltaX;
			if (error < 0 && drawX != end_x)
			{
				drawX += stepX;
				error += deltaY;
			}
		}
	}
	else
	{
		error = deltaX / 2;
		while (drawX != end_x + 1 || drawY != end_y)
		{
			frm->put_point(drawX, drawY);
			drawX++;
			error -= deltaY;
			if (error < 0 && drawY != end_y)
			{
				drawY += stepY;
				error += deltaX;
			}
		}
	}

	return;
}

void Line::move(int h, int v)
{
	start_x += h;
	end_x += h;
	start_y += v;
	end_y += v;

	return;
}



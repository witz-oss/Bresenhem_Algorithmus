#include "Kreis.h"

Kreis::Kreis(int start_x, int start_y, int diametr)
{
	this->start_x = start_x;
	this->start_y = start_y;
	this->diametr = diametr;
}

void Kreis::draw(Frame* frm)
{

}

void Kreis::move(int h, int l)
{
	this->start_x += h;
	this->start_y += l;
}

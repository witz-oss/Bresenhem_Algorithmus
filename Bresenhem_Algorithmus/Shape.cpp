#include "Shape.h"

Shape* Shape::last{ nullptr };

Shape::Shape()
{
	prev = last;
	last = this;
}

void Shape::show_all_shapes(Frame* frm)
{
	frm->showCoutPut();
}
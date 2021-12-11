#include "Shape.h"

Shape* Shape::last{ nullptr };

Shape::Shape()
{
	prev = last;
	last = this;
}

void Shape::show_all_shapes(Frame* frm)
{

	//frm->showCoutPut();

	while (last != nullptr)
	{
		frm->reset();
		last->draw(frm);
		frm->showCoutPut();
		last = last->prev;
	}

	//for (; last != nullptr; last = last->prev)
	//{
		//frm->reset();
		//last->draw(frm);
		//frm->showCoutPut();
	//}
}
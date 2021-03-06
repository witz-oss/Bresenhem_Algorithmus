#include "Shape.h"

Shape* Shape::last{ nullptr };

Shape::Shape()
{
	prev = last;
	last = this;
}

void Shape::show_all_shapes(Frame* frm)
{
	auto lastP = last;			 
	while (last != nullptr)
	{
		lastP = last;			
		frm->reset();
		last->draw(frm);
		frm->show();
		last = lastP;			
		last = last->prev;
	}

	//for (Shape* p{ last }; p != nullptr; p = p->prev)
	//{
		//p->draw(frm);
		//frm->show();
		//frm->reset();
	//}

	return;
}


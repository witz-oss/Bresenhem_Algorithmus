#include "Frame.h"
#ifndef SHAPE_H
#define SHAPE_H
class Shape
{
public:
	Shape();
	//virtual ~Shape();												// soll da so sein ??? (diese class ist complet virtual (basis class))
	static void show_all_shapes(Frame*);							// gibt alle Shape objeckte auf Frame aus
	virtual void draw(Frame* target)const = 0;						// reine virtuelle funktion 
	virtual void move(int, int) = 0;								// reine virtuelle funktion
private:
	static Shape* last; //last[nullpte]->last[1]->last[2]
	Shape* prev;		//prev[1] <- prev[2] <- last
};

#endif // !S
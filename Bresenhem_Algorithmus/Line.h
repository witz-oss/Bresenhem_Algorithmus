#ifndef LINE_H
#define LINE_H

#include "Shape.h"
#include "Frame.h"

class Line : public Shape
{
public:
	Line() = delete;					// нахуй удалит без переменных
	Line(int, int, int, int);
	//~Line();							// он типа нужен ведь ??
	void set(int, int, int, int);
	void draw(Frame*);//const;
	void move(int, int);
private:
	int start_x{};
	int start_y{};
	int end_x{};
	int end_y{};
};

#endif // !LINE_H
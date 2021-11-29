#include <iostream>
#include <array>
#ifndef FRAME_H
#define FRAME_H

const int wide{ 55 };
const int high{ 34 };

class Frame
{
public:
	enum color { black = ' ', white = '*' };
	Frame();
	friend std::ostream& operator<<(std::ostream&, const Frame&);
	void reset();											// Frame leeren
	void put_point(int, int);								// Punkt im Frame speichern
	void show()const;										// Frame auf die Konsole ausgeben
	void showCoutPut()const;								// Frame auf die Konsole mit cout.put() ausgibt
	bool on_frame(int, int)const;							// "Clipping" 
private:
	std::array<std::array<Frame::color, wide>, high> frm;
};

template<typename T>
void swap(T* a, T* b)
{
	T temp{ *a };
	*a = *b;
	*b = temp;
}

#endif // !FRAME_H


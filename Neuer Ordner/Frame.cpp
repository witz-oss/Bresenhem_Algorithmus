#include "Frame.h"

Frame::Frame() :
	frm{}
{
	for (int i{}; i < high; ++i)
		for (int j{}; j < wide; ++j)
			frm[i][j] = Frame::black;
}

Frame::Frame(const Frame* other)
{
	this->frm = other->frm;
}

Frame& Frame::operator=(const Frame& other)
{
	if (this == &other)
		return *this;

	for (int i{}; i < high; ++i)
		for (int j{}; j < wide; ++j)
			this->frm[i][j] = other.frm[i][j];
	return *this;
}

void Frame::reset()
{
	for (int i{}; i < high; ++i)
		for (int j{}; j < wide; ++j)
			frm[i][j] = Frame::black;
}

void Frame::put_point(int pWide, int pHigh)
{
	if (on_frame(pWide, pHigh) == true)
		frm[pWide][pHigh] = Frame::white;
	else
		throw std::runtime_error("ausser Matrix");
}

void Frame::show() const
{
	std::cout << *this;
}

void Frame::showCoutPut() const
{
	for (int i{}; i < high; ++i)
	{
		for (int j{}; j < wide; ++j)
		{
			if (frm[i][j] == Frame::black)
				std::cout.put(' ');
			else
				std::cout.put('*');
		}
		std::cout << std::endl;
	}
}

bool Frame::on_frame(int x, int y) const
{
	if (x < wide && y < high && x >= 0 && y >= 0)
		return true;
	return false;
}

std::ostream& operator<<(std::ostream& os, const Frame& frame)
{
	for (int i{}; i < high; ++i)
	{
		for (int j{}; j < wide; ++j)
		{
			if (frame.frm[i][j] == Frame::black)
				os << ' ';
			else
				os << '*';
		}
		os << std::endl;
	}
	return os;
}
#include "Triangle.h"

Triangle::Triangle(int start_x, int start_y, int len1, int len2, int len3)
{
	if (len1 >= len2 && len2 >= len3 && len1 > 0 && len2 > 0 && len3 > 0)
	{
		this->start_x = start_x;
		this->start_y = start_y;
		this->len1 = len1;
		this->len2 = len2;
		this->len3 = len3;
	}
	else
		throw std::runtime_error("die Lenge der Seiten nicht stimmen !!!!");

	fehlendePunkte();
}

void Triangle::fehlendePunkte()
{
	this->end_y = start_y + len1;
	int z{};
	z = (pow(len1, 2) - pow(len2, 2) + pow(len3, 2)) / (2 * len1);
	int h{};
	h = sqrt(pow(len3, 2) - pow(z, 2));

	if ((len2 + len3) < len1)
		throw std::exception("len2 + len3 kann nicht kleine als len1 sein");

	spitze_x = start_x - h;
	spitze_y = start_y + z;
}

void Triangle::draw(Frame* frm)const
{
	int drawY{ start_y };

	Line line1(start_x, start_y, spitze_x, spitze_y);
	line1.draw(frm);
	Line line2(start_x, start_y, start_x, end_y);
	line2.draw(frm);
	Line line3(spitze_x, spitze_y, start_x, end_y);
	line3.draw(frm);
}

void Triangle::move(int h, int l)
{
	this->start_x += h;
	this->start_y += l;
}

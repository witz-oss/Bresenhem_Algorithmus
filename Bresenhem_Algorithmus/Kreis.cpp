#include "Kreis.h"

Kreis::Kreis(int start_x, int start_y, int radius)
{
	this->start_x = start_x;
	this->start_y = start_y;
	this->radius = radius;
}

void Kreis::draw(Frame* frm)const
{
	int topX{ start_x - radius };
	int buttomX{ start_x + radius };
	int permYpl{ start_y };
	int permYmn{ start_y };

	int radiusX{};
	int radiusXY{};
	int radiusY{};
	int diff1{};
	int diff2{};
	int diff3{};

	frm->put_point(topX, start_y);
	frm->put_point(buttomX, start_y);

	while (topX != start_x)
	{
		radiusX = sqrt(pow((topX - start_x + 1), 2) + pow((permYpl - start_y), 2));
		radiusXY = sqrt(pow((topX - start_x + 1), 2) + pow((permYpl - start_y + 1), 2));
		radiusY = sqrt(pow((topX - start_x), 2) + pow((permYpl - start_y + 1), 2));

		diff1 = radiusX - radius;
		if (diff1 < 0)
			diff1 *= -1;
		diff2 = radiusXY - radius;
		if (diff2 < 0)
			diff2 *= -1;
		diff3 = radiusY - radius;
		if (diff3 < 0)
			diff3 *= -1;

		if (diff1 < diff2)
		{
			topX++;
			buttomX--;
		}
		else
		{
			if (diff2 < diff3)
			{
				topX++;
				buttomX--;
				permYpl++;
				permYmn--;
			}
			else
			{
				permYpl++;
				permYmn--;
			}
		}
		frm->put_point(topX, permYpl);		// 1/4
		frm->put_point(buttomX, permYmn);	// 3/4
		frm->put_point(buttomX, permYpl);	// 2/4	
		frm->put_point(topX, permYmn);		// 4/4	
	}
	//  vlt 1/8 wäre besser
	return;
}

void Kreis::move(int h, int l)
{
	this->start_x += h;
	this->start_y += l;

	return;
}

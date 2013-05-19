#include "..\Main.h"

#ifndef _aitest_RECTANGLE_H
#define _aitest_RECTANGLE_H

namespace ait
{
	class Rectangle : public Shape
	{
	public:
		Rectangle(Vector2D<double> pos, double width, double height)
		{
			mShape = sf::Shape::Rectangle((float)pos.x, (float)pos.y,
											(float)(pos.x+width), (float)(pos.y+height),
											sf::Color(0,0,0,255));
			SetPos(pos);
		}

		void Draw()
		{

		}
	};
};

#endif


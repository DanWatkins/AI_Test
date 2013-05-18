#ifndef _aitest_RECTANGLE_H
#define _aitest_RECTANGLE_H

class Rectangle : public Shape
{
public:
	Rectangle(Vector2D<double> pos, double width, double height)
	{
		mShape = sf::Shape::Rectangle(pos.x, pos.y, pos.x+width, pos.y+height, sf::Color(0,0,0,255));
		SetPos(pos);
	}

	void Draw()
	{

	}
};

#endif


#include "Obstacle.h"

namespace ait
{
	void Obstacle::Write(std::ostream &os)
	{
		os << std::endl;
		os << EntityType() << ",";
		os << GetPos().x << GetPos().y << ",";
		os << GetBoundingRadius();
	}


	void Obstacle::Read(std::ifstream &in)
	{
		double x, y, r;

		in >> x >> y >> r;
		SetPos(Vector2D<double>(x,y));
		SetBoundingRadius(r);
	}
};
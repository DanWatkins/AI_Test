#include "..\Main.h"

#ifndef _aitest_OBSTACLE_H
#define _aitest_OBSTACLE_H

namespace ait
{
	class Obstacle : public Entity
	{
	public:
		Obstacle(double x, double y, double r);
		Obstacle(Vector2D<double> pos, double radius);

		virtual ~Obstacle() {}

		void Update(double timeElapsed);
		void Render() {} //TODO Implement

		void Write(std::ostream &os);
		void Read(std::ifstream &in);
	};
};

#endif


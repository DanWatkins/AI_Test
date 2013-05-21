#include "..\Main.h"

#ifndef _aitest_WORLD_H
#define _aitest_WORLD_H

namespace ait
{
	class World
	{
	private:
		std::vector<Vehicle*> mVehicles;
		std::vector<Entity*> mObstacles;
		

		bool mPaused;
	};
};

#endif


#include "..\Main.h"

#ifndef _aitest_VEHICLE_H
#define _aitest_VEHICLE_H

namespace ait
{
	class Vehicle : public MovingEntity
	{
	private:
		World *mWorld;
		//SteeringBehaviors *mSteeringBehaviors;

	public:
		Vehicle() { mWorld = NULL; }

		void Update(double timeElapsed);
	};
};

#endif


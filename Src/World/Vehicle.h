#include "..\Main.h"

#ifndef _aitest_VEHICLE_H
#define _aitest_VEHICLE_H

namespace ait
{
	class Vehicle : public MovingEntity
	{
	private:
		World *mWorld;
		SteeringBehavior *mSteeringBehavior;
		Smoother< Vector2D<double> > *mHeadingSmoother;
		Vector2D<double> mSmoothedHeading;
		bool mSmoothingOn;
		double mTimeElapsed;
		std::vector< Vector2D<double> > mVehicleVB;

		void InitBuffer();
		Vehicle(const Vehicle&);
		Vehicle & operator=(const Vehicle&);


	public:
		Vehicle(World *world, Vector2D<double> pos, double rotation, Vector2D<double> velocity,
				double mass, double maxForce, double maxSpeed, double maxTurnRate, double scale);
		~Vehicle();

		void Update(double timeElapsed);
		void Draw();

		SteeringBehavior* const GetSteeringBehavior() { return mSteeringBehavior; }
		World* const GetWorld() { return mWorld; }

		Vector2D<double> SmoothedHeading() { return mSmoothedHeading; }
		bool IsSmoothingOn() { return mSmoothingOn; }
		void SetSmoothing(bool smoothing) { mSmoothingOn = smoothing; }
		void ToggleSmoothing() { mSmoothingOn = !mSmoothingOn; }
		double GetTimeElapsed() { return mTimeElapsed; }
	};
};

#endif


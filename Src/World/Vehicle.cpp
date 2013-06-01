#include "Vehicle.h"

namespace ait
{
	Vehicle::Vehicle(World *world, Vector2D<double> pos, double rotation, Vector2D<double> velocity,
				double mass, double maxForce, double maxSpeed, double maxTurnRate, double scale)
	{
		MovingEntity(pos, scale, velocity, maxSpeed, Vector2D<double>(sin(rotation),-cos(rotation)), mass, Vector2D<double>(scale,scale), maxTurnRate, maxForce);

		mWorld = world;
		mSmoothedHeading = Vector2D<double>(0.0,0.0);
		mSmoothingOn = false;
		mTimeElapsed = 0.0;

		InitBuffer();
		mSteeringBehavior = new SteeringBehavior(this);
		mHeadingSmoother = new Smoother< Vector2D<double> >(0.0,0.0); //TODO FINISH THIS LINE
	}


	Vehicle::~Vehicle()
	{
		delete mSteeringBehavior;
		delete mHeadingSmoother;
	}

	void Vehicle::Update(double timeElapsed)
	{
		mTimeElapsed = timeElapsed;
		Vector2D<double> oldPos = GetPos();

		Vector2D<double> steeringForce;
		steeringForce = mSteeringBehavior->Calculate();

	}


	void Vehicle::Draw()
	{
	}
};
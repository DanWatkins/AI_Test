#include "MovingEntity.h"

namespace ait
{
	MovingEntity::MovingEntity(Vector2D<double> pos, double radius, Vector2D<double> velocity, double maxSpeed,
					Vector2D<double> heading, double mass, Vector2D<double> scale, double turnRate, double maxForce)
	{
		Entity(EntityType::Default, pos, radius);  //TODO 0
		mHeading = heading;
		mVelocity = velocity;
		mMass = mass;
		mSide = mHeading.Perpendicular();
		mMaxSpeed = maxSpeed;
		mMaxTurnRate = turnRate;
		mMaxForce = maxForce;
		mScale = scale;
	}
};
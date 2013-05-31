#include "..\Main.h"

#ifndef _aitest_MOVING_ENTITY_H
#define _aitest_MOVING_ENTITY_H

namespace ait
{
	class MovingEntity : public Entity
	{
	private:
		Vector2D<double> mVelocity;
		Vector2D<double> mHeading;
		Vector2D<double> mSide;

		double mMass;
		double mMaxSpeed;
		double mMaxForce;
		double mMaxTurnRate;

	public:
		MovingEntity();

		void SetVelocity(Vector2D<double> velocity) { mVelocity = velocity; }
		Vector2D<double> GetVelocity() { return mVelocity; }
		void SetHeading(Vector2D<double> heading) { mHeading = heading; }
		Vector2D<double> GetHeading() { return mHeading; }
		void SetSide(Vector2D<double> side) { mSide = side; }
		Vector2D<double> GetSide() { return mSide; }

		void SetMass(double mass) { mMass = mass; }
		double GetMass() { return mMass; }
		void SetMaxSpeed(double maxSpeed) { mMaxSpeed = maxSpeed; }
		double GetMaxSpeed() { return mMaxSpeed; }
		double GetSpeed() { return mVelocity.Length(); }
		double GetSpeedSq() { return mVelocity.LengthSq(); }
		void SetMaxForce(double maxForce) { mMaxForce = maxForce; }
		double GetMaxForce() { return mMaxForce; }
		void SetMaxTurnRate(double maxTurnRate) { mMaxTurnRate = maxTurnRate; }
	};
};

#endif


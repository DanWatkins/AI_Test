#include "SteeringBehavior.h"

namespace ait
{
	/*=============================================================================
	-- Calculates how much of its maximum steering force the vehicle has left to
	   apply and then applies that amount of the force to add.
	=============================================================================*/
	bool SteeringBehavior::AccumulateForce(Vector2D<double> &sf, Vector2D<double> forceToAdd)
	{
		double magnitudeSoFar = sf.Length();
		double magnitudeRemaining = mVehicle->GetMaxForce() - magnitudeSoFar;

		if (magnitudeRemaining <= 0.0)
			return false;

		double magnitudeToAdd = forceToAdd.Length();

		if (magnitudeToAdd < magnitudeRemaining)
			sf += forceToAdd;
		else
		{
			Vector2D<double> temp = forceToAdd * magnitudeRemaining;
			temp.Normalize();
			sf += temp;
		}

		return true;
	}


	/*=============================================================================
	-- Creates the feelers (antenna) used by WallAvoidance.
	=============================================================================*/
	void SteeringBehavior::CreateFeelers()
	{
		mFeelers[0] = mVehicle->GetPos() + (mVehicle->GetHeading() * mWallDetectionFeelerLength);//TODO possible issue with order of operations
		
		Vector2D<double> temp = mVehicle->GetHeading();
		Vec2DRotateAroundOrigin(temp, PI/2.0 * 3.5);
		mFeelers[1] = mVehicle->GetPos() + temp * mWallDetectionFeelerLength/2.0;//TODO right order here??

		temp = mVehicle->GetHeading();
		Vec2DRotateAroundOrigin(temp, PI/4.0);
		mFeelers[2] = (mVehicle->GetPos() + temp * mWallDetectionFeelerLength/2.0);//TODO right order here??
	}


	/*=============================================================================
	-- Returns a steering force that directs the agent towards the targetPos.
	=============================================================================*/
	Vector2D<double> SteeringBehavior::Seek(Vector2D<double> targetPos)
	{
		Vector2D<double> desiredVelocity = targetPos - mVehicle->GetPos();
		desiredVelocity.Normalize();
		desiredVelocity *= mVehicle->GetMaxSpeed();

		return desiredVelocity - mVehicle->GetVelocity();
	}


	/*=============================================================================
	-- Returns a steering force that directs the agent away from the targetPos.
	=============================================================================*/
	Vector2D<double> SteeringBehavior::Flee(Vector2D<double> targetPos)
	{
		const double panicDistanceSq = 100.0 * 100.0;

		//return no steering force if the target is out of the panic distance
		if (mVehicle->GetPos().DistanceToSq(targetPos) > panicDistanceSq)
			return Vector2D<double>();

		Vector2D<double> desiredVelocity = mVehicle->GetPos() - targetPos;
		desiredVelocity.Normalize();
		desiredVelocity *= mVehicle->GetMaxSpeed();

		return desiredVelocity - mVehicle->GetVelocity();
	}


	/*=============================================================================
	-- 
	=============================================================================*/
	Vector2D<double> SteeringBehavior::Arrive(Vector2D<double> targetPos, Deceleration deceleration)
	{
		Vector2D<double> toTarget = targetPos - mVehicle->GetPos();
		
		double distance = toTarget.Length();

		if (distance > 0)
		{
			const double decelerationTweaker = 0.3;
			double speed = distance / ((double)deceleration * decelerationTweaker);
			speed = Min(speed, mVehicle->GetMaxSpeed());

			Vector2D<double> desiredVelocity = toTarget * speed / distance;

			return desiredVelocity - mVehicle->GetVelocity();
		}

		return Vector2D<double>(0,0);
	}


	/*=============================================================================
	-- 
	=============================================================================*/
	Vector2D<double> SteeringBehavior::Pursuit(Vehicle *evader)
	{
		Vector2D<double> toEvader = evader->GetPos() - mVehicle->GetPos();
		double relativeHeading = mVehicle->GetHeading().DotProduct(evader->GetHeading());

		if (toEvader.DotProduct(mVehicle->GetHeading()) > 0  &&  relativeHeading < -0.95)
			return Seek(evader->GetPos());

		double lookAheadTime = toEvader.Length() / mVehicle->GetMaxSpeed() + evader->GetSpeed();

		return Seek(evader->GetPos() + evader->GetVelocity() * lookAheadTime);
	}


	/*=============================================================================
	-- 
	=============================================================================*/
	Vector2D<double> SteeringBehavior::OffsetPursuit(const Vehicle *agent, const Vector2D<double> offset)
	{
	}


	/*=============================================================================
	-- 
	=============================================================================*/
	Vector2D<double> SteeringBehavior::Evade(const Vehicle *agent)
	{
	}


	/*=============================================================================
	-- 
	=============================================================================*/
	Vector2D<double> SteeringBehavior::Wander()
	{
	}


	/*=============================================================================
	-- 
	=============================================================================*/
	Vector2D<double> SteeringBehavior::ObstacleAvoidance(const std::vector<Entity*> &obstacles)
	{
	}


	/*=============================================================================
	-- 
	=============================================================================*/
	Vector2D<double> SteeringBehavior::WallAvoidance(const std::vector<Wall2D> &walls)
	{
	}


	/*=============================================================================
	-- 
	=============================================================================*/
	Vector2D<double> SteeringBehavior::FollowPath()
	{
	}


	/*=============================================================================
	-- 
	=============================================================================*/
	Vector2D<double> SteeringBehavior::Interpose(const Vehicle *vehicleA, const Vehicle *vehicleB)
	{
	}


	/*=============================================================================
	-- 
	=============================================================================*/
	Vector2D<double> SteeringBehavior::Hide(const Vehicle *hunter, const std::vector<Entity*> &obstacles)
	{
	}
	

	/*=============================================================================
	-- 
	=============================================================================*/
	Vector2D<double> SteeringBehavior::Cohesion(const std::vector<Vehicle*> &agents)
	{
	}


	/*=============================================================================
	-- 
	=============================================================================*/
	Vector2D<double> SteeringBehavior::Separation(const std::vector<Vehicle*> &agents)
	{
	}


	/*=============================================================================
	-- 
	=============================================================================*/
	Vector2D<double> SteeringBehavior::Alignment(const std::vector<Vehicle*> &agents)
	{
	}


	/*=============================================================================
	-- 
	=============================================================================*/
	Vector2D<double> SteeringBehavior::CohesionPlus(const std::vector<Vehicle*> &agents)
	{
	}


	/*=============================================================================
	-- 
	=============================================================================*/
	Vector2D<double> SteeringBehavior::SeparationPlus(const std::vector<Vehicle*> &agents)
	{
	}


	/*=============================================================================
	-- 
	=============================================================================*/
	Vector2D<double> SteeringBehavior::AlignmentPlus(const std::vector<Vehicle*> &agents)
	{
	}
};
#include "SteeringBehavior.h"

namespace ait
{
	SteeringBehavior::SteeringBehavior(Vehicle *agent) : mFeelers(3)
	{
		mVehicle = agent;
		mFlags = 0;
		mBoxLength = Prm.MinDetectionBoxLength;
		mWeightCohesion = Prm.CohesionWeight;
		mWeightAlignment = Prm.AlignmentWeight;
		mWeightSeparation = Prm.SeparationWeight;
		mWeightObstacleAvoidance = Prm.ObstacleAvoidanceWeight;
		mWeightWander = Prm.WanderWeight;
		mWeightWallAvoidance = Prm.WallAvoidanceWeight;
		mViewDistance = Prm.ViewDistance;
		mWallDetectionFeelerLength = Prm.WallDetectionFeelerLength;
        mDeceleration = Normal,
        mTargetAgent1 = NULL;
        mTargetAgent2 = NULL,
        mWanderDistance = gWanderDistance;
        mWanderJitter = gWanderJitterPerSec;
        mWanderRadius = gWanderRadius;
        mWaypointSeekDistanceSq = gWaypointSeekDistance*gWaypointSeekDistance;
        mWeightSeek = Prm.SeekWeight;
        mWeightFlee = Prm.FleeWeight;
        mWeightArrive = Prm.ArriveWeight;
        mWeightPursuit = Prm.PursuitWeight;
        mWeightOffsetPursuit = Prm.OffsetPursuitWeight;
        mWeightInterpose = Prm.InterposeWeight;
        mWeightHide = Prm.HideWeight;
        mWeightEvade = Prm.EvadeWeight;
        mWeightFollowPath = Prm.FollowPathWeight;
        mCellSpaceOn = false;
        mSummingMethod = Prioritized;

		double theta = RandFloat() * TWO_PI;
		mWanderTarget = Vector2D<double>(mWanderRadius * cos(theta), mWanderRadius * sin(theta));
		mPath = new Path();
		mPath->SetLooped(true);
	}


	SteeringBehavior::~SteeringBehavior()
	{
		delete mPath;
	}

	Vector2D<double> SteeringBehavior::Calculate()
	{
		mSteeringForce.Zero();

		if (!mCellSpaceOn)
		{
			if (On(BehaviorSeparation) || On(BehaviorAllignment) || On(BehaviorCohesion))
				int n=0;
				// TODO uncomment when World is finished mVehicle->GetWorld()->TagVehiclesWithingViewRange(mVehicle, mViewDistance);
		}
		else
		{
			if (On(BehaviorSeparation) || On(BehaviorAllignment) || On(BehaviorCohesion))
				int n=0;
				// TODO uncomment when World is finished mVehicle->GetWorld()->CellSpace()->CalculateNeighbors(mVehicle->GetPos(), mViewDistance);
		}

		switch (mSummingMethod)
		{
		case WeightedAverage:
			mSteeringForce = CalculateWeightedSum(); break;

		case Prioritized:
			mSteeringForce = CalculatePrioritized(); break;

		case Dithered:
			mSteeringForce = CalculateDithered(); break;

		default:
			mSteeringForce = Vector2D<double>(0.0,0.0);
		}

		return mSteeringForce;
	}


	double SteeringBehavior::ForwardComponent()
	{
		return mVehicle->GetHeading().DotProduct(mSteeringForce);
	}


	double SteeringBehavior::SideComponent()
	{
		return mVehicle->GetSide().DotProduct(mSteeringForce);
	}


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
		double panicDistanceSq = 100.0 * 100.0;

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
			double decelerationTweaker = 0.3;
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
	Vector2D<double> SteeringBehavior::OffsetPursuit(Vehicle *agent, Vector2D<double> offset)
	{
		Vector2D<double> worldOffsetPos = PointToWorldSpace(offset, agent->GetHeading(), agent->GetSide(), agent->GetPos());
		Vector2D<double> toOffset = worldOffsetPos - mVehicle->GetPos();

		double lookAheadTime = toOffset.Length() / (mVehicle->GetMaxSpeed() + agent->GetSpeed());

		return Arrive(worldOffsetPos + agent->GetVelocity() * lookAheadTime, Deceleration::Fast);
	}


	/*=============================================================================
	-- 
	=============================================================================*/
	Vector2D<double> SteeringBehavior::Evade(Vehicle *agent)
	{
		Vector2D<double> toPursuer = agent->GetPos() - mVehicle->GetPos();

		const double threatRange = 100.0;
		if (toPursuer.LengthSq() > threatRange*threatRange)
			return Vector2D<double>();

		double lookAheadTime = toPursuer.Length() / (mVehicle->GetMaxSpeed() + agent->GetSpeed());

		return Flee(agent->GetPos() + agent->GetVelocity() * lookAheadTime);
	}


	/*=============================================================================
	-- 
	=============================================================================*/
	Vector2D<double> SteeringBehavior::Wander()
	{
		double jitterThisTimeSlice = mWanderJitter * mVehicle->GetTimeElapsed();

		mWanderTarget += Vector2D<double>(RandClamped() * jitterThisTimeSlice, RandClamped() * jitterThisTimeSlice);
		mWanderTarget.Normalize();
		mWanderTarget *= mWanderRadius;

		Vector2D<double> target = mWanderTarget + Vector2D<double>(mWanderDistance, 0.0);
		Vector2D<double> targetWorldSpace = PointToWorldSpace(target, mVehicle->GetHeading(), mVehicle->GetSide(), mVehicle->GetPos());

		return targetWorldSpace - mVehicle->GetPos();
	}


	/*=============================================================================
	-- 
	=============================================================================*/
	Vector2D<double> SteeringBehavior::ObstacleAvoidance(std::vector<Entity*> &obstacles)
	{

	}


	/*=============================================================================
	-- 
	=============================================================================*/
	Vector2D<double> SteeringBehavior::WallAvoidance(std::vector<Wall2D> &walls)
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
	Vector2D<double> SteeringBehavior::Interpose(Vehicle *vehicleA, Vehicle *vehicleB)
	{
	}


	/*=============================================================================
	-- 
	=============================================================================*/
	Vector2D<double> SteeringBehavior::Hide(Vehicle *hunter, std::vector<Entity*> &obstacles)
	{
	}
	

	/*=============================================================================
	-- 
	=============================================================================*/
	Vector2D<double> SteeringBehavior::Cohesion(std::vector<Vehicle*> &agents)
	{
	}


	/*=============================================================================
	-- 
	=============================================================================*/
	Vector2D<double> SteeringBehavior::Separation(std::vector<Vehicle*> &agents)
	{
	}


	/*=============================================================================
	-- 
	=============================================================================*/
	Vector2D<double> SteeringBehavior::Alignment(std::vector<Vehicle*> &agents)
	{
	}


	/*=============================================================================
	-- 
	=============================================================================*/
	Vector2D<double> SteeringBehavior::CohesionPlus(std::vector<Vehicle*> &agents)
	{
	}


	/*=============================================================================
	-- 
	=============================================================================*/
	Vector2D<double> SteeringBehavior::SeparationPlus(std::vector<Vehicle*> &agents)
	{
	}


	/*=============================================================================
	-- 
	=============================================================================*/
	Vector2D<double> SteeringBehavior::AlignmentPlus(std::vector<Vehicle*> &agents)
	{
	}
};
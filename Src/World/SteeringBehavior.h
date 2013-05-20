#include "..\Main.h"

#ifndef _aitest_STEERING_BEHAVIOR_H
#define _aitest_STEERING_BEHAVIOR_H

namespace ait
{
	enum SummingMethod
	{
		WeightedAverage,
		Prioritized,
		Dithered
	};


	enum BehaviorType
	{
		None				= 0x00000,
		Seek				= 0x00002,
		Flee				= 0x00004,
		Arrive				= 0x00008,
		Wander				= 0x00010,
		Cohesion			= 0x00020,
		Separation			= 0x00040,
		Allignment			= 0x00080,
		ObstacleAvoidance	= 0x00100,
		WallAvoidance		= 0x00200,
		FollowPath			= 0x00400,
		Pursuit				= 0x00800,
		Evade				= 0x01000,
		Interpose			= 0x02000,
		Hide				= 0x04000,
		Flock				= 0x08000,
		OffsetPursuit		= 0x10000
	};


	class SteeringBehavior
	{
		Vehicle *mVehicle;
		Vehicle *mTargetAgent1;
		Vehicle *mTargetAgent2;

		Vector2D<double> mSteeringForce;
		Vector2D<double> mTarget;
		double mBoxLength;
	
		std::vector< Vector2D<double> > mFeelers;
		double mWallDetectionFeelerLength;
		Vector2D<double> mWanderTarget;

		double mWanderJitter;
		double mWanderRadius;
		double mWanderDistance;

		//multipliers that effect the strength of the appropriate behavior
		double mWeightSeparation;
		double mWidthCohesion;
		double mWeightAlignment;
		double mWeightWander;
		double mWeightObstacleAvoidance;
		double mWeightWallAvoidance;
		double mWeightSeek;
		double mWeightFlee;
		double mWeightArrive;
		double mWeightPursuit;
		double mWeightOffsetPursuit;
		double mWeightInterpose;
		double mWeightHide;
		double mWeightEvade;
		double mWeightFollowPath;

		double mViewDistance;
		 //Path *mPath;
	};
};

#endif


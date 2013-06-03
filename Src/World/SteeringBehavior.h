#include "..\Main.h"

#ifndef _aitest_STEERING_BEHAVIOR_H
#define _aitest_STEERING_BEHAVIOR_H

namespace ait
{
	//the radius of the constraining circle for the wander behavior
	double gWanderRadius = 1.2;

	//the distance the wander circle is projected in front of the angent
	double gWanderDistance = 2.0;

	//the maximium amount of displacement along the circle each frame
	double gWanderJitterPerSec = 80.0;

	//used in path following
	double gWaypointSeekDistance = 20.0;


	class SteeringBehavior
	{
	public:
		enum SummingMethod
		{
			WeightedAverage,
			Prioritized,
			Dithered
		};

	private:
		enum Behavior
		{
			BehaviorNone				= 0x00000,
			BehaviorSeek				= 0x00002,
			BehaviorFlee				= 0x00004,
			BehaviorArrive				= 0x00008,
			BehaviorWander				= 0x00010,
			BehaviorCohesion			= 0x00020,
			BehaviorSeparation			= 0x00040,
			BehaviorAllignment			= 0x00080,
			BehaviorObstacleAvoidance	= 0x00100,
			BehaviorWallAvoidance		= 0x00200,
			BehaviorFollowPath			= 0x00400,
			BehaviorPursuit				= 0x00800,
			BehaviorEvade				= 0x01000,
			BehaviorInterpose			= 0x02000,
			BehaviorHide				= 0x04000,
			BehaviorFlock				= 0x08000,
			BehaviorOffsetPursuit		= 0x10000
		};

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
		double mWeightCohesion;
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

		Path *mPath;

		double mWaypointSeekDistanceSq;
		Vector2D<double> mOffset;
		int mFlags;

		enum Deceleration { Slow = 3, Normal = 2, Fast = 1 };
		Deceleration mDeceleration;

		bool mCellSpaceOn;
		SummingMethod mSummingMethod;

		//methods
		bool On(Behavior behavior) { return (mFlags & behavior) == behavior; }
		bool AccumulateForce(Vector2D<double> &sf, Vector2D<double> forceToAdd);
		void CreateFeelers();

		//TODO all these private methods are going to need a '_' prefix or should be made public
		//behavior methods
		Vector2D<double> Seek(Vector2D<double> targetPos);
		Vector2D<double> Flee(Vector2D<double> targetPos);
		Vector2D<double> Arrive(Vector2D<double> targetPos, Deceleration deceleration);
		Vector2D<double> Pursuit(Vehicle *evader);
		Vector2D<double> OffsetPursuit(Vehicle *agent, Vector2D<double> offset);
		Vector2D<double> Evade(Vehicle *agent);
		Vector2D<double> Wander();
		Vector2D<double> ObstacleAvoidance(std::vector<Entity*> &obstacles);
		Vector2D<double> WallAvoidance(std::vector<Wall2D> &walls);
		Vector2D<double> FollowPath();
		Vector2D<double> Interpose(Vehicle *vehicleA, Vehicle *vehicleB);
		Vector2D<double> Hide(Vehicle *hunter, std::vector<Entity*> &obstacles);

		Vector2D<double> Cohesion(std::vector<Vehicle*> &agents);
		Vector2D<double> Separation(std::vector<Vehicle*> &agents);
		Vector2D<double> Alignment(std::vector<Vehicle*> &agents);

		Vector2D<double> CohesionPlus(std::vector<Vehicle*> &agents);
		Vector2D<double> SeparationPlus(std::vector<Vehicle*> &agents);
		Vector2D<double> AlignmentPlus(std::vector<Vehicle*> &agents);


		Vector2D<double> CalculateWeightedSum();
		Vector2D<double> CalculatePrioritized();
		Vector2D<double> CalculateDithered();

		Vector2D<double> GetHidingPosition(Vector2D<double> posOb, double radiusOb, Vector2D<double> posHunter);

	public:
		SteeringBehavior(Vehicle *agent);
		virtual ~SteeringBehavior();

		Vector2D<double> Calculate();

		double ForwardComponent();
		double SideComponent();
	};
};

#endif


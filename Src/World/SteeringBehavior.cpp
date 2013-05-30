#include "SteeringBehavior.h"

namespace ait
{
	bool SteeringBehavior::AccumulateForce(Vector2D<double> &sf, Vector2D<double> forceToAdd)
	{

	}

	void SteeringBehavior::CreateFeelers()
	{
	}


	Vector2D<double> SteeringBehavior::Seek(Vector2D<double> targetPos)
	{
	}


	Vector2D<double> SteeringBehavior::Flee(Vector2D<double> targetPos)
	{
	}


	Vector2D<double> SteeringBehavior::Arrive(Vector2D<double> targetPos, Deceleration deceleration)
	{
	}


	Vector2D<double> SteeringBehavior::Pursuit(const Vehicle *agent)
	{
	}


	Vector2D<double> SteeringBehavior::OffsetPursuit(const Vehicle *agent, const Vector2D<double> offset)
	{
	}


	Vector2D<double> SteeringBehavior::Evade(const Vehicle *agent)
	{
	}


	Vector2D<double> SteeringBehavior::Wander()
	{
	}


	Vector2D<double> SteeringBehavior::ObstacleAvoidance(const std::vector<Entity*> &obstacles)
	{
	}


	Vector2D<double> SteeringBehavior::WallAvoidance(const std::vector<Wall2D> &walls)
	{
	}



	Vector2D<double> SteeringBehavior::FollowPath()
	{
	}


	Vector2D<double> SteeringBehavior::Interpose(const Vehicle *vehicleA, const Vehicle *vehicleB)
	{
	}


	Vector2D<double> SteeringBehavior::Hide(const Vehicle *hunter, const std::vector<Entity*> &obstacles)
	{
	}
	

	Vector2D<double> SteeringBehavior::Cohesion(const std::vector<Vehicle*> &agents)
	{
	}


	Vector2D<double> SteeringBehavior::Separation(const std::vector<Vehicle*> &agents)
	{
	}


	Vector2D<double> SteeringBehavior::Alignment(const std::vector<Vehicle*> &agents)
	{
	}


	Vector2D<double> SteeringBehavior::CohesionPlus(const std::vector<Vehicle*> &agents)
	{
	}


	Vector2D<double> SteeringBehavior::SeparationPlus(const std::vector<Vehicle*> &agents)
	{
	}


	Vector2D<double> SteeringBehavior::AlignmentPlus(const std::vector<Vehicle*> &agents)
	{
	}
};
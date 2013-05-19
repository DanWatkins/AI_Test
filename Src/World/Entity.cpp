#include "Entity.h"

namespace ait
{
	Entity::Entity()
	{
		mId = -1;
		mEntityType = EntityType::Default;
		mTagged = false;
		mBoundingRadius = 2.0;
	}


	Entity::Entity(EntityType entityType)
	{
		Entity::Entity();
		entityType = entityType;
	}


	Entity::Entity(EntityType entityType, Vector2D<double> pos, double radius)
	{
		Entity::Entity(entityType);
		SetPos(pos);
		SetBoundingRadius(radius);
	}
};
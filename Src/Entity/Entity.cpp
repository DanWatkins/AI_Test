#include "Entity.h"

Entity::Entity()
{
	mId = -1;
	mEntityType = EntityTypeDefault;
	mTagged = false;
	mBoundingRadius = 2.0;
}


Entity::Entity(EntityType entityType)
{
	Entity();
	entityType = entityType;
}


Entity::Entity(EntityType entityType, Vector2D<double> pos, double radius)
{
	Entity(entityType);
	SetPos(pos);
	SetBoundingRadius(radius);
}
#ifndef _aitest_ENTITY_H
#define _aitest_ENTITY_H

#include "..\Main.h"

enum EntityType
{
	EntityTypeDefault = 1
};

struct Message;

class Entity
{
private:
	int mId;
	EntityType mEntityType;
	bool mTagged;

protected:
	Vector2D<double> mPos;
	Vector2D<double> mScale;
	double mBoundingRadius;

public:
	Entity();
	Entity(EntityType entityType);
	Entity(EntityType entityType, Vector2D<double> pos, double radius);

	virtual ~Entity() {}
	virtual void Update(double timeElapsed) {}
	virtual void Draw() {}
	virtual bool HandleMessage(const Message &message) { return false; }

	virtual void Write(std::ostream &os) {}
	virtual void Read(std::ifstream &is) {}


	//accessor and mutators
	int GetId() { return mId; }
	EntityType GetEntityType() { return mEntityType; }
	bool GetTagged() { return mTagged; }
	void SetTagged(bool tagged) { mTagged = tagged; }

	Vector2D<double> GetPos() { return mPos; }
	void SetPos(Vector2D<double> pos) { mPos = pos; }
	Vector2D<double> GetScale() { return mScale; }
	void SetScale(Vector2D<double> scale) { mScale = scale; }
	double GetBoundingRadius() { return mBoundingRadius; }
	void SetBoundingRadius(double boundingRadius) { mBoundingRadius = boundingRadius; }

};

#endif


#include "..\Main.h"

#ifndef _aitest_TRANSFORMATION_H
#define _aitest_TRANSFORMATION_H

namespace ait
{
	std::vector< Vector2D<double> > WorldTransform(std::vector< Vector2D<double> > &points,
													const Vector2D<double> &pos,
													const Vector2D<double> &forward,
													const Vector2D<double> &side,
													const Vector2D<double> &scale);

	std::vector< Vector2D<double> > WorldTransform(std::vector< Vector2D<double> > &points,
													const Vector2D<double> &pos,
													const Vector2D<double> &forward,
													const Vector2D<double> &side);

	Vector2D<double> PointToWorldSpace(const Vector2D<double> &point,
										const Vector2D<double> &agentHeading,
										const Vector2D<double> &agentSide,
										const Vector2D<double> &agentPositoin);

	Vector2D<double> VectorToWorldSpace(const Vector2D<double> &vec,
										const Vector2D<double> &agentHeading,
										const Vector2D<double> &agentSide);

	Vector2D<double> PointToLocalSpace(const Vector2D<double> &point,
								 Vector2D<double> &agentHeading,
								 Vector2D<double> &agentSide,
								  Vector2D<double> &agentPosition);

	Vector2D<double> VectorToLocalSpace(const Vector2D<double> &vec,
								 const Vector2D<double> &agentHeading,
								 const Vector2D<double> &agentSide);

	void Vec2DRotateAroundOrigin(Vector2D<double>& vector, double angle);

	std::vector< Vector2D<double> > CreateWhiskers(unsigned int NumWhiskers, double WhiskerLength,
									double fov, Vector2D<double> facing, Vector2D<double> origin);


};

#endif


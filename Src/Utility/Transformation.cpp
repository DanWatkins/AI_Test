#include "Transformation.h"

namespace ait
{
	/*=============================================================================
	-- 
	=============================================================================*/
	std::vector< Vector2D<double> > WorldTransform(std::vector< Vector2D<double> > &points,
													const Vector2D<double> &pos,
													const Vector2D<double> &forward,
													const Vector2D<double> &side,
													const Vector2D<double> &scale)
	{
		std::vector< Vector2D<double> > tranVector2Ds = points;
		MatrixC2D transformMatrix;

		if (scale.x != 1.0  ||  scale.y != 1.0)
			transformMatrix.Scale(scale.x, scale.y);

		transformMatrix.Rotate(forward, side);
		transformMatrix.Translate(pos.x, pos.y);
		transformMatrix.TransformVector2Ds(tranVector2Ds);

		return tranVector2Ds;
	}


	/*=============================================================================
	-- 
	=============================================================================*/
	std::vector< Vector2D<double> > WorldTransform(std::vector< Vector2D<double> > &points,
													const Vector2D<double> &pos,
													const Vector2D<double> &forward,
													const Vector2D<double> &side)
	{
		std::vector< Vector2D<double> > tranVector2Ds = points;
		MatrixC2D transformMatrix;

		transformMatrix.Rotate(forward, side);
		transformMatrix.Translate(pos.x, pos.y);
		transformMatrix.TransformVector2Ds(tranVector2Ds);

		return tranVector2Ds;
	}


	/*=============================================================================
	-- 
	=============================================================================*/
	Vector2D<double> PointToWorldSpace(const Vector2D<double> &point,
										const Vector2D<double> &agentHeading,
										const Vector2D<double> &agentSide,
										const Vector2D<double> &agentPositoin)
	{
		Vector2D<double> transPoint = point;
		MatrixC2D transformMatrix;

		transformMatrix.Rotate(agentHeading, agentSide);
		transformMatrix.Translate(agentPositoin.x, agentPositoin.y);
		transformMatrix.TransformVector2D(transPoint);

		return transPoint;
	}


	/*=============================================================================
	-- 
	=============================================================================*/
	Vector2D<double> VectorToWorldSpace(const Vector2D<double> &vec,
										const Vector2D<double> &agentHeading,
										const Vector2D<double> &agentSide)
	{
		Vector2D<double> transVec = vec;
		MatrixC2D matrixTransform;
		matrixTransform.Rotate(agentHeading, agentSide);
		matrixTransform.TransformVector2D(transVec);

		return transVec;
	}


	/*=============================================================================
	-- 
	=============================================================================*/
	Vector2D<double> PointToLocalSpace(const Vector2D<double> &point,
								 Vector2D<double> &agentHeading,
								 Vector2D<double> &agentSide,
								  Vector2D<double> &agentPosition)
	{

		//make a copy of the point
	  Vector2D<double> TransPoint = point;
  
	  //create a transformation matrix
		MatrixC2D matTransform;

	  double Tx = -agentPosition.DotProduct(agentHeading);
	  double Ty = -agentPosition.DotProduct(agentSide);

	  //create the transformation matrix
	  matTransform.Set_11(agentHeading.x); matTransform.Set_12(agentSide.x);
	  matTransform.Set_21(agentHeading.y); matTransform.Set_22(agentSide.y);
	  matTransform.Set_31(Tx);           matTransform.Set_32(Ty);
	
	  //now transform the vertices
	  matTransform.TransformVector2D(TransPoint);

	  return TransPoint;
	}


	/*=============================================================================
	-- 
	=============================================================================*/
	Vector2D<double> VectorToLocalSpace(const Vector2D<double> &vec,
								 const Vector2D<double> &agentHeading,
								 const Vector2D<double> &agentSide)
	{ 
		Vector2D<double> transPoint = vec;
		MatrixC2D matTransform;

		matTransform.Set_11(agentHeading.x); matTransform.Set_12(agentSide.x);
		matTransform.Set_21(agentHeading.y); matTransform.Set_22(agentSide.y);
		matTransform.TransformVector2D(transPoint);

		return transPoint;
	}

	/*=============================================================================
	-- Rotates a vector around the origin @angle radians.
	=============================================================================*/
	void Vec2DRotateAroundOrigin(Vector2D<double>& vector, double angle)
	{
	  //create a transformation matrix
	  MatrixC2D mat;

	  //rotate
	  mat.Rotate(angle);
	
	  //now transform the object's vertices
	  mat.TransformVector2D(vector);
	}


	/*=============================================================================
	-- Given an origin, a facing direction, a 'field of view' describing the limit
	   of the outer whiskers, a whisker length and the number of whiskers this
	   method returns a vector containing the end positions of a series of whiskers
	   radiating away from the origin and with equal distance between them.
	=============================================================================*/
	std::vector< Vector2D<double> > CreateWhiskers(unsigned int NumWhiskers, double WhiskerLength,
									double fov, Vector2D<double> facing, Vector2D<double> origin)
	{
		//this is the magnitude of the angle separating each whisker
		double sectorSize = fov/(double)(NumWhiskers-1);

		std::vector< Vector2D<double> > whiskers;
		Vector2D<double> temp;
		double angle = -fov*0.5; 

		for (unsigned int w=0; w<NumWhiskers; ++w)
		{
			//create the whisker extending outwards at this angle
			temp = facing;
			Vec2DRotateAroundOrigin(temp, angle);
			//TODO whiskers.push_back(origin + WhiskerLength * temp);
			whiskers.push_back(origin + (temp * WhiskerLength)); //TODO is this right?

			angle += sectorSize;
		}

	  return whiskers;
	}
};
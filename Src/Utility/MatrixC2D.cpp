#include "MatrixC2D.h"

namespace ait
{
	void MatrixC2D::MatrixMultiply(Matrix &matrix)
	{
		Matrix tempMatrix;
  
		//first row
		tempMatrix._11 = (mMatrix._11*matrix._11) + (mMatrix._12*matrix._21) + (mMatrix._13*matrix._31);
		tempMatrix._12 = (mMatrix._11*matrix._12) + (mMatrix._12*matrix._22) + (mMatrix._13*matrix._32);
		tempMatrix._13 = (mMatrix._11*matrix._13) + (mMatrix._12*matrix._23) + (mMatrix._13*matrix._33);

		//second
		tempMatrix._21 = (mMatrix._21*matrix._11) + (mMatrix._22*matrix._21) + (mMatrix._23*matrix._31);
		tempMatrix._22 = (mMatrix._21*matrix._12) + (mMatrix._22*matrix._22) + (mMatrix._23*matrix._32);
		tempMatrix._23 = (mMatrix._21*matrix._13) + (mMatrix._22*matrix._23) + (mMatrix._23*matrix._33);

		//third
		tempMatrix._31 = (mMatrix._31*matrix._11) + (mMatrix._32*matrix._21) + (mMatrix._33*matrix._31);
		tempMatrix._32 = (mMatrix._31*matrix._12) + (mMatrix._32*matrix._22) + (mMatrix._33*matrix._32);
		tempMatrix._33 = (mMatrix._31*matrix._13) + (mMatrix._32*matrix._23) + (mMatrix._33*matrix._33);

		mMatrix = tempMatrix;
	}

	void MatrixC2D::Identity()
	{
		mMatrix._11 = 1.0; mMatrix._12 = 0.0; mMatrix._13 = 0.0;
		mMatrix._21 = 0.0; mMatrix._22 = 1.0; mMatrix._23 = 0.0;
		mMatrix._31 = 0.0; mMatrix._32 = 0.0; mMatrix._33 = 1.0;
	}


	void MatrixC2D::Translate(double x, double y)
	{
		Matrix tempMatrix;

		tempMatrix._11 = 1.0; tempMatrix._12 = 0.0; tempMatrix._13 = 0.0;
		tempMatrix._21 = 0.0; tempMatrix._22 = 1.0; tempMatrix._23 = 0.0;
		tempMatrix._31 = x; tempMatrix._32 = y; tempMatrix._33 = 1.0;

		MatrixMultiply(tempMatrix);
	}


	void MatrixC2D::Scale(double xScale, double yScale)
	{
		Matrix tempMatrix;

		tempMatrix._11 = xScale; tempMatrix._12 = 0.0; tempMatrix._13 = 0.0;
		tempMatrix._21 = 0.0; tempMatrix._22 = yScale; tempMatrix._23 = 0.0;
		tempMatrix._31 = 0.0; tempMatrix._32 = 0.0; tempMatrix._33 = 1.0;

		MatrixMultiply(tempMatrix);
	}


	void MatrixC2D::Rotate(double rotation)
	{
		Matrix tempMatrix;

		double sin = std::sin(rotation);
		double cos = std::cos(rotation);

		tempMatrix._11 = cos; tempMatrix._12 = sin; tempMatrix._13 = 0.0;
		tempMatrix._21 = -sin; tempMatrix._22 = cos; tempMatrix._23 = 0.0;
		tempMatrix._31 = 0.0; tempMatrix._32 = 0.0; tempMatrix._33 = 1.0;

		MatrixMultiply(tempMatrix);
	}


	void MatrixC2D::Rotate(Vector2D<double> &fwd, Vector2D<double> &side)
	{
		Matrix tempMatrix;

		tempMatrix._11 = fwd.x; tempMatrix._12 = fwd.y; tempMatrix._13 = 0.0;
		tempMatrix._21 = side.x; tempMatrix._22 = side.y; tempMatrix._23 = 0.0;
		tempMatrix._31 = 0.0; tempMatrix._32 = 0.0; tempMatrix._33 = 1.0;

		MatrixMultiply(tempMatrix);
	}


	void MatrixC2D::TransformVector2Ds(std::vector< Vector2D<double> > &points)
	{
		for (unsigned n=0; n<points.size(); n++)
			TransformVector2D(points.at(n));
	}


	void MatrixC2D::TransformVector2D(Vector2D<double> &point)
	{
		double tempX = (mMatrix._11 * point.x) + (mMatrix._21 * point.y) + mMatrix._31;
		double tempY = (mMatrix._12 * point.x) _ (mMatrix._22 * point.y) + mMatrix._32;

		point.x = tempX;
		point.y = tempY;
	}
};
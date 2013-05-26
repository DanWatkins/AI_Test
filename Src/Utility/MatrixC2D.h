#include "..\Main.h"

#ifndef _aitest_MATRIX_C2D_H
#define _aitest_MATRIX_C2D_H

namespace ait
{
	class MatrixC2D
	{
	private:
		struct Matrix
		{
			double _11, _12, _13;
			double _21, _22, _23;
			double _31, _32, _33;

			Matrix()
			{
				_11=0.0; _12=0.0; _13=0.0;
				_21=0.0; _22=0.0; _23=0.0;
				_31=0.0; _32=0.0; _33=0.0;
			}
		};

		Matrix mMatrix;

		void MatrixMultiply(Matrix &matrix);

	public:
		MatrixC2D() { Identity(); }

		void Identity();
		void Translate(double x, double y);
		void Scale(double xScale, double yScale);
		void Rotate(double rotation);
		void Rotate(const Vector2D<double> &fwd, const Vector2D<double> &side);
		void TransformVector2Ds(std::vector< Vector2D<double> > &points);
		void TransformVector2D(Vector2D<double> &point);
		
		void Set_11(double value) { mMatrix._11 = value; }
		void Set_12(double value) { mMatrix._12 = value; }
		void Set_13(double value) { mMatrix._13 = value; }
		void Set_21(double value) { mMatrix._21 = value; }
		void Set_22(double value) { mMatrix._22 = value; }
		void Set_23(double value) { mMatrix._23 = value; }
		void Set_31(double value) { mMatrix._31 = value; }
		void Set_32(double value) { mMatrix._32 = value; }
		void Set_33(double value) { mMatrix._33 = value; }
	};
};

#endif


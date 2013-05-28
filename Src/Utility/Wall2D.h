#include "..\Main.h"

#ifndef _aitest_WALL2D
#define _aitest_WALL2D

namespace ait
{
	class Wall2D
	{
	protected:
		Vector2D<double> mVa, mVb, mVn;

		void CalculateNormal();

	public:
		Wall2D(Vector2D<double> a, Vector2D<double> b);
		Wall2D(Vector2D<double> a, Vector2D<double> b, Vector2D<double> n);

		void Draw(bool drawNormals=false);

		Vector2D<double> GetFrom() { return mVa; }
		void SetFrom(Vector2D<double> fromVector) { mVa = fromVector; CalculateNormal(); }
		Vector2D<double> GetTo() { return mVb; }
		void SetTo(Vector2D<double> toVector) { mVb = toVector; CalculateNormal(); }
		Vector2D<double> GetNormal() { return mVn; }
		void SetNormal(Vector2D<double> n) { mVn = n; }

		Vector2D<double> GetCenter() { return (mVa+mVb)/2.0; }

		std::ostream& Write(std::ostream &os);
		void Read(std::ifstream &in);
	};
};

#endif


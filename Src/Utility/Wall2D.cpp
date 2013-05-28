#include "Wall2D.h"

namespace ait
{
	void Wall2D::CalculateNormal()
	{
		Vector2D<double> temp = mVb-mVa;
		temp.Normalize();

		mVn.x = -temp.y;
		mVn.y = temp.x;
	}


	Wall2D::Wall2D(Vector2D<double> a, Vector2D<double> b)
	{
		mVa = a;
		mVb = b;
		CalculateNormal();
	}


	Wall2D::Wall2D(Vector2D<double> a, Vector2D<double> b, Vector2D<double> n)
	{
		mVa = a;
		mVb = b;
		mVn = n;
	}


	void Wall2D::Draw(bool drawNormals)
	{
		//TODO implement someday
	}


	std::ostream& Wall2D::Write(std::ostream &os)
	{
		os << std::endl;
		os << GetFrom().x << "x" << GetFrom().y << ",";
		os << GetTo().x << "x" << GetTo().y << ",";
		os << GetNormal().x << "x" << GetNormal().y;

		return os;
	}


	void Wall2D::Read(std::ifstream &in)
	{
		double x,y;

		in >> x >> y;
		SetFrom(Vector2D<double>(x,y));

		in >> x >> y;
		SetTo(Vector2D<double>(x,y));

		in >> x >> y;
		SetNormal(Vector2D<double>(x,y));
	}
};
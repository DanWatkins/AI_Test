#ifndef _aitest_VECTOR2D_H
#define _aitest_VECTOR2D_H

#include "../Main.h"

template <class T>
class Vector2D
{
public:
	T x, y;

	Vector2D() { Zero(); }
	Vector2D(T x, T y) { this->x = x; this->y = y; }

	void Zero() { x = T(0.0); y = T(0.0); }


	T Length() { return std::sqrt(x*x + y*y); }
	T LengthSq() { return x*x + y*y; }
	T LengthSqrt() { return std::sqrt(Length()); }

	void Normalize()
	{
		double vectorLength = Length();

		if (vectorLength > std::numeric_limits<double>::epsilon())
		{
			x /= vectorLength;
			y /= vectorLength;
		}
	}

	double DotProduct(const Vector2D<T> &vect) { return x*vect.x + y*vect.y; }

	enum { clockwise = 1, anticlockwise = -1 };
	int SignToVector(const Vector2D<T> &vect) { return (y*vect.x > x*vect.y) ? anticlockwise : clockwise;}

	Vector2D<T> Perpendicular() { return Vector2D<T>(-y, x); }

	double DistanceTo(const Vector2D<T> &vect)
	{
		double dx = vect.x - x;
		double dy = vect.y - y;

		return std::sqrt(dx*dx + dy*dy);
	}

	double DistanceToSq(const Vector2D<T> &vect)
	{
		double dx = vect.x - x;
		double dy = vect.y - y;

		return dx*dx + dy*dy;
	}

	Vector2D<T> Reverse() { return Vector2D<T>(-x,-y); }


	//operators
	const Vector2D<T>& operator+=(const Vector2D<T> &rhs) { x += rhs.x; y += rhs.y; }
	const Vector2D<T>& operator-=(const Vector2D<T> &rhs) { x -= rhs.x; y -= rhs.y; }
	const Vector2D<T>& operator*=(const Vector2D<T> &rhs) { x *= rhs.x; y *= rhs.y; }
	const Vector2D<T>& operator/=(const Vector2D<T> &rhs) { x /= rhs.x; y /= rhs.y; }

	bool operator==(const Vector2D<T>& rhs) { return IsEqual(x,rhs.x) && IsEqual(y,rhs.y); }
	bool operator!=(const Vector2D<T>& rhs) { return !IsEqual(x,rhs.x) || !IsEqual(y,rhs.y); }
};

#endif


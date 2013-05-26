#include "..\Main.h"

#ifndef _aitest_UTILITY_H
#define _aitest_UTILITY_H

namespace ait
{
	//forward declarations
	template <class T>
    class Vector2D;

	template <class V>
	class Vector3D;
	class String;

    //pre-calculated constants
    const double PI = 3.141592654;
	const double TWO_PI = PI*2;
    const double PI_OVER_180 = 0.0174532925;
    const double PI_UNDER_180 = 57.29577951;



    /*=============================================================================
    -- Math helper functions.
    =============================================================================*/
    double ToDouble(String text);
    float ToFloat(String text);
    int ToInt(String text);
    bool ToBool(String text);
    Vector2D<double> ToVector2D(String text);
	Vector3D<double> ToVector3D(String text);

    double DivideD(double a, double b);
    float DivideF(float a, float b);
    int DivideI(int a, int b);

    int Round(double n);
    int Round(float n);
    int RoundUp(double n);
    int RoundUp(float n);
    int RoundDown(double n);
    int RoundDown(float n);

    double DegToRad(double deg);
    float DegToRad(float deg);
    int DegToRad(int deg);
    double RadToDeg(double rad);
    float RadToDeg(float rad);
    int RadToDeg(int rad);


	bool LessThan(double number, double numberToBeLessThan, double marginOfError);
	bool GreaterThan(double number, double numberToBeGreaterThan, double marginOfError);

	inline bool IsEqual(double a, double b)
	{
		return std::fabs(a-b) < 1E-12;
	}


	template <class T>
	T Min(T a, T b) { return a < b ? a : b; }

	template <class T>
	T Max(T a, T b) { return a > b ? a : b; }


	inline bool InRange(double start, double end, double value)
	{
		if (start < end)
			return (value > start  &&  value < end);
		else
			return (value < start  &&  value > end);
	}


	inline int RandInt(int x, int y)
	{
		return rand() % (y-x+1)+x;
	}


	inline double RandFloat()
	{
		return rand() / (RAND_MAX+1.0);
	}


	inline double RandInRange(double x, double y)
	{
		return x + RandFloat() * (y-x);
	}


	inline bool RandBool()
	{
		return RandFloat() > 0.5;
	}


	inline double RandClamped()
	{
		return RandFloat() - RandFloat();
	}
}

#endif


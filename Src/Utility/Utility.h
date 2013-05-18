#ifndef _aitest_UTILITY_H
#define _aitest_UTILITY_H

#include "..\Main.h"

inline bool IsEqual(double a, double b)
{
	return std::fabs(a-b) < 1E-12;
}

#endif


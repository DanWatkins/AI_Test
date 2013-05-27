#include "..\Main.h"

#ifndef _aitest_SMOOTHER_H
#define _aitest_SMOOTHER_H

namespace ait
{
	template <class T>
	class Smoother
	{
	private:
		std::vector<T> mHistory;
		int mNextUpdateSlot;
		T mZeroValue;

	public:
		Smoother(int sampleSize, T zeroValue):
			mHistory(sampleSize, zeroValue),
			mZeroValue(zeroValue),
			mNextUpdateSlot(0) {}

		T Update(const T &mostRecentValue)
		{
			//overwrite the oldest value with the newest
			mHistory[mNextUpdateSlot++] = mostRecentValue;

			//make sure mNextUpdateSlot wraps
			if (mNextUpdateSlot == mHistory.size()) mNextUpdateSlot = 0;

			//calculate the average of the history list
			T sum = mZeroValue;

			std::vector<T>::iterator iter = mHistory.begin();
			while (iter != mHistory.end())
			{
				sum += *iter;
				iter++;
			}

			return sum / (double)mHistory.size();
		}
	};
};

#endif


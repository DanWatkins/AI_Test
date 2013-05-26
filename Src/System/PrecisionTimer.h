#include "..\Main.h"

#ifndef _aitest_PRECISION_TIMER_H
#define _aitest_PRECISION_TIMER_H

namespace ait
{
	class PrecisionTimer
	{
	private:
		long long	mCurrentTime,
					mLastTime,
					mLastTimeInTimeElapsed,
					mNextTime,
					mStartTime,
					mFrameTime,
					mPerfCountFreq;

		double	mTimeElapsed,
				mLastTimeElapsed,
				mTimeScale,

				mNormalFPS,
				mSlowFPS;

		bool mStarted;
		bool mSmoothUpdates;

	public:
		PrecisionTimer();
		PrecisionTimer(double fps);

		//managment
		void Start();
		bool IsReadyForNextFrame();
		
		//accessor and mutator
		double GetTimeElapsed();
		double GetCurrentTIme();
		void SetStarted(bool started) { mStarted = started; }
		bool GetStartd() { return mStarted; }

	};
};

#endif


#include "PrecisionTimer.h"

namespace ait
{
	PrecisionTimer::PrecisionTimer()
	{
		mNormalFPS				= 0.0;
		mSlowFPS				= 1.0;
		mTimeElapsed			= 0.0;
		mFrameTime				= 0;
		mLastTime				= 0;
		mLastTimeInTimeElapsed	= 0;
		mPerfCountFreq			= 0;
		mStarted				= false;
		mStartTime				= 0;
		mLastTimeElapsed		= 0.0;
		mSmoothUpdates			= false;

		QueryPerformanceFrequency((LARGE_INTEGER*) &mPerfCountFreq);
		mTimeScale = 1.0/mPerfCountFreq;
	}


	PrecisionTimer::PrecisionTimer(double fps)
	{
		//TODO potentially just call PrecisionTimer() to reduce redundancy
		mNormalFPS				= fps;
		mSlowFPS				= 1.0;
		mTimeElapsed			= 0.0;
		mFrameTime				= 0;
		mLastTime				= 0;
		mLastTimeInTimeElapsed	= 0;
		mPerfCountFreq			= 0;
		mStarted				= false;
		mStartTime				= 0;
		mLastTimeElapsed		= 0.0;
		mSmoothUpdates			= false;

		QueryPerformanceFrequency((LARGE_INTEGER*) &mPerfCountFreq);
		mTimeScale = 1.0/mPerfCountFreq;
	}


	void PrecisionTimer::Start()
	{
		mStarted = true;
		mTimeElapsed = 0.0;

		QueryPerformanceCounter((LARGE_INTEGER*) &mLastTime);

		mStartTime = mLastTimeInTimeElapsed = mLastTime;
		mNextTime = mLastTime + mFrameTime;
	}


	bool PrecisionTimer::IsReadyForNextFrame()
	{
		QueryPerformanceCounter((LARGE_INTEGER*) &mCurrentTime);

		if (mCurrentTime > mNextTime)
		{
			mTimeElapsed = (mCurrentTime - mLastTime) * mTimeScale;
			mLastTime = mCurrentTime;

			mNextTime = mCurrentTime + mFrameTime;

			return true;
		}

		return false;
	}


	double PrecisionTimer::GetTimeElapsed()
	{
		mLastTimeElapsed = mTimeElapsed;

		QueryPerformanceCounter((LARGE_INTEGER*) &mCurrentTime);
		mTimeElapsed = (mCurrentTime - mLastTimeInTimeElapsed)*mTimeScale;
		mLastTimeInTimeElapsed = mCurrentTime;

		const double smoothness = 5.0;

		if (mSmoothUpdates)
		{
			if (mTimeElapsed < (mLastTimeElapsed*smoothness))
				return mTimeElapsed;
			else
				return 0.0;
		}
		else
			return mTimeElapsed;
	}


	double PrecisionTimer::GetCurrentTIme()
	{
		QueryPerformanceCounter((LARGE_INTEGER*) &mCurrentTime);
		return (mCurrentTime - mStartTime) * mTimeScale;
	}
};
#include "..\Main.h"

#ifndef _aitest_TIMER_H
#define _aitest_TIMER_H

namespace ait
{
    /*=============================================================================
      Class to keep track of time. 
    =============================================================================*/
    class Timer
    {
    private:
        sf::Clock mClock;
        float mEnd;


    public:
        Timer()
        {
            Start();
            mEnd = 0.0f;
        }

        void Start()
        {
            mClock.Reset();
        }

        void End()
        {
            mEnd = mClock.GetElapsedTime();
        }

		//returns time in milli-seconds
        float GetTime()
        {
            return mEnd*1000;
        }

        float GetTimeAndEnd()
        {
            End();
            return GetTime();
        }
    };

};

#endif


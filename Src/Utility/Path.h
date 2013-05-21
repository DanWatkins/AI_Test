#include "..\Main.h"

#ifndef _aitest_PATH_H
#define _aitest_PATH_H

namespace ait
{
	class Path
	{
	private:
		std::list< Vector2D<double> > mWaypoints;
		std::list< Vector2D<double> >::iterator mCurrentWaypoint;
		bool mLooped; //last goes to first

	public:
		Path() { mLooped = false; }
		Path(int waypointCount, double minX, double minY, double maxX, double maxY, bool looped);

		//initialization
		std::list< Vector2D<double> > CreateRandomPath(int wayPointCount, double minX, double minY, double maxX, double maxY);
		void Set(std::list< Vector2D<double> >newPath);
		void Set(Path path);

		//general
		void Draw();
		void Clear() { mWaypoints.clear(); }
		bool IsFinished() { return !(mCurrentWaypoint != mWaypoints.end()); }
		void SetLooped(bool looped) { mLooped = looped; }
		std::list< Vector2D<double> > GetPath() { return mWaypoints; }

		//waypoint managment
		void AddWaypoint(Vector2D<double> newWayPoint);
		Vector2D<double> GetCurrentWaypoint();
		void SetNextWaypoint();	
	};
};

#endif


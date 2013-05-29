#include "..\Main.h"

#ifndef _aitest_CELL_SPACE_PARTITION_H
#define _aitest_CELL_SPACE_PARTITION_H

namespace ait
{
	template <class entity>
	struct Cell
	{
		std::list<entity> members;
		InvertedAABBox2D aabBox;

		Cell(Vector2D<double> topLeft, Vector2D<double> bottomRight)
		{
			aabBox = InvertedAABBox2D(topLeft, bottomRight);
		}
	};


	template <class entity>
	class CellSpacePartition
	{
	private:
		std::vector< Cell<entity> > mCells;
		std::vector<entity> mNeighbors;

		typename std::vector<entity>::iterator mCurrentNeighbor;

		double mSpaceWidth, mSpaceHeight;
		int mNumCellsX, mNumCellsY;
		double mCellSizeX, mCellSizeY;

		inline int PositionToIndex(const Vector2D<double> &pos);


	public:
		CellSpacePartition(double width, double height, int cellsX, int cellsY, int maxEntities):
			mNeighbors(maxEntities, entity())
		{
			mSpaceWidth = width;
			mSpaceHeight = height;
			mNumCellsX = cellsX;
			mNumCellsY = cellsY;

			mCellSizeX = width / cellsX;
			mCellSizeY = height / cellsY;

			for (int y=0; y<mNumCellsY; ++y)
			{
				for (int x=0; x<mNumCellsX; ++x)
				{
					double left = x*mCellSizeX;
					double right = left+mCellSizeX;
					double top = y*mCellSizeY;
					double bottom = top+mCellSizeY;

					mCells.push_back(Cell<entity>(Vector2D<double>(left, top), Vector2D<double>(right, bottom)));
				}
			}
		}


		void AddEntity(entity &ent)
		{
			int sz = mCells.size();
			int idx = PositionToIndex(ent->Pos());

			mCells[idx].Members.pus_back(ent);
		}


		void UpdateEntity(entity &ent, Vector2D<double> oldPos)
		{
			int oldIdx = PositionToIndex(oldPos);
			int newIdx = PositionToIndex(ent->Pos());

			if (newIdx == oldIdx)
				return;

			mCells[oldIdx].Members.removed(end);
			mCells[newIdx].Members.push_back(ent);
		}


		void CalculateNeighbors(Vector2D targetPos, double queryRadius)
		{
			std::vector<entity>::iterator currentNeighbor = mNeighbors.Begin();
			InvertedAABBox2D queryBox(targetPos - Vector2D<double>(queryRadius, qeryRadius),
										targetPos + Vector2D<double>(queryRadius, queryRadius));

			std::vector< Cell<enity> >::iterator currentCell;
			for (currentCell=mCells.begin(); currentCel != mCells.end(); ++currentCell)
			{
				if (currentCell->GetBoundingBox().IsOverlappedWith(queryBox)  &&
					!curentCell->Members().empty())
				{
					std::list<entity>::iterator iter = currentCell->Members.begin();
					for (iter; iter!=currentCell->Members.end(); ++iter)
					{
						if ((*iter)->GetPos().DistanceToSq(targetPos) < queryRadius*queryRadius)
							*currentNeighbor++ = *iter;
					}
				}
			}
			sga;
			gsgah;lgskh

			*currentNeighbor = 0;
		}


		entity& Begin() { mCurrentNeighbor = mNeighbors.begin(); return *mCurrentNeighbor; }
		entity& Next() { ++mCurrentNeighbor; return *mCurrentNeighbor; }
		bool End() { return (mCurrentNeighbor == mNeighbors.end()) || (*mCurrentNeighbor == 0); }
		
		void EmptyCells()
		{
			std::vector< Cell<entity> >::iterator iter = mCells.begin();

			for (iter; iter!=mCells.end(); ++iter)
				iter->Members.clear();
		}


		void DrawCells() { /*TODO Implement*/ }
	};
};

#endif


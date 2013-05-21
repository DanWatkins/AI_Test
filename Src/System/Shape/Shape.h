#include "..\..\Main.h"

#ifndef _aitest_SHAPE_H
#define _aitest_SHAPE_H

namespace ait
{
	class Shape
	{
	protected:
		sf::RenderWindow *mRenderWindow;
		sf::Shape mShape;
		Vector2D<double> mPos;

	public:
		virtual void Draw() = 0;

		void SetRenderWindow(sf::RenderWindow *renderWindow) { mRenderWindow = renderWindow; }
		sf::RenderWindow *GetRenderWindow() { return mRenderWindow; }

		void SetPos(Vector2D<double> pos) { mPos = pos; }
		Vector2D<double> GetPos() { return mPos; }
	};
};

#endif


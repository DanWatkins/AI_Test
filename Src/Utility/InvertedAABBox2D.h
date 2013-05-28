#include "..\Main.h"

#ifndef _aitest_INVERTEDAABB2D_H
#define _aitest_INVERTEDAABB2D_H

namespace ait
{
	class InvertedAABBox2D
	{
	private:
  
	  Vector2D<double>  m_vTopLeft;
	  Vector2D<double>  m_vBottomRight;

	  Vector2D<double>  m_vCenter;
  
	public:

	  InvertedAABBox2D(Vector2D<double> tl,
					   Vector2D<double> br):m_vTopLeft(tl),
									m_vBottomRight(br),
									m_vCenter((tl+br)/2.0)
	  {}

	  //returns true if the bbox described by other intersects with this one
	  bool isOverlappedWith(const InvertedAABBox2D& other)const
	  {
		return !((other.Top() > this->Bottom()) ||
			   (other.Bottom() < this->Top()) ||
			   (other.Left() > this->Right()) ||
			   (other.Right() < this->Left()));
	  }

  
	  Vector2D<double> TopLeft()const{return m_vTopLeft;}
	  Vector2D<double> BottomRight()const{return m_vBottomRight;}

	  double    Top()const{return m_vTopLeft.y;}
	  double    Left()const{return m_vTopLeft.x;}
	  double    Bottom()const{return m_vBottomRight.y;}
	  double    Right()const{return m_vBottomRight.x;}
	  Vector2D<double> Center()const{return m_vCenter;}

	  void     Render(bool RenderCenter = false)const
	  {
		  //TODO Implement later
		/*gdi->Line((int)Left(), (int)Top(), (int)Right(), (int)Top() );
		gdi->Line((int)Left(), (int)Bottom(), (int)Right(), (int)Bottom() );
		gdi->Line((int)Left(), (int)Top(), (int)Left(), (int)Bottom() );
		gdi->Line((int)Right(), (int)Top(), (int)Right(), (int)Bottom() );*/


		if (RenderCenter)
		{
		  //TODO Implement later gdi->Circle(m_vCenter, 5);
		}
	  }

	};
};

#endif


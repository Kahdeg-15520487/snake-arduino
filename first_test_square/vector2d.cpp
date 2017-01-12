#include "vector2d.h"
//using namespace graphic;

vector2d::vector2d(int X,int Y){
  x=X;
  y=Y;
}

vector2d::vector2d(const vector2d& vt){
  x= vt.GetX();
  y= vt.GetY();
}

vector2d vector2d::CongVT(vector2d vt){
	return vector2d(x+vt.GetX(),y+vt.GetY());
}

vector2d vector2d::TruVT(vector2d vt){
	return vector2d(x-vt.GetX(),y-vt.GetY());
}

#include "vector2d.h"

vector2d::vector2d(int X,int Y){
  x=X;
  y=Y;
}

vector2d::vector2d(const vector2d& vt){
  x= vt.GetX();
  y= vt.GetY();
}

vector2d vector2d::operator+(const vector2d& vt){
	return vector2d(x+vt.GetX(),y+vt.GetY());
}
vector2d vector2d::operator+=(const vector2d& vt){
	x+=vt.GetX();
	y+=vt.GetY();
	return *this;
}
vector2d vector2d::operator-(const vector2d& vt){
	return vector2d(x-vt.GetX(),y-vt.GetY());
}
vector2d vector2d::operator-=(const vector2d& vt){
  x-=vt.GetX();
  y-=vt.GetY();
  return *this;
}
vector2d vector2d::operator=(const vector2d& vt){
  x=vt.GetX();
  y=vt.GetY();
  return *this;
}
bool vector2d::operator==(const vector2d& vt){
  if (x==vt.GetX() && y==vt.GetY())
    return true;
  else return false;
}


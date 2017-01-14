#pragma once
#include <UTFT.h>
#include "Wire.h"
using namespace std;

class Square
{
  private:
  int x, y;
  
  public:
  Square() {x=0;y=0;};
  Square(int X, int Y) {x=X;y=Y;};
  ~Square() {};

  void setx(int X) {x=X;};
  void sety(int Y) {y=Y;};
  int getx() {return x;};
  int gety() {return y;};

  void drawSq(int);
  void ersSq();
};


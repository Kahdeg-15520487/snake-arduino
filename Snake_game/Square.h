
#ifndef SQUARE_H
#define SQUARE_H

#include <UTFT.h>
//#include "Wire.h"
//using namespace std;

class Square
{
  private:
  int x, y;
  UTFT scr;
  public:
  Square() {x=0;y=0;};
  Square(int X,int Y) {x=X;y=Y;};
  Square(int X, int Y, UTFT SCR) {x=X;y=Y;scr=SCR;};
  ~Square() {};

  void setx(int X) {x=X;};
  void sety(int Y) {y=Y;};
  void setscr(UTFT SCR) {scr=SCR;};
  int getx() {return x;};
  int gety() {return y;};

  void drawSq(int);
  void ersSq();
};
#endif

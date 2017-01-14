#include "Square.h"
UTFT scr1(CTE28,38,39,40,41);
void Square::drawSq(int a)
{
  switch (a)
  {
    case 0:
    scr1.drawRect(x,y,x+8,y+8);
    case 2:
    scr1.drawRect(x,y-1,x+8,y+8);
    case 4:
    scr1.drawRect(x,y,x+9,y+8);
    case 6:
    scr1.drawRect(x-1,y,x+8,y+8);
    case 8:
    scr1.drawRect(x,y,x+8,y+9);
  }
}

void Square::ersSq()
{
  scr1.setColor(VGA_BLACK);
  scr1.drawRect(x-1,y-1,x+9,y+9);
  scr1.setColor(VGA_WHITE);
}


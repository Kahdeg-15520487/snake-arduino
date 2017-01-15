#include "Snake.h"
UTFT scr(CTE28,38,39,40,41);
extern uint8_t SmallFont[];

void drawSq(Square s,int a)
{
  int x=s.getx();
  int y=s.gety();
  switch (a)
  {
    case 0:
    {
    scr.drawRect(x,y,x+8,y+8);
    break;
    }
    case 2:
    {
    scr.drawRect(x,y-1,x+8,y+8);
    break;
    }
    case 4:
    {
    scr.drawRect(x,y,x+9,y+8);
    break;
    }
    case 6:
    {
    scr.drawRect(x-1,y,x+8,y+8);
    break;
    }
    case 8:
    {
    scr.drawRect(x,y,x+8,y+9);
    break;
    }
  }
}

void ersSq(Square s)
{
  int x=s.getx();
  int y=s.gety();
  scr.setColor(VGA_BLACK);
  scr.drawRect(x-1,y-1,x+9,y+9);
  scr.setColor(VGA_WHITE);
}

void setup() {
  // put your setup code here, to run once:
  randomSeed(analogRead(0));
  //initialize lcd
  scr.InitLCD();
  scr.setFont(SmallFont);
  scr.clrScr();               //clear the noise
  scr.setColor(VGA_WHITE);  //set draw color to white
  //initialize serial comm
  Serial.begin(9600);
  scr.drawRect(0,0,319,239);
//  for(int i=0;i<4;i++)
//    scr.drawRect(0+i,0+i,319-i,239-i);
  //Snake S;
  //drawSq(S.getsq(0),0);
  //for (int i=0; i<S.getn()-1;i++)
  //drawSq(S.getsq(i),S.getdir());
}
void loop()
{
  
}



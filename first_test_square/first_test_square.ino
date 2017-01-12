#include <UTFT.h>
extern uint8_t SmallFont[];
UTFT scr(CTE28,38,39,40,41);

#include "vector2d.h"

void setup() {
  // put your setup code here, to run once:
  scr.InitLCD();
  scr.setFont(SmallFont);
  scr.clrScr();
  scr.setColor(255,255,255);
  scr.drawRect(0,0,319,239);
  Serial.begin(9600);
}

vector2d posx(0,0);
vector2d posy(8,8);
vector2d dir(8,0);

void loop() {
  scr.clrScr();
  while (Serial.available() > 0) {
    int d = Serial.parseInt();
    switch (d){
      case 0: //up
        dir.SetX(0);
        dir.SetY(8);
        break;
      case 1: //down
        dir.SetX(0);
        dir.SetY(-8);
        break;
      case 2: //left
        dir.SetX(-8);
        dir.SetY(0);
        break;
      case 3: //right
        dir.SetX(8);
        dir.SetY(0);
        break;
      case 4: //stop
        dir.SetX(0);
        dir.SetY(0);
      default:
        break;
    }
     
  }
  
  posx = posx.CongVT(dir);
  posy = posy.CongVT(dir);
  if ((posy.GetY()>240) || (posy.GetY()<0) ||
      (posx.GetX()>320) || (posx.GetX()<0))
  {
    dir.SetX(0);
    dir.SetY(0);
  }
  draw_snake_part(posx,posy);
  delay(500);
}

void draw_snake_part(vector2d posx,vector2d posy){
    scr.fillRect(posx.GetX(),posx.GetY(),posy.GetX(),posy.GetY());
}


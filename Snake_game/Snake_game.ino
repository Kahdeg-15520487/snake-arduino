#include "Snake_sc.h"
UTFT scr(CTE28,38,39,40,41);
extern uint8_t SmallFont[];

int main() {
  // put your setup code here, to run once:
  randomSeed(analogRead(0));
  //initialize lcd
  scr.InitLCD();
  scr.setFont(SmallFont);
  scr.clrScr();               //clear the noise
  scr.setColor(VGA_WHITE);  //set draw color to white
  //initialize serial comm
  Serial.begin(9600);
  for(int i=0;i<4;i++)
    scr.drawRect(0+i,0+i,319-i,239-i);
  return 0;
  
}


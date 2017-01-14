#include <UTFT.h>
extern uint8_t SmallFont[];
UTFT scr(CTE28,38,39,40,41);

#include "vector2d.h"
#include "matrix.h"

const vector2d zero(0,0);
const vector2d up(0,-1);
const vector2d down(0,1);
const vector2d left(-1,0);
const vector2d right(1,0);

vector2d fruit;
int fruitlife;
vector2d head(20,15);
vector2d tail(19,15);
vector2d tailold;
vector2d dir(1,0);
matrix matr;
bool isdead = false;

void setup() {
  randomSeed(analogRead(0));
  
  //initialize lcd
  scr.InitLCD();
  scr.setFont(SmallFont);
  scr.clrScr();               //clear the noise
  scr.setColor(VGA_WHITE);  //set draw color to white
  scr.drawRect(0,0,319,239);  //draw the border
  //initialize serial comm
  Serial.begin(9600);
  spawn_fruit();
}

void loop() {
  scr.drawRect(0,0,319,239);  //draw the border
  if (!isdead){
    if (Serial.available() > 0) {
      int d = Serial.parseInt();
      switch (d){
        case 0: //up
          dir = up;
          Serial.print("up");
          Serial.print('\n');
          break;
        case 1: //down
          dir = down;
          Serial.print("down");
          Serial.print('\n');
          break;
        case 2: //left
          dir = left;
          Serial.print("left");
          Serial.print('\n');
          break;
        case 3: //right
          dir = right;
          Serial.print("right");
          Serial.print('\n');
          break;
        case 4: //stop
          dir = zero;
          Serial.print("stop");
          Serial.print('\n');
        default:
          
          break;
      }     
    }

    //handle movement
    tailold=tail;
    Swap(head,tail);
    head=tail+dir;

    //handle collsion with fruit
    //check if the head is overlapping the fruit
    //if yes: +erase fruit
    //        +head+=dir
    //if no : +decrase fruitlife
    //        +if fruitlife<0 -> erase fruit and spawn new fruit
    if (head == fruit){
      Serial.print(head.GetX());
      Serial.print(",");
      Serial.print(head.GetY());
      Serial.print('\n');
      fillrect(head,VGA_WHITE);
      head+=dir;
      Serial.print(head.GetX());
      Serial.print(",");
      Serial.print(head.GetY());
      Serial.print('\n');
      spawn_fruit();
    }
    else{
      if (fruitlife >0)
        fruitlife=fruitlife;
        //fruitlife-=1;
      else spawn_fruit();
    }
   
    
    //handle collision with wall
    if (head.GetX()<0 || head.GetX()>39 || head.GetY()<0 || head.GetY()>29)
    {
      dir = zero;
      isdead = true;
      Serial.print("dead :(");
    }

    //handle collision with self
    //

    //handl draw operation
    draw_snake();
    draw_fruit();
  }
  delay(500);
}

void draw_snake(){
  fillrect(tailold,VGA_BLACK);            //erase the old tail
  fillrect(head,VGA_WHITE);               //fill the head
}

void spawn_fruit(){
  //spawn fruit position
  fruit = vector2d(random(40),random(30));
  fruitlife = 8;
}

void draw_fruit(){
  int x=fruit.GetX()*8;
  int y=fruit.GetY()*8;
  int oldcolor = scr.getColor();
  fillrect(fruit,VGA_BLACK);
  scr.setColor(VGA_GREEN);
  //scr.fillRect(x,y,x+7,y+7);
  switch (fruitlife){
    case 8:
      scr.fillRect(x,y,x+7,y+7);
      break;
    case 7:
      scr.fillRect(x,y,x+6,y+6);
      break;
    case 6:
      scr.fillRect(x+1,y+1,x+6,y+6);
      break;
    case 5:
      scr.fillRect(x+1,y+1,x+5,y+5);
      break;
    case 4:
      scr.fillRect(x+2,y+2,x+5,y+5);
      break;
    case 3:
      scr.fillRect(x+2,y+2,x+4,y+4);
      break;
    case 2:
      scr.fillRect(x+3,y+3,x+4,y+4);
      break;
    case 1:
      //scr.fillRect();
      break;
    case 0:
      //scr.fillRect();
      break;
    default:
      break;
  }
  scr.setColor(oldcolor);
}

void fillrect(vector2d pos,int color){
  int x=pos.GetX()*8;
  int y=pos.GetY()*8;
  int oldcolor = scr.getColor();
  scr.setColor(color);
  scr.fillRect(x,y,x+7,y+7);
  scr.setColor(oldcolor);
}

void Swap(vector2d& vt1,vector2d& vt2){
  vector2d vttemp = vt1;
  vt1=vt2;
  vt2=vttemp;
}


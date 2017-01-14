#include "Snake_sc.h"

Snake::Snake()
{
  Init(L);
  for(int i=0;i<n;i++)
  {
    Square a(cul.getx()+i*10,cul.getx()+i*10);
    Insert_first (L, a);
    L->data.drawSq(dir);
  }
}


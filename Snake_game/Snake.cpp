#include "Snake.h"

const Square cul(6,6);
const Square cur(6,313);
const Square cdl(233,6);
const Square cdr(233,313);

Snake::Snake()
{
  Init(L);
  for(int i=0;i<n;i++)
  {
    Square a(36-(i*10),6);
    if(i=0)
        tail=a;
    if(i=n-1)
        head=a;
    Insert_first (L, a);
  }
}

bool Snake::check_mv(int a)
{
  if((a==dir) or
     (dir==2 and a==8) or
     (dir==8 and a==2) or
     (dir==4 and a==6) or
     (dir==6 and a==4) or
     (a!=(2,4,6,8)))
      return false;
  else return true;
}

void Snake::change_dir()
{
  if (check_mv(Serial.parseInt()))
      dir = Serial.parseInt();
}

void Snake::S_addh()
{
  switch(dir)
  {
    case 2:
    {
      Square New(head.getx()+10,head.gety());
      Insert_first(L,New);
    }
    case 4:
    {
      Square New(head.getx(),head.gety()-10);
      Insert_first(L,New);
    }
    case 6:
    {
      Square New(head.getx(),head.gety()+10);
      Insert_first(L,New);
    }
    case 8:
    {
      Square New(head.getx()-10,head.gety());
      Insert_first(L,New);
    }
  }
  head=L->data;
}

void Snake::S_move()
{
  Del_last(L, tail);
  Snake::S_addh();
}

bool Snake::check_cl()
{
  if((head.getx()<6) or
     (head.getx()>313) or
     (head.gety()<6) or
     (head.gety()>233))
        return true;
  else
  {
    Node *P=L->next;
    while (P!= NULL)
    {
        if(P->data.getx()==head.getx())
            return true;
        P=P->next;
    }
    return false;
  }
}

void Snake::S_incr()
{
  n=n+2;
  Snake::S_addh();
  Snake::S_addh();
}

Square Snake::getsq(int k)
{
  Node *P=L;
  int i=0;
  while (i<k)
  {
    P=P->next;
    i++;
  }
  return P->data;
}



#ifndef SNAKE_SC_H
#define SNAKE_SC_H

#include "Struct_List.h"

class Snake
{
  private:
  int n=4;
  int dir=6;
  List L;

  Square head;
  Square tail;

  public:
  Snake();
  ~Snake() {};

  void change_dir();
  void S_addh();
  void S_move();
  void S_incr();

  bool check_mv(int);
  bool check_cl();

  Square getsq(int);
  int getn() {return n;};
  int getdir() {return dir;};
};
#endif

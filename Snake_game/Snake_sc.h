#ifndef SNAKE_SC_H
#define SNAKE_SC_H

#include "Square.h"
typedef struct Node 
{
    Square data;
    Node *next; 
} NODE;
typedef Node *List;

const Square cul(6,6);
const Square cur(6,313);
const Square cdl(233,6);
const Square cdr(233,313);

Node *Make_Node (Node *, Square);
void Insert_first (List &, Square);
void Init (List &L);
void Insert_k (List &, Square , int);
int Search (List , Square);
void Del_first (List &, Square &);
void Del_k (List &, Square &, int);




class Snake
{
  private:
  int n=4;
  int dir=6;
  List L;
  Square head;
  Square tail;
  Square food;

  public:
  Snake();
  ~Snake() {};

  
};
#endif


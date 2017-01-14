#include "Square.h"
typedef struct Node 
{
    Square data;
    Node *next; 
};
typedef Node *List;

const Square cul(6,6);
const Square cur(6,313);
const Square cdl(233,6);
const Square cdr(233,313);

Node *Make_Node (Node *, Square);
void Insert_first (List &, Square);
void Init (List &L) {L=NULL;};
void Insert_k (List &, Square , int);
int Search (List , Square);
void Del_first (List &, Square &);
void Del_k (List &, Square &, int);

Node *Make_Node (Node *P, Square x) 
{
    P = (Node *) malloc (sizeof (Node)); //Cap phat vung nho cho P
    P->next = NULL; //Cho truong Next tro den NULL
    P->data = x; //Ghi du lieu vao Data
    return P; 
}

void Insert_first (List &L, Square x)  //Chen x vao vi tri dau tien trong danh sach
{
    Node *P; 
    P = Make_Node(P,x); //tao 1 Node P
    P->next = L; //Cho P tro den L
    L = P; //L tro ve P
}
#ifndef SNAKE_SC_H
#define SNAKE_SC_H
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


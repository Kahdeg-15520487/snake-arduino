#ifndef LIST_H
#define LIST_H

#include "Square.h"

struct Node 
{
    Square data;
    Node *next; 
};
typedef Node *List;

Node *Make_Node (Node *, Square);
void Init (List &) ;
void Insert_first (List &, Square);
void Del_last (List &, Square &);

#endif


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
void Insert_first (List &L, Square x)  //Chen x vao vi tri dau tien trong danh sach
{
    Node *P; 
    P = Make_Node(P,x); //tao 1 Node P
    P->next = L; //Cho P tro den L
    L = P; //L tro ve P
}
void Init (List &L) {L=NULL;};
Node *Make_Node (Node *P, Square x) 
{
    P = (Node *) malloc (sizeof (Node)); //Cap phat vung nho cho P
    P->next = NULL; //Cho truong Next tro den NULL
    P->data = x; //Ghi du lieu vao Data
    return P; 
}

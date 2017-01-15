#include "Struct_List.h"

Node *Make_Node (Node *P, Square x)
{
        P = (Node *) malloc (sizeof (Node));
        P->next = NULL;
        P->data = x;
        return P;
}

void Init (List &L) {
        L=NULL;
}

void Insert_first (List &L, Square x)
{
        Node *P;
        P = Make_Node(P,x);
        P->next = L;
        L = P;
}

void Del_last (List &L, Square &a)
{
        Node *P=L;
        while (P->next != NULL)
        {
                P=P->next;
        }
        a = P->data;
        P = NULL;
}

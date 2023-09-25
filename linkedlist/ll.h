#include <stdio.h>
#include <stdlib.h>
typedef struct Node *PtrToNode;
typedef struct Node *List;
struct Node
{
    int element;
    struct Node *next;
};
PtrToNode MakeNode(int e);
void AddElement(List L, int e);
int ListSize(const List L);
void insert(List L, int pos, int e);
int rem(List L, int pos);
int find(List L, int e);
void del(List L);
void print_clist(List l);
PtrToNode Interleave(List l1, List l2);
List reverse(List l);
PtrToNode reverse_rec(PtrToNode l);
PtrToNode rec_Interleave(List l1, List l2);
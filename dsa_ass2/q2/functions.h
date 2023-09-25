#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Qnode
{
    int elem;
    struct Qnode *next;
    struct Qnode *prev;
} Qnode;
typedef Qnode *ptrnode;
typedef Qnode *Queue;
Queue InitQueue();
void Push(Queue head, int val);
int Pop(Queue head);
void Inject(Queue head, int val);
int popRear(Queue head);
void Print(Queue head);
void PrintReverse(Queue head);
int findElem(Queue head, int pos);
void removeKElems(Queue head, int k);
#endif
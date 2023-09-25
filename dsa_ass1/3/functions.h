#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int Element;
    struct Node* NextNode;
}Node;
typedef Node* PtrNode;
void Insert(PtrNode Head, int num);
PtrNode Find( PtrNode Head, int num );
void Print( PtrNode Head);

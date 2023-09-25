#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    long long int col;
    long long int val;
    struct Node* next;
    
}Node;
typedef Node* PtrNode;
typedef struct row
{
    long long int row;
    struct Node* next;
    struct row* nextrow;
}row;



typedef row* Ptrrow;
typedef struct Node2{
    long long int row;
    long long int col;
    long long int val;
    struct Node2* next;
}Node2;
typedef Node2* ptr;
PtrNode MakeNode(long long int val, long long int col);
void Insert(Ptrrow Head,long long int val, long long int col);
Ptrrow MakeHead(long long int row, Ptrrow MHead);
Ptrrow Findrow(long long int row, Ptrrow MHead);
void Print(Ptrrow MHead, long long int k);
void MakeMatrix(Ptrrow MHead, long long int k);
Ptrrow Transpose(Ptrrow MHead);
void Multiply(Ptrrow MHead1, Ptrrow MHead2,Ptrrow new);
Ptrrow appendhead(Ptrrow Head, long long int row);
void nprint(Ptrrow MHead);
ptr create(int k);
ptr create_t(int k);
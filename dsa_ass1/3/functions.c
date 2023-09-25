#include "functions.h"

void Insert(PtrNode Head, int num){
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    n->Element=num;
    n->NextNode=NULL;
    if(Head->NextNode == NULL){
        Head->NextNode=n;
        n->NextNode=Head;
        return;
    }
    PtrNode C = Head->NextNode;
    Head->NextNode=n;
    n->NextNode=C;
    
    return;
}

PtrNode Find(PtrNode Head, int num) {
    if (Head->NextNode == NULL)
        return NULL;
    else{
        PtrNode C = Head->NextNode;
        if (C->Element == num)
            return C;
        while (C->NextNode!=Head && C->NextNode->Element!=num)
        {
            C=C->NextNode;
        }
        if(C->NextNode->Element!=num){
            return NULL;
        }

        PtrNode temp=C->NextNode;
        PtrNode i = Head->NextNode;
        Head->NextNode=C->NextNode;
        C->NextNode=C->NextNode->NextNode;
        temp->NextNode=i;
        return temp;
    }
    return NULL;
}

void Print(PtrNode Head){
    if(Head->NextNode==NULL){
        return;
    }
    PtrNode C=Head->NextNode;
    printf("%d ",C->Element);
    while (C->NextNode!=Head)
    {
        C=C->NextNode;
        printf("%d ",C->Element);
    }
    return;
}

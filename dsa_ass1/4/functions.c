#include "functions.h"

Ptrrow MakeHead(long long int row, Ptrrow MHead){
    Ptrrow Head=(Ptrrow)malloc(sizeof(row));
    Head->row=row;
    Head->nextrow=NULL;
    Head->next=NULL;
    if(MHead->nextrow==NULL){
        MHead->nextrow=Head;
        return Head;
    }
    while(MHead->nextrow!=NULL && row>(MHead->nextrow->row)){
        MHead=MHead->nextrow;
    }
    Head->nextrow=MHead->nextrow;
    MHead->nextrow=Head;
    return Head;
}
Ptrrow appendhead(Ptrrow Head, long long int row){
    Ptrrow H=(Ptrrow)malloc(sizeof(row));
    H->row=row;
    H->nextrow=Head->nextrow;
    H->next=NULL;
    Head->nextrow=H;
    return H;
}
Ptrrow Findrow(long long int row, Ptrrow MHead){
    Ptrrow x=MHead;
    Ptrrow prev=x;

    while(x!=NULL){
        if(x->row==row){
            return x;
        }
        else if(x->row > row){
            return prev;
        }
        prev=x;
        x=x->nextrow;
        
    }
    return prev;
}

PtrNode MakeNode(long long int val, long long int col){
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    n->col=col;
    n->val=val;
    n->next=NULL;
    return n;
}
void Insert(Ptrrow Head,long long int val, long long int col){
    PtrNode n=MakeNode(val,col);
    PtrNode x;
    if(Head->next==NULL){
        Head->next=n;
        return;
    }
    x=Head->next;
    if(col<x->col){
        Head->next=n;
        n->next=x;
        return;
    }
    while(x->next!=NULL && col>x->next->col){
        x=x->next;
    }
    n->next=x->next;
    x->next=n;
    return;
}
void Print(Ptrrow MHead, long long int k){
        Ptrrow Head=MHead->nextrow;
        printf("%lld\n",k);
        while(Head!=NULL){
            PtrNode x=Head->next;
            
            while(x!=NULL){
                if(x->val!=0){
                    printf("%lld %lld %lld\n",Head->row,x->col,x->val);

                }
                x=x->next;
            }
            Head=Head->nextrow;
            
        }
}
void MakeMatrix(Ptrrow MHead,long long int k){
        long long int r;
        Ptrrow Head;
        PtrNode x;
        for(long long int a=0;a<k;a++){
            if(a==0){
                long long int j,val;
                scanf("%lld %lld %lld",&r,&j,&val);
                Head = MakeHead(r,MHead);
                Insert(Head,val,j);
                x=Head->next;
            }
            else{
                long long int i,j,val;
                
                scanf("%lld %lld %lld",&i,&j,&val);
                if(i!=r){
                    Head = appendhead(Head,i);
                    PtrNode n=MakeNode(val,j);
                    Head->next=n;
                    x=n;
                }
                
                else{
                    PtrNode n=MakeNode(val,j);
                    x->next=n;
                    x=n;   
                }
                r=i;    
            }
        }
}




Ptrrow Transpose(Ptrrow MHead){
        Ptrrow new=(Ptrrow)malloc(sizeof(row));
        new->nextrow=NULL;
        new->row=-1;
        new->next=NULL;

        MHead=MHead->nextrow;
        PtrNode x= MHead->next;
        while(MHead!=NULL){
            Ptrrow Head=Findrow(x->col,new);
            if(Head->row!=x->col){
                Head=appendhead(Head,x->col);
            }
            Insert(Head,x->val,MHead->row);
            
            x=x->next;
            if(x==NULL){
                MHead=MHead->nextrow;
                if(MHead!=NULL){
                    x=MHead->next;
                }                
            }
        }
        return new;
}

void nprint(Ptrrow MHead){
    Ptrrow Head=MHead->nextrow;
        while(Head!=NULL){
            PtrNode x=Head->next;
            
            while(x!=NULL){
                if(x->val!=0){
                    printf("%lld %lld %lld\n",Head->row,x->col,x->val);

                }
                x=x->next;
            }
            Head=Head->nextrow;
            
        }
}

void Multiply(Ptrrow MHead1, Ptrrow MHead2, Ptrrow new){
        Ptrrow new_Head;
        Ptrrow Head2=MHead2->nextrow;
        PtrNode x1,x2,x3;
        long long int sum,k=0;
        int it=0;
        MHead1=MHead1->nextrow;
        while(MHead1!=NULL){

            if(it==0){
                new_Head=MakeHead(MHead1->row,new);
            }
            else{
                new_Head=appendhead(new_Head,MHead1->row);
            }
            
            x3=new_Head->next;
            while(Head2!=NULL){
                sum=0;
                x1=MHead1->next;
                x2=Head2->next;
                
                while(x1!=NULL && x2!=NULL){
                    if(x1->col==x2->col){
                        sum+=x2->val*x1->val;
                        x1=x1->next;
                        x2=x2->next;
                    }
                    else if(x1->col<x2->col){
                        x1=x1->next;
                    }
                    else if(x2->col<x1->col){
                        x2=x2->next;
                    }
                }
                if(sum!=0){
                    
                    k++;
                    PtrNode n=MakeNode(sum,Head2->row);
                    if(x3==NULL){
                        new_Head->next=n;
                        x3=n;
                    }
                    else{
                        x3->next=n;
                        x3=x3->next;
                    }
                }
                Head2=Head2->nextrow;
            }
            MHead1=MHead1->nextrow;
            Head2=MHead2->nextrow;
            it++;
        }
        
        Print(new,k);
}
ptr create(int k){
    ptr new=(ptr)malloc(sizeof(Node2));
        new->col=-1;
        new->row=-1;
        new->val=-1;
        new->next=NULL;
    ptr n=new;
    for(long long int a=0;a<k;a++){
        
        int i,j,val;
        scanf("%d %d %d",&i,&j,&val);

        ptr x=(ptr)malloc(sizeof(Node2));
        x->col=j;
        x->row=i;
        x->val=val;
        n->next=x;
        n=n->next;
    }
    return new;   
}
ptr create_t(int k){
    ptr new=(ptr)malloc(sizeof(Node2));
        new->col=-1;
        new->row=-1;
        new->val=-1;
        new->next=NULL;
    ptr n=new;
    for(long long int a=0;a<k;a++){
        
        int i,j,val;
        scanf("%d %d %d",&j,&i,&val);

        ptr x=(ptr)malloc(sizeof(Node2));
        x->col=j;
        x->row=i;
        x->val=val;
        n->next=x;
        n=n->next;
    }
    return new;  
}
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    long long int key;
    struct Node* right;
    struct Node* left;
}Node;
typedef Node* ptrnode;
typedef Node* Tree;
typedef struct Qnode
{
    ptrnode tr_node;
    struct Qnode* next;
}Qnode;

typedef Qnode* ptrq;
typedef struct qn{
    ptrq front;
    ptrq rear;
}qn;
typedef qn* Queue;

typedef struct qinfo{
    ptrnode t;
    long long int min;
    long long int max;
    struct qinfo* next;
}qinfo;

typedef struct infoq{
    qinfo* front;
    qinfo* rear;
}infoq;
typedef infoq* Range_queue; 

ptrnode makenode(long long int e);

Node* ListToBST (long long int n, long long int arr[n]);
void ModifyBST (Node* BST);

void enqueue(Queue q, ptrnode t);
ptrnode dequeue(Queue q);


void enqueue2(Range_queue q, qinfo* t);
void dequeue2(Range_queue q);


long long int print_tree(Tree T);

ptrnode makenode(long long int e){
    ptrnode T=(ptrnode)malloc(sizeof(Node));
    T->key=e;
    T->left=NULL;
    T->right=NULL;
    return T;
}

Node* ListToBST(long long int n,long long int arr[n]){
    Tree T=makenode(arr[0]);
    long long int i=1;
    long long int min=arr[0];
    long long int max=arr[0];
    Range_queue rq=(Range_queue)malloc(sizeof(infoq));
    rq->front=NULL;
    rq->rear=NULL;
    while(i!=n){
        if(max<arr[i]){
            max=arr[i];
        }
        else if(min>arr[i]){
            min=arr[i];
        }
        i++;
    }
    qinfo* k=(qinfo*)malloc(sizeof(qinfo));
    k->t=T;
    k->min=min-1;
    k->max=max+1;
    enqueue2(rq,k);
    for(long long int i=1;i<n;i++){
        qinfo* k=(qinfo*)malloc(sizeof(qinfo));
        k->t=makenode(arr[i]);
        if(arr[i]<rq->front->max && arr[i]>rq->front->min){
            if(arr[i]<rq->front->t->key){
                if(rq->front->t->left!=NULL){
                    dequeue2(rq);
                    i--;
                    continue;
                }
                rq->front->t->left=k->t;
                k->min=rq->front->min;
                k->max=rq->front->t->key;
                enqueue2(rq,k);
            }
            else{
                rq->front->t->right=k->t;
                k->max=rq->front->max;
                k->min=rq->front->t->key;
                enqueue2(rq,k);
            }
        }
        else{
            dequeue2(rq);
            i--;
        }
        if(rq->front->t->right!=NULL){
            dequeue2(rq);
        }
    }
    free(rq);
    return T;
}
void ModifyBST (Node* BST){
    static long long int pref_sum=0;
    if(BST!=NULL){
        ModifyBST(BST->left);
        pref_sum+=BST->key;
        BST->key=pref_sum;
        ModifyBST(BST->right);
    }
}

void enqueue(Queue q, ptrnode t){
    ptrq n= (ptrq)malloc(sizeof(Qnode));
    n->tr_node=t;
    if(q->front==NULL){
        q->front=n;
        q->rear=n;
        n->next=NULL;
        return;
    }
    q->rear->next=n;
    q->rear=n;
}

ptrnode dequeue(Queue q){
    if(q->front==NULL){
        return NULL;
    }
    ptrnode temp=q->front->tr_node;
    q->front=q->front->next;
    return temp;
}


void enqueue2(Range_queue q, qinfo* n){
    if(q->front==NULL){
        q->front=n;
        q->rear=n;
        n->next=NULL;
        return;
    }
    q->rear->next=n;
    q->rear=n;
}
void dequeue2(Range_queue q){
    if(q->front==NULL){
        return;
    }
    qinfo* temp=q->front;
    q->front=q->front->next;
    free(temp); 
}

long long int print_tree(Tree T){
    long long int sum=0;
    Queue Q=(Queue)malloc(sizeof(qn));
    Q->front=NULL;
    Q->rear=NULL;
    enqueue(Q,T);
    while(Q->front!=NULL){
        ptrnode k=dequeue(Q);
        printf("%lld ",k->key);
        sum+=k->key;
        if(k->left!=NULL){
            enqueue(Q,k->left);
        }
        if(k->right!=NULL){
            enqueue(Q,k->right);
        }
    }
    printf("\n");
    return sum;
}

int main(){
    long long int n;
    scanf("%lld",&n);
    long long int arr[n];
    for(long long int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    Tree T=ListToBST(n,arr);
    ModifyBST(T);
    long long int max_sale=print_tree(T);
    printf("%lld\n",max_sale);
}
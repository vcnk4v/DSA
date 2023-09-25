#include<stdio.h>
#include<stdlib.h>
typedef struct Tnode{
    int key;
    struct Tnode* left;
    struct Tnode* right;
}Tnode;

typedef Tnode* ptrnode;
typedef Tnode* Tree;

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
ptrnode makenode(int e);
int search_index(int a, int n, int arr[n]);
void enqueue(Queue q, ptrnode t);
ptrnode dequeue(Queue q);
void delqnode(ptrq *p);

Tree make_tree(int n, int in[n], int pre[n], int end,int* start);

Tree create(int n, int in[n], int pre[n]);
void print_tree(Tree T);

ptrnode makenode(int e){
    ptrnode T=(ptrnode)malloc(sizeof(Tnode));
    T->key=e;
    T->left=NULL;
    T->right=NULL;
    return T;
}

Tree make_tree(int n, int in[n], int pre[n], int end,int* start){
    if(*start==n-1){
        return NULL;
    }
    *start=*start+1;
    ptrnode t=makenode(pre[*start]);
    int in_index=search_index(pre[*start],n,in);
    if(in_index>=end){
        *start=*start-1;
        return NULL;
    }
    t->left=make_tree(n,in,pre,in_index,start);
    t->right=make_tree(n,in,pre,end,start);
    return t;
}

Tree create(int n, int in[n], int pre[n]){
    int start;
    start=-1;
    int max=0;
    for(int i=0;i<n;i++){
        if(in[i]>max){
            max=in[i];
        }
    }
    
    Tree T=make_tree(n,in,pre,n,&start);
    
    return T;
}

int search_index(int a, int n, int arr[n]){
    for(int i=0;i<n;i++){
        if(arr[i]==a){
            return i;
        }
    }
    return -1;
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
    ptrq p=q->front;
    q->front=q->front->next;
    delqnode(&p);
    return temp;
}

void delq(Queue *Q){
    if(*Q){
        free(*Q);
        *Q=NULL;
    }
}
void delqnode(ptrq *p){
    if(*p){
        free(*p);
        *p=NULL;
    }
}
void print_tree(Tree T){
    Queue Q=(Queue)malloc(sizeof(qn));
    Q->front=NULL;
    Q->rear=NULL;
    enqueue(Q,T);
    while(Q->front!=NULL){
        ptrnode k=dequeue(Q);
        printf("%d ",k->key);
        if(k->left!=NULL){
            enqueue(Q,k->left);
        }
        if(k->right!=NULL){
            enqueue(Q,k->right);
        }
    }
    delq(&Q);
    printf("\n");
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int in[n];
        int pre[n];
        for(int i=0;i<n;i++){
            scanf("%d",&in[i]);
        }
        for(int i=0;i<n;i++){
            scanf("%d",&pre[i]);
        }
        Tree t=create(n,in,pre);
        print_tree(t);
    }
}
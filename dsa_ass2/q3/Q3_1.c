#include<stdio.h>
#include<stdlib.h>
typedef struct Tnode{
    int key;
    struct Tnode* left;
    struct Tnode* right;
}Tnode;

typedef Tnode* ptrnode;
typedef Tnode* Tree;

typedef struct snode
{
    ptrnode tr_node;
    struct snode* next;
}snode;

typedef snode* Stack;
typedef snode* ptrs;

void push(Stack s, ptrnode t);
ptrnode pop(Stack s);
Tree Insert(Tree T, int e);
ptrnode makenode(int e);

void traverse(Tree T, Stack s1, Stack s2,int n);

ptrnode makenode(int e){
    ptrnode T=(ptrnode)malloc(sizeof(Tnode));
    T->key=e;
    T->left=NULL;
    T->right=NULL;
    return T;
}

void push(Stack s, ptrnode t){
    ptrs n=(ptrs)malloc(sizeof(snode));
    n->next=s->next;
    n->tr_node=t;
    s->next=n;
}

ptrnode pop(Stack s){
    if(s->next==NULL){
        return NULL;
    }
    ptrs temp=s->next;
    s->next=temp->next;
    return temp->tr_node;
}

void traverse(Tree t,Stack s1,Stack s2, int n){
    push(s1,t);
    int count=0;
    while(count<n){
        while(s1->next!=NULL){
            ptrnode parent=pop(s1);
            if(parent->left!=NULL){
                push(s2,parent->left);
            }
            if(parent->right!=NULL){
                push(s2,parent->right);
            }
            printf("%d ",parent->key);
            free(parent);
            count++;
        }
        while(s2->next!=NULL){
            ptrnode parent=pop(s2);
            if(parent->right!=NULL){
                push(s1,parent->right);
            }
            if(parent->left!=NULL){
                push(s1,parent->left);
            }
            printf("%d ",parent->key);
            free(parent);
            count++;
        }
    }
    printf("\n");
}

Tree Insert(Tree T, int e){
    if(T==NULL){
        T=makenode(e);
        return T;
    }
    else if(e<T->key){
        T->left=Insert(T->left,e);
    }
    else if (e>T->key){
        T->right=Insert(T->right,e);
    }
    return T;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        Tree T=(Tree)malloc(sizeof(Tree));
        T->left=NULL;
        T->right=NULL;
        n-=1;
        int root;
        scanf("%d",&root);
        T->key=root;
        n++;
        int i=1;
        int x;
        while(i!=n){
            scanf("%d",&x);
            Insert(T,x);
            i++;
        }
        
      
        Stack s1=(Stack)malloc(sizeof(snode));
        s1->next=NULL;
        s1->tr_node=NULL;

        Stack s2=(Stack)malloc(sizeof(snode));
        s2->next=NULL;
        s2->tr_node=NULL;
    
        traverse(T,s1,s2,n);
        free(s1);
        free(s2);
    }
}

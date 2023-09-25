//iterative binary trees
#include<stdio.h>
#include<stdlib.h>
typedef struct Tnode{
    int key;
    struct Tnode* left;
    struct Tnode* right;
}Tnode;

typedef Tnode* ptrnode;
typedef Tnode* Tree;

typedef struct snode{
    ptrnode tree_node;
    struct snode* next;
}snode;

typedef snode* Stack;


void push(Stack s, ptrnode t){
    Stack n=(Stack)malloc(sizeof(snode));
    n->tree_node=t;
    n->next=s->next;
    s->next=n;
}

ptrnode pop(Stack s){
    if(s->next==NULL){
        return NULL;
    }
    Stack temp=s->next;
    s->next=temp->next;
    return temp->tree_node;
}


void print_tree(Tree T){
    Stack s=(Stack)malloc(sizeof(snode));
    s->next=NULL;
    s->tree_node=NULL;
    if(T!=NULL){
        push(s,T);
        while(s->next!=NULL){
            ptrnode k=pop(s);
            printf("%d ",k->key);
            if(k->right!=NULL){
                push(s,k->right);
            }
            if(k->left!=NULL){
                push(s,k->left);
            }
        }
    }
}
/* Level Order Traversal
Iterative approach: use queues
while q is not empty{
Enque(q,t)
if left!=null
enque(q,t->left)
if right!=null
enque(q,t->right)
n=deque(q)
print(n)
}

Recursive approach:
level(tree_node t,lvl){
    if t=null{
        return;
    }
    else{
        if(lvl==1)
            print(l)
    }
    level(t->left,level-1)
    level(tree->right.level-1)
}


*/
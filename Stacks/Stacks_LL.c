#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int elem;
    struct Node *next;
} Node;

typedef Node *Stack;
typedef Node *ptrnode;

int isempty(Stack s)
{
    if (s->next == NULL)
    {
        return 1;
    }
    return 0;
}
Stack create()
{
    Stack s = (Stack)malloc(sizeof(Node));
    s->elem = -1;
    s->next = NULL;
    return s;
}
void push(int elem, Stack s)
{
    ptrnode n = (ptrnode)malloc(sizeof(Node));
    n->elem = elem;
    n->next = s->next;
    s->next = n;
}
int top(Stack s)
{
    if (isempty(s))
    {
        return -1;
    }
    return s->next->elem;
}
int pop(Stack s)
{
    if (isempty(s))
    {
        return -1;
    }
    ptrnode x = s->next;
    s->next = x->next;
    int k = x->elem;
    free(x);
    return k;
}

int main()
{
    Stack s = create();
    int i = 5;
    while (i--)
    {
        push(i, s);
    }
    i = 5;
    while (i--)
    {
        printf("%d ", pop(s));
    }
}
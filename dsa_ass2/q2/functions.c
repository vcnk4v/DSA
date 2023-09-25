#include "functions.h"
Queue InitQueue()
{
    Queue q = (Queue)malloc(sizeof(Qnode));
    q->next = NULL;
    q->prev = NULL;
    q->elem = -1;
    return q;
}
ptrnode createNode(int val)
{
    ptrnode p = (ptrnode)malloc(sizeof(Qnode));
    p->elem = val;
    p->next = NULL;
    p->prev = NULL;
    return p;
}
void Push(Queue head, int val)
{
    ptrnode p = createNode(val);
    if (head->next == NULL)
    {
        p->next = head;
        p->prev = head;
        head->next = p;
        head->prev = p;
        return;
    }
    p->next = head;
    p->prev = head->prev;
    head->prev->next = p;
    head->prev = p;
}
int Pop(Queue head)
{
    if (head->next == NULL)
    {
        return -1;
    }
    int k = head->next->elem;
    if (head->next == head->prev)
    {
        head->next = NULL;
        head->prev = NULL;
        return k;
    }
    ptrnode x = head->next;
    head->next = head->next->next;
    head->next->prev = head;
    free(x);
    return k;
}
void Inject(Queue head, int val)
{
    ptrnode p = createNode(val);
    if (head->next == NULL)
    {
        head->next = p;
        p->next = head;
        p->prev = p;
        head->prev = p;
        return;
    }
    p->next = head->next;
    p->prev = head;
    head->next->prev = p;
    head->next = p;
}
int popRear(Queue head)
{
    if (head->next == NULL)
    {
        return -1;
    }
    int k = head->prev->elem;
    if (head->next == head->prev)
    {
        head->next = NULL;
        head->prev = NULL;
        return k;
    }
    ptrnode x = head->prev;
    x->prev->next = head;
    head->prev = x->prev;
    free(x);
    return k;
}
void Print(Queue head)
{
    Queue q = InitQueue();
    if (head->next == NULL)
    {
        printf("-1");
        return;
    }
    while (head->next != NULL)
    {
        printf("%d ", head->next->elem);
        Push(q, Pop(head));
    }
    head->next = q->next;
    head->prev = q->prev;
}
void PrintReverse(Queue head)
{
    if (head->next == NULL)
    {
        printf("-1");
        return;
    }
    Queue q = InitQueue();
    while (head->next != NULL)
    {
        printf("%d ", head->prev->elem);
        Inject(q, popRear(head));
    }
    head->next = q->next;
    head->prev = q->prev;
}
int findElem(Queue head, int pos)
{
    Queue temp = InitQueue();
    int k;
    while (pos--)
    {
        if (head->next == NULL)
        {
            while (temp->next != NULL)
            {
                Inject(head, popRear(temp));
            }
            return -1;
        }
        Push(temp, Pop(head));
    }
    k = temp->prev->elem;
    while (temp->next != NULL)
    {
        Inject(head, popRear(temp));
    }
    return k;
}
void removeKElems(Queue head, int k)
{
    if (head->next == NULL)
    {
        return;
    }
    while (k--)
    {
        Pop(head);
    }
}
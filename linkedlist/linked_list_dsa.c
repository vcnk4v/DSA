#include "ll.h"

PtrToNode MakeNode(int e)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->element = e;
    n->next = NULL;
    return n;
}
void AddElement(List L, int e)
{
    struct Node *n = MakeNode(e);
    if (L == NULL)
    {
        L = n;
        return;
    }
    else
    {
        while (L->next != NULL)
        {
            L = L->next;
        }
        L->next = n;
    }
    return;
}
int ListSize(const List L)
{
    int len = 0;
    List i = L;
    if (L == NULL)
    {
        return 0;
    }
    while (i->next != NULL)
    {
        len++;
        i = i->next;
    }
    return len + 1;
}
void insert(List L, int pos, int e)
{
    struct Node *n = MakeNode(e);
    for (int i = 0; i < pos - 1; i++)
    {
        L = L->next;
    }
    n->next = L->next;
    L->next = n;
    return;
}
int rem(List L, int pos)
{
    if (L == NULL)
    {
        return -1;
    }
    if (ListSize(L) < pos)
    {
        return -1;
    }
    List node_i;
    for (int i = 0; i < pos - 1; i++)
    {
        L = L->next;
        node_i = L->next;
    }
    L->next = (L->next)->next;
    free(node_i);
    return 0;
}
int find(List L, int e)
{
    if (L == NULL)
    {
        return -1;
    }
    int pos = 0;
    while (L->next != NULL)
    {
        L = L->next;
        if (L->element == e)
        {
            return pos + 1;
        }
        pos++;
    }
    return -1;
}
void del(List L)
{
    struct Node *temp;
    while (L != NULL)
    {
        temp = L;
        L = L->next;
        free(temp);
    }
}
void print_clist(List l)
{
    while (l != NULL)
    {
        printf("%d  ", l->element);
        l = l->next;
    }
}
List reverse(List l)
{
    List newhead = MakeNode(0);
    List ans = newhead;
    while (l != NULL)
    {
        PtrToNode n = (PtrToNode)malloc(sizeof(struct Node));
        n->element = l->element;
        n->next = NULL;
        if (newhead == NULL)
        {
            insert(newhead, 1, l->element);
        }
        else
        {
            n->next = newhead;
            newhead = n;
        }
        l = l->next;
    }
    return newhead;
}
PtrToNode reverse_rec(PtrToNode head)
{
    if (!head || !(head->next))
        return head;
    PtrToNode res = reverse_rec(head->next);
    head->next->next = head;
    head->next = NULL;
    return res;
}
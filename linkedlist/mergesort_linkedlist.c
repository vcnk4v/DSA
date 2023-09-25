#include <stdio.h>
#include <stdlib.h>
typedef struct Node2
{
    long long int row;
    long long int col;
    long long int val;
    struct Node2 *next;
} Node2;
typedef struct Node2 *ptr;
ptr create_t(int k)
{
    ptr new = (ptr)malloc(sizeof(Node2));
    new->col = -1;
    new->row = -1;
    new->val = -1;
    new->next = NULL;
    ptr n = new;
    for (long long int a = 0; a < k; a++)
    {

        int i, j, val;
        scanf("%d %d %d", &j, &i, &val);

        ptr x = (ptr)malloc(sizeof(Node2));
        x->col = j;
        x->row = i;
        x->val = val;
        n->next = x;
        n = n->next;
    }
    return new;
}
ptr merge(ptr l1, ptr l2);

void halve(ptr n, Node2 **first, Node2 **end)
{
    ptr x;
    ptr y;
    y = n;
    x = n->next;

    while (x != NULL)
    {
        x = x->next;
        if (x != NULL)
        {
            y = y->next;
            x = x->next;
        }
    }

    *first = n;
    *end = y->next;
    y->next = NULL;
}

void MergeSort(Node2 **H)
{
    ptr head = *H;
    ptr a;
    ptr b;

    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }

    halve(head, &a, &b);

    MergeSort(&a);
    MergeSort(&b);

    *H = merge(a, b);
}

ptr merge(Node2 *a, Node2 *b)
{
    ptr result = NULL;
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    if (a->row <= b->row || (a->row == b->row && a->col <= b->col))
    {
        result = a;
        result->next = merge(a->next, b);
    }
    else
    {
        result = b;
        result->next = merge(a, b->next);
    }
    return (result);
}

int main()
{
    int k;
    scanf("%d", &k);
    struct Node2 *New = create_t(k);

    MergeSort(&New);
    New = New->next;
    while (New != NULL)
    {
        printf("%lld %lld %lld\n", New->row, New->col, New->val);
        New = New->next;
    }
}
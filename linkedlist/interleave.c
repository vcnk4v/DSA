#include "ll.h"
PtrToNode Interleave(List l1, List l2)
{
    PtrToNode new, t1, t2;
    if (l1 == NULL)
    {
        return l2;
    }
    else if (l2 == NULL)
    {
        return l1;
    }
    new = l1;
    while (l1 != NULL && l2 != NULL)
    {
        t1 = l1->next;
        t2 = l2->next;
        if (l1->next != NULL)
        {
            l2->next = l1->next;
        }
        l1->next = l2;
        l1 = t1;
        l2 = t2;
    }
    return new;
}

PtrToNode rec_Interleave(List l1, List l2)
{
    if (l1 == NULL)
    {
        return l2;
    }
    else if (l2 == NULL)
    {
        return l1;
    }
    else
    {
        PtrToNode temp1 = l1->next;
        PtrToNode temp2 = l2->next;
        l1->next = l2;
        l2->next = rec_Interleave(temp1, temp2);
        return l1;
    }
}

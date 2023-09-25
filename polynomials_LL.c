#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int coeff;
    int power;
    struct node *next;
} node;
typedef node *poly;
typedef node *ptrnode;

void Addterm(int power, int coeff, poly p)
{
    ptrnode new = (ptrnode)malloc(sizeof(node));
    new->coeff = coeff;
    new->power = power;
    while (p->next != NULL)
    {
        if (p->next->power > power)
        {
            new->next = p->next;
            p->next = new;
            return;
        }
        p = p->next;
    }
    new->next = NULL;
    p->next = new;
}
poly addpoly(poly p1, poly p2)
{
    p1 = p1->next;
    p2 = p2->next;
    poly new = (ptrnode)malloc(sizeof(node));
    poly ans = new;
    new->coeff = -1;
    new->power = -1;
    while (p2 != NULL && p1 != NULL)
    {
        if (p1->power < p2->power)
        {
            ptrnode n = (ptrnode)malloc(sizeof(node));
            n->power = p1->power;
            n->coeff = p1->coeff;
            n->next = NULL;
            new->next = n;
            new = new->next;
            p1 = p1->next;
        }
        else if (p1->power > p2->power)
        {
            ptrnode n = (ptrnode)malloc(sizeof(node));
            n->power = p2->power;
            n->coeff = p2->coeff;
            n->next = NULL;
            new->next = n;
            new = new->next;
            p2 = p2->next;
        }
        else
        {
            ptrnode n = (ptrnode)malloc(sizeof(node));
            n->power = p1->power;
            n->coeff = p1->coeff + p2->coeff;
            n->next = NULL;
            new->next = n;
            new = new->next;
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    if (p1 == NULL && p2 != NULL)
    {
        new->next = p2;
    }
    else if (p1 != NULL && p2 == NULL)
    {
        new->next = p1;
    }
    return ans;
}
void print(poly p)
{
    p = p->next;
    while (p != NULL)
    {
        printf("%d %d\n", p->power, p->coeff);
        p = p->next;
    }
}
poly multiply(poly p1, poly p2)
{
    poly new = (ptrnode)malloc(sizeof(node));
    new->coeff = -1;
    new->power = -1;
    new->next = NULL;
    p1 = p1->next;
    p2 = p2->next;
    poly ptrp2 = p2;
    while (p1 != NULL)
    {
        poly product = (ptrnode)malloc(sizeof(node));
        product->coeff = -1;
        product->power = -1;
        product->next = NULL;
        while (p2 != NULL)
        {
            Addterm(p1->power + p2->power, p1->coeff * p2->coeff, product);
            p2 = p2->next;
        }
        p2 = ptrp2;
        print(new);
        new = addpoly(new, product);
        p1 = p1->next;
    }
    return new;
}
int main()
{
    poly p1 = (ptrnode)malloc(sizeof(node));
    poly p2 = (ptrnode)malloc(sizeof(node));
    p1->power = -1;
    p1->coeff = -1;
    p2->power = -1;
    p2->coeff = -1;
    p1->next = NULL;
    p2->next = NULL;
    Addterm(1, 1, p1);
    Addterm(5, 1, p1);
    Addterm(6, 1, p1);
    Addterm(10, 2, p1);
    Addterm(1, 1, p2);
    Addterm(7, 1, p2);
    Addterm(3, 5, p2);
    Addterm(10, 3, p2);
    poly ans = addpoly(p1, p2);
    print(ans);
    poly mult = multiply(p1, p2);
    print(mult);
}
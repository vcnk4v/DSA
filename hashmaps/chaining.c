// CODE FROM MARK ALLEN WEISS

#include <stdio.h>
#include <stdlib.h>
typedef struct listnode *nodeptr;
struct listnode
{
    int element;
    nodeptr next;
};
typedef nodeptr list;
typedef nodeptr position;
struct hashtable
{
    int tablesize;
    list *the_lists; // pointer to the pointer to listnode
};
typedef struct hashtable *hasht;
hasht init(int tsize)
{
    int i;
    hasht ht = (hasht)malloc(sizeof(struct hashtable));
    ht->tablesize = tsize;
    ht->the_lists = (position *)malloc(sizeof(list) * tsize);
    for (int i = 0; i < tsize; i++)
    {
        ht->the_lists[i] = (list)malloc(sizeof(struct listnode));
        ht->the_lists[i]->next = NULL;
    }
    return ht;
}
position
find(int key, hasht H)
{
    position p;
    list L;
    L = H->the_lists[hash(key, H->tablesize)];
    p = L->next;
    while ((p != NULL) && (p->element != key))
    {
        p = p->next;
    }
    return p;
}

void insert(int key, hasht H)
{
    position pos, new_cell;
    list L;
    pos = find(key, H);
    if (pos == NULL)
    {
        new_cell = (position)malloc(sizeof(struct listnode));
        if (new_cell == NULL)
            fatal_error("Out of space!!!");
        else
        {
            L = H->the_lists[hash(key, H->tablesize)];
            new_cell->next = L->next;
            new_cell->element = key; /* Probably need strcpy!! */
            L->next = new_cell;
        }
    }
}
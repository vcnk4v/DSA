#include <stdio.h>
#include <stdlib.h>
typedef struct Tnode
{
    int key;
    struct Tnode *left;
    struct Tnode *right;
} Tnode;

typedef Tnode *ptrnode;
typedef Tnode *Tree;

ptrnode findmin(Tree t)
{
    if (t == NULL)
    {
        return NULL;
    }
    else if (t->left == NULL)
    {
        return t;
    }
    else
    {
        return findmin(t->left);
    }
}

Tree deletenode(Tree t, int val)
{
    if (t->key < val)
    {
        t->left = deletenode(t->right, val);
    }
    else if (t->key > val)
    {
        t->right = deletenode(t->left, val);
    }
    else
    {
        if (t->left == NULL && t->right == NULL)
        {
            free(t);
            return NULL;
        }
        else if (t->left == NULL && t->right != NULL)
        {
            ptrnode temp = t;
            t = t->right;
            free(temp);
            return t;
        }
        else if (t->left != NULL && t->right == NULL)
        {
            ptrnode temp = t;
            t = t->left;
            free(temp);
            return t;
        }
        else
        {
            ptrnode s = findmin(t->right);
            t->key = s->key;
            t->right = deletenode(t->right, s->key);
        }
    }
}
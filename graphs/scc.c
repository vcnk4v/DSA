#include <stdio.h>
#include <stdlib.h>

typedef struct stgraph *graph;
typedef struct stnode *node;
struct stgraph
{
    int n;
    node *pvertex;
};
struct stnode
{
    int vertex;
    node pnext;
};
graph create(int in)
{
    graph g = (graph)malloc(sizeof(struct stgraph));
    g->n = in;
    g->pvertex = (node *)malloc(sizeof(node) * in);
    for (int i = 0; i < in; i++)
    {
        g->pvertex[i] = (node)malloc(sizeof(struct stnode));
        g->pvertex[i]->vertex = i;
        g->pvertex[i]->pnext = NULL;
    }
    return g;
}

void insertedge(graph g, int u, int v)
{
    node temp = (node)malloc(sizeof(struct stnode));
    temp->vertex = v;
    temp->pnext = g->pvertex[u]->pnext;
    g->pvertex[u]->pnext = temp;
}

typedef struct Stackinfo *Stack;
typedef struct Stackinfo
{
    int max_elems;
    int top_index;
    int *Stackelems;
} Stackinfo;

Stack InitStack(int max_elems);
int isfull(Stack s);
int isempty(Stack s);
void Push(Stack s, int e);
int Pop(Stack s);
int Top(Stack s);
Stack InitStack(int max_elems)
{
    Stack s = (Stack)malloc(sizeof(Stackinfo));
    s->Stackelems = (int *)malloc(sizeof(int) * max_elems);
    s->top_index = -1;
    s->max_elems = max_elems;
    return s;
}
int isfull(Stack s)
{
    if (s->top_index == s->max_elems - 1)
    {
        return 1;
    }
    return 0;
}
int isempty(Stack s)
{
    if (s->top_index == -1)
    {
        return 1;
    }
    return 0;
}
void Push(Stack s, int e)
{

    s->Stackelems[++(s->top_index)] = e;
}
int Pop(Stack s)
{

    return s->Stackelems[(s->top_index)--];
}
int Top(Stack s)
{
    return s->Stackelems[s->top_index];
}

graph transpose(graph g)
{
    int n = g->n;
    graph tg = create(n);
    for (int i = 0; i < n; i++)
    {
        node curr = g->pvertex[i]->pnext;
        while (curr != NULL)
        {
            insertedge(tg, curr->vertex, i);
            curr = curr->pnext;
        }
    }
    return tg;
}

void fillorder(graph g, int v, int *visited, Stack s, int *stackSize)
{
    visited[v] = 1;
    node n = g->pvertex[v]->pnext;
    while (n != NULL)
    {
        if (!visited[n->vertex])
        {
            fillorder(g, n->vertex, visited, s, stackSize);
        }
        n = n->pnext;
    }
    Push(s, v);
    *stackSize = *stackSize + 1;
}

void DFS(graph g, int v, int *visited)
{
    visited[v] = 1;
    printf("%d ", v);
    node curr = g->pvertex[v]->pnext;
    while (curr != NULL)
    {
        if (!visited[curr->vertex])
        {
            DFS(g, curr->vertex, visited);
        }
        curr = curr->pnext;
    }
}

void printscc(graph g)
{
    int num_elems = g->n;
    int visited[num_elems];
    for (int i = 0; i < num_elems; i++)
    {
        visited[i] = 0;
    }
    Stack s = InitStack(num_elems);
    int stackSize = 0;
    for (int i = 0; i < num_elems; i++)
    {
        if (!visited[i])
        {
            fillorder(g, i, visited, s, &stackSize);
        }
    }
    graph tg = transpose(g);
    for (int i = 0; i < num_elems; i++)
    {
        visited[i] = 0;
    }
    while (stackSize > 0)
    {
        int n = Pop(s);
        stackSize--;
        if (!visited[n])
        {
            DFS(tg, n, visited);
            printf("\n");
        }
    }
}

int main()
{
    int V = 5;
    graph graph = create(V);
    insertedge(graph, 1, 0);
    insertedge(graph, 0, 2);
    insertedge(graph, 2, 1);
    insertedge(graph, 0, 3);
    insertedge(graph, 3, 4);

    printf("Following are strongly connected components in given graph:\n");
    printscc(graph);

    return 0;
}
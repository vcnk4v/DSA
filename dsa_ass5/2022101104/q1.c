#include <stdio.h>
#include <stdlib.h>
struct node
{
    int vertex;
    struct node *next;
    int visited;
};
typedef struct node *ptrnode;
struct graphnode
{
    int n;
    ptrnode *ptrvertex;
};

struct heapstr
{
    int max;
    int num_elems;
    ptrnode *elems;
};
typedef struct graphnode *graph;
typedef struct heapstr *Heap;
Heap make(int n);
void heapify(Heap h, int index);
ptrnode extractmin(Heap h);

graph create(int num_v);
void insertedge(graph g, int u, int v);

void find(graph g, int n, int *planets);

graph create(int num_v)
{
    graph g;
    g = (graph)malloc(sizeof(struct graphnode));
    g->n = num_v;
    g->ptrvertex = (ptrnode *)malloc(sizeof(ptrnode) * num_v);
    for (int i = 0; i < num_v; i++)
    {
        g->ptrvertex[i] = (ptrnode)malloc(sizeof(struct node));
        g->ptrvertex[i]->vertex = i;
        g->ptrvertex[i]->visited = 0;
        g->ptrvertex[i]->next = NULL;
    }
    return g;
}
void insertedge(graph g, int u, int v)
{

    ptrnode temp = g->ptrvertex[u];

    temp = (ptrnode)malloc(sizeof(struct node));
    temp->vertex = v;
    temp->next = g->ptrvertex[u]->next;
    g->ptrvertex[u]->next = temp;
}

Heap insert(Heap H, ptrnode e)
{

    int index = H->num_elems;
    H->elems[index] = e;
    while (index > 0 && H->elems[(index - 1) / 2]->vertex > H->elems[index]->vertex)
    {
        ptrnode temp = H->elems[index];
        H->elems[index] = H->elems[(index - 1) / 2];
        H->elems[(index - 1) / 2] = temp;

        index = (index - 1) / 2;
    }
    H->num_elems += 1;
    return H;
}

Heap make(int n)
{
    Heap h = (Heap)malloc(sizeof(struct heapstr));
    h->max = n;
    h->num_elems = 0;
    h->elems = (ptrnode *)malloc(sizeof(ptrnode) * (n));

    return h;
}

void heapify(Heap h, int index)
{
    int less = index;
    int l = 2 * index + 1;
    int r = l + 1;
    if (l < h->num_elems && h->elems[l]->vertex < h->elems[less]->vertex)
    {
        less = l;
    }
    if (r < h->num_elems && h->elems[r]->vertex < h->elems[less]->vertex)
    {
        less = r;
    }
    if (less != index)
    {
        ptrnode temp = h->elems[less];
        h->elems[less] = h->elems[index];
        h->elems[index] = temp;
        heapify(h, less);
    }
}

ptrnode extractmin(Heap h)
{
    if (h->num_elems == 0)
        return 0;

    ptrnode min = h->elems[0];

    h->elems[0] = h->elems[h->num_elems - 1];
    h->num_elems -= 1;

    heapify(h, 0);

    return min;
}

void find(graph g, int n, int *planets)
{
    Heap h = make(n);
    int i = 0;
    g->ptrvertex[0]->visited = 1;
    h = insert(h, g->ptrvertex[0]);
    while (h->num_elems > 0) // edges
    {
        ptrnode curr = extractmin(h); // logn
        planets[i++] = curr->vertex;
        curr = g->ptrvertex[curr->vertex]->next;
        while (curr != NULL) // edges
        {
            if (g->ptrvertex[curr->vertex]->visited == 0)
            {
                h = insert(h, curr); // logn
                g->ptrvertex[curr->vertex]->visited = 1;
            }
            curr = curr->next;
        }
    }
    free(h);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    graph g = create(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        u--;
        insertedge(g, u, v - 1);
        insertedge(g, v - 1, u);
    }

    int planets[n];
    find(g, n, planets);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", planets[i] + 1);
    }
    printf("\n");
}
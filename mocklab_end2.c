#include <stdio.h>
#include <stdlib.h>
struct node
{
    int vertex;
    struct node *nexttt;
};
typedef struct graphnode *graph;
typedef struct node *ptrnode;
struct graphnode
{
    int n;
    ptrnode *ptrvertex;
};

struct Qnode
{
    int n;
    struct Qnode *next;
};
typedef struct Qnode *vertex;

struct Q
{
    vertex front;
    int numelems;
    vertex end;
};
typedef struct Q *Queue;

Queue init()
{
    Queue q = (Queue)malloc(sizeof(struct Q));
    q->front = NULL;
    q->end = NULL;
    q->numelems = 0;
    return q;
}

void insert(Queue q, int n)
{
    vertex new = (vertex)malloc(sizeof(struct Qnode));
    new->n = n;
    if (q->front == NULL)
    {
        q->front = new;
        q->end = new;
        q->numelems += 1;
        new->next = NULL;
        return;
    }
    q->end->next = new;
    q->end = new;
    q->numelems += 1;
}

vertex dequeue(Queue q)
{
    if (q->front == NULL)
    {
        return NULL;
    }
    vertex temp = q->front;
    q->front = q->front->next;
    q->numelems -= 1;
    return temp;
}

int bfs(graph g, int v, int k, int *visit)
{
    Queue q = init();
    insert(q, v);
    int ans = 0;
    visit[v] = 1;
    int depth = 0;
    if (k == 0)
    {
        return 1;
    }

    while (q->front != NULL)
    {
        depth++;

        while (s--)
        {
            vertex v = dequeue(q);
            visit[v->n] = 1;
            ptrnode start = g->ptrvertex[v->n]->nexttt;
            while (start != NULL)
            {
                if (visit[start->vertex] == 0)
                {
                    if (depth == k)
                    {
                        ans++;
                    }
                    else
                    {
                        insert(q, start->vertex);
                    }
                }
                start = start->nexttt;
            }
        }
        if (depth == k)
        {
            return ans;
        }
    }
    return 0;
}

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
        g->ptrvertex[i]->nexttt = NULL;
    }
    return g;
}

void insertedge(graph g, int u, int v)
{

    ptrnode temp = g->ptrvertex[u];

    temp = (ptrnode)malloc(sizeof(struct node));
    temp->vertex = v;
    temp->nexttt = g->ptrvertex[u]->nexttt;
    g->ptrvertex[u]->nexttt = temp;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k;
        scanf("%d %d", &n, &k);

        graph g = create(n);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            u--;
            v--;
            insertedge(g, u, v);
            insertedge(g, v, u);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int v = g->ptrvertex[i]->vertex;
            int visit[n];
            for (int j = 0; j < n; j++)
            {
                visit[j] = 0;
            }

            ans += bfs(g, v, k, visit);
        }
        printf("%d\n", ans / 2);
    }
}
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int vertex;
    struct node *next;
};
typedef struct graphnode *graph;
typedef struct node *ptrnode;
struct graphnode
{
    int n;
    ptrnode *ptrvertex;
};

int cmp(const void *a, const void *b)
{
    const int *x = (int *)a;
    const int *y = (int *)b;

    if (*x > *y)
        return 1;
    else if (*x < *y)
        return -1;

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
        g->ptrvertex[i]->next = NULL;
    }
    return g;
}
void dfs(int v, int dest, graph g, int *visit, int color, int n, int m, int colors[n][m], int *ans)
{
    visit[v] = 1;
    ptrnode node = g->ptrvertex[v]->next;

    while (node != NULL)
    {
        if (visit[node->vertex] != 1 && colors[node->vertex][v] == color)
        {
            if (node->vertex == dest)
            {
                *ans = 1;
                return;
            }
            dfs(node->vertex, dest, g, visit, color, n, m, colors, ans);
        }
        node = node->next;
    }
}
void insertedge(graph g, int u, int v)
{

    ptrnode temp = g->ptrvertex[u];

    temp = (ptrnode)malloc(sizeof(struct node));
    temp->vertex = v;
    temp->next = g->ptrvertex[u]->next;
    g->ptrvertex[u]->next = temp;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int colors[n][m];
    int cc[m];
    int num_c = 1;
    int x = 0;
    graph g = create(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--;
        b--;
        colors[a][b] = c;
        colors[b][a] = c;
        cc[x++] = c;
        insertedge(g, a, b);
        insertedge(g, b, a);
    }

    qsort(cc, m, sizeof(int), cmp);
    for (int i = 1; i < m; i++)
    {
        if (cc[i] != cc[i - 1])
        {
            num_c++;
        }
    }

    int q;
    scanf("%d", &q);
    while (q--)
    {
        int u, v;
        int ans = 0;
        scanf("%d %d", &u, &v);
        u--;
        v--;
        for (int i = 0; i < num_c; i++)
        {
            int a = 0;
            int visit[n];
            for (int i = 0; i < n; i++)
            {
                visit[i] = 0;
            }

            dfs(u, v, g, visit, i + 1, n, m, colors, &a);
            ans += a;
        }
        printf("%d\n", ans);
    }
}
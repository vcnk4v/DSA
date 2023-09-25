#include <stdio.h>
#include <stdlib.h>
struct node
{
    int vertex;
    int adjvers[4];
    int fertile;
};
typedef struct node *ptrnode;
typedef struct graphnode *graph;
struct graphnode
{
    int n;
    ptrnode *ptrvertex;
};
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
        g->ptrvertex[i]->fertile = 0;
    }
    return g;
}

void insertedges(graph g, int n, int m, int r, int fertiles[r])
{
    int direction1[4] = {-1, 1, 0, 0};
    int direction2[4] = {0, 0, -1, 1};
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < 4; j++)
        {

            int p = fertiles[i] / m + direction1[j];
            int q = fertiles[i] % m + direction2[j];
            g->ptrvertex[fertiles[i]]->adjvers[j] = -1;
            if (p >= n || q >= m || p < 0 || q < 0)
            {
                continue;
            }
            if (g->ptrvertex[p * m + q]->fertile != 0)
            {
                g->ptrvertex[fertiles[i]]->adjvers[j] = p * m + q;
            }
        }
    }
}

void dfs(int v, graph g, int *visit, int *earnings, int *fence)
{
    visit[v] = 1;
    for (int i = 0; i < 4; i++)
    {
        if (g->ptrvertex[v]->adjvers[i] != -1 && !visit[g->ptrvertex[v]->adjvers[i]])
        {
            dfs(g->ptrvertex[v]->adjvers[i], g, visit, earnings, fence);
            *earnings += 4;
        }
        else if (g->ptrvertex[v]->adjvers[i] == -1)
        {
            *fence -= 1;
        }
    }
}

int max_continuous(graph g, int r, int fertiles[r], int n, int m)
{
    int visit[n * m];
    for (int i = 0; i < n * m; i++)
    {
        visit[i] = 0;
    }
    int max = 0;
    int cur;
    for (int i = 0; i < r; i++)
    {
        int earnings = 4;
        int fence = 0;
        if (visit[fertiles[i]] == 0)
        {
            dfs(fertiles[i], g, visit, &earnings, &fence);
            cur = earnings + fence;
            if (cur > max)
            {
                max = cur;
            }
        }
    }
    return max;
}

int main()
{
    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);
    graph g = create(n * m);
    int fertiles[r];
    for (int p = 0; p < r; p++)
    {
        int i, j;
        scanf("%d %d", &i, &j);
        i--;
        j--;
        fertiles[p] = i * m + j;
        int key = i * m + j;
        ptrnode temp = g->ptrvertex[key];
        temp->fertile = 1;
        temp->vertex = key;
    }
    insertedges(g, n, m, r, fertiles);
    int max = max_continuous(g, r, fertiles, n, m);
    printf("%d\n", max);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct info
{
    int *known;
    int *cost;
};
typedef struct info *infotable;

struct heapstr
{
    int max;
    int num_elems;
    int *elems;
};

typedef struct heapstr *Heap;
Heap make(int n);
void heapify(Heap h, int index, infotable T);
int extractmin(Heap h, infotable T);
Heap insert(Heap H, int e, infotable T);
Heap insert(Heap H, int e, infotable T)
{
    int index = H->num_elems;
    H->elems[index] = e;
    while (index > 0 && T->cost[H->elems[(index - 1) / 2]] > T->cost[H->elems[index]])
    {
        int temp = H->elems[index];
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
    h->elems = (int *)malloc(sizeof(int) * (n));

    return h;
}

void heapify(Heap h, int index, infotable T)
{
    int less = index;
    int l = 2 * index + 1;
    int r = l + 1;
    if (l < h->num_elems && T->cost[h->elems[l]] < T->cost[h->elems[less]])
    {
        less = l;
    }
    if (r < h->num_elems && T->cost[h->elems[r]] < T->cost[h->elems[less]])
    {
        less = r;
    }
    if (less != index)
    {
        int temp = h->elems[less];
        h->elems[less] = h->elems[index];
        h->elems[index] = temp;
        heapify(h, less, T);
    }
}

int extractmin(Heap h, infotable T)
{
    if (h->num_elems == 0)
        return 0;

    int min = h->elems[0];

    h->elems[0] = h->elems[h->num_elems - 1];
    h->num_elems -= 1;

    heapify(h, 0, T);

    return min;
}

infotable shortestpath(int n, int m, int costs[n][m])
{

    infotable table = (infotable)malloc(sizeof(struct info));
    table->known = (int *)malloc(sizeof(int) * n * m);
    table->cost = (int *)malloc(sizeof(int) * n * m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            table->known[i * m + j] = 0;
            table->cost[i * m + j] = __INT_MAX__;
        }
    }
    Heap h = make(n * m);

    table->cost[0] = costs[0][0];
    table->known[0] = 1;

    for (int i = 0; i < n; i++)
    {
        table->cost[i * m] = costs[i][0];
        insert(h, i * m, table);
    }
    for (int i = 1; i < m; i++)
    {
        table->cost[(n - 1) * m + i] = costs[n - 1][i];
        insert(h, (n - 1) * m + i, table);
    }
    int direction1[4] = {-1, 1, 0, 0};
    int direction2[4] = {1, 1, -1, -1};
    while (h->num_elems != 0)
    {
        int curr = extractmin(h, table);
        table->known[curr] = 1;
        for (int i = 0; i < 4; i++)
        {
            int p = curr / m + direction1[i];
            int q = curr % m + direction1[(i + 2) % 4];
            if (p >= n || q >= m || p < 0 || q < 0)
            {
                continue;
            }
            if (table->known[p * m + q] == 1)
            {
                continue;
            }

            if (table->cost[p * m + q] > table->cost[curr] + (costs[p][q]))
            {
                table->cost[p * m + q] = table->cost[curr] + (costs[p][q]);
                insert(h, p * m + q, table);
            }
        }
        for (int i = 0; i < 4; i++)
        {
            int p = curr / m + direction2[i];
            int q = curr % m + direction2[(i + 1) % 4];
            if (p >= n || q >= m || p < 0 || q < 0)
            {
                continue;
            }
            if (table->known[p * m + q] == 1)
            {
                continue;
            }

            if (table->cost[p * m + q] > table->cost[curr] + (costs[p][q]))
            {
                table->cost[p * m + q] = table->cost[curr] + (costs[p][q]);
                insert(h, p * m + q, table);
            }
        }
    }
    return table;
}

int least_cost(int n, int m, int costs[n][m])
{

    infotable final = shortestpath(n, m, costs);
    int min = costs[0][0];
    for (int i = 0; i < n * m; i += m)
    {
        if (final->cost[i + m - 1] < min)
        {
            min = final->cost[i + m - 1];
        }
    }
    for (int i = 0; i < m - 1; i++)
    {
        if (final->cost[i] < min)
        {
            min = final->cost[i];
        }
    }
    return min;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        int costs[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &costs[i][j]);
            }
        }

        int ans = least_cost(n, m, costs);
        printf("%d\n", ans);
    }
}
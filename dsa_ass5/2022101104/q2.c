#include <stdio.h>
#include <stdlib.h>

struct info
{
    int *known;
    int *cost;
};
typedef struct info *infotable;

typedef struct Qnode
{
    int elem;
    struct Qnode *next;
    struct Qnode *prev;
} Qnode;
typedef Qnode *ptrnode;
typedef Qnode *Queue;

Queue InitQueue()
{
    Queue q = (Queue)malloc(sizeof(Qnode));
    q->next = NULL;
    q->prev = NULL;
    q->elem = -1;
    return q;
}
ptrnode createNode(int val)
{
    ptrnode p = (ptrnode)malloc(sizeof(Qnode));
    p->elem = val;
    p->next = NULL;
    p->prev = NULL;
    return p;
}
void Push(Queue head, int val)
{
    ptrnode p = createNode(val);
    if (head->next == NULL)
    {
        p->next = head;
        p->prev = head;
        head->next = p;
        head->prev = p;
        return;
    }
    p->next = head;
    p->prev = head->prev;
    head->prev->next = p;
    head->prev = p;
}
int Pop(Queue head)
{
    if (head->next == NULL)
    {
        return -1;
    }
    int k = head->next->elem;
    if (head->next == head->prev)
    {
        head->next = NULL;
        head->prev = NULL;
        return k;
    }
    ptrnode x = head->next;
    head->next = head->next->next;
    head->next->prev = head;
    free(x);
    return k;
}
void Inject(Queue head, int val)
{
    ptrnode p = createNode(val);
    if (head->next == NULL)
    {
        head->next = p;
        p->next = head;
        p->prev = p;
        head->prev = p;
        return;
    }
    p->next = head->next;
    p->prev = head;
    head->next->prev = p;
    head->next = p;
}

int shortestpath(int n, int m, int heights[n][m])
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
    int direction1[4] = {-1, 1, 0, 0};
    Queue elevator = InitQueue();
    Push(elevator, 0);
    table->known[0] = 1;
    table->cost[0] = 0;

    // h = insert(h, 0, table);

    while (elevator->next != NULL) // Edges
    {
        // int curr = extractmin(h, table); // log n
        int curr = Pop(elevator);
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

            if (table->cost[p * m + q] > table->cost[curr] + (0 != (heights[p][q] - heights[curr / m][curr % m])))
            {
                table->cost[p * m + q] = table->cost[curr] + (0 != (heights[p][q] - heights[curr / m][curr % m]));
                // insert(h, p * m + q, table); // log n
                if (0 != (heights[p][q] - heights[curr / m][curr % m]))
                {
                    Push(elevator, p * m + q);
                }
                else
                {
                    Inject(elevator, p * m + q);
                }
            }
        }
    }
    return table->cost[(n * m - 1)];
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        int heights[n][m];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &heights[i][j]);
            }
        }

        int x = shortestpath(n, m, heights);
        printf("%d\n", x);
    }
}
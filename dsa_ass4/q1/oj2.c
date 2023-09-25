#include <stdio.h>
#include <stdlib.h>
struct heapstr
{
    int max;
    int num_elems;
    long long int *arr;
};

typedef struct heapstr *Heap;

Heap insert(Heap H, long long int e)
{

    int index = H->num_elems;
    H->arr[index] = e;
    while (index > 0 && H->arr[(index - 1) / 2] < H->arr[index])
    {
        long long int temp = H->arr[index];
        H->arr[index] = H->arr[(index - 1) / 2];
        H->arr[(index - 1) / 2] = temp;

        index = (index - 1) / 2;
    }
    H->num_elems += 1;
    return H;
}

void heapify(Heap h, int index)
{
    int more = index;
    int l = 2 * index + 1;
    int r = l + 1;
    if (l < h->num_elems && h->arr[l] > h->arr[more])
    {
        more = l;
    }
    if (r < h->num_elems && h->arr[r] > h->arr[more])
    {
        more = r;
    }
    if (more != index)
    {
        long long int temp = h->arr[more];
        h->arr[more] = h->arr[index];
        h->arr[index] = temp;
        heapify(h, more);
    }
}
long long int extractmax(Heap h)
{
    if (h->num_elems == 0)
        return 0;

    long long int maxx = h->arr[0];

    h->arr[0] = h->arr[h->num_elems - 1];
    h->num_elems -= 1;

    heapify(h, 0);

    return maxx;
}

int main()
{
    long long int t;
    scanf("%lld", &t);
    while (t--)
    {
        long long int n, k;
        scanf("%lld %lld", &n, &k);
        Heap H = (Heap)malloc(sizeof(struct heapstr));
        H->max = n;
        H->num_elems = 0;
        H->arr = (long long int *)malloc(sizeof(long long int) * (n));

        long long int a[n];
        for (long long int i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
            insert(H, a[i]);
        }
        long long int max = 0;
        while (k--)
        {
            long long int x = extractmax(H);
            max += x;
            x--;
            insert(H, x);
            if (H->arr[0] <= 0)
            {
                break;
            }
        }
        printf("%lld\n", max);
    }
}
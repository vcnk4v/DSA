#include "sort.h"
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
    if (r < h->num_elems && h->arr[2 * index + 2] > h->arr[more])
    {
        more = 2 * index + 2;
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

#include "heap.h"
Heap insert(Heap H, long long int e)
{

    int index = H->num_elems;
    H->knobs[index] = e;
    while (index > 0 && H->knobs[(index - 1) / 2] > H->knobs[index])
    {
        long long int temp = H->knobs[index];
        H->knobs[index] = H->knobs[(index - 1) / 2];
        H->knobs[(index - 1) / 2] = temp;

        index = (index - 1) / 2;
    }
    H->num_elems += 1;
    return H;
}

void heapify(Heap h, int index)
{
    int less = index;
    int l = 2 * index + 1;
    int r = l + 1;
    if (l < h->num_elems && h->knobs[l] < h->knobs[less])
    {
        less = l;
    }
    if (r < h->num_elems && h->knobs[r] < h->knobs[less])
    {
        less = r;
    }
    if (less != index)
    {
        long long int temp = h->knobs[less];
        h->knobs[less] = h->knobs[index];
        h->knobs[index] = temp;
        heapify(h, less);
    }
}
void printh(Heap h)
{
    for (int i = 0; i < h->num_elems; i++)
    {
        printf("%lld ", h->knobs[i]);
    }
}
long long int extractmax(Heap h)
{
    if (h->num_elems == 0)
        return 0;

    long long int maxx = h->knobs[0];

    h->knobs[0] = h->knobs[h->num_elems - 1];
    h->num_elems -= 1;

    heapify(h, 0);

    return maxx;
}

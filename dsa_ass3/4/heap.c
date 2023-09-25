#include "heap.h"
void printh(Heap h)
{
    for (int i = 0; i < h->num_elems; i++)
    {
        printf("%lld ", h->elems[i]);
    }
}

Heap insert(Heap H, long long int e)
{

    int index = H->num_elems;
    H->elems[index] = e;
    while (index > 0 && H->elems[(index - 1) / 2] > H->elems[index])
    {
        long long int temp = H->elems[index];
        H->elems[index] = H->elems[(index - 1) / 2];
        H->elems[(index - 1) / 2] = temp;

        index = (index - 1) / 2;
    }
    H->num_elems += 1;
    return H;
}

Heap make(int *arr, int n)
{
    Heap h = (Heap)malloc(sizeof(struct heapstr));
    h->max = n;
    h->num_elems = 0;
    h->elems = (long long int *)malloc(sizeof(long long int) * (n));
    for (int i = 0; i < n; i++)
    {
        insert(h, arr[i]);
    }

    return h;
}

void heapify(Heap h, int index)
{
    int less = index;
    int l = 2 * index + 1;
    int r = l + 1;
    if (l < h->num_elems && h->elems[l] < h->elems[less])
    {
        less = l;
    }
    if (r < h->num_elems && h->elems[r] < h->elems[less])
    {
        less = r;
    }
    if (less != index)
    {
        long long int temp = h->elems[less];
        h->elems[less] = h->elems[index];
        h->elems[index] = temp;
        heapify(h, less);
    }
}

long long int extractmin(Heap h)
{
    if (h->num_elems == 0)
        return 0;

    long long int min = h->elems[0];

    h->elems[0] = h->elems[h->num_elems - 1];
    h->num_elems -= 1;

    heapify(h, 0);

    return min;
}

int *der(int *arr, int n, int *hash)
{
    Heap nums = make(arr, n);
    int *drarry = (int *)malloc(sizeof(int) * n);
    int least, temp;
    int i = 0;
    while (nums->num_elems != 1)
    {
        least = extractmin(nums);

        if (hash[least] == i)
        {
            temp = least;
            least = extractmin(nums);
            drarry[i] = least;
            i++;
            nums = insert(nums, temp);
        }
        else
        {
            drarry[i] = least;
            i++;
        }
    }
    least = extractmin(nums);
    if (hash[least] == i)
    {
        temp = drarry[i - 1];
        drarry[i - 1] = least;
        drarry[i] = temp;
    }
    else
    {
        drarry[i] = least;
    }
    return drarry;
}

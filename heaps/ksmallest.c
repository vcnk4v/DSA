#include "heaps.h"
void kelem(int *arr, int n, int k)
{

    Heap h = create(n);
    for (int i = 0; i < n; i++)
    {
        if (h->num_elems < k)
        {
            insert(h, arr[i]);
        }
        else if (h->num_elems == k)
        {
            if (arr[i] >= h->pelems[0])
            {
                continue;
            }
            else
            {
                h->num_elems -= 1;
                insert(h, arr[i]);
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        printf("%d", h->pelems[i]);
    }
}
int main()
{
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }
    kelem(arr, 5, 3);
}

/*
to get kth smallest element, mak a heap, do extractmin (k-1) times and then get the root
*/
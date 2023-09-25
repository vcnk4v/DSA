#include <stdio.h>
#include <stdlib.h>
#include "heaps.h"

Heap create(int capacity)
{
    Heap h = (Heap)malloc(sizeof(struct stheap));
    h->pelems = (elemtype *)malloc(sizeof(elemtype) * (capacity + 1));
    h->capacity = capacity;
    h->num_elems = 0;
    // if i want minheap i can initialize the first elem to be neg inf and similarly for maxheap
    return h;
}

void insert(Heap H, long long int e)
{

    int index = H->num_elems;
    H->pelems[index] = e;
    while (index > 0 && H->pelems[(index - 1) / 2] > H->pelems[index])
    {
        long long int temp = H->pelems[index];
        H->pelems[index] = H->pelems[(index - 1) / 2];
        H->pelems[(index - 1) / 2] = temp;

        index = (index - 1) / 2;
    }
    H->num_elems += 1;
}

void heapify(Heap h, int index) // recursive, for iterarive: while loop until greatest==index and keep incrementing left=2*i+1
{
    int smallest = index;
    int l = 2 * index + 1;
    int r = l + 1;
    if (l < h->num_elems && h->pelems[l] < h->pelems[smallest])
    {
        smallest = l;
    }
    if (r < h->num_elems && h->pelems[r] < h->pelems[smallest])
    {
        smallest = r;
    }
    if (smallest != index)
    {
        elemtype temp = h->pelems[smallest];
        h->pelems[smallest] = h->pelems[index];
        h->pelems[index] = temp;
        heapify(h, smallest);
    }
}

long long int extractmin(Heap h) // if it is a minheap
{
    if (h->num_elems == 0)
        return 0;

    int minElement = h->pelems[0];

    h->pelems[0] = h->pelems[h->num_elems - 1];
    h->num_elems -= 1;

    int i = 0;
    int lesser = i;
    do
    {
        i = lesser;
        int left = 2 * i + 1;

        if (left + 1 < h->num_elems && h->pelems[lesser] < h->pelems[left] && h->pelems[lesser] < h->pelems[left + 1])
        {
            break;
        }

        if (left < h->num_elems && h->pelems[left] < h->pelems[lesser])
            lesser = left;

        if (left + 1 < h->num_elems && h->pelems[left + 1] < h->pelems[lesser])
            lesser = left + 1;

        long long int temp = h->pelems[lesser];
        h->pelems[lesser] = h->pelems[i];
        h->pelems[i] = h->pelems[lesser];

    } while (lesser != i);

    return minElement;
}

void deleteroot(Heap h)
{
    h->pelems[0] = h->pelems[h->num_elems - 1];
    h->num_elems -= 1;
    heapify(h, 0);
}

int check_minheap(int *arr, int i, int n) // recursive
{
    if (i >= (n - 1) / 2)
        return 1;
    if (arr[i] <= arr[2 * i + 1] && arr[i] <= arr[2 * i + 2] && check_minheap(arr, 2 * i + 1, n) && check_minheap(arr, 2 * i + 2, n))
        return 1;

    return 0;
}
int ismaxHeap(int *arr, int n) // iterative
{
    for (int i = 0; i <= (n - 2) / 2; i++)
    {

        if (arr[2 * i + 1] > arr[i])
            return 0;

        if (2 * i + 2 < n && arr[2 * i + 2] > arr[i])
            return 0;
    }
    return 1;
}

void printh(Heap h)
{
    for (int i = 0; i < h->num_elems; i++)
    {
        printf("%d ", h->pelems[i]);
    }
}
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     int a;
//     Heap h = create(n);
//     while (n--)
//     {
//         scanf("%d", &a);
//         insert(h, a);
//     }
//     deleteroot(h);
//     printh(h);
//     printf("\n%d", isHeap(h->pelems, h->num_elems));
//     return 0;
// }

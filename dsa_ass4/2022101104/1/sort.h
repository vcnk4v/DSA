#include <stdio.h>
#include <stdlib.h>
struct heapstr
{
    int max;
    int num_elems;
    long long int *arr;
};

typedef struct heapstr *Heap;
Heap insert(Heap H, long long int e);
void heapify(Heap h, int index);
long long int extractmax(Heap h);
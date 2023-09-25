#include <stdio.h>
#include <stdlib.h>
struct heapstr
{
    int max;
    int num_elems;
    long long int *elems;
};
typedef struct heapstr *Heap;
typedef struct heapstr *Heap;
void printh(Heap h);
Heap insert(Heap H, long long int e);
Heap make(int *arr, int n);

void heapify(Heap h, int index);
long long int extractmin(Heap h);
int *der(int *arr, int n, int *hash);

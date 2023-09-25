#include <stdio.h>
#include <stdlib.h>

typedef int elemtype;

struct stheap
{
    int num_elems;
    int capacity;
    elemtype *pelems;
};

typedef struct stheap *Heap;
Heap create(int capacity);
void insert(Heap h, elemtype e);
void heapify(Heap h, int index);
long long int extractmin(Heap h);
void deleteroot(Heap h);
int check_minheap(int *arr, int i, int n);
void printh(Heap h);
int ismaxHeap(int *arr, int n); // iterative

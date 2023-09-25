#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent a node in the adjacency list
struct AdjListNode
{
    int dest;
    int weight;
    struct AdjListNode *next;
};

// Structure to represent an adjacency list
struct AdjList
{
    struct AdjListNode *head;
};

// Structure to represent a graph
struct Graph
{
    int V;
    struct AdjList *array;
};

// Structure to represent a heap node
struct HeapNode
{
    int vertex;
    int key;
};

// Structure to represent a heap
struct MinHeap
{
    int size;
    int capacity;
    int *position;
    struct HeapNode **array;
};

// Function to create a new adjacency list node
struct AdjListNode *newAdjListNode(int dest, int weight)
{
    struct AdjListNode *newNode =
        (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with V vertices
struct Graph *createGraph(int V)
{
    struct Graph *graph =
        (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array =
        (struct AdjList *)malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph *graph, int src, int dest, int weight)
{
    struct AdjListNode *newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to create a new heap node
struct HeapNode *newHeapNode(int vertex, int key)
{
    struct HeapNode *node =
        (struct HeapNode *)malloc(sizeof(struct HeapNode));
    node->vertex = vertex;
    node->key = key;
    return node;
}

// Function to create a min heap
struct MinHeap *createMinHeap(int capacity)
{
    struct MinHeap *minHeap =
        (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap->position =
        (int *)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array =
        (struct HeapNode **)malloc(capacity * sizeof(struct HeapNode *));
    return minHeap;
}

// Function to swap two nodes of the min heap
void swapHeapNode(struct HeapNode **a, struct HeapNode **b)
{
    struct HeapNode *t = *a;
    *a = *b;
    *b = t;
}

// Function to heapify at a given index
void minHeapify(struct MinHeap *minHeap, int idx)
{
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;

    if (left < minHeap->size &&
        minHeap->array[left]->key < minHeap->array[smallest]->key)
        smallest = left;

    if (right < minHeap->size &&
        minHeap->array[right]->key < minHeap->array[smallest]->key)
        smallest = right;

    if (smallest != idx)
    {
        struct HeapNode *smallestNode = minHeap->array[smallest];
        struct HeapNode *idxNode = minHeap->array[idx];

        minHeap->position[smallestNode->vertex] = idx;
        minHeap->position[idxNode->vertex] = smallest;

        swapHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

        minHeapify(minHeap, smallest);
    }
}

// Function to check if the given min heap is empty
int isEmpty(struct MinHeap *minHeap)
{
    return minHeap->size == 0;
}

// Function to extract the minimum node from the heap
struct HeapNode *extractMin(struct MinHeap *minHeap)
{
    if (isEmpty(minHeap))
        return NULL;

    struct HeapNode *root = minHeap->array[0];
    struct HeapNode *lastNode = minHeap->array[minHeap->size - 1];

    minHeap->array[0] = lastNode;

    minHeap->position[root->vertex] = minHeap->size - 1;
    minHeap->position[lastNode->vertex] = 0;

    --minHeap->size;
    minHeapify(minHeap, 0);

    return root;
}

// Function to decrease the key value of a given vertex
void decreaseKey(struct MinHeap *minHeap, int vertex, int key)
{
    int i = minHeap->position[vertex];

    minHeap->array[i]->key = key;

    while (i && minHeap->array[i]->key < minHeap->array[(i - 1) / 2]->key)
    {
        minHeap->position[minHeap->array[i]->vertex] = (i - 1) / 2;
        minHeap->position[minHeap->array[(i - 1) / 2]->vertex] = i;
        swapHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);

        i = (i - 1) / 2;
    }
}

// Function to check if a given vertex is in min heap
int isInMinHeap(struct MinHeap *minHeap, int vertex)
{
    if (minHeap->position[vertex] < minHeap->size)
        return 1;
    return 0;
}

// Function to print the constructed MST
void printMST(int parent[], int n, struct Graph *graph)
{
    printf("Edge\n");
    for (int i = 1; i < n; ++i)
        printf("%d - %d\n", parent[i], i);
}

// Function to construct and print the MST
void primMST(struct Graph *graph)
{
    int V = graph->V; // Number of vertices in the graph
    int parent[V];    // Array to store constructed MST
    int key[V];       // Key values used to pick minimum weight edge in cut
    struct MinHeap *minHeap = createMinHeap(V);

    for (int v = 1; v < V; ++v)
    {
        parent[v] = -1;
        key[v] = INT_MAX;
        minHeap->array[v] = newHeapNode(v, key[v]);
        minHeap->position[v] = v;
    }

    key[0] = 0;
    minHeap->array[0] = newHeapNode(0, key[0]);
    minHeap->position[0] = 0;
    minHeap->size = V;

    while (!isEmpty(minHeap))
    {
        struct HeapNode *minNode = extractMin(minHeap);
        int u = minNode->vertex;

        struct AdjListNode *crawl = graph->array[u].head;
        while (crawl != NULL)
        {
            int v = crawl->dest;

            if (isInMinHeap(minHeap, v) && crawl->weight < key[v])
            {
                key[v] = crawl->weight;
                parent[v] = u;
                decreaseKey(minHeap, v, key[v]);
            }

            crawl = crawl->next;
        }
    }

    printMST(parent, V, graph);
}

// Driver program to test above functions
int main()
{
    int V = 5; // Number of vertices in the graph
    struct Graph *graph = createGraph(V);
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 3, 6);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 8);
    addEdge(graph, 1, 4, 5);
    addEdge(graph, 2, 4, 7);
    addEdge(graph, 3, 4, 9);

    primMST(graph);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Define a structure for the binary tree node
typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

typedef Node *Tree;
// Define a structure for the queue node
typedef struct QueueNode
{
    Node *node;
    int hd; // horizontal distance
} QueueNode;

// Function to create a new binary tree node
Node *newNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to perform a level order traversal of the binary tree
void printTopView(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // Create an empty queue for level order traversal
    QueueNode qn;
    qn.node = root;
    qn.hd = 0;
    QueueNode queue[100];
    int front = 0, rear = 0;
    queue[rear++] = qn;

    // Create a map to store the first node encountered at each horizontal distance
    int min_hd = 0, max_hd = 0;
    int map[100];
    for (int i = 0; i < 100; i++)
    {
        map[i] = -1;
    }

    // Traverse the binary tree level by level
    while (front < rear)
    {
        qn = queue[front++];
        Node *node = qn.node;
        int hd = qn.hd;

        // Update the minimum and maximum horizontal distances
        if (hd < min_hd)
        {
            min_hd = hd;
        }
        if (hd > max_hd)
        {
            max_hd = hd;
        }

        // If the horizontal distance of the current node is not already set in the map,
        // add it to the map and print the node data
        if (map[hd] == -1)
        {
            map[hd] = node->data;
            printf("%d ", node->data);
        }

        // Enqueue the left child node with its horizontal distance
        if (node->left != NULL)
        {
            QueueNode left;
            left.node = node->left;
            left.hd = hd - 1;
            queue[rear++] = left;
        }

        // Enqueue the right child node with its horizontal distance
        if (node->right != NULL)
        {
            QueueNode right;
            right.node = node->right;
            right.hd = hd + 1;
            queue[rear++] = right;
        }
    }
}

void printleftview(Tree t, int *mdepth, int level)
{
    if (t == NULL)
    {
        return;
    }
    if (level > *mdepth)
    {
        printf("%d ", t->data);
        *mdepth = level;
    }
    printleftview(t->left, mdepth, level + 1);
    printleftview(t->right, mdepth, level + 1);
}

void leftView(Tree root)
{
    int max_level = 0;
    printleftview(root, &max_level, 1);
}

// Driver program to test the above function
int main()
{
    // Construct the binary tree
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);

    // Print the top view of the binary tree
    printf("Top view of the binary tree is: ");
    printTopView(root);
    printf("\n");
    leftView(root);

    return 0;
}

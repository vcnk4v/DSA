#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode *PtrToNode;

typedef struct TreeNode
{
    char *name;
    int isFile;
    int size;
    struct TreeNode *Firstchild;
    struct TreeNode *Nextsibling;
} TreeNode;

typedef struct TreeNode *DirOrFile;

void printentry(DirOrFile D, int numspaces)
{
    for (int i = 0; i < numspaces; i++)
    {
        printf(" ");
    }
    printf("%s\n", D->name);
}

// preorder
void printdir(DirOrFile D, int depth)
{
    if (D != NULL)
    {
        printentry(D, depth);
        DirOrFile c = D->Firstchild;
        while ((c != NULL))
        {
            printdir(c, depth + 1);
            c = c->Nextsibling;
        }
    }
}

int getsize(DirOrFile D)
{
    if (D == NULL)
    {
        return 0;
    }

    if (D->isFile)
    {
        return D->size;
    }

    // Traverse child nodes recursively to get the total size of a directory
    int totalSize = 0;
    DirOrFile child = D->Firstchild;
    while (child != NULL)
    {
        totalSize += getsize(child); // Traverse child node
        child = child->Nextsibling;
    }
    D->size = totalSize; // Update directory size
    return totalSize;
}

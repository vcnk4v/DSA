#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

#define ALPHABET_SIZE 26

// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

// If not present, inserts the key into the trie
// If the key is the prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, char *key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < strlen(key); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}

// function break the string into minimum cut
// such the every substring after breaking
// in the dictionary.
void minWordBreak(struct TrieNode *root, char *key, int start, int *min_Break, int level)
{
    struct TrieNode *pCrawl = root;

    // base case, update minimum Break
    if (start == strlen(key))
    {
        *min_Break = (*min_Break < level - 1) ? *min_Break : level - 1;
        return;
    }

    // traverse given key(pattern)
    for (int i = start; i < strlen(key); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return;

        // if we find a condition where we can
        // move to the next word in a trie
        // dictionary
        if (pCrawl->children[index]->isEndOfWord)
            minWordBreak(root, key, i + 1, min_Break, level + 1);

        pCrawl = pCrawl->children[index];
    }
}

// Driver program to test above functions
int main()
{
    char *dictionary[] = {"Cat", "Mat",
                          "Ca", "Ma", "at", "C", "Dog", "og", "Do"};
    int n = sizeof(dictionary) / sizeof(dictionary[0]);
    struct TrieNode *root = getNode();

    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, dictionary[i]);

    int min_Break = INT_MAX;

    minWordBreak(root, "CatMatat", 0, &min_Break, 0);
    printf("%d\n", min_Break);

    return 0;
}

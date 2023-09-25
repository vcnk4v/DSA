#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tr
{
    int word;
    struct Tr *children[26];
};
typedef struct Tr *Trie;

Trie maken(int word)
{
    Trie n = (Trie)malloc(sizeof(struct Tr));
    n->word = word;
    for (int i = 0; i < 26; i++)
    {
        n->children[i] = NULL;
    }
    return n;
}
int cmp(const void *a, const void *b)
{
    char *const *stringa = a;
    char *const *stringb = b;
    return strcmp(*stringa, *stringb);
}
void insert(Trie t, char *str, int len)
{
    for (int i = 0; i < len; i++)
    {
        int ind = str[i] - 'a';
        Trie next = t->children[ind];
        if (next == NULL)
        {
            t->children[ind] = maken(0);
            next = t->children[ind];
        }
        t = next;
    }
    t->word = 1;
}

int search(char *str, Trie t, int len)
{
    Trie curr = t;
    for (int i = 0; i < len; i++)
    {
        int ind = str[i] - 'a';
        Trie next = curr->children[ind];
        if (next == NULL)
        {
            return 0;
        }
        curr = next;
    }
    return 1;
}

int main()
{
    int s;
    scanf("%d", &s);
    Trie *targetwords = (Trie *)malloc(sizeof(Trie) * s);
    char **targets = (char **)malloc(sizeof(char *) * s);
    for (int i = 0; i < s; i++)
    {
        targets[i] = (char *)malloc(sizeof(char) * 2000001);
    }

    for (int session = 0; session < s; session++)
    {
        int n;
        scanf("%d", &n);
        scanf("%s", targets[session]);
        targetwords[session] = maken(1);
        int l = strlen(targets[session]);
        insert(targetwords[session], targets[session], l);
        for (int i = 0; i < n; i++)
        {
            char guess[2000001];
            scanf("%s", guess);
            int len = strlen(guess);
            insert(targetwords[session], guess, len);
        }
    }
    int m;
    scanf("%d", &m);
    while (m--)
    {
        char query[400001];

        scanf("%s", query);
        int len = strlen(query);
        int ans[s];
        int count = 0;
        int maxlen = 0;
        for (int i = 0; i < s; i++)
        {
            int isitthere = search(query, targetwords[i], len);
            if (isitthere == 1)
            {
                ans[i] = 1;
                int x = strlen(targets[i]);
                if (x > maxlen)
                {

                    maxlen = x;
                }

                count++;
            }
            else
            {
                ans[i] = 0;
            }
        }
        printf("%d ", count);
        char *answer[count];
        for (int i = 0; i < count; i++)
        {
            answer[i] = (char *)malloc(sizeof(char) * (maxlen + 1));
        }

        int index = 0;
        for (int i = 0; i < s; i++)
        {
            if (ans[i] == 1)
            {
                strcpy(answer[index++], targets[i]);
            }
        }
        qsort(answer, count, sizeof(char *), cmp);
        for (int i = 0; i < count; i++)
        {
            printf("%s ", answer[i]);
        }

        printf("\n");
        for (int i = 0; i < count; i++)
        {
            free(answer[i]);
        }
    }

    for (int i = 0; i < s; i++)
    {
        free(targets[i]);
        free(targetwords[i]);
    }
    free(targets);
    free(targetwords);
    return 0;
}

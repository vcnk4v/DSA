#include "hash.h"

void sort(char *sorted)
{
    int len = strlen(sorted);
    char temp;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (sorted[j] < sorted[i])
            {
                temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }
}

long long int findhash(char *str, long long int tsize)
{
    long long int x = 0;
    long long int pr = 1;
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        x = (x + (str[i] - 'a' + 1) * pr) % tsize;
        pr = (pr * 37) % tsize;
    }
    return x;
}

htable create(long long int tsize)
{
    htable H;

    H = (htable)malloc(sizeof(struct table));

    H->tsize = tsize;

    H->listptr = (LIST *)malloc(sizeof(LIST) * H->tsize);

    for (long long i = 0; i < H->tsize; i++)
    {
        H->listptr[i] = (LIST)malloc(sizeof(struct hashnode));

        H->listptr[i]->next = NULL;
    }
    return H;
}

void insert(char *str, htable H)
{
    LIST n = (LIST)malloc(sizeof(struct hashnode));

    char sorted[11];
    strcpy(sorted, str);
    sort(sorted);
    long long hashvalue = findhash(sorted, H->tsize);
    LIST L = H->listptr[hashvalue];
    strcpy(n->key, sorted);
    n->next = L->next;
    strcpy(n->str, str);
    L->next = n;
}

void printrev(LIST head, int *flag, char *sorted)
{
    if (head == NULL)
    {
        return;
    }
    printrev(head->next, flag, sorted);
    if (strcmp(sorted, head->key) == 0)
    {
        printf("%s ", head->str);
        *flag = 1;
    }
}

void print_anagrams(char *s, htable ht)
{
    char sorted[11];
    strcpy(sorted, s);
    sort(sorted);

    long long int hashval = findhash(sorted, ht->tsize);

    LIST l = ht->listptr[hashval];
    LIST i = l->next;

    if (i == NULL)
    {
        printf("-1");
        return;
    }

    int flag = 0;
    printrev(i, &flag, sorted);
    if (flag == 0)
    {
        printf("-1");
    }
}

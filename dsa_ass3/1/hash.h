#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct hashnode *hptr;
struct hashnode
{
    char key[11];
    char str[11];
    hptr next;
};
typedef hptr LIST;
struct table
{
    LIST *listptr;
    long long int tsize;
};
typedef struct table *htable;
void sort(char *sorted);
long long int findhash(char *str, long long int tsize);
htable create(long long int tsize);
void insert(char *str, htable H);
void printrev(LIST head, int *flag, char *sorted);
void print_anagrams(char *s, htable ht);

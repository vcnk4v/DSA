#include <stdio.h>
#include <stdlib.h>
int **indirect(int *a, int n)
{
    int **p = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        p[i] = &a[i];
    }
    for (int i = 0; i < n; i++)
    {
        int *curr = p[i];
        int j;
        for (j = i; j > 0 && *curr < *p[j - 1]; j--)
        {
            p[j] = p[j - 1];
        }
        p[j] = curr;
    }
    return p;
}

void insitu(int *a, int n)
{
    int **p = indirect(a, n);

    for (int i = 0; i < n; i++)
    {
        int curr = a[i];
        int j = i;
        while (p[j] != &a[i])
        {
            a[j] = *p[j];
            int next_j = p[j] - &a[0];
            p[j] = &a[j];
            j = next_j;
        }
        a[j] = curr;
        p[j] = &a[j];
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    insitu(a, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
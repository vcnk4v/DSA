#include <stdio.h>
#include <stdlib.h>

int compare(char *a, char *b)
{
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0')
    {
        if (a[i] == b[i])
        {
            i++;
        }
        else if (i % 2 == 0)
        {
            if (a[i] > b[i])
            {
                return 1;
            }
            return 0;
        }
        else
        {
            if (a[i] > b[i])
            {
                return 0;
            }
            return 1;
        }
    }
    if (a[i] == '\0')
    {
        if (i % 2 == 0)
        {
            return 1;
        }
        return 0;
    }
    else
    {
        if (i % 2 == 0)
        {
            return 0;
        }
        return 1;
    }
}

void mergesorted(char **a, int start, int end, int mid, int max)
{
    int len1 = mid - start + 1;
    int len2 = end - mid;

    char **arr1 = (char **)malloc(sizeof(char *) * (len1));

    char **arr2 = (char **)malloc(sizeof(char *) * (len2));

    for (int i = 0; i < len1; i++)
    {

        arr1[i] = a[start + i];
    }
    for (int i = 0; i < len2; i++)
    {

        arr2[i] = a[mid + i + 1];
    }
    int i1 = 0, i2 = 0, ind = start;
    while (i1 < len1 && i2 < len2)
    {
        if (compare(arr2[i2], arr1[i1]))
        {

            a[ind] = arr1[i1];
            ind++;
            i1++;
        }
        else
        {

            a[ind] = arr2[i2];
            ind++;
            i2++;
        }
    }
    while (i1 < len1)
    {

        a[ind] = arr1[i1];
        ind++;
        i1++;
    }
    while (i2 < len2)
    {

        a[ind] = arr2[i2];
        ind++;
        i2++;
    }

    free(arr1);

    free(arr2);
}

void mergesort(char **a, int start, int end, int max)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergesort(a, start, mid, max);
        mergesort(a, mid + 1, end, max);
        mergesorted(a, start, end, mid, max);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);

        char **arr = (char **)malloc(sizeof(char *) * n);
        int len[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &len[i]);
            arr[i] = (char *)malloc(sizeof(char *) * len[i]);
            scanf("%s", arr[i]);
        }

        int max = 0;
        for (int i = 0; i < n; i++)
        {
            if (max < len[i])
            {
                max = len[i];
            }
        }

        mergesort(arr, 0, n - 1, max);
        for (int i = 0; i < n; i++)
        {
            printf("%s\n", arr[i]);
        }
        for (int i = 0; i < n; i++)
        {
            free(arr[i]);
        }
        free(arr);
    }
}
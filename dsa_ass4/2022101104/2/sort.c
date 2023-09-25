#include "sort.h"

int cmp(long long int *a_arr1, long long int *a_arr2, long long int *b_arr1, long long int *b_arr2, int i1, int i2)
{
    if (a_arr1[i1] < a_arr2[i2])
    {
        return 1;
    }
    else if (a_arr1[i1] == a_arr2[i2] && b_arr1[i1] < b_arr2[i2])
    {
        return 1;
    }
    return 0;
}

void mergesorted(long long int *a, int start, int end, int mid, long long int *b)
{
    int len1 = mid - start + 1;
    int len2 = end - mid;
    long long int arr1[len1];
    long long int arr2[len2];

    long long int b1[len1];
    long long int b2[len2];
    for (int i = 0; i < len1; i++)
    {
        arr1[i] = a[start + i];
        b1[i] = b[start + i];
    }
    for (int i = 0; i < len2; i++)
    {
        arr2[i] = a[mid + i + 1];
        b2[i] = b[mid + i + 1];
    }
    int i1 = 0, i2 = 0, ind = start;
    while (i1 < len1 && i2 < len2)
    {
        if (cmp(arr1, arr2, b1, b2, i1, i2))
        {
            b[ind] = b1[i1];
            a[ind++] = arr1[i1++];
        }
        else
        {
            b[ind] = b2[i2];
            a[ind++] = arr2[i2++];
        }
    }
    while (i1 < len1)
    {
        b[ind] = b1[i1];
        a[ind++] = arr1[i1++];
    }
    while (i2 < len2)
    {
        b[ind] = b2[i2];
        a[ind++] = arr2[i2++];
    }
}

void mergesort(long long int *a, int start, int end, long long int *b)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergesort(a, start, mid, b);
        mergesort(a, mid + 1, end, b);
        mergesorted(a, start, end, mid, b);
    }
}

long long int j2_end(long long int *b, long long int *a, int n)
{
    if (b[0] < a[0])
    {
        a[0] = b[0];
    }
    for (int i = 1; i < n; i++)
    {
        if (b[i] < a[i] && b[i] >= a[i - 1])
        {
            a[i] = b[i];
        }
    }
    return a[n - 1];
}

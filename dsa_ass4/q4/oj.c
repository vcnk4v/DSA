#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void mergesorted(int *a, int start, int end, int mid)
{
    int len1 = mid - start + 1;
    int len2 = end - mid;
    int arr1[len1];
    int arr2[len2];
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
        if (arr1[i1] < arr2[i2])
        {
            a[ind++] = arr1[i1++];
        }
        else
        {
            a[ind++] = arr2[i2++];
        }
    }
    while (i1 < len1)
    {
        a[ind++] = arr1[i1++];
    }
    while (i2 < len2)
    {
        a[ind++] = arr2[i2++];
    }
}

void mergesort(int *a, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergesort(a, start, mid);
        mergesort(a, mid + 1, end);
        mergesorted(a, start, end, mid);
    }
}

int max_wins(int *A, int k, int m, int j)
{
    if (k == 1)
    {
        return m;
    }
    int count = 0;
    for (int i = 0; i <= k * m - k; i += k)
    {
        swap(&A[i], &A[i + j]);
        mergesort(A, i + 1, i + k - 1);
    }
    int jschool[m];
    int max[m];
    for (int i = 0; i < m; i++)
    {
        jschool[i] = A[i * k];
        max[i] = A[(i + 1) * k - 1];
    }

    mergesort(jschool, 0, m - 1);
    mergesort(max, 0, m - 1);
    for (int i = m - 1; i >= 0; i--)
    {
        if (jschool[i] > max[i])
        {
            count++;
        }
        else if (i != 0)
        {
            int temp = jschool[0];
            for (int j = 0; j < i; j++)
            {
                jschool[j] = jschool[j + 1];
            }
            jschool[i] = temp;
        }
    }
    return count;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int k, m;
        scanf("%d %d", &k, &m);
        int A[k * m];
        for (int i = 0; i < k * m; i++)
        {
            scanf("%d", &A[i]);
        }

        int j;
        scanf("%d", &j);
        j--;
        int wins = max_wins(A, k, m, j);
        printf("%d\n", wins);
    }
}
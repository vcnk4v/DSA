#include "heap.h"
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int hash[max + 1];
    for (int i = 0; i <= max; i++)
    {
        hash[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] = i;
    }
    int *d = der(arr, n, hash);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", d[i]);
    }
    printf("\n");
    return 0;
}
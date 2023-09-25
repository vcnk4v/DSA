#include "sort.h"
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
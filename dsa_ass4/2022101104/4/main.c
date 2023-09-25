#include "sort.h"
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
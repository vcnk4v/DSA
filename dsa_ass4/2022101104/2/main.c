#include "sort.h"

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        long long int a[n];
        long long int b[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &b[i]);
        }

        mergesort(a, 0, n - 1, b);

        printf("%lld ", a[n - 1]);
        printf("%lld\n", j2_end(b, a, n));
    }
    return 0;
}
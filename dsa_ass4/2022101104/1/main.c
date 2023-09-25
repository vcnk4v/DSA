#include "sort.h"
int main()
{
    long long int t;
    scanf("%lld", &t);
    while (t--)
    {
        long long int n, k;
        scanf("%lld %lld", &n, &k);
        Heap H = (Heap)malloc(sizeof(struct heapstr));
        H->max = n;
        H->num_elems = 0;
        H->arr = (long long int *)malloc(sizeof(long long int) * (n));

        long long int a[n];
        for (long long int i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
            insert(H, a[i]);
        }
        long long int max = 0;
        while (k--)
        {
            long long int x = extractmax(H);
            max += x;
            x--;
            insert(H, x);
            if (H->arr[0] <= 0)
            {
                break;
            }
        }
        printf("%lld\n", max);
    }
}
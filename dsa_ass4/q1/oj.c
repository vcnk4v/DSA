#include <stdio.h>
void heapify(long long int index, long long int *h, long long int n)
{
    long long int less = index;
    long long int l = 2 * index + 1;
    long long int r = l + 1;
    if (l < n && h[l] > h[less])
    {
        less = l;
    }
    if (r < n && h[r] > h[less])
    {
        less = r;
    }
    if (less != index)
    {
        long long int temp = h[less];
        h[less] = h[index];
        h[index] = temp;
        heapify(less, h, n);
    }
}

void reverse(long long int *a, long long int n)
{
    for (long long int i = 0; i < n / 2 - 1; i++)
    {
        long long int temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }
}

void sort(long long int n, long long int *a)
{
    long long int size = n;
    for (long long int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(i, a, n);
    }
    n--;
    while (n >= 1)
    {
        long long int temp = a[0];
        a[0] = a[n];
        a[n] = temp;
        heapify(0, a, n);
        n--;
    }
    reverse(a, size);
}

void insert(long long int *a, long long int *n, long long int e)
{
    a[*n] = e;
    long long int i = *n;
    while (i > 0 && a[(i - 1) / 2] < a[i])
    {
        long long int temp = a[i];
        a[i] = a[(i - 1) / 2];
        a[(i - 1) / 2] = temp;

        i = (i - 1) / 2;
    }
    *n = *n + 1;
}

long long int exmax(long long int *a, long long int *n)
{
    long long int m = a[0];
    a[0] = a[*n - 1];
    heapify(0, a, *n - 1);
    *n = *n - 1;
    return m;
}

int main()
{
    long long int t;
    scanf("%lld", &t);
    while (t--)
    {
        long long int n, k;
        scanf("%lld %lld", &n, &k);
        long long int a[n];
        for (long long int i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
        }
        sort(n, a);

        long long int max = 0;
        while (k--)
        {
            int m = exmax(a, &n);
            max += m;
            m--;
            insert(a, &n, m);

            if (a[0] <= 0)
            {
                break;
            }
        }
        printf("%lld\n", max);
    }
}
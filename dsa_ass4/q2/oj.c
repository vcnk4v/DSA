#include <stdio.h>

int cmp(long long int *a_arr, long long int *b_arr, int i1, int i2)
{
    if (a_arr[i1] > a_arr[i2])
    {
        return 1;
    }
    else if (a_arr[i1] == a_arr[i2] && b_arr[i1] > b_arr[i2])
    {
        return 1;
    }
    return 0;
}

void pdown(int begin, long long int *a, long long int *b, int end)
{
    while (2 * begin + 1 < end)
    {
        int in = begin;

        if (cmp(a, b, 2 * begin + 1, begin))
        {
            in = 2 * begin + 1;
        }
        if (2 * begin + 2 < end)
        {
            if (cmp(a, b, 2 * begin + 2, in))
            {
                in = 2 * begin + 2;
            }
        }

        long long int temp = a[begin];
        a[begin] = a[in];
        a[in] = temp;
        temp = b[begin];
        b[begin] = b[in];
        b[in] = temp;
        begin = 2 * begin + 1;
    }
}

void sort(int n, long long int *a, long long int *b)
{

    for (int i = (n - 2) / 2; i >= 0; i--)
    {
        pdown(i, a, b, n);
    }
    n--;
    while (n >= 0)
    {
        long long int temp = a[0];
        a[0] = a[n];
        a[n] = temp;
        temp = b[0];
        b[0] = b[n];
        b[n] = temp;
        pdown(0, a, b, n);
        n--;
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

        sort(n, a, b);

        printf("%lld ", a[n - 1]);
        printf("%lld\n", j2_end(b, a, n));
    }
    return 0;
}
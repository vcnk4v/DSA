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
void shell(long long int *a, int n, long long int *b)
{
    int incr;
    for (incr = n / 2; incr > 0; incr /= 2)
    {
        long long int curr;
        long long int c2;
        for (int i = incr; i < n; i++)
        {
            curr = a[i];
            c2 = b[i];
            int j = i;
            while (cmp(a, b, i, j - incr) == 0)
            {
                a[j] = a[j - incr];
                b[j] = b[j - incr];
                j -= incr;
            }
            a[j] = curr;
            b[j] = c2;
        }
    }
}

long long int j2_end(long long int *b, long long int *a, int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%lld ", b[i]);
    }
    printf("\n");

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

        shell(a, n, b);

        printf("%lld ", a[n - 1]);
        printf("%lld\n", j2_end(b, a, n));
    }
    return 0;
}
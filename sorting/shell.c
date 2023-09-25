#include <stdio.h>
void shell(int *a, int n)
{
    int incr;
    for (incr = n / 2; incr > 0; incr /= 2)
    {
        int curr;
        for (int i = incr; i < n; i++)
        {
            curr = a[i];
            int j = i;
            while (j >= incr && curr < a[j - incr])
            {
                a[j] = a[j - incr];
                j -= incr;
            }
            a[j] = curr;
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    shell(a, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
#include "hash.h"
int main()
{
    int n, q;

    scanf("%d %d", &n, &q);
    char str[n + 1];
    scanf("%s", str);
    long long int pp[n + 1];
    pp[0] = 1;
    for (int i = 1; i < n + 1; i++)
    {
        pp[i] = prime * pp[i - 1];
    }

    long long int *frontarr = hash(str, 0, n);
    long long int *revarr = hash(str, 1, n);

    while (q--)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        int sublen = r - l;

        long long int forward = frontarr[r - 1] - frontarr[l - 1] * pp[sublen];
        long long int backward = revarr[n - l] - revarr[n - r] * pp[sublen];

        if (forward != backward)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }

    free(frontarr);
    free(revarr);

    return 0;
}
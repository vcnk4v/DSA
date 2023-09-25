#include "hash.h"
long long int *hash(char *str, int is_rev, int len)
{
    long long int *arr = (long long int *)malloc(sizeof(long long int) * (len));

    if (is_rev == 0)
    {
        arr[0] = (str[0] - 'a' + 1) * prime;
        for (int i = 1; i < len; i++)
        {
            arr[i] = arr[i - 1] * prime + (str[i] - 'a' + 1);
        }
    }
    else
    {
        arr[0] = (str[len - 1] - 'a' + 1);
        for (int i = 1; i < len; i++)
        {
            arr[i] = arr[i - 1] * prime + (str[len - i - 1] - 'a' + 1);
        }
    }
    return arr;
}

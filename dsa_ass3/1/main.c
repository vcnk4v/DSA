#include "hash.h"
int main()
{
    long long int n, q;
    scanf("%lld %lld", &n, &q);
    htable h = create(802421);
    while (n--)
    {
        char str[11];
        scanf("%s", str);
        insert(str, h);
    }
    while (q--)
    {
        char str[11];
        scanf("%s", str);
        print_anagrams(str, h);
        printf("\n");
    }
    return 0;
}

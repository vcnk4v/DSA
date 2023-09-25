#include "heap.h"
int main()
{
    Heap H = (Heap)malloc(sizeof(struct heapstr));
    int n;
    scanf("%d", &n);
    H->max = n;
    H->num_elems = 0;
    H->knobs = (long long int *)malloc(sizeof(long long int) * (n));
    long long int temp = 0;
    int count = 0;
    long long int a;

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a);
        if (a >= 0)
        {
            temp += a;
            count++;
        }
        else
        {
            long long int x;
            H = insert(H, a);
            temp += a;
            count++;
            if (temp < 0)
            {
                x = extractmax(H);
                temp -= x;
                count--;
            }
        }
    }
    printf("%d\n", count);
}
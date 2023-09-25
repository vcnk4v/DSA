#include "functions.h"
int main()
{
    int t;
    scanf("%d", &t);
    Queue q = InitQueue();
    while (t--)
    {
        char str[6];
        scanf("%s", str);
        int n, k;
        if (str[4] == '1')
        {
            scanf("%d", &n);
            Push(q, n);
        }
        else if (str[4] == '2')
        {
            printf("%d\n", Pop(q));
        }
        else if (str[4] == '3')
        {
            scanf("%d", &n);
            Inject(q, n);
        }
        else if (str[4] == '4')
        {
            printf("%d\n", popRear(q));
        }
        else if (str[4] == '5')
        {
            Print(q);
            printf("\n");
        }
        else if (str[4] == '6')
        {
            PrintReverse(q);
            printf("\n");
        }
        else if (str[4] == '7')
        {
            scanf("%d", &n);
            printf("%d\n", findElem(q, n));
        }
        else if (str[4] == '8')
        {
            scanf("%d", &k);
            removeKElems(q, k);
        }
    }
    return 0;
}
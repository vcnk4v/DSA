#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insertion(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        int curr = a[i];
        int j;
        for (j = i; j > 0 && a[j - 1] > curr; j--)
        {
            a[j] = a[j - 1];
        }
        a[j] = curr;
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
    insertion(a, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
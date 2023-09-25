#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int QPartition(int *arr, int l, int r, int pivot)
{
    int i = 0, j = r;
    while (1)
    {
        while (arr[++i] < pivot)
        {
        }
        while (arr[--j] > pivot)
        {
        }
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
        else
        {
            break;
        }
    }
    swap(&arr[i], &arr[r - 1]);
    return i;
}

int Medianof3(int *arr, int l, int r)
{
    int m = l + (r - l) / 2;
    if (arr[l] > arr[m])
    {
        swap(&arr[l], &arr[m]);
    }
    if (arr[m] > arr[r])
    {
        swap(&arr[m], &arr[r]);
    }
    if (arr[l] > arr[r])
    {
        swap(&arr[l], &arr[r]);
    }
    swap(&arr[m], &arr[r - 1]);
    return arr[r - 1];
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
void quickSort(int *arr, int l, int r)
{
    if (r - l + 1 < 10)
    {
        insertion(arr, r - l + 1);
    }
    else
    {
        int pivot_value = Medianof3(arr, l, r);
        int pivot_index = QPartition(arr, l, r, pivot_value);
        quickSort(arr, l, pivot_index - 1);
        quickSort(arr, pivot_index + 1, r);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
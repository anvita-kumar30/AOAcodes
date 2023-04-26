#include <stdio.h>
#include <math.h>
int A[10];
int B[10];
int n;
int count;
void input(int size)
{
    int i;
    for (i = 0; i < size; i++)
        scanf("%d", &A[i]);
}
void display(int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d\t", A[i]);
}
void merge(int low, int mid, int high)
{
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;
    while ((i <= mid) && (j <= high))
    {
        if (A[i] <= A[j])
        {
            B[k] = A[i];
            i++;
        }
        else
        {
            B[k] = A[j];
            j++;
        }
        k++;   
    }
    if (i > mid)
    {
        while(j <= high)
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i <= mid)
        {
            B[k] = A[i];
            i++;
            k++;
        }
    }
    for (k = low; k <= high; k++)
    {
        A[k] = B[k];
    }
}
void mergeSort(int low, int high)
{
    if (low < high)
    {
        int mid = floor((low + high) / 2);
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
    }
    count++;
}
int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("\nEnter the elements:\n");
    input(n);
    printf("\nArray before sorting:\n");
    display(n);
    mergeSort(0, n - 1);
    printf("\n\nArray after sorting:\n");
    display(n);
    printf("\n\nNumber of calls made to the merge sort procedure: %d", count);
    return 0;
}
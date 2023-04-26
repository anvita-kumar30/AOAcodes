#include <stdio.h>
#include <math.h>
int A[10];
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
int Partition(int lb, int ub)
{
    int pivot, i, j, temp, temp1;
    pivot = A[lb];
    int start = lb;
    int end = ub;
    while(start < end)
    {
        while(A[start] <= pivot)
        {
            start++;
        }
        while(A[end] > pivot)
        {
            end--;
        }
        if(start < end)
        {
            temp = A[start];
            A[start] = A[end];
            A[end] = temp;
        }
    }
    temp1 = A[lb];
    A[lb] = A[end];
    A[end] = temp1;
    return end;
}
void QuickSort(int lb, int ub)
{
    int loc;
    if (lb < ub)
    {
        loc = Partition(lb, ub);
        QuickSort(lb, loc - 1);
        QuickSort(loc + 1, ub);
    }
    count++;
}
int main()
{
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("\nEnter the elements:\n");
    input(n);
    printf("\nArray before sorting:\n");
    display(n);
    QuickSort(0, n - 1);
    printf("\n");
    printf("\nArray after sorting:\n");
    display(n);
    printf("\n\nNumber of calls made to the procedure: %d", count);
    return 0;
}
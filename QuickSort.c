#include <stdio.h>
#include <math.h>
int A[10];
int B[10];
int n;
int count;
void input(int size)
{
    int i;
    for (i = 0; i <= size - 1; i++)
        scanf("%d", &A[i]);
}
void display(int size)
{
    int i;
    for (i = 0; i <= size - 1; i++)
        printf("%d\t", A[i]);
}
int Partition(int p, int r)
{
    int x, i, j, temp, temp1;
    x = A[r];
    i = p - 1;
    for (j = p; j <= r - 1; j++)
    {
        if (A[j] <= x)
        {
            i = i + 1;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    temp1 = A[i + 1];
    A[i + 1] = A[r];
    A[r] = temp1;
    return i + 1;
}
void QuickSort(int p, int r)
{
    int q;
    if (p < r)
    {
        q = Partition(p, r);
        QuickSort(p, q - 1);
        QuickSort(q + 1, r);
    }
    count++;
}
int main()
{
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    input(n);
    printf("Array before sorting:\n");
    display(n);
    QuickSort(0, n - 1);
    printf("\n");
    printf("Array after sorting:\n");
    display(n);
    printf("\n");
    printf("Number of calls made to the procedure: %d", count);
    return 0;
}
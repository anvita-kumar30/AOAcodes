#include <stdio.h>
#include <conio.h>
void readArray(int n, int array[n])
{
    printf("\nEnter the array elements :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
}
void displayArray(int n, int array[n])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", array[i]);
    }
}
void selectionSort(int n, int array[n])
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        for (int k = i + 1; k < n; k++)
        {
            if (array[k] < array[j])
            {
                j = k;
            }
        }
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        printf("\n\nPass Number %d : ", i + 1);
        displayArray(n, array);
    }
}
void main()
{
    int n;
    printf("Enter the array size: ");
    scanf("%d", &n);
    int array[n];
    readArray(n, array);
    printf("\nBefore swapping the array elements are as follows:\n");
    displayArray(n, array);
    selectionSort(n, array);
    printf("\n\nAfter swapping the array elements are as follows:\n");
    displayArray(n, array);
}
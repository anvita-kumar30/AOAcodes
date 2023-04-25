#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int board[20], count;
int n, i, j, p;
void print(int n)
{
    int i, j;
    printf("\nSolution %d (in 2D format):\n", ++count);
    for (i = 1; i <= n; ++i)
        printf("\t%d", i);
    for (i = 1; i <= n; ++i)
    {
        printf("\n\n%d", i);
        for (j = 1; j <= n; ++j)
        {
            if (board[i] == j)
                printf("\tQ");
            else
                printf("\t-");
        }
    }
    printf("\nSolution %d (in 1D format): [", count);
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= n; ++j)
        {
            if (board[i] == j)
                printf(" %d ",j);
        }
    }
    printf("]");
    printf("\n");
}
int place(int row, int column)
{
    int i;
    for (i = 1; i <= row - 1; ++i)
    {
        if ((board[i] == column) || (abs(board[i] - column) == abs(i - row)))
            return 0;
    }
    return 1;
}
void nqueen(int row, int n)
{
    for (int column = 1; column <= n; ++column)
    {
        if (place(row, column))
        {
            board[row] = column;
            if (row == n)
                print(n);
            else
                nqueen(row + 1, n);
        }
    }
}
int main()
{
    printf(" - N Queens Problem Using Backtracking -");
    printf("\nEnter number of Queens: ");
    scanf("%d", &n);
    nqueen(1, n);
    printf("\nTotal number of calls to queen procedure: %d\n", count);
    return 0;
}
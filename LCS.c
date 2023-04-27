#include<stdio.h>
#include<string.h>
char x[30], y[30];  //strings
char b[30][30];  //arrows
int c[30][30];   //table values
int m=0, n=0;
void print_lcs(int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == 'd')
    {
        print_lcs(i - 1, j - 1);
        printf("%c\t", x[i-1]);
    }
    else if (b[i][j] == 't')
    {
        print_lcs(i - 1, j);
    }
    else
    {
        print_lcs(i, j - 1);
    }
}
void LCS(char x[30], char y[30])
{
    int i, j;
    m = strlen(x);
    n = strlen(y);
    b[m + 1][n + 1];
    c[m + 1][n + 1];
    for (i = 0; i <= m; i++)
    {
        c[i][0] = 0;
    }
    for (i = 0; i <= n; i++)
    {
        c[0][i] = 0;
    }
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'd';
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 't';
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'l';
            }
        }
    }
    printf("\n\nThe Matrix will be:-\n");
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%d%c\t", c[i][j], b[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int i,j;
    printf("Enter 1st string: ");
    scanf("%s", x);
    printf("Enter 2nd string: ");
    scanf("%s", y);
    printf("\nThe contents of the 1st string x is: \n");
    for (int i = 0; i < strlen(x); i++)
    {
        printf("%c\t", x[i]);
    }
    printf("\nThe contents of the 2nd string y is: \n");
    for (int i = 0; i < strlen(y); i++)
    {
        printf("%c\t", y[i]);
    }
    LCS(x, y);
    printf("\nLength of LCS: %d\n", c[m][n]);
    printf("The longest subsequence is: ");
    print_lcs(m, n);
    return 0;
}
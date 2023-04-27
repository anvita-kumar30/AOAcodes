#include <stdio.h>
#include <string.h>
int adj[100][100], mincost = 0, min, parent[9];
void input(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("Enter element in [%d][%d]: ", i, j);
            scanf("%d", &adj[i][j]);
        }
    }
}
void display(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d\t", adj[i][j]);
        }
        printf("\n");
    }
}
int find(int i)
{
    while (parent[i])
        i = parent[i];
    return i;
}
int uni(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}
void kruskal(int n)
{
    int i, j, k, a, b, u, v, ne = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (adj[i][j] == 0)
            {
                adj[i][j] = 999;
            }
        }
    }
    while (ne < n)
    {
        for (i = 1, min = 999; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (adj[i][j] < min)
                {
                    min = adj[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v))
        {
            printf("%d edge (%d,%d) =%d\n", ne++, a, b, min);
            mincost += min;
        }
        adj[a][b] = adj[b][a] = 999;
    }
    printf("\nMinimum cost = %d\n", mincost);
}
void main()
{
    int nodes;
    printf("Enter number of vertices: ");
    scanf("%d", &nodes);
    input(nodes);
    display(nodes);
    kruskal(nodes);
}
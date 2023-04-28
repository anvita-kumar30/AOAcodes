#include <stdio.h>
int m,n;
float x[10];
struct knaps
{
	int w, p, obj_no;
	float pw;
};

struct knaps arr[10];

void sortks()
{
    int i, j;
    struct knaps temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < (n - 1 -i); j++)
        {
            if (arr[j].pw < arr[j + 1].pw)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            } 
        }
    }
} 
int greedyknapsack()
{
	int i, rem_cap, profit=0;
	for(i=0; i<n; i++)
		x[i]=0;
	rem_cap=m;
	for(i=0; i<n; i++)
	{
		if(arr[i].w > rem_cap)
			break;
		x[arr[i].obj_no-1] = 1;
		profit = profit + arr[i].p;
		rem_cap = rem_cap - arr[i].w;	
	}	
	if(i<=n)
	{
		x[arr[i].obj_no-1]=(float)(rem_cap)/(float)(arr[i].w);
		profit = profit + x[arr[i].obj_no-1]*(arr[i].p);
	}	
	return profit;	
}
int main()
{
	int i,value;
	printf("Enter knapsack capacity: ");
	scanf("%d",&m);
	printf("Enter the number of objects: ");
	scanf("%d",&n);
	printf("\nEnter Weights:\n");
	for(i=0; i<n; i++)
	{
		printf("Enter weight of object %d: ", i+1);
		scanf("%d", &arr[i].w);
	}
	printf("\nEnter Profits:\n");
	for(i=0; i<n; i++)
	{
		printf("Enter profit of object %d: ", i+1);
		scanf("%d", &arr[i].p);
	}
	for(i=0; i<n; i++)
		arr[i].obj_no = i+1;
	for(i=0; i<n; i++)
	{
		arr[i].pw = (float)(arr[i].p)/(float)(arr[i].w);
	}
	printf("\nCalculating Ratio");
	printf("\nObject\tWeight\t\tProfit\t\tRatio\n");
	for(i=0; i<n; i++)
	{
		printf("%d\t%d\t\t%d\t\t%f\n",arr[i].obj_no,arr[i].w,arr[i].p,arr[i].pw);
	}
	sortks();
	printf("\nAfter sorting");
	printf("\nObject\tWeight\t\tProfit\t\tRatio\n");
	for(i=0; i<n; i++)
	{
		printf("%d\t%d\t\t%d\t\t%f\n",arr[i].obj_no,arr[i].w,arr[i].p,arr[i].pw);
	}
	value=greedyknapsack();
    printf("\nSolution Vector=[");
	for(i=0; i<n; i++)
		printf("%0.2f\t",x[i]);
    printf("\b\b\b\b\b]");
	printf("\nTotal Profit= %d", value);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
float caltotalprofit(int n,int profit[],int weight[],int c);
float fractionalknapsack(int n,int profit[],int weight[],int c);
int boundedknapsack(int n,int profit[],int weight[],int c);
int max(int a ,int b);
int main() 
{
	int n,c,ch,tp1;
	printf("\nEnter the no of items: ");
	scanf("%d",&n);
	int i,profit[n],weight[n];
	float tp;
	for(i=0;i<n;i++)
	{
		printf("Enter profit and weight for item %d: ",(i+1));
		scanf("%d",&profit[i]);
		scanf("%d",&weight[i]);
	}
	printf("\nEnter the capacity of knapsack: ");
	scanf("%d",&c);
	while(1)
	{
		printf("\n\t1-fractional knapsack\n\t2-0/1 knapsack\n\t3-which is better\n\t4-EXIT");
		printf("\nplease,Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				tp=fractionalknapsack(n,profit,weight,c);
				printf("\nTOTAL PROFIT EARN BY FRACTIONAL KNAPSACK IS %.2f:",tp);
				break;
			case 2:
				tp1=boundedknapsack(n,profit,weight,c);
				printf("\nTOTAL PROFIT EARN BT 0/1 KNAPSACK BY DYNAMICK PROGRAMING: %d",tp1);
				break;
			case 3:
				if(tp>(float)tp1)
				   printf("\nFractional knapsack is better");
				else if(tp<(float)tp1)
				   printf("\nbounded knapsack is better");
				else
				   printf("\nBoth are equal");
				   
				break;
			case 4:
				printf("\nTHANK YOU!!!");
				return 0;
			default:
				printf("\nPlease Enter the correct choice: ");
		}
	}
	
}
float fractionalknapsack(int n,int profit[],int weight[],int c)
{
	int i,j,ch;
	float ratio[n],tp;
	for(i=0;i<n;i++)
	{
		ratio[i]=(float)profit[i]/weight[i];
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(ratio[j]<ratio[j+1])
			{
				float temp;
				temp=ratio[j];
				ratio[j]=ratio[j+1];
				ratio[j+1]=temp;
				
				int temp1;
				temp1=profit[j];
				profit[j]=profit[j+1];
				profit[j+1]=temp1;
				
				temp1=weight[j];
				weight[j]=weight[j+1];
				weight[j+1]=temp1;
			}
		}
	}
	tp=caltotalprofit(n,profit,weight,c);
	return tp;
}
float caltotalprofit(int n,int profit[],int weight[],int c)
{
	
	int i,flag=0;
	float tp=0.0;
	for(i=0;i<n;i++)
	{
		if(weight[i]>c)
		{
			break;
		}
		else
		{
			tp+=profit[i];
			c-=weight[i];
		}
	}

		if(i<n)
		    tp+=(float)c/weight[i]*profit[i];
	return tp;
}

int boundedknapsack(int n,int profit[],int weight[],int c)
{
	if(n==0 || c== 0)
	    return 0;
	if(weight[n-1]>c)
	    return boundedknapsack(n-1,profit,weight,c);
	else
	    return max(profit[n-1]+boundedknapsack(n-1,profit,weight,c-weight[n-1]),boundedknapsack(n-1,profit,weight,c));
}

int max(int a ,int b)
{
	return (a>b)?a:b;
}

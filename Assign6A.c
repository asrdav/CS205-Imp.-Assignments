//To find the minimum no. of coins required to make given amount and also the no. of coins of particular denomination.
#include<stdio.h>
#define INF ((int)1e+6)
#define max(a,b) ((a)>(b)?a:b)
#define min(a,b) ((a)<(b)?a:b)

int main()
{
	int n,i=0,j,sum,max1=0,k=0;
	printf("Enter sum->");
	scanf("%d",&sum);	//sum is amount of money required.

	int denom[sum+1][501];		//denom array is made to store no. of coins of different denominations.

	printf("Enter n->");
	scanf("%d",&n);			//n is no. of coins of different denominations.

	int val[1000];			//val array is to store the value of denominations.
	while(i<n)		//while loop is to store the given data.
	{
	scanf("%d",&val[i]);
	max1=max(max1,val[i]);
	i++;
	}

	int result[sum+1];		//result array is to store the minimum no. of coins required for variable sum.
	result[0]=0;
	
	int temp;	
	
	for(i=1;i<=sum;i++)		//nested loop for filling entries of result array.
	{	

	temp=INF;
	for(j=0;j<n;j++)
	{
	if(val[j]<=i && result[i-val[j]]+1<temp)
	{
	temp=result[i-val[j]]+1;

	for(k=0;k<=min(i,max1);k++)
	denom[i][k]=0;	

	for(k=0;k<=min(i-val[j],max1);k++)		//for loop is to fill the entries of 2D array for given variable sum.
	denom[i][k]=denom[i-val[j]][k];
	denom[i][val[j]]+=1;
	}

	}
	result[i]=temp;			
	}

	if(result[sum]==INF)
	printf("Denomination can't be made.");
	
	else
	{
	printf("The minimum no. of coins required is %d\n",result[sum]);
	printf("Following coins are needed->\n");
	for(i=0;i<=min(max1,sum);i++)		//for loop made for printing the no. of coins required of different denomination.
	{
	if(denom[sum][i]==0)
	continue;
	printf("%d coins are needed of denomination %d\n",denom[sum][i],i);
	}
	}

return 0;
}

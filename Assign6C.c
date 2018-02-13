//To find 2 sets such that the difference between sets is minimum and also print the elements in the sets.
#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#define min(a,b) ((a)<(b)?a:b)
#define max(a,b) ((a)>(b)?a:b)
#define INF (int)1e+7

int arr[1000];			//arr is made to store the numbers.
bool cond[1000]={false};	//cond array is made to print the required elements.
int table[1001][10001],x;	//2D table array is made to find minimum difference.


void print(int index[],int j)		//print array is made to separate the elements in the sets.
{
	int i;
	for(i=0;i<x;i++)
	cond[i]=false;

	for(i=0;i<=j;i++)		//for loop is used to separate element in set1 from set2.
	cond[index[i]]=true;
}


void print_set(int tmp,int sum_temp,int index[],int j)		//print_set function is made to find the required elements.
{
	int *p;

	if(tmp==1&&sum_temp!=0&&table[1][sum_temp]==1)		//base condition 1 of recursion.
	{
	index[++j]=tmp-1;
	print(index,j);
	return ;
	}

	if(tmp==1&&sum_temp==0)			//base condition 2 of recursion.
	{
	print(index,j);
	return ;
	}

	if(table[tmp-1][sum_temp]==1)		//if current element is excluded.
	{
	p=index;
	print_set(tmp-1,sum_temp,p,j);		//print_set function recursively called.
	}

	if(arr[tmp-1]<=sum_temp&&table[tmp-1][sum_temp-arr[tmp-1]]==1)		//if current element is included.
	{
	index[++j]=tmp-1;
	print_set(tmp-1,sum_temp-arr[tmp-1],index,j);		//print_set function recursively called.	
	}
}
	

int main()
{
	int i,arr_sum=0,j,result=INF,n,k,y=0;
	int index[1001];		//index array is to store the indexes of elements in set1.
	printf("Enter n->");
	scanf("%d",&n);			//n is no. of numbers entered.

	i=0;
	while(i<n)		
	{
	scanf("%d",&arr[i]);
	arr_sum+=arr[i];		//arr_sum is the sum of all the numbers.
	i++;
	}

	for(i=0;i<=n;i++)
	table[i][0]=1;

	for(i=1;i<=arr_sum;i++)
	table[0][i]=0;

	for(i=1;i<=n;i++)			//for loop is for filling all positions of table.
	{
		for(j=1;j<=arr_sum;j++)
		{
			table[i][j]=table[i-1][j];
			if(arr[i-1]<=j)
			table[i][j]=table[i][j]||table[i-1][j-arr[i-1]];		
		}
	}

	for(i=(arr_sum)/2;i>=0;i--)		//for loop is used for finding the minimum difference.
	{
		if(table[n][i]==1)
		{
		k=i;
		printf("The minimum difference is->%d\n",arr_sum-2*i);
		break;
		}
	}

	for(i=1;i<=n;i++)		
	{
	if(table[i][k]==1)
	break;
	}	
	
	int sum_temp=k;
	k=i;
	x=i;
	print_set(k,sum_temp,index,-1);		//print_set function called.

	printf("The elements in set1 are->\n");
	for(i=0;i<k;i++)		//for loop for printing elements in set1.
	{
	if(cond[i]==false)
	continue;
	else
	{
	y++;
	printf("%d ",arr[i]);
	}

	}
	if(y==0)
	printf("None");
	printf("\n");

	printf("The elements in set2 are->\n");
	for(i=0;i<n;i++)		///for loop for printing elements in set2.
	{
	if(cond[i]==true)
	continue;
	else
	printf("%d ",arr[i]);
	}

	if(y==n)
	printf("None");
				
return 0;	
}

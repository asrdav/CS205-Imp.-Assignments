//To finalize a list of disjoint pairs with difference between pairs smaller than a particular no. such that the sum of all pairs is maximum.
#include<stdio.h>
#include<stdlib.h>

int arr[10000];		//arr array has been made to store the numbers.

void swap(int tmp1,int tmp2)		//swap function is made to do the required swapping.
{
	int t;
	t=arr[tmp1];
	arr[tmp1]=arr[tmp2];
	arr[tmp2]=t;
}

int partition(int st,int la)
{
	int temp1,j,i;
	temp1=st+rand()%(la+1-st);		//rand function used to perform partition through random pivot.
	swap(temp1,la);

i=st-1;
	for(j=st;j<la;j++)		//for loop for calculating partition index.
	{
		if(arr[j]<=arr[la])
		{
		i++;
		swap(i,j);		//swap function called.
		}
	}
	swap(i+1,la);			//swap function called.
return (i+1);
}

void quick_sort(int begin,int end)		//quick_sort function made to sort the function.
{
	if(begin<end)
	{
	int p=partition(begin,end);			//partition function called.
	quick_sort(begin,p-1);			//quick_sort function recursively called.
	quick_sort(p+1,end);				//quick_sort function recursively called.
	}	
}

int main()
{
        int n,m;
        printf("Enter n->");		//n is no. of numbers taken.
        scanf("%d",&n);
        printf("Enter the numbers->");	
        int i=0;

        while(i<n)
        {
        scanf("%d",&arr[i]);
        i++;
        }

        printf("Enter m->");		//m is the upper limit of the difference of pairs.
        scanf("%d",&m);

	quick_sort(0,n-1);		//quick_sort function called.

	if(i<2)
	{
	printf("Error!!!Enter 2 or more than 2 numbers.");
	return 0;
	}

	int dp[n];		//dp array has been made to store max required sum for n elements.
	int cond[n][arr[n-1]+1];		//cond 2D array has been made to store numbers included in final list.

	for(i=0;i<=arr[n-1];i++)
	cond[0][i]=0;

	dp[0]=0;

	for(i=1;i<n;i++)
	{
	dp[i]=dp[i-1];		//max sum for i elements for which pair with i-1 element has not been made.
	for(int j=0;j<arr[n-1]+1;j++)
	cond[i][j]=cond[i-1][j];

	if(arr[i]-arr[i-1]<=m)
	{
		if(i>=2)
		{
		if(dp[i-2]+arr[i]+arr[i-1]>dp[i])	//if block for including ith & (i-1)th pair if pair can be made.
		{
		dp[i]=dp[i-2]+arr[i]+arr[i-1];
		for(int j=0;j<arr[n-1]+1;j++)
		cond[i][j]=cond[i-2][j];

		cond[i][arr[i]]++;
		cond[i][arr[i-1]]++;
		}
		}

		else
		{
			if(arr[i]+arr[i-1]>dp[i])
			{
			dp[i]=arr[i]+arr[i-1];
			cond[i][arr[i]]++;
			cond[i][arr[i-1]]++;
			}
		}
	}
	
	}

	int k=0,x,y;	//k,x and y are intermediate variables.
	int count_pairs=1;
	
	for(i=0;i<arr[n-1]+1;i++)
	{
	if(cond[n-1][i]==0)
	{
	k++;
	continue;
	}
	}

	if(k==arr[n-1]+1)
	printf("There are no valid pairs.Enter valid numbers.");
	else
	printf("The pairs that make the maximum sum are->\n");

	k=0;
	for(int j=0;j<arr[n-1]+1;j++)
	{
	if(cond[n-1][j]==0)
	continue;

	if(cond[n-1][j]!=0&&k==0)
	{
	x=j;
	k++;
	}

	else if(cond[n-1][j]!=0&&k!=0)
	{
	y=j;
	k=0;
	printf("Pair(%d): %d,%d\n",count_pairs,x,y);
	count_pairs++;
	}
	}	

return 0;
}

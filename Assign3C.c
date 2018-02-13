//To find the maximum sub-array sum.
#include<stdio.h>
#define max(a,b) ((a)>(b)?a:b)
#define min(a,b) ((a)<(b)?a:b)

long num[100005],sum1,sum2,sum3,sum4;	//num array is declared globally to store the numbers.


long max_sum(int start,int last)		//max_sum function is made to find the required sum.
{

	if(last<start)		
	return 0;

	if(last-start==0)	//if else-if block is made to terminate the recursion.
	{
	sum1= num[start];	
	return sum1;
	}

	else if(last-start==1)
	{
	sum1= (max(max(num[start],num[last]),num[start]+num[last]));
	return sum1;
	}
					//sum4 is the maximum required sum of left and right subarray.				
		
	sum4=max(max_sum(start,start+(last-start)/2),max_sum(start+(last-start)/2+1,last));	//max_sum function recursively called.

	sum3=num[(last-start)/2] + num[(last-start)/2+1];		//sum3 is required combined sum of left and right subarray. 
	int i,j;		
	i=(last-start)/2-1;
	j=(last-start)/2+2;	

while(i>=start)				//while loop made to decode the req. left side sum of required combined sum.
{
	while(num[i]>=0)
	{
	sum3+=num[i];
	i--;
	if(i<start)	break;
	}
	
	sum2=0;
	while(i>=start&&num[i]<0)
	{
	sum2+=num[i];
	i--;
	}
	
	if(i>=start)
	{
	if(num[i]>sum2)
	sum3+=num[i]+sum2;
	else
	break;
	}
	i--;
}
	

while(j<=last)				//while loop made to decode the req. right side sum of req. combined sum.
{
	while(num[j]>=0)
	{
	sum3+=num[j];
	j++;
	if(j>last)	break;
	}
	
	sum2=0;
	while(j<=last&&num[j]<0)
	{
	sum2+=num[j];
	j++;
	}
	
	if(j<=last)
	{
	if(num[j]>sum2)
	sum3+=num[j]+sum2;
	else
	break;
	}
	j++;
}
	return max(sum3,sum4);		//req. max sum is returned.
}



int main()
{
	int n;		//n is no. of inputs given.
	long sum;	//sum is required sum to be printed.
	printf("Enter the no. of inputs->");
	scanf("%d",&n);
	int i=0;

	while(i<n)
	{
	scanf("%ld",&num[i]);
	i++;
	}

sum=max_sum(0,n-1);		//max_sum function called.

	printf("Maximum sub-array sum->%ld",sum);
return 0;
}

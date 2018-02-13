//To make a recursive routine using a recursive routine for finding max-min.
#include<stdio.h>
#include<stdlib.h>

int num[100005];		//num array declared globally to store the numbers.

struct find			//find structure made to store max-min.
{
	int mx;
	int mn;
};

struct find m;

void max_min(int begin,int end)		//max_min function made to store max at start and min at end of the array.
{
	int mx1,mn1,mx2,mn2;

	if(end>=begin)			//if-else if-block made to terminate the recursion.
	{
	if(end==begin)
	m.mx=m.mn=begin;

	else if(end-begin==1)
	{
	m.mx=(num[begin]>=num[end])?begin:end;
	m.mn=(num[begin]>=num[end])?end:begin;
	}

	else			//else block made to do the recursion.
	{
	max_min(begin,begin+(end-begin)/2);		//max_min function recursively called.
	mx1=m.mx;
	mn1=m.mn;
	max_min(begin+1+(end-begin)/2,end);		//max_min function recursively called.
	mx2=m.mx;
	mn2=m.mn;
	m.mx=(num[mx1]>=num[mx2])?mx1:mx2;
	m.mn=(num[mn1]>=num[mn2])?mn2:mn1;
	}
	}
}


	
void swap(int *a,int *b)		//swap function made to swap the numbers.
{
	int t=*a;
	*a=*b;
	*b=t;
}	


void sort(int start,int last)		//sort function made to sort the array while keeping max at start and min at end.
{
	if(start<=last)			//if block made to take all possible cases.
	{
	max_min(start,last);		//max_min function called.

	if(num[last]==num[m.mx]&&num[start]==num[m.mn])
	swap(&num[start],&num[last]);			//swap function called.
	
	else if(num[last]==num[m.mx])
	{
	swap(&num[start],&num[last]);			//swap function called.
	swap(&num[m.mn],&num[last]);			//swap function called.
	}	

	else if(num[start]==num[m.mn])
	{
	swap(&num[last],&num[start]);			//swap function called.
	swap(&num[start],&num[m.mx]);			//swap function called.
	}

	else
	{
	swap(&num[start],&num[m.mx]);			//swap function called.
	swap(&num[last],&num[m.mn]);			//swap function called.
	}
	
	sort(start+1,last-1);			//sort function recursively called.
	}
}


int main()
{
	int n;			//n is the number of inputs given.
	printf("Enter no. of inputs to be given->");
	scanf("%d",&n);
	int i=0;

	while(i<n)		//while loop made to take the numbers as input.
	{
	scanf("%d",&num[i]);
	i++;
	}
	
sort(0,n-1);		//sort function called.

	printf("The sorted list->\n");

	for(i=n-1;i>=0;i--)			//for loop used to print the numbers in sorted form.
	printf("%d ",num[i]);

printf("\nMax->%d",num[0]);
printf("\nMin->%d",num[n-1]);	

return 0;
}

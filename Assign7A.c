//To determine ith order statistics in worst case linear time.
#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 9999


void swap(int *a,int *b)	//swap function has been created to swap 2 numbers.
{
	int t=*a;
	*a=*b;
	*b=t;
}


int partition(int arr[],int st,int la,int pivot)	//partition function has been created to partition the array as in quicksort.
{
	int i;
	for(i=st;i<=la;i++)
	{
	if(arr[i]==pivot)
	break;
	}
swap(&arr[i],&arr[la]);		//swap function called.
	i=st-1;
	for(int j=st;j<la;j++)
	{
		if(arr[j]<=arr[la])
		{
		i++;
		swap(&arr[j],&arr[i]);		//swap function called.
		}
	}
swap(&arr[i+1],&arr[la]);		//swap function called.
return (i+1);
}		


int ins_sort(int arr[],int st,int la)		//ins_sort function has been made to carry out insertion sort.
{						
	for(int i=st+1;i<la;i++)
	{
	int key=arr[i];
	int j=i-1;
	while(j>=0&&arr[j]>key)		
	{
	arr[j+1]=arr[j];
	j--;
	}
	arr[j+1]=key;
	}
return arr[st+(la-st)/2];
}


int r_select(int arr[],int begin,int end,int req)		//r_select function has been made to return the kth smallest number.
{
	if(req>0&&req<=end-begin+1)
	{

	int i,temp[1000],k=0;		//temp array has been made to store medians of the groups made.
	for(i=begin;i<=end;i=i+5)	//for loop made to divide elements into group of 5 and sort them.
	{
	if(i+4<=end)
	temp[k]=ins_sort(arr,i,i+5);		//ins_sort function called.
	else
	temp[k]=ins_sort(arr,i,end+1);		//ins_sort function called.
	k++;
	}
	
	int j,p;
	if(k>1)
	j=r_select(temp,0,k-1,k/2);		//r_select function recursively called.
	
	else if(k==1)
	j=temp[k-1];

	p=partition(arr,begin,end,j);		//partition function called to partition the array on basis of pivot.

	if(req==p-begin+1)		//base condition of recursion.
	return arr[p];
	else if(req<p-begin+1)
	return r_select(arr,begin,p-1,req);		//r_select function recursively called.
	else
	return r_select(arr,p+1,end,req-(p-begin+1));		//r_select function recursively called.
	}

	else
	return INT_MAX;	
}


int main()
{
	int n,i=0,arr[10000];		//arr array has been made to store the given numbers.
	printf("Enter n->");		//n is no. of numbers given.
	scanf("%d",&n);

	printf("Enter the numbers->");
	while(i<n)
	{
	scanf("%d",&arr[i]);
	i++;
	}

int k;
	printf("Enter k->");		//k is position of the element to be found.
	scanf("%d",&k);
						//r_select function called.
int req_element=r_select(arr,0,n-1,k);		//req_element is the required element.

	if(req_element==INT_MAX)
	printf("Please,Enter valid k next time.");
	else	
	printf("The required element is->%d",req_element);
return 0;
}

//To implement search in sorted array by splitting the input into three sets of equal sizes.
#include<stdio.h>

int num1[100005];		//num1 array made to store the numbers.

        int n,k,find_num;


void swap(int *a,int *b)		//swap function made to swap the numbers.
{
        int t;
        t=*a;
        *a=*b;
        *b=t;
}

int partition(int low,int high)			//partition function made to partition the array for quick sort.
{
        int i,j;
        i=low;
	j=high+1;

	while(1)			//while loop to create partition.
	{
	while(num1[++i]<=num1[low])
	if(i==high)	break;

	while(num1[--j]>num1[low])
	if(j==low)	break;
	
	if(i>=j)break;
	swap(&num1[i],&num1[j]);		//swap function called.
	}
swap(&num1[low],&num1[j]);		//swap function called.
	
     return j;
}


void quick_sort(int start,int last)		//quick_sort function made to sort the array.
{
        if(start<last)
        {
        int p=partition(start,last);
    	quick_sort(start,p-1);			//quick_sort function recursively called.
        quick_sort(p+1,last);			//quick_sort function recursively called.
        }
}


int search(int begin,int end)		//search function made to search the given no.
{
	if(begin>end)		
	return -1;

	else			
	{
	int mid1=begin+(end-begin)/3;		//mid1 is the end of the first interval.
	int mid2=begin+2*(end-begin)/3;		//mid2 is the end of the second interval.

	if(find_num==num1[mid1]||find_num==num1[mid2])	//if block to terminate recursion.		
	return (find_num==num1[mid1])?mid1:mid2;

	else if(find_num<num1[mid1])
	return search(begin,mid1-1);		//search function recursively called.

	else if(find_num>num1[mid1]&&find_num<num1[mid2])
	return search(mid1+1,mid2-1);		//search function recursively called.

	else if(find_num>num1[mid2])
	return search(mid2+1,end);		//search function recursively called.

	}
		 	
}	


int main()
{
        printf("Enter no. of inputs->");
        scanf("%d",&n);		//n is no. of inputs given.
        int i=0,x;
        while(i<n)		//while loop made to store the numbers in num1 array.
        {
        scanf("%d",&x);
        num1[i]=x;
        i++;
        }

quick_sort(0,n-1);		//quick_sort function called.
printf("Sorted list->\n");

	for(i=0;i<n;i++)	//for loop made to print the sorted array.
	printf("%d ",num1[i]);
	printf("\n");

printf("Enter no. to be searched->");
scanf("%d",&find_num);			//find_num is no. to be searched.
	
k=search(0,n-1);		//search function called.

        if(k!=-1)		//if-else block made to print the final message.
        printf("Data found and is at index %d.",k);
        else
        printf("Data not found.");
return 0;
}

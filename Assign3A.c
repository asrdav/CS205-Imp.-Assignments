//To recursively randomly select a number and then divide the array as per required condition and then find the median.
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int num[100005];		//num array is used to store the numbers.
int n;				//n is the no. of inputs given.

void swap(int *a,int *b)	//swap function used to swap the numbers.
{
        int t=*a;
        *a=*b;
        *b=t;
}


int find_median(int index,int start,int last)		//find_median function is made to find the median.
{
						//index is the index of randomly selected number.
        int i=start,j=last;
        int y;
        while(1)		//while loop used to divide the array on basis of number chosen.
        {
        while(i<=last&&i!=index&&num[i]<=num[index])
        i++;

        while(j>=start&&j!=index&&num[j]>num[index])
        j--;

        if(i>=j)	break;
	if(i==index)
	index=j;
	else if(j==index)
	index=i;

        swap(&num[i],&num[j]);			//swap function called.
        }

if(index==(n+1)/2-1)			//base condition of recursion.
        y=num[index];

else if(index<(n+1)/2-1)
        y=find_median(index+1+rand()%(last-index),index+1,last);		//recursive call to function made.

else
        y=find_median(start+rand()%(index-start),start,index-1);		//recursive call to function made.

return y;
}



int main()
{
        int randomIndex;
	printf("Enter no. of inputs->");
        scanf("%d",&n);
        int i=0;

        while(i<n)
        {
        scanf("%d",&num[i]);
        i++;
        }

srand(time(NULL));		

        randomIndex=rand()%n;		//random index generated.
        int median=find_median(randomIndex,0,n-1);		//find_median function called.

	printf("The final array->\n");

	for(i=0;i<n;i++)
	printf("%d ",num[i]);

printf("\nMedian->%d",median);

return 0;
}

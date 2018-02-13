//To find the minimum no. of steps to reduce the number to 1.
#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 9999
#define min(a,b) ((a)<(b)?a:b)          //min has been defined to find the minimum.

int arr_step[10001];			//arr_step array has been declared to perform dp approach.

int min_steps(int n)             //min_steps function has been defined to find the minimum no. of steps.
{
	if(arr_step[n]!=INT_MAX)	//base condition of recursion.
	return arr_step[n];
								//ternary operator used.
        int steps1 =  (n%7==0)?1+min_steps(n/7):INT_MAX;          

        int steps2 =  (n%5==0)?1+min_steps(n/5):INT_MAX;    

        int steps3 =  (n%3==0)?1+min_steps(n/3):INT_MAX;       

        int steps4 =  (n%2==0)?1+min_steps(n/2):INT_MAX;        

        int steps5 =  1+min_steps(n-1);                

       	arr_step[n]= min(min(min(steps1,steps2),min(steps3,steps4)),steps5);
	return arr_step[n];
}


int main()
{
        int n,i;
        printf("Enter the number->");
        scanf("%d",&n);
	
	if(n==0)
	{
	printf("Error!!!Enter number greater than or equal to 1.");
	return 0;
	}
	for(i=0;i<=n;i++)
	arr_step[i]=INT_MAX;	
	arr_step[1]=0;

        int steps=min_steps(n);               //steps is required no. of minimum steps.

printf("The required minimum steps are->%d",steps);
return 0;
}


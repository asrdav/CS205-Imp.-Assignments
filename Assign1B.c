//To find max. no. of chocolates Shanaya can take from non-consecutive boxes out of N boxes and to find max. digit in the answer recursively.
#include<stdio.h>
#define max(a,b) ((a)>(b)?a:b)	//define macros used to define max.

int max1=0;		//max1 declared globally to access everywhere without any problem.


void largeDigit(int x)			//largeDigit function made to find the max. digit in max. chocolates Shanaya will get.
	{
	max1=max(max1,x%10);
	x=x/10;
	if(x!=0)
	largeDigit(x);		//recursive call made to largeDigit function.
	}


int main()
{	
	int n,i=0;		//n is no. of boxes.
	int b[1000];		//b array is made to take the boxes as input.
	scanf("%d",&n);
	int sum1=0,sum2,sum3;	//sum1 is the sum without the current variable.
					//sum2 is intermediate variable made to prevent any loss of possibilities.
						//sum3 is the sum also taking the current variable.

	while(i<n)
	{
	scanf("%d",&b[i]);
	i++;
	}

	sum3=b[0];		//initiating the sum3 variable.
	i=1;

	while(i<n)		//while loop initiated to find max. no. of chocolates Shanaya can take.
	{	
	sum2=max(sum1,sum3);
	sum3=sum1+b[i];
	sum1=sum2;
	i++;
	}
	
	largeDigit(max(sum1,sum3));		//largeDigit function called.
	
printf("%d\n%d",max(sum1,sum3),max1);
return 0;
}

//To find recursive sum of a given no.
#include<stdio.h>
#include<math.h>

long long sum[100005]={},i=0;		//sum array declared globally and initialized with 0 and to store the sum.

void rec_sum(long long y)		//rec_sum function made to find the recursive sum.
{
        if(y==0)		//if block made to erminate the recursion.
        return ;

        int z=y%10;
        sum[i]=sum[i]+z;
        y=y/10;
        rec_sum(y);		//rec_sum recursively called.
}


int main()
{
        long long n;			//n is the no. entered.
        printf("Enter a number->");
        scanf("%lld",&n);

        n=fabs(n);		//fabs function used in case the no. is negative.

        sum[0]=n;

        while(sum[i]>9)		//while loop made to call rec_sum function for no. greater than 9.
        {
        i++;
        rec_sum(sum[i-1]);		//rec_sum function called.
        }

long long j=0;

        while(j<=i)		//while loop made to print the recursive sum of the numbers.
        {
        (j==i)?printf("%lld",sum[j]):printf("%lld->",sum[j]);
        j++;
        }
return 0;
}

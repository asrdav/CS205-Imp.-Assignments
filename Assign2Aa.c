//To count no.of odd digits in a given no.
#include<stdio.h>
#include<math.h>

int x=0;	//x is count of odd digits in the no.

void count_odd(long long y)	//count_odd function is made to count the no. of odd digits.
        {
        if(y==0)
        return ;
        int z=y%10;
        if(z%2!=0)		//if-block for checking no. is odd or even.
        x++;
        y=y/10;
        count_odd(y);		//recursive call made to count_odd function.
        }

int main()
{
        long long n;	//n is the given no.
        printf("Enter a number->");
        scanf("%lld",&n);

        n=fabs(n);	//fabs function used in case no. is negative.

        if(n!=0)
        count_odd(n);		//count_odd function called.
        printf("%d",x);
        return 0;
}

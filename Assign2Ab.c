//To find the largest and smallest digit in a given no.
#include<stdio.h>
#include<math.h>
#define max(a,b) ((a)>(b)?a:b)		//define macros used to find max of 2 no.'s easily.
#define min(a,b) ((a)<(b)?a:b)		//define macros used to find min of 2 no.'s easily.


int max1=0,min1=0;	

void count_min_max(long long y)		//count_min_max function called to find maximum and minimum of a given no.
        {
        if(y==0)
        return ;

        int z=y%10;

        max1=max(z,max1);		//max used to find max.
        min1=min(z,min1);		//min used to find min.

        y=y/10;
        count_min_max(y);		//count_min_max function recursively called.
        }


int main()
{
        long long n;			//n is the given number.
        printf("Enter a number->");
        scanf("%lld",&n);

        n=fabs(n);		//fabs function used in case no. is negative.

        min1=max1=n%10;		//max1,min1 variable initialized.

        if(n==0)		//if-else block to consider different cases.
        min1=max1=0;
        else
        count_min_max(n/10);		//count_min_max function called.

        printf("Min->%d\nMax->%d",min1,max1);
        return 0;
}

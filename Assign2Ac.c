//To find binary equivalent of a given no.
#include<stdio.h>
#include<math.h>
#define size ((int)1e+7)	//define macros used to convert long integer to integer.

int num[size]={};		//num array declared and initialized globally.
long i=0;

void binary_equ(long long y)		//binary_equ function called to find binary equivalent of the no.
{
        if(y==0)
        return ;

        int z=y%2;
        num[i]=z;
        y=y/2;
        i++;

        binary_equ(y);		//binary_equ function recursively called.
}


int main()
{
        long long n;		//n is no. entered.

        printf("Enter a number->");
        scanf("%lld",&n);

        n=fabs(n);		//fabs function used in case no. is negative.
        if(n!=0)
        binary_equ(n);		//binary_equ function called.
        long j;
        printf("Binary equivalent of a number->\n");

        if(n==0)
        printf("0");
        else
        {
        for(j=i-1;j>=0;j--)		//for loop used to print the binary equivalent of the no.
        printf("%d",num[j]);
        }

return 0;
}

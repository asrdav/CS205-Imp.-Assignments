//To follow the given sequence and print the values at all operations performed and also the no. operations performed and also required error message.
#include<stdio.h>

int j=0;

void sequence(long long n)		//sequence function made to recursively follow the sequence.
{
        if(n==1)			//if block made to terminate the recursion.
        {
        printf("Final value->%lld\n",n);
        return ;
        }
        else if(n%2==0)
        {
        j++;
        printf("Next value is %lld\n",n);
        sequence(n/2);			//sequence function recursively called.
        }
        else
        {
        j++;
        printf("Next value is %lld\n",n);
        sequence(3*n+1);		//sequence function recursively called.
        }
}

int main()
{
        long long n;
        printf("Enter a number->");
        scanf("%lld",&n);			//n is no. entered.

        printf("Initial value is %lld\n",n);

	if(n<1)				//if block made to print the required message at proper condition.
	{
	printf("Error\n");
	return 0;
	}

        if(n!=1)
        {
        if(n%2==0)
        sequence(n/2);			//sequence function called.
        else
        sequence(3*n+1);		//sequence function called.
        j++;
        printf("Operations performed->%d",j);

        }
        else
        printf("Final value is same as initial value.\nOperations performed->0");

return 0;
}
      

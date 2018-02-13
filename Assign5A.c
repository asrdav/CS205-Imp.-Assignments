//To measure the performance of quick sort choosing differnet pivots and sorting different arrangement of arrays.
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

long *arr,n;			//arr is pointer made to store the numbers upto n.
					// n is the no. for which time is calculated.


long median(long temp1,long temp2,long temp3)		//median function is made to find median if pivot_type is 2 or 3.
{
	if((arr[temp1]>=arr[temp2]&&arr[temp1]<=arr[temp3])||(arr[temp1]>=arr[temp3]&&arr[temp1]<=arr[temp2]))
	return temp1;
	else if((arr[temp2]>=arr[temp1]&&arr[temp2]<=arr[temp3])||(arr[temp2]>=arr[temp3]&&arr[temp2]<=arr[temp1]))
	return temp2;
	else
	return temp3;
}

void swap(long tmp1,long tmp2)		//swap function is made to do the required swapping.
{
	long t;
	t=arr[tmp1];
	arr[tmp1]=arr[tmp2];
	arr[tmp2]=t;
}


long partition(long st,long la,int pivot_type)		//partition function is made to make partition for quick sort.
{						//st is start index of array and la is last index and pivot_type is required pivot choice.

	long temp1,temp2,i,j,tmp1,tmp2,tmp3,t;

	if(pivot_type==0)		
	swap(st,la);			//swap function called.

	else if(pivot_type==1)
	{
	temp1=st+rand()%(la+1-st);
	swap(temp1,la);		//swap function called.
	}

	else 
	{

	if(pivot_type==2)
	{
	tmp1=st;
	tmp2=st+(la+1-st)/2;
	tmp3=la;
	temp2=median(tmp1,tmp2,tmp3);		//median function called.
	}

	else
	{
	tmp1=st+(la+1-st)/4;
	tmp2=st+(la+1-st)/2;
	tmp3=st+(3*(la+1-st))/4;
	temp2=median(tmp1,tmp2,tmp3);		//median function called.
	}

	swap(temp2,la);			//swap function called.
	}

i=st-1;
	for(j=st;j<la;j++)		//for loop for calculating partition index.
	{
		if(arr[j]<=arr[la])
		{
		i++;
		swap(i,j);		//swap function called.
		}
	}
	swap(i+1,la);			//swap function called.
return (i+1);
}


void quick_sort(long begin,long end,int pivot_type)		//quick_sort function made to sort the function.
{
	if(begin<end)
	{
	long p=partition(begin,end,pivot_type);			//partition function called.
	quick_sort(begin,p-1,pivot_type);			//quick_sort function recursively called.
	quick_sort(p+1,end,pivot_type);				//quick_sort function recursively called.
	}	
}


int main()
{
	double result[16][3];		//result array is made to store the results.
	srand((unsigned int)time(NULL));
	clock_t c1,c2;		//c1 and c2 are used for measuring time spent in quick_sort.
	long rand1,rand2;		//rand1 is 1st random index and rand2 is 2nd random index.
	int i,j;
	long k,t;

printf("Choice:     First(0)       Random(1)       Median of three1(2)       Median of three2(3)\n");

printf("\nn      Choice     Random        Sorted        Almost Sorted\n");

for(i=4;i<=7;i++)		//for loop to take in all te cases.
{
	n=pow(10,i);
	arr=(long *) malloc(n*sizeof(long));		//allocating memory for pointer arr.
	for(j=0;j<=3;j++)			//for loop for considering different pivots.
	{

	for(k=0;k<n;k++)			//for loop for filling array with random elements from 1 to 10^9-1
	arr[k]=rand()%1000000000;		//generating random no.

	c1=clock();			
	quick_sort(0,n-1,j);		//quick_sort function called.
	c2=clock();                             
	result[(i-4)*4+j][0]=(double)(c2-c1)/(double)CLOCKS_PER_SEC;

	if(i<6||(i>=6&&j!=0))
	{
	c1=clock();
	quick_sort(0,n-1,j);		//quick_sort function called.
	c2=clock();
	result[(i-4)*4+j][1]=(double)(c2-c1)/(double)CLOCKS_PER_SEC;
	}
	
	for(k=1;k<=n/100;k++)
	{
	rand1=rand()%n;			//generating randomindex1.
	rand2=rand()%n;			//generating randomindex2. 
	swap(rand1,rand2);		//swap function called.
	}

	
	c1=clock();
	quick_sort(0,n-1,j);		//quick_sort function called.
	c2=clock();
	result[(i-4)*4+j][2]=(double)(c2-c1)/(double)CLOCKS_PER_SEC;
	}
	free(arr);		//freeing the array.
	
}

int z=0;

for(i=0;i<16;i++,z++)		//for loop for printing the required time spent.
{
		if(i<4)
		printf("10000      ");
		else if(i>=4&&i<8)
		printf("100000     ");
		else if(i>=8&&i<12)
		printf("1000000    ");
		else
		printf("10000000   ");

		printf("%d      ",i%4);
		for(j=0;j<=2;j++)
		{
		if((i==8&&j==1)||(i==12&&j==1))
		printf("Too time taking      ");
		else
		printf("%lf      ",result[i][j]);
		}
	printf("\n");
	if(z==3)
	{
	printf("\n");
	z=-1;
	}
}

return 0;
}

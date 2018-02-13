//To write a c program for matrix multiplication using divide and conquer approach.
#include<stdio.h>
#include<stdlib.h>

struct data			//struct data made to access arrays easily.
{
	int arr[100][100];
};

struct data temp1,temp2;		//temp1 and temp2 are global variables made to take the initial arrays as input.

struct data plus(struct data m1,struct data m2,int order)		//plus function made to add the respective elements of matrices.
{
	struct data m;
	int i=0,j=0;
	for(i=0;i<order;i++)		//for loop for adding the matrices.
	{
	for(j=0;j<order;j++)
	m.arr[i][j]=m1.arr[i][j]+m2.arr[i][j];
	}
return m;
}
	

struct data div_conq(int order,int rs,int cs,int rs1,int cs1)		//div_conq function made to divide the matrix into subproblems.
{					//rs and rs1 are starting index of first array and second array resp. and so for cs and cs1.
	struct data m;
	int i,j;
	if(order==2)		//base condition of recursion.
	{
		m.arr[0][0]=temp1.arr[rs][cs]*temp2.arr[rs1][cs1]+temp1.arr[rs][cs+1]*temp2.arr[rs1+1][cs1];
		m.arr[0][1]=temp1.arr[rs][cs]*temp2.arr[rs1][cs1+1]+temp1.arr[rs][cs+1]*temp2.arr[rs1+1][cs1+1];
		m.arr[1][0]=temp1.arr[rs+1][cs]*temp2.arr[rs1][cs1]+temp1.arr[rs+1][cs+1]*temp2.arr[rs1+1][cs1];
		m.arr[1][1]=temp1.arr[rs+1][cs]*temp2.arr[rs1][cs1+1]+temp1.arr[rs+1][cs+1]*temp2.arr[rs1+1][cs1+1];

	return m;
	}

	else		//recursive condition
	{			//respective matrices divided and added.
	struct data m1=plus(div_conq(order/2,rs,cs,rs1,cs1),div_conq(order/2,rs,cs+order/2,rs1+order/2,cs1),order/2);

	struct data m2=plus(div_conq(order/2,rs,cs,rs1,cs1+order/2),div_conq(order/2,rs,cs+order/2,rs1+order/2,cs1+order/2),order/2);

	struct data m3=plus(div_conq(order/2,rs+order/2,cs,rs1,cs1),div_conq(order/2,rs+order/2,cs+order/2,rs1+order/2,cs1),order/2);

	struct data m4=plus(div_conq(order/2,rs+order/2,cs,rs1,cs1+order/2),div_conq(order/2,rs+order/2,cs+order/2,rs1+order/2,cs1+order/2),order/2);
					//for loop made to create sublocks of final array.
	for(i=0;i<order/2;i++)	
	{
	for(j=0;j<order/2;j++)
	m.arr[i][j]=m1.arr[i][j];
	}

	for(i=0;i<order/2;i++)
	{
	for(j=0;j<order/2;j++)
	m.arr[i][j+order/2]=m2.arr[i][j];
	}

	for(i=0;i<order/2;i++)
	{
	for(j=0;j<order/2;j++)
	m.arr[i+order/2][j]=m3.arr[i][j];
	}
	
	for(i=0;i<order/2;i++)
	{
	for(j=0;j<order/2;j++)
	m.arr[i+order/2][j+order/2]=m4.arr[i][j];
	}

	return m;
	}
}


int main()
{
	int n;
	printf("Enter the order of the matrix:");
	scanf("%d",&n);
	int i=0,j=0;

	printf("Enter the elements of first array->\n");
	for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
	scanf("%d",&temp1.arr[i][j]);
	}

	printf("Enter the elements of second array->\n");
	for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)	
	scanf("%d",&temp2.arr[i][j]);
	}

struct data result = div_conq(n,0,0,0,0);	//div_conq function called.

	printf("The product matrix is->\n");

	for(i=0;i<n;i++)			//for loop made to print the final array.
		{
			for(j=0;j<n;j++)
			printf("%d ",result.arr[i][j]);
		printf("\n");
		}

return 0;
}

//To find the minimum cost for travelling from 0th room to last room of puzzler's house.
#include<stdio.h>
#define min(a,b) ((a)<(b)?a:b)

struct cost		//cost structure is used to store the minimum cost till that room and the direction of travel from previous room.
{
	int value;
	char c;
};


struct cost bottom_up[500][500];	//bottom_up 2D array is made to store datas for all rooms.


int main()
{
	char stack[500];		//stack array is made to store the directions.
	int m,n,k=0;
	printf("Enter m and n->\n");		//m is no. of rows and n is no. of columns.
	scanf("%d %d",&m,&n);
	int i=0,j=0,puzzle[500][500];		//puzzle 2D array is made to store the given data.

	for(i=0;i<m;i++)
	{
	for(j=0;j<n;j++)
	scanf("%d",&puzzle[i][j]);
	}

bottom_up[0][0].value=puzzle[0][0];

	for(i=1;i<m;i++)
	{
	bottom_up[i][0].value=puzzle[i][0]+bottom_up[i-1][0].value;
	bottom_up[i][0].c='w';
	}

	for(j=1;j<n;j++)
	{
	bottom_up[0][j].value=puzzle[0][j]+bottom_up[0][j-1].value;
	bottom_up[0][j].c='r';
	}

	for(i=1;i<m;i++)		//nested loop for filling the entries of 2D bottom_up array.
	{
		for(j=1;j<n;j++)
		{
		bottom_up[i][j].value=min(min(bottom_up[i-1][j-1].value,bottom_up[i-1][j].value),bottom_up[i][j-1].value)+puzzle[i][j];
		if(bottom_up[i][j].value==bottom_up[i-1][j-1].value+puzzle[i][j])
		bottom_up[i][j].c='d';
	
		else if(bottom_up[i][j].value==bottom_up[i-1][j].value+puzzle[i][j])
		bottom_up[i][j].c='w';
		
		else
		bottom_up[i][j].c='r';
		}
	}

printf("Cost->%d\n",bottom_up[m-1][n-1].value);
printf("The path is->\n");
	for(i=m-1,j=n-1;i!=0||j!=0;)		//for loop for filling the entries in stack array.
	{
	if(bottom_up[i][j].c=='d')
	{
	i-=1;
	j-=1;
	stack[k]='d';
	k++;
	}
	
	else if(bottom_up[i][j].c=='w')
	{
	i-=1;
	stack[k]='w';
	k++;
	}
	
	else
	{
	j-=1;
	stack[k]='r';
	k++;
	}
	}

	k-=1;
for(;k>=0;k--)			//for loop for printing the directions.
	{
	if(stack[k]=='d')	printf("Diagonal  ");
	else if(stack[k]=='w')		printf("Downward ");
	else		printf("Rightward ");
	}

return 0;--
}
		



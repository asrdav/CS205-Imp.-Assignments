//To write a program of who can access whose acounts as per the given condition.
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define INF (int)9999999

struct node 		//node struct is basic node of the graph.
{
	char c[5];	//c array stores name of the student of the node.
	int sum;	//sum stores the sum of ascii value of characters of the name.
};

int main()
{
	int n;
	printf("Enter the number of names->\n");
	scanf("%d",&n);		//n is number of names.
	printf("Enter the names->\n");
	int i,j,tmp=0,k,weight=0,d;
	

	struct node arr[n+1];			//arr stores info about nodes of graph.	
	int **wt=(int **) malloc((n+1)* sizeof(int *));		//wt double pointers are for Floyd Warshall algo.

	for(i=0;i<=n;i++)		//for loop for allocating memory for the pointers.
	wt[i]=(int *) malloc((n+1)* sizeof(int));

	for(i=0;i<=n;i++)		//for loop for initializing wt matrix.
	{
		for(j=0;j<=n;j++)
		wt[i][j]=(i==j)?0:INF;
	}	

	for(i=0;i<=n;i++)	//initializing arr struct array.
	arr[i].sum=0;

	for(i=1;i<=n;i++)
	{
		scanf("%s",arr[i].c);
		for(k=0;k<5;k++)		//loop for calculating sum of ascii values of the name.
		arr[i].sum+=arr[i].c[k];	
	}

	printf("Enter predefined d->\n");
	scanf("%d",&d);			//d is predefined threshold value of distance.

	for(i=1;i<=n;i++)		//nested loop to find the edges and to fill wt matrix.
	{
	for(j=i+1;j<=n;j++)
	{
	tmp=0;
	weight=0;	//weight stores the edge weight.

	for(k=0;k<5;k++)	//finding the edges.
	{	
		if(arr[i].c[k]!=arr[j].c[k]){	weight+=fabs(arr[i].c[k]-arr[j].c[k]);	tmp++;	}
	}
		if(tmp==1)
		{
			if(arr[i].sum>arr[j].sum&&weight<d)	 wt[i][j]=weight;
			else if(arr[i].sum<arr[j].sum&&weight<d)   wt[j][i]=weight;		
		}
	}
	}

	for(k=1;k<=n;k++)		//performing FLOYD WARSHALL algortihm on wt matrix.
     {
	for(i=1;i<=n;i++)
	   {
	     for(j=1;j<=n;j++)
	     {
	     if(wt[i][k]+wt[k][j]<wt[i][j])
	    	 wt[i][j]=wt[i][k]+wt[k][j];
	     }
           }
     }

	printf("    Student's Name :: Accessible Accounts\n\n");
	for(i=1;i<=n;i++)		//printing the account's name and respective accounts they can access.
	{
		printf("\t%s->",arr[i].c);
		for(j=1;j<=n;j++)
		{
		if(wt[i][j]!=INF)	printf("%s ",arr[j].c);
		}
	printf("\n");
	}

	printf("\t(i=1 corr. to 1st word,i=2 corr. to 2nd word and so on...)\n");
	printf("\t(1 stands for access and 0 for not access.)\n\tAccess Matrix->\n");
	for(i=1;i<=n;i++)
	{
		printf("\t");
		for(j=1;j<=n;j++)
		{
		if(wt[i][j]!=INF)	printf("1 ");
		else	printf("0 ");
		}
	printf("\n");
	}

return 0;
}


	

		

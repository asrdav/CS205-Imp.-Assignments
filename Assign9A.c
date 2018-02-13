//To find cost effective solution of supplying water to all houses as per the required condition.
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define min(a,b) ((a)<(b)?a:b)
#define INF (double)99999

struct g_node			//g_node is basic node of the graph.
{
	int ne[500];		//ne array stores the neighbours.
	int cnt;		//cnt stores the count of neighbours.
	int cost[500];		//cost array stores cost of adjacent neighbours.
	int tmp[124];		//tmp array is soring count of character in name.
	char name[500];		//name stores name of the owner.
	double own_cost;	//own_cost stores boring a well in house itself.
	int parent;		//parent stores the house from which water is coming.
};

bool final[500]={false};

int main()
{
	int n;		//n is no. of localities.
	printf("Enter no. of localities->\n");
	scanf("%d",&n);
	printf("\t(The localities are from 1 to n.)\n");
	int i,j,k,req_index;
	printf("Enter the names->\n");
	double min_d;

	struct g_node arr[n+1];		//arr struct has been made to store data of graph.
	for(i=0;i<=n;i++)		//initializing arr structure.
	{
	arr[i].cnt=1;	
	arr[i].parent=i;
	for(j=0;j<124;j++)
	arr[i].tmp[j]=0;
	}

	for(i=1;i<=n;i++)
	{
	scanf("%s",arr[i].name);
	k=0;
		for(j=0;j<strlen(arr[i].name);j++)
		{
		k+=(int)arr[i].name[j];
		arr[i].tmp[arr[i].name[j]]++;
		}
	arr[i].own_cost=(double)k/strlen(arr[i].name);
	}

	int x,y,z;
	for(i=1;i<=n;i++)	//nested loop for finding edges between the houses.
	{

	for(j=i+1;j<=n;j++)
	{
	x=0;	
	y=0;

	for(k=0;k<124;k++)
	{
		if(arr[i].tmp[k]-arr[j].tmp[k]==1)	
		{
		x++;
		z=k;
		}	
		else if(arr[i].tmp[k]-arr[j].tmp[k]==-1)
		{	
		y++;
		z=k;
		}
	}

	if((x==1&&y==0)||(y==1&&x==0))
	{
	arr[i].ne[arr[i].cnt]=j;
	arr[j].ne[arr[j].cnt]=i;
	arr[i].cost[arr[i].cnt]=z;
	arr[j].cost[arr[j].cnt]=z;
	arr[i].cnt++;
	arr[j].cnt++;	
	}

	}

	}

	j=1;	
	
	while(j!=n)		//performing prim's algorithm.
	{
	min_d=INF;
	for(i=1;i<=n;i++)   //finding minimum in left array.
	{
		if(final[i]==false && arr[i].own_cost<min_d)
		{
		min_d=arr[i].own_cost;
		req_index=i;	//req_index stores index with minimum value.
		}
	}
	final[req_index]=true;
	
	for(i=1;i<arr[req_index].cnt;i++)
	{
		if(final[arr[req_index].ne[i]]==false&&arr[arr[req_index].ne[i]].own_cost>arr[req_index].cost[i])
		{
		arr[arr[req_index].ne[i]].own_cost=arr[req_index].cost[i];
		arr[arr[req_index].ne[i]].parent=req_index;
		}
	}
	j++;
	}
	double cost_final=0.0;
	printf("The required solution is ->\n\n");
	printf(" Locality::Parent::Cost\n");
	printf("      (Water source)\n\n");
	for(i=1;i<=n;i++)
	{
	cost_final+=arr[i].own_cost;
	printf("[%d]  %s  %s  %0.3lf\n",i,arr[i].name,arr[arr[i].parent].name,arr[i].own_cost);
	}
	printf("The required final cost is->%0.3lf",cost_final);
return 0;
}
	
	

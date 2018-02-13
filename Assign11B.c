//To find maximum flow in the given network.
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define min(a,b) ((a)<(b)?a:b)
#define INF (int)999999

struct g_node		//g_node is basic node of the graph.
{
	int *ne;
	int cnt;
	int parent;
};


int aug_path(struct g_node arr[],int s,int t,int **res_graph)	//aug_path is for finding possibility of augmented path.
{
	int i;
	bool visited[t+1];
	struct g_node res[t+1];
	int pt[t+1];
	pt[0]=s;

	for(i=s;i<=t;i++)
	visited[i]=false;

	int front=0,end=0;
	visited[s]=true;
	int j,v=s;
	res[front]=arr[s];
		while(front<=end)	//implementing breadth first search.
		{
			for(j=0;j<=res[front].cnt;j++)
			{
				if(visited[res[front].ne[j]]==false&&res_graph[v][res[front].ne[j]]>0)
				{
				visited[res[front].ne[j]]=true;
				res[++end]=arr[res[front].ne[j]];
				pt[end]=res[front].ne[j];
				arr[res[front].ne[j]].parent=v;
				}
			}
		front+=1;
		v=pt[front];
		}
	if(visited[t]==true)	return 1;
	else
	return 0;
}

				
int find_flow(struct g_node arr[],int s,int t,int **res_graph)	//find_flow is to find max. flow in the graph.
{
	int v1,flow_tmp,max_flow=0;

	while(aug_path(arr,s,t,res_graph))	//calling aug_path function.
	{		
	   flow_tmp=INF;
		for(v1=t;v1!=s;v1=arr[v1].parent)
			flow_tmp=min(flow_tmp,res_graph[arr[v1].parent][v1]);
		for(v1=t;v1!=s;v1=arr[v1].parent)
		{
			res_graph[arr[v1].parent][v1]-=flow_tmp;
			res_graph[v1][arr[v1].parent]+=flow_tmp;
		}
	max_flow+=flow_tmp;
	}
return max_flow;	//returning max_flow.
}			


int main()
{
	int n;

	printf("Enter n->\n");
	scanf("%d",&n);
	int i,j;
	int **res_graph=(int **) malloc((n+2)*sizeof(int *));	//res_graph stores the residual graph.
		for(i=0;i<=n+1;i++)
		{	
			res_graph[i]=(int *) malloc((n+2)*sizeof(int));
			for(j=0;j<=n+1;j++)
			res_graph[i][j]=0;
		}
	

	int tmp1=n/4;
	int tmp2=(3*n)/4;

	struct g_node arr[n+2];
	for(i=0;i<=n+1;i++)
	{
		arr[i].cnt=-1;
		arr[i].parent=-1;
		arr[i].ne=(int *) malloc((n+1)*sizeof(int));
	}

	for(i=1;i<=n;i++)	//for loop for finding the edge weights in the graph.
	{
            for(j=i+1;j<=n;j++)
	     {
		if(j-i<=3)
		{
			arr[i].ne[++arr[i].cnt]=j;
			res_graph[i][j]=i+j;
		}
	     }
	}

	for(i=1;i<=n;i++)	//for loop for finding edge weights from source.
	{
		if(i>=1&&i<=tmp1)
		{
			arr[0].ne[++arr[0].cnt]=i;
			res_graph[0][i]=i;
		}
	}

	for(i=1;i<=n;i++)	//for loop for finding edge weights to sink.
	{
		if(i>=tmp2&&i<=n)
		{
			arr[i].ne[++arr[i].cnt]=n+1;
			res_graph[i][n+1]=i;
		}
	}

	int max_flow=find_flow(arr,0,n+1,res_graph);	//find_flow function called.
	if(max_flow!=0)
	printf("The maximum flow is->\n%d",max_flow);
	else
	printf("There is no path between source and sink");

return 0;
}

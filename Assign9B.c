//To find the most reliable path between given vertices in the directed graph.
#include<stdio.h>
#include<stdbool.h>
#define max(a,b) ((a)>(b)?a:b)

struct g_node			//g_node is basic node of graph.
{
	int ne[500];		//ne array stores the list of neighbours.
	double prob[500];	//prob array stores the probability of the neighbours.
	int cnt;		//cnt stores the count of neighbours.
	int parent;		//parent stores the parent of the vertex.
	double val;		//val stores the probability of vertex itself.
};

bool final[500]={false};

int main()
{
	int v,e,src,dest,req_index,i,j;
	double max_d=0.0;

	printf("Enter no. of vertices->\n");
	scanf("%d",&v);		
	printf("\t(The vertices are from 1 to n.)\n");
	printf("Enter no. of edges->\n");
	scanf("%d",&e);
	struct g_node arr[v+1];		//arr struct stores the data of nodes in the graph.
	int res[v];			//res array stores the parent of each vertex in required path.
	res[0]=0;

	for(i=0;i<=v;i++)		//initializing arr structure.
	{
	arr[i].parent=-1;
	arr[i].cnt=1;
	arr[i].val=0.0;
	}

	printf("Enter edges along with weights->\n\t(Edge u,Edge v,Given probability:)\n");
	for(i=1;i<=e;i++)
	{
	int x,y;
	double w;		//w is the probability of given path.
	scanf("%d %d %lf",&x,&y,&w);
	arr[x].ne[arr[x].cnt]=y;
	arr[x].prob[arr[x].cnt]=w;
	arr[x].cnt++;
	}
	printf("Enter source and destination->\n");
	scanf("%d %d",&src,&dest);

	if(src==dest)
	{
	printf("The path length is 0 and is the most reliable path.(source and destination same)\n");
	return 0;
	}
	arr[src].val=1.0;
	j=1;	
	
	while(j!=v)
	{
	
	max_d=0.0;
	for(i=1;i<=v;i++)
	{
		if(final[i]==false && arr[i].val>max_d)
		{
		max_d=arr[i].val;
		req_index=i;
		}
	}
	final[req_index]=true;
	
	for(i=1;i<arr[req_index].cnt;i++)
	{
		if(final[arr[req_index].ne[i]]==false&&arr[arr[req_index].ne[i]].val<arr[req_index].val*(arr[req_index].prob[i]))
		{
		arr[arr[req_index].ne[i]].val=arr[req_index].val*(arr[req_index].prob[i]);
		arr[arr[req_index].ne[i]].parent=req_index;
		}
	}
	j++;
	}
	if(arr[dest].val==0.0)
	{
	printf("There exist no reliable path between given two vertices.");
	return 0;
	}
	
	printf("The required probability is -> %lf\n",arr[dest].val);
	
	i=dest;
	j=1;
	res[j]=dest;
	j++;
	while(arr[i].parent!=-1)	//while loop for scanning each vertex in required path.
	{
	res[j]=arr[i].parent;
	i=arr[i].parent;
	j++;
	}
printf("The required path is->\n");
	for(i=j-1;i>=1;i--)
	{
	if(i==1)
	printf("%d ",res[i]);
	else
	printf("%d ->",res[i]);
	}

return 0;
}

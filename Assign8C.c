//To find the maximum no. of edges in connected componemts of the graph.
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max(a,b) ((a)>(b)?a:b)

struct node		//node struct array has been made to store the data of the node of the graph.
{
	int ne[500];	//ne array has been made to store the neighbours.
	int cnt;	//cnt stores the count of neighbours.
};

int main()
{
	int n,m,mx=0;
	printf("Enter n(no. of vertices)->\n");
	scanf("%d",&n);
	printf("(The numbers are from 1 to n.)\n");
	printf("Enter m(no. of edges)->\n");
	scanf("%d",&m);

	struct node arr[n+1],res[n+1];	//arr struct array has been made to store data of nodes of the graph.
					//res struct array has been made to store intermediate results. 
	int num[501]={0};
	bool visited[501]={false};
	int i,j;
	for(i=0;i<=n;i++)	arr[i].cnt=0;
	int a,b;	
	printf("Enter edges->\n");
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&a,&b);
			arr[a].ne[arr[a].cnt]=b;
			arr[a].cnt++;
			arr[b].ne[arr[b].cnt]=a;
			arr[b].cnt++;
		}
	 int front,end,k=-1;		//front stores front index of queue.
					//end stores end index of queue.
	for(i=1;i<=n;i++)		//loop for case of disconnected graph.
	{
		if(arr[i].cnt==0)	
		{	
		k++;	
		continue;
		}

		else if(visited[i]==true)	continue;
		k++;
		front=1;	end=1;

		res[front]=arr[i];
		visited[i]=true;
		while(front<=end)		//breadth first search implementation.
		{
			for(j=0;j<res[front].cnt;j++)		
			{
				if(visited[res[front].ne[j]]==false)
				{
				visited[res[front].ne[j]]=true;
				res[end+1]=arr[res[front].ne[j]];
				end++;	
				}
			}
		num[k]+=res[front].cnt;
		front++;
		}
	}
		for(i=0;i<=k;i++)
		mx=max(mx,num[i]/2);
printf("The maximum no. of edges in all of the connected components is %d.",mx);		

return 0;
}	

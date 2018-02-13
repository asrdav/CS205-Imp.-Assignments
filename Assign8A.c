//To divide n no. of players into two groups such that no groups has rivalry between their members.
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node		//node struct is basic node of the graph created.
{
	int ne[500];		//stores the neighbours.
	int cnt;		//stores the count of neighbours.
	char clr;		//clr stores the colour assigned to the node.(blue('b') or red('r'))
};

int main()
{
	int n,r;
	printf("Enter n->\n");
	scanf("%d",&n);		//n is no. of players.
	printf("(The numbers are from 1 to n.)\n");
	printf("Enter r->\n");
	scanf("%d",&r);		//r is no. of pairs between whom rivalry is there.

	struct node arr[n+1],res[n+1];		//arr struct array stores the nodes of graph.
						//res struct array stores the intermediate results.
	bool visited[501]={false};
	int i,j;
	for(i=0;i<=n;i++)	
	{
	arr[i].cnt=0;	
	arr[i].clr='z';
	}
	int a,b;	
	printf("Enter pairs->\n");
		for(i=0;i<r;i++)
		{
			scanf("%d %d",&a,&b);
			arr[a].ne[arr[a].cnt]=b;
			arr[a].cnt++;
			arr[b].ne[arr[b].cnt]=a;
			arr[b].cnt++;
		}
	 int front,end;		//front is to store front index of queue formed,end is to store end index of queue formed.
	for(i=1;i<=n;i++)		//loop for case of disconnected graph.
	{
		if(arr[i].cnt==0)	//b is to show blue colour and r is to show red colour.
		{	
		arr[i].clr='b';	
		continue;	
		}

		else if(arr[i].clr=='z')	arr[i].clr='b';
		else if(visited[i]==true)	continue;
		front=1;	end=1;

		res[front]=arr[i];
		visited[i]=true;
		while(front<=end)	//breadth first search implementation.
		{
			for(j=0;j<res[front].cnt;j++)	
			{
				if(visited[res[front].ne[j]]==false)
				{
				visited[res[front].ne[j]]=true;
				arr[res[front].ne[j]].clr=(res[front].clr=='b')?'r':'b';
				res[end+1]=arr[res[front].ne[j]];
				end++;	
				}
	       if((arr[res[front].ne[j]].clr=='b'&&res[front].clr=='b')||(arr[res[front].ne[j]].clr=='r'&&res[front].clr=='r'))	
				break;
			}
		if(j!=res[front].cnt)	
		{
		printf("Can't be divided");		
		return 0;	
		}
		front++;
		}
	}

printf("The players in set 1 are->\n");
	for(i=1;i<=n;i++)
	{
	if(arr[i].clr=='b')
	printf("%d ",i);	
	}
printf("\nThe players in set2 are->\n");
	for(i=1;i<=n;i++)
	{
	if(arr[i].clr=='r')
	printf("%d ",i);	
	}

return 0;
}	

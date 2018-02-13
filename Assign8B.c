//To construct a graph between given words using given condition and to draw its adjacency matrix.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct node		//node struct is basic node of graph.
{
	char c[5];		//stores the word.
	int tmp[124];		//stores the count of characters in the word.
	int ne[500];		//stores the neighbours.
	int cnt;		//stores count of neighbours.
	int val;		//index of the word given to it.
};

struct node arr[501];		//arr struct array has been made to store the data of nodes.

int main()
{
	int n,i,j,k;
	char c1[5],c2[5];	//c1 and c2 are temporary array made to store the words.
	int temp1[124],temp2[124];	//temp1 and temp2 are temporary array to store count of characters in c1 and c2 resp.
	printf("Enter the number of words->");
	scanf("%d",&n);
	struct node res[n+1];	//res struct array has been made to store intermediate results.

	for(i=0;i<=n;i++)
	{
	arr[i].cnt=0;
	for(j=0;j<124;j++)
	arr[i].tmp[j]=0;
	}

	for(j=0;j<124;j++)	
	{	
	temp1[j]=0;	
	temp2[j]=0;
	}

	printf("Enter the words->\n");
	for(i=1;i<=n;i++)
	{
	scanf("%s",arr[i].c);
	arr[i].val=i;
	for(j=0;j<5;j++)
	arr[i].tmp[arr[i].c[j]]++;
	}

	printf("\t(i=1 corr. to 1st word,i=2 corr. to 2nd word and so on)\n");
	int adj[n+1][n+1];

	for(i=0;i<=n;i++)
	{
	for(j=0;j<=n;j++)
	adj[i][j]=0;
	}

	int x,y,x1,y1;
	for(i=1;i<=n;i++)
	{
		c1[0]='\0';
		memcpy(c1,&arr[i].c[1],5);
		for(k=0;k<4;k++)	temp1[c1[k]]++;
		for(j=i+1;j<=n;j++)
		{
			c2[0]='\0';
			memcpy(c2,&arr[j].c[1],5);
			for(k=0;k<4;k++)	temp2[c2[k]]++;
			x=0;	y=0;	x1=0;	y1=0;
			for(k=0;k<124;k++)	//checking edge if formed between words considered.
			{			 
				if(arr[j].tmp[k]-temp1[k]==1)	x++;
				if(arr[j].tmp[k]-temp1[k]!=1&&arr[j].tmp[k]-temp1[k]!=0)	x1++;
				if(arr[i].tmp[k]-temp2[k]==1)	y++;
				if(arr[i].tmp[k]-temp2[k]!=1&&arr[i].tmp[k]-temp2[k]!=0)	y1++;			
			}
			if(x==1&&x1==0)	{	adj[j][i]=1;	arr[i].ne[arr[i].cnt]=j;	arr[i].cnt++;	}
			if(y==1&&y1==0)	{	adj[i][j]=1;	arr[j].ne[arr[j].cnt]=i;	arr[j].cnt++;	}
		for(k=0;k<4;k++)	temp2[c2[k]]=0;
		}
	for(k=0;k<4;k++)	temp1[c1[k]]=0;
	}
	
	int front,end;		//front stores front index of queue formed and end stores end index of queue formed.
	k=-1;
	int num=0;
	bool visited[999]={false};
	for(i=1;i<=n;i++)		//to implement case of disconnected graph.
	{
		if(arr[i].cnt==0)	
		{	
		visited[i]=true;	
		k++;	
		continue;	
		}

		else if(visited[i]==true)	continue;
		k++;
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
				res[end+1]=arr[res[front].ne[j]];
				end++;	
				}
				else
				{
				if(adj[res[front].val][res[front].ne[j]]==1)
				{
				printf("GRAPH IS CYCLIC\n");
				num++;
				break;
				}
				}
			}
		if(num==1)	break;	
		front++;
		}
	if(num==1)	break;
	}
	if(num==0)	printf("GRAPH IS ACYCLIC\n");
	printf("\t(Here adj[i][j] represents that if word ith can be formed from word jth or not.)\n");

printf("The adjacency matrix is->\nWord-");
		for(k=1;k<=n;k++)
		printf("%d ",k);
		printf("\n");
		
		for(k=1;k<=n;k++)
		{
		printf("(%d)  ",k);
		for(j=1;j<=n;j++)
		printf("%d ",adj[k][j]);
		printf("\n");
		}	

return 0;
}

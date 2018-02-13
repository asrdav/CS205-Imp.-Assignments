//To allot students their placements in such a way that maximum students are placed.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#define min(a,b) ((a)<(b)?a:b)
#define INF (int)999999

struct g_node		//g_node is basic node of the graph.
{
	int tmp[124];
	int cnt;
	int *ne;
	char name[100];
	int parent;	
};

int final[20],n;	//final array stores the respective companies where students have been placed.

int aug_path(struct g_node arr[],int s,int t,int **res_graph)  //aug_path is for finding chances of augmented path.
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

				
int find_offer(struct g_node arr[],int s,int t,int **res_graph)	//find_offer is to find max. offer in the graph.
{
	int v1,offer_tmp,max_offer=0;

	while(aug_path(arr,s,t,res_graph))	//calling aug_path function.
	{		
	   offer_tmp=INF;
		for(v1=t;v1!=s;v1=arr[v1].parent)
		{
			offer_tmp=min(offer_tmp,res_graph[arr[v1].parent][v1]);
			if(v1>=n+1&&v1<=n+19)
			final[v1-n]=arr[v1].parent;
		}
		for(v1=t;v1!=s;v1=arr[v1].parent)
		{
			res_graph[arr[v1].parent][v1]-=offer_tmp;
			res_graph[v1][arr[v1].parent]+=offer_tmp;
		}
	max_offer+=offer_tmp;
	}
return max_offer;	//returning max_offer.
}


int main()
{
	char string[19][30]={"Microsoft","Google","Adobe","Mentor Graphics","Synopsis","IBM",   				  					"Wipro","TCS","CTS","Goldman","Infosys","Cadence","Texas Instrument",
				"DRDO","HAL","ISRO","Capgemini","Ushacomm","Ericson"};
	int tmp_job[19][124];

	int i,j,k;
	printf("Enter the no. of students->\n");
	scanf("%d",&n); 
	printf("Enter the students->\n");
	for(i=0;i<=19;i++)
	final[i]=-1;

	struct g_node arr[n+21];
	for(i=0;i<=n+20;i++)		//nodes initialization.
	{
		arr[i].cnt=-1;
		arr[i].parent=-1;
		for(k=0;k<124;k++)
		arr[i].tmp[k]=0;
		arr[i].ne=(int *) malloc((n)*sizeof(int));
	}

	for(i=0;i<19;i++)
	{
		for(j=0;j<124;j++)
		tmp_job[i][j]=0;
	}

	for(i=1;i<=n;i++)
	{
		scanf("%s",arr[i].name);
		for(j=0;j<strlen(arr[i].name);j++)
		{
			if(arr[i].name[j]==' ')continue;
			else
			arr[i].tmp[tolower(arr[i].name[j])]++;
		}
	}

	for(i=0;i<=18;i++)		//counting the characters.
	{
		for(j=0;j<strlen(string[i]);j++)
		{
			if(string[i][j]==' ')continue;
			else
			tmp_job[i][tolower(string[i][j])]++;
		}
	}
			
	int **res_graph=(int **) malloc((n+21)*sizeof(int *));
	for(i=0;i<=n+20;i++)
	res_graph[i]=(int *) malloc((n+21)*sizeof(int));
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)	res_graph[i][j]=0;
	}

	for(i=1;i<=n;i++)	{	res_graph[0][i]=1;	arr[0].ne[++arr[0].cnt]=i;	}
	for(i=1;i<=19;i++)	{	res_graph[n+i][n+20]=1;		arr[n+i].ne[++arr[n+i].cnt]=n+20;	}
	int com;

	for(i=1;i<=n;i++)		//forming the edges.
	{
		for(j=1;j<=19;j++)
		{
		com=0;
			for(k=0;k<124;k++)
			{
			if(arr[i].tmp[k]!=0&&tmp_job[j-1][k]!=0)	com+=min(arr[i].tmp[k],tmp_job[j-1][k]);
			}
		if(com>=2)
		{	res_graph[i][n+j]=1;	arr[i].ne[++arr[i].cnt]=n+j;	}
		}
	}

	int max_offer=find_offer(arr,0,n+20,res_graph);		//find_offer function called.
	printf("Maximum %d students got placed.\n",max_offer);

	for(i=1;i<=19;i++)
	{
		if(final[i]!=-1)
			printf("%s placed student %s.\n",string[i-1],arr[final[i]].name);
	}		 
	
return 0;
}				

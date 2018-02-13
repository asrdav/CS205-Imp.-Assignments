//To find and show location of restaurants as per the condition and then find required paths to the localities.
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define min(a,b) ((a)<(b)?a:b)
#define INF (double)99999

struct g_node		//g_node is basic node of graph.
{
	char c[1000];	//name of the locality.
	int val;	//stores value of the word.
	int parent;	//parent stores the restaurant that is delivering pizza to that location.
};


bool visited[501]={false};
int parent[501][501];		////parent 2d array has been made to keep track of paths.


void rec_print(struct g_node arr[],int i,int j,int num)
{
	if(i!=j)
	rec_print(arr,i,parent[i][j],num+1);		//rec_print_function called.

	if(num==0)
	printf("%s",arr[j].c);
	else
	printf("%s->",arr[j].c);
}


int min_edit_distance(char c1[],char c2[],int l1,int l2)	//min_edit_distance is made to find the edit distance between two.
{				//l1 is length of c1 array,l2 is length of c2 array.
	if(l1==0)	return l2;
	if(l2==0)	return l1;

	if(c1[l1-1]==c2[l2-1])
	return min_edit_distance(c1,c2,l1-1,l2-1);

	return 1+min(min(min_edit_distance(c1,c2,l1,l2-1),min_edit_distance(c1,c2,l1-1,l2)),min_edit_distance(c1,c2,l1-1,l2-1));
}


int main()
{
	int n;		//n is no. of localities.
	printf("Enter the no. of localities->\n");
	scanf("%d",&n);
	printf("\t(The localities are from 1 to n.)\n");

	struct g_node arr[n+1];		//arr struct has been made to store the data of nodes.
	double wt[n+1][n+1];	//wt 2D array has been made to perform FLOYD WARSHALL algorithm.
	int i,j,k;
	int max=0,max1,req_index,vis=0,result[n],cnt=-1;  
			//result array has been made to keep track of locations of restaurants.
	for(i=0;i<=n;i++)
	{
	for(j=0;j<=n;j++)
	wt[i][j]=(i==j)?0:INF;
	}

	printf("Enter the names of the localities->\n");
	for(i=0;i<=n;i++)	//initializing arr structure.
	{	
	arr[i].parent=i;
	arr[i].val=i;
	}

	for(i=1;i<=n;i++)
	scanf("%s",arr[i].c);

	int e;
	printf("Enter the number of edges->\n");
	scanf("%d",&e);		//e is no. of edges.
	printf("Enter the localities'no. along with traffic condition->\n");
	printf("\t(1 corr. to 1st word,2 corr. to 2nd word,3 to 3rd and so on....)\n");
	for(i=1;i<=e;i++)
	{
	int u,v,tmp;	//tmp is min edit distance between the given strings.
	double tr;		//tr is traffic condition between the given u and v edges.
	scanf("%d %d %lf",&u,&v,&tr);
	tmp=min_edit_distance(arr[u].c,arr[v].c,strlen(arr[u].c),strlen(arr[v].c));	//min_edit_distance function called.
	wt[u][v]=((double)tmp)*tr;
	wt[v][u]=((double)tmp)*tr;
	}

	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(wt[i][j]>30)	parent[i][j]=-1;
			else	parent[i][j]=i;
		}
	}

  for(k=1;k<=n;k++)		//performing FLOYD WARSHALL algortihm.
    {
	for(i=1;i<=n;i++)
	   {
	     for(j=1;j<=n;j++)
	     {
	     if(wt[i][k]+wt[k][j]<wt[i][j])
	     	{
	     	 parent[i][j]=parent[k][j];			
	    	 wt[i][j]=wt[i][k]+wt[k][j];
	    	}
	     }
           }
     }
	
	while(1)	//while loop for considering all possible cases.
	{
		max=0;
		for(i=1;i<=n;i++)	//for maintaining the location of restaurants.
		{
			if(visited[i]==true)	continue;			
			max1=0;
			for(j=1;j<=n;j++)
			{
			if(i==j)	continue;
			if(wt[i][j]<=30.0&&visited[j]==false)	max1++;
			}
		if(max1>max)	{	max=max1;	req_index=i;	}
		if(max1==0)	{	result[++cnt]=i;	visited[i]=true;	}
		}
     if(max1!=0)
      {
	for(i=1;i<=n;i++)
	{
	if(i==req_index)	continue;
	if(wt[req_index][i]<=30.0&&visited[i]==false)	{	visited[i]=true;	arr[i].parent=req_index;	}
	}
	visited[req_index]=true;
	result[++cnt]=req_index;
     }

	vis=0;
	for(i=1;i<=n;i++){	if(visited[i]==true)	vis++;	}
	if(vis==n)	break;
	}

	printf("The restaurants are located at->\n");	//printing restaurants' location.
	for(i=0;i<=cnt;i++)
	printf("%d ",result[i]);	

	int tmp1[n+1],tmp2[n+1],cnt1=-1;	//tmp1 and tmp2 array stores the source and corr. destination resp.
				//cnt1 is intermediate variable. 
	for(i=0;i<=cnt;i++)
	{
		printf("\nThe localities whose delivery occurs from restaurant %d (is/are)->\n",result[i]);
		for(j=1;j<=n;j++)
		{
		if(arr[j].parent==result[i])
		{
		tmp1[++cnt1]=result[i];
		tmp2[cnt1]=j;
		printf("%d ",j);
		}
		}
	}
	
	printf("\nThe paths are->\nRESTAURANT  DESTINATION\n");	
	for(i=0;i<=cnt1;i++)		//printing the paths.
	{
	if(tmp1[i]==tmp2[i])
	printf("%s->%s\n",arr[tmp1[i]].c,arr[tmp2[i]].c);
	else
	{
	rec_print(arr,tmp1[i],tmp2[i],0);	//rec_print function called.
	printf("\n");
	}
	} 
return 0;
}

	
	

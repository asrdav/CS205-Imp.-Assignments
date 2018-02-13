//To find most economically schedule of 8 matches that requires least travel.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define min(a,b) ((a)<(b)?a:b)
#define INF 99999

bool visited[8][8]; 	//visited 2D array stores the visited cities while calculating min. cost for ith starting city.
char path[8][8];	//path stores resp. path taking ith city as starting point.
int val[8]={0};		//val array stores the resp. cost taking ith city as starting point.

void req_path(int dist[][8],char cities[],int i)    //req_path fills the corr. path,visited and val matrix for ith starting city.
{
	int cnt=-1,j,min_temp=INF,k,req_index,tmp1=0;

	path[i][++cnt]=cities[i];
	visited[i][i]=true;
	k=i;
	while(1)
	{
		for(j=0;j<8;j++)	//for loop for finding min weight value and resp. city in kth traversal.
		{
		if(j==k||visited[i][j]==true)	continue;
		else {	if(min_temp>dist[k][j])	{	min_temp=dist[k][j];	req_index=j;	}	}	
		}

	val[i]+=min_temp;	//min_temp stores resp. min val for kth traversal for ith starting city.
	visited[i][req_index]=true;	

	k=req_index;		//req_index stores resp. city having min. weight of kth traversal.
	path[i][++cnt]=cities[k];
	min_temp=INF;

	tmp1=0;
		for(j=0;j<8;j++)	//loop for breaking through the req_path function.
		{
		if(visited[i][j]==true)	tmp1++;		}
	if(tmp1==8)	break;
	}
}
	
int main()
{
	char cities[8]={'C','K','I','B','N','R','G','H'};	//cities matrix stores corr. cities.
	int dist[8][8]={{0,1700,1200,300,900,1200,1900,500},	//dist 2D matrix stores distance between resp. given locations.
			{1700,0,1300,1600,1000,300,500,1200},
			{1200,1300,0,1100,400,1000,1700,700},
			{300,1600,1100,0,900,1400,2100,500},
			{900,1000,400,900,0,900,1400,400},
			{1200,300,1000,1400,900,0,700,1000},
			{1900,500,1700,2100,1400,700,0,2400},
			{500,1200,700,500,400,1000,2400,0}};

	int i,j,k;
	for(i=0;i<8;i++)	//initializing visited matrix.
	{		
		for(j=0;j<8;j++)
		visited[i][j]=false;
	}

	for(k=0;k<8;k++)	//performing FLOYD WARSHALL algorithm.
	{
	   for(i=0;i<8;i++)
	    {
		for(j=0;j<8;j++)
		{
		if(dist[i][k]+dist[k][j]<dist[i][j])
		dist[i][j]=dist[i][k]+dist[k][j];
		}
	    }
	}
	i=0;	
	
	while(i<8)
	{
	req_path(dist,cities,i);	//req_path function called.
	i++;
	}

	int min_tmp=INF,index;
	for(i=0;i<8;i++)	//finding the final minimum cost possible among all possible starting cities.
	{
	if(min_tmp>val[i])	{	min_tmp=val[i];		index=i;	}	
	}

	printf("   Economically preferable match schedule is ->\n");

	for(j=0;j<8;j++)		//printing the required schedule and required total cost.
	{
	if(path[index][j]=='C')	  printf("%d.  MA Chidambaram Stadium(Chennai)\n",j+1);
	else if(path[index][j]=='K')  printf("%d.  Eden Gardens(Kolkata)\n",j+1);
	else if(path[index][j]=='I')  printf("%d.  Holkar Cricket Stadium(Indore)\n",j+1);
	else if(path[index][j]=='B')  printf("%d.  M.Chinnaswamy Stadium(Bengaluru)\n",j+1);
	else if(path[index][j]=='N')  printf("%d.  Vidarbha Cricket Association Ground(Nagpur)\n",j+1);
	else if(path[index][j]=='R')  printf("%d.  JSCA International Stadium Complex(Ranchi)\n",j+1);
	else if(path[index][j]=='G')  printf("%d.  Barsapara Cricket Stadium(Guwahati)\n",j+1);
	else  printf("%d.  Rajiv Gandhi International Stadium(Hyderabad)\n",j+1);
	}
	printf("The total cost is->%dkm",val[index]);

return 0;
}		

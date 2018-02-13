//To find maximum flow among given cities using push_relabel algorithm.
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>
#define min(a,b) ((a)<(b)?a:b)
#define INF 99999

struct g_node		//g_node is basic node of graph.
{
	int height;
	int exc_flow;
	int *ne;
	int cnt;
	int char_length;
	int tmp[124];
	int incom_edge;
	int outgo_edge;
	int val;
};

struct g_node arr[72],*qu_tmp;
int res_graph[72][72],front=0,end=-1,x=0;
bool visited[72]={false};

void push(int u,int v)		//push operation.
{
	int fl=min(res_graph[u][v],arr[u].exc_flow);
	arr[v].exc_flow+=fl;
	res_graph[u][v]-=fl;
	res_graph[v][u]+=fl;
	arr[u].exc_flow-=fl;
}

void relabel(int u)		//relabel operation.
{
	int i;
	int min1=INF;
	for(i=1;i<=71;i++)
	{
		if(res_graph[u][i]>0)
		min1=min(min1,arr[i].height);
	}
arr[u].height=1+min1;
}	

int find_flow()		//returns max_flow in graph.
{
	int i;
	while(front<=end)		//queue implementation.
	{	
	int u=qu_tmp[front].val;
		while(arr[u].exc_flow>0)
		{
		int tmp=-1;
			for(i=1;i<=71&&arr[u].exc_flow>0;i++)
			{
				if(arr[u].height>arr[i].height)
				{	
				tmp++;
				if(res_graph[u][i]>0)
				{
				push(qu_tmp[front].val,i);		//push function called.
				if(visited[i]==false&&i!=1&&i!=71)
				{	visited[i]=true;	qu_tmp[++end]=arr[i];	}
				}
				}
			}
		if(tmp==-1||(i==72&&arr[u].exc_flow>0))
		relabel(qu_tmp[front].val);		//relabel function called.
		x++;
		}
	visited[qu_tmp[front].val]=false;
	front+=1;
	}
return arr[71].exc_flow;
}
		

int main()
{
       char cities[71][20]={"Goa","Mumbai","Delhi","Bangalore","Hyderabad","Ahmedabad","Chennai","Kolkata","Surat","Pune","Jaipur",
			     "Lucknow", "Kanpur","Nagpur","Visakhapatnam","Indore","Thane","Bhopal","Patna","Vadodara","Ghaziabad",
			     "Ludhiana", "Coimbatore",  "Agra","Madurai","Nashik","Faridabad","Meerut","Rajkot","Varanasi",
			     "Srinagar","Aurangabad","Dhanbad","Amritsar","NaviMumbai","Allahabad","Ranchi","Howrah","Jabalpur", 				     "Gwalior","Vijayawada","Jodhpur","Raipur","Kota","Guwahati","Chandigarh","Solapur",
			     "Tiruchirappalli","Bareilly","Moradabad","Mysore","Tiruppur", "Gurgaon","Aligarh","Jalandhar",
			     "Bhubaneswar","Salem","Warangal","Guntur","Bhiwandi","Saharanpur","Gorakhpur","Bikaner","Amravati",
			     "Noida","Jamshedpur","Bhilai","Cuttack", "Firozabad","Kochi","Thiruvananthapuram"};

	int i,j,k;
	for(i=0;i<72;i++)
	{
		for(j=0;j<72;j++)
		res_graph[i][j]=0;
	}

	for(i=0;i<72;i++)
	{
		arr[i].cnt=-1;
		arr[i].exc_flow=0;
		arr[i].height=0;
		arr[i].ne=(int *) malloc(71*sizeof(int));
		for(k=0;k<124;k++)
		arr[i].tmp[k]=0;
		arr[i].incom_edge=0;
		arr[i].outgo_edge=0;
		arr[i].val=i;
	}

	for(i=1;i<=71;i++)
	{
		arr[i].char_length=strlen(cities[i-1]);
		for(j=0;j<arr[i].char_length;j++)
		arr[i].tmp[tolower(cities[i-1][j])]++;
	}

	int com;
	for(i=2;i<=70;i++)		//forming the edges in graph.
	{
		for(j=i+1;j<=70;j++)
		{
		com=0;
		for(k=0;k<124;k++)
		{
			if(arr[i].tmp[k]!=0&&arr[j].tmp[k]!=0)		com+=min(arr[i].tmp[k],arr[j].tmp[k]);
		}
		if(arr[i].char_length-arr[j].char_length==1&&com>=1)	
			{	
			res_graph[j][i]=2*com;	
			arr[i].incom_edge++;
			arr[j].outgo_edge++;
			arr[j].ne[++arr[j].cnt]=i;	
			}
		else if(arr[j].char_length-arr[i].char_length==1&&com>=1)	
			{
			res_graph[i][j]=2*com;
			arr[i].outgo_edge++;
			arr[j].incom_edge++;
			arr[i].ne[++arr[i].cnt]=j;
			}
		}
	}

	for(i=2;i<=70;i++)	//connecting source and sink.
	{
		if(arr[i].incom_edge==0)	{	res_graph[1][i]=20;	arr[1].ne[++arr[1].cnt]=i;	}
		if(arr[i].outgo_edge==0)	{	res_graph[i][71]=20;	arr[i].ne[++arr[i].cnt]=71;	}
	}		

	arr[1].height=71;
	qu_tmp=(struct g_node *) malloc(5000*sizeof(struct g_node));

	for(i=0;i<=arr[1].cnt;i++)
	{
		arr[arr[1].ne[i]].exc_flow=res_graph[1][arr[1].ne[i]];
		res_graph[arr[1].ne[i]][1]+=res_graph[1][arr[1].ne[i]];
		res_graph[1][arr[1].ne[i]]=0;

		qu_tmp[++end]=arr[arr[1].ne[i]];
		visited[arr[1].ne[i]]=true;
	}

	int max_flow=find_flow();	//find_flow function called.
	printf("The maximum flow among the network of cities is->%d.",max_flow);
return 0;
}

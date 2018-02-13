//To find the shortest path from home to office.
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define INF (int)999999
#define max(a,b) ((a)>(b)?a:b)
#define min(a,b) ((a)<(b)?a:b)

struct g_node		//g_node is basic node of the graph.
{
        char name[200];
        int tmp[124];
        int char_length;
	int val;
	int *ne;
	int cnt;
	int parent;
};

void print_path(struct g_node arr[],int index,int num)		//printing the path.
{
	if(arr[index].parent!=-1)
	print_path(arr,arr[index].parent,num+1);

	if(num==0)
	printf("%s",arr[index].name);
	else
	printf("%s-> ",arr[index].name);	
}
	
int main()
{
        int n;
        printf("Enter the no. of localities->\n");
        scanf("%d",&n);

        struct g_node arr[n+1];		//arr stores the data of nodes.
        int **wt=(int **) malloc((n+1)*sizeof(int *));
        int i=1,j=1,k,com;

        for(i=0;i<=n;i++)
        {	
		wt[i]=(int *) malloc((n+1)*sizeof(int));
                for(j=0;j<=n;j++)
                wt[i][j]=INF;
        }

        for(i=0;i<=n;i++)
        {
		arr[i].ne=(int*) malloc((n)*sizeof(int));
                for(k=0;k<124;k++)
		arr[i].tmp[k]=0;
	
		arr[i].cnt=-1;		
		arr[i].val=INF;	 	
		arr[i].parent=-1;
        }
        printf("Enter the localities->\n");
        for(i=1;i<=n;i++)
        {
        scanf("%s",arr[i].name);
                for(k=0;k<strlen(arr[i].name);k++)
                arr[i].tmp[arr[i].name[k]]++;
        arr[i].char_length=strlen(arr[i].name);
        }

        char home[200];
        char office[200];

        printf("Enter Home->\n");
        scanf("%s",home);
        printf("Enter Office->\n");
        scanf("%s",office);
        int st,dest;

        for(i=1;i<=n;i++)		//loop for connecting the edges.
        {
                if(strcmp(arr[i].name,home)==0)         st=i;
                else if(strcmp(arr[i].name,office)==0)          dest=i;

                for(j=i+1;j<=n;j++)
                {
                com=0;
                        for(k=0;k<124;k++)	//checking the condition for edges.
                        {
                                if(arr[i].tmp[k]!=0&&arr[j].tmp[k]!=0)
                                com+=min(arr[i].tmp[k],arr[j].tmp[k]);
                        }
       	        if(arr[i].char_length-arr[j].char_length==1&&com>=1) 	{ wt[j][i]=1; arr[j].ne[++arr[j].cnt]=i;	}

                else if(arr[j].char_length-arr[i].char_length==1&&com>=1) { wt[i][j]=1; arr[i].ne[++arr[i].cnt]=j;	}

                else if(arr[i].char_length-arr[j].char_length==2&&com>=2) { wt[j][i]=1; arr[j].ne[++arr[j].cnt]=i;	}

                else if(arr[j].char_length-arr[i].char_length==2&&com>=2) { wt[i][j]=1; arr[i].ne[++arr[i].cnt]=j;	}  
                }
        }
        int distance;
        for(i=1;i<=n;i++)		//assigning weights to the edges.
        {
                for(j=i+1;j<=n;j++)
                {
		distance=0;
                        if(wt[i][j]==1||wt[j][i]==1)
                        {
                                for(k=0;k<max(strlen(arr[i].name),strlen(arr[j].name));k++)
                                {
                                        if(k>=min(strlen(arr[i].name),strlen(arr[j].name)))
                                              distance+=(strlen(arr[i].name)>strlen(arr[j].name))?arr[i].name[k]:arr[j].name[k];

                                        else
                                              distance+=fabs(arr[i].name[k]-arr[j].name[k]);
                                }
                        if(wt[i][j]==1) wt[i][j]=distance;
                        else    wt[j][i]=distance;
                        }
                }
        }

bool final[n+1];
	for(i=0;i<=n;i++)	final[i]=false;

	arr[st].val=0;
	int req_index,min_d;
	while(1)		//implementing djikstra algorithm.
	{
	
	min_d=INF;
	for(i=1;i<=n;i++)
	{
		if(final[i]==false && arr[i].val<min_d)
		{
		min_d=arr[i].val;
		req_index=i;
		}
	}
	final[req_index]=true;
	if(final[dest]==true||(min_d==INF&&i==n+1))	break;
	
      for(i=0;i<=arr[req_index].cnt;i++)
      {
      if(final[arr[req_index].ne[i]]==false&&arr[arr[req_index].ne[i]].val>arr[req_index].val+wt[req_index][arr[req_index].ne[i]])
		{
		arr[arr[req_index].ne[i]].val=arr[req_index].val+wt[req_index][arr[req_index].ne[i]];
		arr[arr[req_index].ne[i]].parent=req_index;
		}
      }

	}
	
        if(arr[dest].val==INF)
        {
        printf("There is no path from home to office.");
        return 0;
        }

        printf("There is a path from home to office.\nThe required path is->\n");
	print_path(arr,dest,0);		//calling print_path function.
return 0;
}

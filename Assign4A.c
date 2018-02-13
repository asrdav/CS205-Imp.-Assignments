//To sort the order of the patients accoding to the priority decided as per the question and then print the order of arrival of the patients.

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

struct data		//struct data created to represent basic details of a patient.
        {
                char name[100];
                double time;
        };


int heap_size;		//heap_size is size of the priority heap made.
struct data pat[1000];	//pat array is used to store the data of n patients.
char word[100];		//word variable is the Doctor's name.
int c3[26]={0};


void swap1(int a,int b)		//swap function created to swap the structures.
                {
                        struct data t;
                        t=pat[a];
                        pat[a]=pat[b];
                        pat[b]=t;
                }


int comp(int a,int b)			//comp function to comp. given argument as per the priority given in the question.
        {
                int c1[26]={0};
                int c2[26]={0};
                int i=0,j=0;

                while(i<strlen(pat[a].name))		//while loop made to find occurences of characters in 1st string.
                {
		if(c1[i]==' ')
		{
		i++;
		continue;	
		}
		char c=tolower((pat[a].name)[i]);
                c1[c-'a']++;
                i++;
                }

                while(j<strlen(pat[b].name))		//while loop made to find occurences of characters in 2nd string.
                {
		if(c2[j]==' ')
		{
		j++;
		continue;
		}
		char c=tolower((pat[b].name)[j]);
                c2[c-'a']++;
                j++;
                }

                int k=0;
                int x=0,y=0;

                while(k<26)		//while loop used to see no. of unique common characters of patient's name with doctor's name.
                {
                if(c1[k]!=0&&c3[k]!=0)
                x++;
                if(c2[k]!=0&&c3[k]!=0)
                y++;
                k++;
                }
if(x>y)
return 1;
else if(x==y&&pat[a].time<pat[b].time)
return 1;
else
return 0;

}

		
void max_heapify(int val)		//max_heapify function used to extract the maximum priority patient in available list of patients.
{
	  int l=2*val+1;
                int r=2*val+2;
                int smallest=val;

                if(l<=heap_size && comp(l,val)==1)		//comp function called.
                smallest=l;
                if(r<=heap_size && comp(r,smallest)==1)		//comp. function called.
                smallest=r;
		
		if(smallest!=val)
		{
                swap1(val,smallest);
                max_heapify(smallest);		//max_heapify function recursively called.
		}
}


void build_heap(int j)			//build_heap is used to create the heap.
{
	while(j>=0)
	{
	max_heapify(j);
	j--;
	}
}


int partition (int low, int high)		//partition function is made to create partition for quick sorting array of structures according to time.
{
    		float main= pat[high].time;
    		int i = low - 1,j;

    		for(j = low;j <= high- 1;j++)
    		{
        	if(pat[j].time<=main)
        	{
           	i++;
            	swap1(i,j);
        	}
    		}
    		swap1(i+1,high);
return (i + 1);
}

void quickSort(int low, int high)		//quick_Sort function made to quick_sort the array.
{
	int par;
    		if (low < high)
    		{
        	par = partition(low, high);		//partiton function called.
        	quickSort(low, par - 1);		//quick_Sort function called.
        	quickSort(par + 1, high);		//quick_Sort function called.
    		}
}


int main()
{
        int n;
                int k=0;
                struct data final[1000];		//final array is the final list.
                int i=0;
                        int temp1,temp2;
		printf("Doctor's name->");
		scanf("%[^\n]",word);		

                printf("Enter n:");
                scanf("%d",&n);
		
		printf("Enter time in 24 hour format(hr.min)\n(Ex->8.01 means 8hr:1min)\n");
                while(i<n)
                {
		printf("Enter patient's name->");
                scanf(" %[^\n]",pat[i].name);
		printf("Enter time of arrival->");
		scanf("%lf",&pat[i].time);
                i++;
                }
               
                int m=0;

                while(m<strlen(word))			//while loop made to find occurences of different characters in Doctor's name.
                {
		if(word[m]==' ')
		{
		m++;
		continue;
		}
		c3[tolower(word[m])-'a']++;
                m++;
                }

                   	quickSort(0,n-1);		//quickSort function called.
	
		int y=0,z,x=0;
		heap_size=-1;
while(y<n)				//while loop made to insert the patients registering during a time interval.
{
		int z=k;
	while(k<n-y)			//while loop made to take care of case when heap_size becomes 0 in the middle.
	{
		if(pat[k].time<=8.00+(x/6)+((x%6)*0.1))	
		k++;
		else if(k==0&&heap_size==-1)
		{
		x++;
		continue;
		}
		else 	break;
	}
	if(z!=k)
	heap_size+=fabs(z-k);

	(heap_size>0)?build_heap((heap_size-1)/2):build_heap(0);	//build_heap funtion called.
x++;
y++;
	struct data t=pat[0];
	for(i=0;i<n-y;i++)
	pat[i]=pat[i+1];
	pat[i]=t;

	k--;
heap_size-=1;
}
	printf("The order of the patients are:\n");
	for(i=n-1;i>=0;i--)		//for loop made to print the final list of patients.
	printf("%s\n",pat[i].name);
return 0;
}

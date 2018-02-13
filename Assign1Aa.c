//Name-Abhinav Siddharth
//Roll no.-1601CS01
//Date-4.8.2017
//To create a linked list where each node contain a part of student's name which distinguishes students,and then sort the linked list and then print full names.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max(a,b) ((a)>(b)?a:b)		//max function made using macros.
#define min(a,b) ((a)<(b)?a:b)		//min function made using macros.

	struct node{			//node is basic unit of linked list.
	char c2[1000];
	char c3[1000];
	struct node *next;
	};


    struct node *head=NULL,*prev;	
    int n;


    void sort()				//sort function made to sort the list.
    {
    struct node *r,*s,*prev2,*prev1,*q,*p;
    s=head;
    r=s;
    int m=1;

    while(m!=n)			//while loop for carrying out insertion sort.
    {
	q=r;
	p=s->next;
    	prev2=r=prev1=s;

    while(p!=NULL)		//while loop for carrying out the comparisons of the data in the list.
	{
    if(strcmp(r->c2,p->c2)>0)
    {	
	r=p;    
	prev1=prev2;
    }
    prev2=p;
    p=p->next;    
	}
	prev1->next=r->next;
	if(r!=s)r->next=s;
	else
	s=s->next;
 
    	if(s==head)
        head=r; 
	else
	q->next=r;	
    m++;
    }
    }



    void print()		//print function made to print the full names present in the list.
    {
	struct node *p;
    p=head;
    while(p!=NULL)
    {
    printf("%s\n",p->c3);
    p=p->next;
    }
    }


int main()
{
    struct node *p;
    printf("Enter no. of students->");
    scanf("%d",&n);	//n is no. of students.

    char c[n][1000];	//c array made to take the names of the students.
    char c1[n][1000];	//c1 array made to take the distinguishing criteria of students.
    int i=0,m=0,j,k;

    while(i<n)		//while loop made to take the names of students.
    {
    scanf("%s",c[i]);
    i++;
    }
        for(i=0;i<n;i++)	//for loop made to make the comparisons and then store the required criteria of students in c1 array.
	{
        m=0;
        for(j=0;j<n;j++)
	{
        if(i==j)continue;

        for(k=0;k<max(strlen(c[i]),strlen(c[j]));k++)	//for loop made to iterate over the length of the comparators.
	{

        if(c[i][k]!=c[j][k])
	{
	m=max(m,k);
	break;	
	}
        }

	if(c[i][k]=='\0'&&c[j][k]=='\0')
	m=k-1;
        }
        strcpy(c1[i],c[i]);		//required data copied.
        c1[i][m+1]='\0';
        }
    i=0;

    for(i=0;i<n;i++)		//for loop made to enter the data in the list.
	{
    p=(struct node*)malloc(sizeof(struct node));

    strcpy(p->c2,c1[i]);
    strcpy(p->c3,c[i]);
    p->next==NULL;
    if(head==NULL)head=p;
    else    
    prev->next=p;

    prev=p;    
	}

    sort();		//sort function called.
    print();		//print function called.
return 0;
}

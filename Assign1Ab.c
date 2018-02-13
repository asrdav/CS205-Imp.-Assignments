//To create 2 separate linked lists of length x and y and then arrange list such that vowels come before consonants and then print list(or sublist) that are palindrome.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

	struct node			//node is basic unit of linked list.
	{
	char ch;
	struct node *next;
	};
	
	struct node *head1=NULL,*head2=NULL;	//head1 and head2 declared globally are head pointers for the linked lists.
	char c1[2][500];			//c1 array made to store 2 linked list final data.
	int m=0;

void arrange(int z)				//arrange function made to arrange the characters in the given order.
{
	struct node *head=NULL;

	if(z==1)
	head=head1;
	else
	head=head2;

	struct node *p=head;
	struct node *prev1=head,*s=NULL;
	int i=0;	
	while(p!=NULL)				//while loop made to separate the vowels and then place them at start.
	{
	char c3=p->ch;
	if(c3=='A'||c3=='E'||c3=='I'||c3=='O'||c3=='U'||c3=='a'||c3=='e'||c3=='i'||c3=='u'||c3=='o')	//if block for vowels.
	{
	if(p!=head)
	{
	prev1->next=p->next;
	if(s==NULL)
	{
	p->next=head;
	head=p;
	}

	else
	{
	p->next=s->next;
	s->next=p;
	}
	}

	s=p;
	}
	prev1=p;
	p=p->next;
	}
	p=head;
	while(p!=NULL)			//while loop for assigning the characters of linked lists separately in c1 array.
	{
	c1[z-1][i]=p->ch;
	p=p->next;
	i++;
	}
	(z==1)?(head1=head):(head2=head);	//conditional opeartor used for using head as a dummy variable.
}
	

void print(int z)		//print function made to print the 2 lists separately using head as a dummy variable.
{
	struct node *head=NULL;
	if(z==1)
	head=head1;
	else
	head=head2;

	struct node *p=head;
	while(p!=NULL)		//while loop made to print the list.
	{
	printf("%c ",p->ch);
	p=p->next;
	}
	printf("\n");
}


void palindrome(int z)			//palindrome function made to check the palindrome list or sublist.
{
	int i=0,j;
	int l,r,e,f;

	while(i<strlen(c1[z-1])-1)	//while loop made to iterate the list.
	{
for(j=i+1;j<strlen(c1[z-1]);j++)	//for loop made to vary the comparants.
{
	l=e=i;
	r=f=j;

	while(r>l)			//while loop made to check palindromes.
	{
	if(c1[z-1][l]==c1[z-1][r])
	{
	l++;
	r--;
	}
	else	break;
	}


	if(r<l||r==l)
	{
	m++;
	while(e<=f)		//while loop made to print the required palindromes.
	{
	printf("%c ",c1[z-1][e]);
	e++;
	}
	printf("\n");
	}
}
	i++;
	}	
}	


int main()
{	
	int x,y;
	int n,i=0;

	struct node *p1,*prev1;
	struct node *p2,*prev2;
	printf("Enter no. of entries->");
	scanf("%d",&n);		//n is total no. of entries.
	char c[n][1000];		//c array made to store the names of students.

	if(n%2==0)		//if-else block made to calculate x and y.
	{	
	x=n/2;
	y=n/2;
	}
	else
	{
	x=n/2;
	y=n-n/2;
	}

	while(i<n)			//while loop made to create 2 lists.
	{
	if(i<x)				//if-else block made to create the 2 lists.
		{
	scanf("%s",c[i]);

	p1=(struct node*) malloc(sizeof(struct node));		//allocating memory for variable node p1.
	p1->ch=c[i][0];	
	p1->next=NULL;

	if(head1==NULL)
	head1=p1;
	else
	prev1->next=p1;
	prev1=p1;
		}

	else
		{
	scanf("%s",c[i]);
	p2=(struct node*) malloc(sizeof(struct node));		//allocating memory for variable node p2.
	p2->ch=c[i][0];	
	p2->next=NULL;

	if(head2==NULL)
	head2=p2;
	else
	prev2->next=p2;
	prev2=p2;
		}

	i++;
	}
arrange(1);		//arrange function called to arrange 1st list.
arrange(2);		//arrange function called to arrange 2nd list.

	print(1);	//print function called to print 1st list.
	print(2);	//print function called to print 2nd list.

	printf("Palindromes in 1st linked list:\n");
palindrome(1);		//palindrome function called to check palindrome in 1st list.
	if(m==0)printf("No palindromes in 1st linked list.\n");
	m=0;

	printf("Palindromes in 2nd linked list:\n");	
palindrome(2);		//palindrome function called to check palindrome in 2nd list.
	if(m==0)printf("No palindromes in 2nd linked list.\n");
return 0;
}

//Make a library system where one can issue books,return books,make new entries,see available books and also details of the book.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct book                      //book node is the basic unit of linked list.
	{
	int s_no;
	char title[100];
	char author[100];
	char issue_status[100];
	struct book *next;
	};

int main()
{
	char choice;			//choice is the choice entered by user.
	int m=0;
	struct book *head=NULL,*p,*prev,*q;	//book pointers declared to traverse the list.
	printf("a->Make a new entry of book.\nb->View details of book.\nc->Show list of available books.\nd->Issue a book.\ne->Return a book.\nf->Exit.\n");

	while(1)			//while loop initiated.
	{
	printf("Enter a choice:\n");
	scanf(" %c",&choice);				//choice entered.

	switch(choice)			//switch statement initiated.
	{
	case 'f':	return 0;		


	case 'a':
	{
	printf("Enter book details:\n");
	p=(struct book*) malloc(sizeof(struct book));	//allocating memory for the node.
	printf("Serial no.->\n");
	scanf("%d",&p->s_no);
	printf("Title->\n");
	scanf(" %[^\n]",p->title);
	printf("Author->\n");
	scanf(" %[^\n]",p->author);
	strcpy(p->issue_status,"Not Issued");
	p->next=NULL;

	if(head==NULL)				//making the linked list.
	head=p;
	else
	prev->next=p;
	prev=p;
	printf("New Entry Successful\n");
	break;
	}


	case 'b':
	{
	if(head==NULL)
	printf("No entry made. Please make a entry.\n");
	else
	{
	printf("1)By serial no.\n2)By title\n3)By Author\nEnter option->\n");
	int choice1;
	scanf("%d",&choice1);		//choice entered by user on entering option b.

	switch(choice1)
	{
	case 1:	
	{
	printf("Enter Serial no.->\n");	
	int num;
	scanf("%d",&num);
	q=head;
	while(q!=NULL&&q->s_no!=num)		//while loop for finding the book acc. to sl.no.
	q=q->next;

	if(q==NULL)	printf("Book not found.\n");
	else
	printf("Slno.->%d    Title->%s    Author->%s    Issue_Status->%s\n",q->s_no,q->title,q->author,q->issue_status);
	break;
	}

	case 2:
	{
	m=0;
	printf("Enter title->\n");
	char c1[100];
	scanf(" %[^\n]",c1);
	q=head;
	while(q!=NULL)				//while loop for finding the book acc. to title.
	{
	if(strcmp(q->title,c1)==0)
	{
	printf("Slno.->%d    Title->%s    Author->%s    Issue_Status->%s\n",q->s_no,q->title,q->author,q->issue_status);
	m++;
	}		
	q=q->next;
	}

	if(m==0)	printf("Book not found.\n");
	break;
	}

	case 3:
	{
	m=0;
	printf("Enter author->\n");		
	char c2[100];
	scanf(" %[^\n]",c2);
	q=head;

	while(q!=NULL)				//while loop for finding the book acc. to author.
	{
	if(strcmp(q->author,c2)==0)
	{
	printf("Slno.->%d    Title->%s    Author->%s    Issue_Status->%s\n",q->s_no,q->title,q->author,q->issue_status);
	m++;
	}	
	q=q->next;
	}

	if(m==0)	printf("Book not found.\n");		//if block in case no book is found.
	break;
	}

	default:	printf("Wrong option chosen\n");	//default case when wrong option is entered under case b.
	}
	}
	break;
	}


	case 'c':
	{
	q=head;
	int n=0;
	if(head==NULL)
	printf("No entry made. Please make a entry.\n");

	else
	{
	while(q!=NULL)						//while loop to show availability of books.
	{
	if(strcmp(q->issue_status,"Not Issued")==0)
	{
	n++;
	printf("Slno.->%d    Title->%s    Author->%s    Issue_Status->%s\n",q->s_no,q->title,q->author,q->issue_status);
	}	
	q=q->next;
	}
	if(n==0)
	printf("No books available. All books are issued.\n");
	}
	break;
	}


	case 'd':
	{
	if(head==NULL)
	printf("No entry made. Please make a entry.\n");
	
	else
	{
	int num1;
	printf("Enter sl.no->\n");
	scanf("%d",&num1);	
	q=head;
	while(q!=NULL&&q->s_no!=num1)		//while loop to find the book is issued or not.
	q=q->next;

	if(q==NULL)	printf("No such Book exists.\n");
	else
	{
	if(strcmp(q->issue_status,"Issued")==0)
	printf("Book already issued.\n");

	else
	{
	q->issue_status[0]='\0';
	strcpy(q->issue_status,"Issued");
	printf("Book issued.\n");
	}
	}
	}	
	break;
	}
	

	case 'e':
	{
	if(head==NULL)
	printf("No entry made. Please make a entry.\n");
	
	else
	{
	int num2;
	printf("Enter sl.no->\n");
	scanf("%d",&num2);
	q=head;
	while(q!=NULL&&q->s_no!=num2)			//while loop to find if the book is issued or not.
	q=q->next;

	if(q==NULL)	printf("No such Book exists.\n");

	else
	{
	if(strcmp(q->issue_status,"Not Issued")==0)
	printf("Book already present.\n");

	else
	{
	q->issue_status[0]='\0';
	strcpy(q->issue_status,"Not Issued");
	printf("Book returned.\n");
	}
	}
	}
	break;
	}


	default:	printf("Wrong choice entered\n");		//default case when wrong choice entered.
	}
	}
return 0;
}
	

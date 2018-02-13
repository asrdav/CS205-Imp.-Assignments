//Name-Abhinav Siddharth
//Roll No.-1601CS01
//Date-02.09.2017
//To sort the players first according to their test score and then according to their name lexicographically if scores are same by linear sorting algorithm.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxm(a,b) ((a)>(b)?a:b)		//maxm is defined to find maximum of 2 numbers.


struct data				//struct data is made to store name and score.
{
	char name[1000];
	int score;
};


int max=0,n,length;			
struct data list[1000];			//list array is made to store the datas.
struct data final1[1000];		//final array is made to store the temporary output in functions called.


void count_sort_char(int st,int la,int temp)      //count_sort_char function is made to sort temp's place letter in given set of names.
{			//st is start index of set of name considered and la is last index of set of name considered.

	int i,temp1[123]={0};		//temp1 array is made to store occurences of letters in list of names considered.

    	for(i=st;i<=la;i++)
	{
	if(length-temp>=strlen(list[i].name))
	{
	temp1[65]++;
	continue;
	}

        temp1[(list[i].name)[length-temp]]++;
	}

    	for(i=1;i<123;i++)
        temp1[i]+=temp1[i-1];
 
    	for(i=la;i>=st;i--)
    	{

	if(length-temp>=strlen(list[i].name))
	{
	final1[st+temp1[65]-1]=list[i];
	temp1[65]--;
	continue;
	}

        final1[st+temp1[(list[i].name)[length-temp]]-1] = list[i];
        temp1[(list[i].name)[length-temp]]--;
    	}

    	for(i=st;i<=la;i++)		//for loop made to store the final sorted input in list array.
        list[i] = final1[i];
}


void radix_sort_char(int st,int la)		//radix_sort_char function called to sort given set of names in linear time.
{
	if(st==la)		//st is start index of set of name considered and la is last index of set of name conidered.
	return ;
	int temp=1;
	
	while(temp<=length)		//length is max. length of name in given set of names.
	{
	count_sort_char(st,la,temp);	//count_sort_char function called.
	temp++;
	}
}	


void count_sort(int temp)		//count_sort is used to sort the temp's place digit in given set of numbers.
{				//temp is the place of the digit passed.

    	int i,temp1[10]={0};		//temp1 array is made to store the occurences of digits in list of numbers.

    	for(i=0;i<n;i++)		
        temp1[(list[i].score/temp)%10]++;

    	for(i=1;i<10;i++)
        temp1[i]+=temp1[i-1];
 
    	for(i=n-1;i>=0;i--)
    	{
        final1[temp1[(list[i].score/temp)%10]-1] = list[i];
        temp1[(list[i].score/temp)%10]--;
    	}
 
    	for(i=0;i<n;i++)	//for loop made to store the sorted input of final array in list array.
        list[i] = final1[i];
}


void radix_sort_num()			//radix_sort_num function is made to sort the list according to numbers in linear time.
{
	int temp=1;
	while(max/temp>0)		//while loop made to consider all numbers having variable length. 
	{
	count_sort(temp);		//count_sort function called.
	temp*=10;
	}
}
	

int main()
{
	printf("Enter the number of datas:");
	scanf("%d",&n);			//n is no.of datas.
	int i=0;

	while(i<n)
	{
	printf("Enter the name of test player:\n");
	scanf(" %[^\n]",list[i].name);
	printf("Enter the test score:\n");
	scanf("%d",&list[i].score);

	max=maxm(list[i].score,max);		//max is used to store the maximum of test scores.
	i++;
	}

	radix_sort_num();			//radix_sort_num function called.
	int k=0;
	i=0;
	length=strlen(list[i].name);	

	for(i=1;i<n;i++)
	{
	if(list[i].score==list[i-1].score)		//checking if score is same.
	continue;
	else
	{
	radix_sort_char(k,i-1);
	k=i;
	}
	length=maxm(length,strlen(list[i].name));	//length is used to store the maximum length of name along all names.
	}

	radix_sort_char(k,i-1); 			//radix_sort_char function called.

	printf("The sorted list->\n");

	for(i=0;i<n;i++)			//for loop is used to print the list.
	printf("%s     %d\n",list[i].name,list[i].score);

return 0;
}

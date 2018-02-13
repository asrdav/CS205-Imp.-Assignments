//To determine if a given word is even or not.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

        char c;				//c is the first letter of the word in recursion.
        int j=0;
        bool cond1=false;

void swap(char *a,char *b)		//swap function used to swap the characters.
{
        char c1;
        c1=*a;
        *a=*b;
        *b=c1;
}

int start,last;		//start is the starting index of array in recursion and last is the ending index of array in recursion.


bool Is_even_string_word(char *str)		//Is_even_string_word function is made to determine the result.
{

        if(start>last)			//base condition of recursion.
        {
        if(j==strlen(str))
        return true;
        else
        return false;
        }

        if(str[start]==c)
        {
        swap(&str[start],&str[j+1]);		//swap function called.
        j=j+2;
        c=str[j];
	start=j+1;
        cond1=Is_even_string_word(str);		//recursive call to function made.
        }

        else
	{
	start+=1;
        cond1=Is_even_string_word(str);	//recursive call to function made.
	}

return cond1;
}


int main()
{	
        char str[100005];		//str array is used to store the word.
	printf("Enter the string->");
        scanf("%s",str);
        c=tolower(str[0]);
	start=1;
	last=strlen(str)-1;	
		
        bool cond;

        if(strlen(str)%2==0)
        {
        cond=Is_even_string_word(str);		//Is_even_string_word function called.
        if(cond==true)
        printf("The word is even.");
        else
        printf("The word is not even.");
        }

        else
           printf("The word is not even.");

return 0;
}

//To write a c program for multiplying two n-bit numbers by an O(n^1.59) algo. that breaks problems into lesser subproblems.
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>


int length(char a[],char b[])		//length function created to append 0's at the start of the string.
{
int len1,len2,i;			//len1,len2 are respective lengths of argument arrays a and b.

	for(i=0;a[i]!='\0';i++);	//for loop for finding len1.
	len1=i;

	for(i=0;b[i]!='\0';i++);	//for loop for finding len2.
	len2=i;
	char bel[1000];			//bel array is a temporary array used for calc. convenience.
	if(len2>len1)			//if -else if -else block made to cover all possible cases.
	{
		for(i=0;i<len1;i++)	
		bel[i]=a[i];
	
		for(i=0;i<len1;i++)
		a[i+len2-len1]=bel[i];

		a[len2]='\0';		//completing the string by setting into null character.
		for(i=0;i<=len2-len1-1;i++)	//for loop for appending the zeroes at top.
		a[i]='0';
	return len2;
	}

	else if(len1>len2)
	{	
		for(i=0;i<len2;i++)
		bel[i]=b[i];
		int i;

		for(i=0;i<len2;i++)
		b[i+len1-len2]=bel[i];

		b[len1]='\0';
		for(i=0;i<=len1-len2-1;i++)	//for loop for appending the zeroes at top.
		b[i]='0';
	return len1;
	}
	else
	return len1;
}			


char *add(char temp1[],char temp2[])		//arr function made to return the required array obtained after adding the bits.
{
	int len=length(temp1,temp2);		//length function called.
	int j,k;
	int carry=0,i;
	char add_array[1000];			//add_array is the array changes are incorporated into.
	char t,*t3;

	for(i=len-1;i>=0;i--)			//for loop made to add the bits.
	{

	int bit1=temp1[i]-'0';			//bit1 is the bit of first array being added.
	int bit2=temp2[i]-'0';			//bit2 is the bit of 2nd array being added.
	
	int num1=(bit1^bit2^carry)+'0';		//XOR operation used to calculate num.
	t=(char)num1;
	if(i==len-1)				//if -else block made to append the lengths.
	{
	add_array[0]=t;
	add_array[len+1]='\0';
	j=1;
	}

	else
	{
	char t1[1000];			//t1 is a temporary array made for ease.
	for(k=0;k<j;k++)
	t1[k]=add_array[k];

	for(k=0;k<j;k++)		//for loop made to append the required character at the top.
	add_array[k+1]=t1[k];
	j=k+1;
	add_array[0]=t;
	}

	carry=(bit1&bit2)|(bit1&carry)|(bit2&carry);		//carry value calculated.
	}

	if(carry==1)			//if  block made if value of carry at last is 1.
	{
	char t2[1000];
	for(k=0;k<j;k++)
	t2[k]=add_array[k];

	for(k=0;k<j;k++)
	add_array[k+1]=t2[k];
	j=k+1;
	add_array[0]='1';
	}
	add_array[j]='\0';		//terminating add_array.

	t3=add_array;
return t3;
}
	

long int multiply(char a[],char b[])		//multiply function made to multiply the numbers in binary form and return its decimal equ.
{
	int y=length(a,b);
	int i;
	if(y==1)
	return (a[0]-'0')*(b[0]-'0');		//base condition of recursion.

	char temp1[1000];		//temp1,temp2,temp3 and temp4 are the respective subhalves.
	char temp2[1000];
	char temp3[1000];
	char temp4[1000];
	char new1[1000];
	char new2[1000];

	int first=y/2;			//first denotes the last index of required subarray.
	int second=y-first;		//second denotes the last index of required subarray.

	strcpy(temp1,a);
	temp1[first]='\0';
	
	memcpy(temp2,&a[first],second);
	temp2[second]='\0';

	strcpy(temp3,b);
	temp3[first]='\0';

	memcpy(temp4,&b[first],second);
	temp4[second]='\0';

	long int r1=multiply(temp1,temp3);		//multiply function recursively called.

	long int r2=multiply(temp2,temp4);		//multiply function recursively called.
	
	char *p1=add(temp1,temp2);			//add function called on 1st integer.

	for(i=0;p1[i]!='\0';i++)			//for loop for copying into new1 array.
	new1[i]=p1[i];
	new1[i]='\0';

	char *p2=add(temp3,temp4);			//add function called on 2nd integer.
	
	for(i=0;p2[i]!='\0';i++)			//for loop for copying into new2 array.
	new2[i]=p2[i];
	new2[i]='\0';
	
	long int r3=multiply(new1,new2);		//multiply function recursively called on new1 and new2 array.

	second=(y%2==0)?y/2:y-y/2;

return 	pow(2,2*second)*r1 + pow(2,second)*(r3-r1-r2) + r2;
}


int main()
{
	char str1[1000],str2[1000];		//str1 is to store 1st integer as binary form and so for str2 for 2nd integer.
	int a,b,i=0;
	int len1,len2;
	printf("Enter two numbers:\n");
	scanf("%d %d",&a,&b);			//a and b are the two numbers entered.

	if(a==0||b==0)	
	{
	printf("The product of numbers is 0");
	return 0;
	}

	double x=log((double)a)/log(2);
	double y=log((double)b)/log(2);

	while(a!=0)			//while loop to create str1 array.
	{
	str1[((int)x)-i]=a%2+'0';
	i++;
	a=a/2;
	}
	
	len1=i;
	i=0;
	while(b!=0)			//while loop to create str2 array.
	{
	str2[((int)y)-i]=b%2+'0';
	i++;
	b=b/2;
	}
	
	len2=i;
	str1[len1]='\0';
	str2[len2]='\0';
	long int  final=multiply(str1,str2);		//multiply function called on str1 and str2 array.
	printf("The product is:%ld",final);
	
return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

typedef int bool;
#define False 0
#define True 1

void PrintNum(char *number);
void Print1ToMaxN(int n);
void Print1ToMaxNRecursively(char *number,int length,int index);

void Print1ToMaxN(int n)
{
	int i=0;
	char *number=(char *)malloc((n+1)*sizeof(char));
    memset(number,'0',n);
	number[n]='\0';
    
	if(n<=0)
	{
		return ;
	}

	for(i=1;i<10;i++)
	{
		number[0]=i+ '0';
		Print1ToMaxNRecursively(number,n,0);
	}

	free(number);
}

void Print1ToMaxNRecursively(char *number,int length,int index)
{
	int i;
	if(index=length - 1)
	{
       PrintNum(number);
		return;
	}

	for(i=0;i<10;++i)
	{
		number[index+1]=i+'0';

		Print1ToMaxNRecursively(number,length,index+1);
	}
}
/*
void PrintNum(char *number)
{
	bool arryBit=True;
	int len=strlen(number);
	int i=0;
	for(i=0;i<len;++i)
	{
		if(arryBit && number[i]!='0')
		{
			arryBit=False;

		}
		if(!arryBit)
		{
			printf("%c",number[i]);
		}
	}
	printf("\t");
}*/

void PrintNum(char* number)					
{
	//bool isBegin0 = true;
	int Length = strlen(number);
	int i;
	for(i = 0; i < Length; i++)
	{
		if (number[i] != '0')
			break;
	}
	printf("%s ",&number[i]);
	
}

int main()
{
	Print1ToMaxN(2);
	return 0;
}
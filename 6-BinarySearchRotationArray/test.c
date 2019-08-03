#include<stdio.h>
#include<stdlib.h>


int MinInorder(int *number,int Index1,int Index2)
{
	int result=number[Index1];
	int i=0;
	for(i=Index1+1;i<=Index2;++i)
	{
		if(number[i]<result)
		{
			result=number[i];
		}
	}
	return result;
}

int MinRotate(int *number,int length)
{
	int Index1=0;
	int Index2=length-1;
	int Midlle=Index1;
	if(number==NULL||length<=0)
	{
		
		return 1;
	}
	while(number[Index1]>=number[Index2])
	{
		if(Index2-Index1==1)   //exit condition
		{
			Midlle=Index2;

			break;
		}
      Midlle=(Index1+Index2)/2;
	  if(number[Index1]==number[Index2]&&number[Midlle]==number[Index2])
	  {
		  return MinInorder(number,Index1,Index2);
	  }
	  if(number[Midlle]>number[Index1])
	  {
           Index1=Midlle;    // Move the Index position
	  }
	  if(number[Midlle]<number[Index2])
	  {
		  Index2=Midlle;     
	  }
		  
	}
	return number[Index2];
}


int main()
{
	int NUM[5]={1,0,1,1,1};
	int number=MinRotate(NUM,5);
	printf("%d",number);

		return 0;
}
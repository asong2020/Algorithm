#include<stdio.h>


int Numberof1(int n)
{
	int count = 0;
	while(n)
	{
		if(n&1)
			count++;
		n=n>>1;
	}
	return count;
}

int Numberof2(int n)
{
	unsigned int flag=1;
	int count=0;
	while(flag)
	{
		if(n&flag)
		{
              count++;
		}
        flag=flag<<1;
	}
	return count;
}

int Numberof3(int n)
{
	int count=0;
	while(n)
	{
		++count;
		n=(n-1)&n;
	}
	return count;
}

int main()
{
	int a;
	int result;
	scanf("%d",&a);
	result=Numberof3(a);
	printf("%d\n",result);
}
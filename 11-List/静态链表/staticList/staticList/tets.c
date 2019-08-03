#include<stdio.h>

#define Maxsize 1000
typedef int bool;
#define False 0
#define True 1
typedef struct
{
	int data;
	int cur;
}Compent,StaticLinkList[Maxsize];

int main()
{
	return 0;
}

int InitList(StaticLinkList space)
{
	int i;
	for (i = 0; i < Maxsize-1; i++)
	{
		space[i].cur = i + 1;

	}
	space[Maxsize - 1].cur = 0;
	return True;
}
//若备用空间链表非空，则返回分配的节点下标，否则返回0
int Malloc_sll(StaticLinkList space)
{
	int i = space[0].cur;
	if (space[0].cur)
	{
		space[0].cur = space[i].cur;
	}
	return i;
}

//插入元素
int ListInsert(StaticLinkList space,int i,int e)
   
	//先判断插入位置是否合法
	if (i<1 || i>Maxsize)
	{
		return False;
	}
	j = Malloc_sll(space);  //获取当前空闲坐标
	if (j)
	{
		space[j].data = e;
		for ( l = 1; l < i-1;l++)
		{
			k = space[k].cur;
		}
		space[j].cur = space[k].cur;
		space[k].cur = j;
		return True;
	}

}
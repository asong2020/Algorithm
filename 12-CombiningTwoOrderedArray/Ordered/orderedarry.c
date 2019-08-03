#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef int bool;
#define False 0
#define True 1
//合并两个数组函数
int *OrderedArry(int* arry1,int length1, int* arry2,int length2)
{
	int* Newarry = (int*)malloc((sizeof(int) * (length1 + length2)));
	int Newarrt_Length = length1 + length2;  //新数组长度
	int arry1Index = 0,arry2Index = 0;
	int i = 0; 
	//先判断两个数组是否为空
	if (arry1 == NULL && length1 <= 0 && arry2 == NULL && length2 <= 0)
	{
		return False;
	}
	//如果两个数组中某一个数组为空时
	if (arry1 == NULL && arry2 != NULL)
	{
		Newarry = arry2;
	}
	else if (arry1 != NULL && arry2 == NULL)
	{
		Newarry = arry1;
	}
	else
	{
		for (i  = 0;  i< Newarrt_Length; i++)
		{
			if (arry1Index < length1 && arry2Index < length2)
			{
				if (arry1[arry1Index] > arry2[arry2Index])
				{
					Newarry[i] = arry2[arry2Index];
					arry2Index++;
				}
				else
				{
					Newarry[i] = arry1[arry1Index];
					arry1Index++;
				}
				
			}
			else if (arry1Index < length1 )
			{
				Newarry[i] = arry1[arry1Index];
				arry1Index++;
			}
			else if (arry2Index < length2)
			{
				Newarry[i] = arry2[arry2Index];
				arry2Index++;
			}

		}
	}

	return Newarry;

}

int main()
{
	int testarry1[5] = { 1,3,4,5,6 };
	int testarry2[4] = { 2,3,4,7 };
	int* testarry3;
	int i = 0;
	testarry3 = OrderedArry(testarry1, 5, testarry2, 4);
	for (i = 0;i < 9 ;i++)
	{
		printf("%d", *(testarry3+i));
	}
	return 0;
}
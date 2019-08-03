#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int MaxProduct_soluction(int length);


int MaxProduct_soluction(int length)
{
    int length_3;//记录切成3米的个数
    int length_2;//记录切成2米的个数
    int Max;
      //3种特例
    if(length<2)
    {
        return 0;
    }
    if(length==2)
    {
        return 1;
    }
    if(length==3)
    {
        return 2;
    } 
    length_3=length / 3;
        if((length-length_3*3)==1)
        {
            length_3-=1;
        }
    length_2=(length-length_3*3) / 2;
    Max=(int)(pow(3,length_3))*(int)(pow(2,length_2));
	return Max;
}



int main()
{
    int testData=8;
    int result=MaxProduct_soluction(testData);
    printf("The value is %d\n",result);
}
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


//求最大值函数
int MaxProduct(int length)
{
    //建立一个数组存放所得各个子问题的最大值
    int *Product=(int *)malloc((length+1)*sizeof(int));
    int max=0;  //返回乘积最大值
    int i,j;//循环求出子问题最优解
    int Productdata;
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
    Product[0]=0;
    Product[1]=1;
    Product[2]=2;
    Product[3]=3;
    for(i=4;i<=length;i++)
    {
        for(j=1;j<=i/2;j++)
        {
           Productdata= Product[j]*Product[i-j];
            if(max<Productdata)
            {
                max=Productdata;
            }
            Product[i]=max;
        }
    }
    max=Product[length];
    free(Product);
    
    return max;
    
}

int main()
{
    int test = 8;
    int result;
    result=MaxProduct(8);
    printf("The max value is %d\n",result);
}
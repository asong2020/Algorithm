#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
typedef int bool;
#define False 0
#define True 1

int MoveCountCore(int threshold,int rows,int cols,int row,int col,bool *visitd);
int GetSum(int number);
int MoveCount(int threshold,int rows,int cols);
//检查机器人能否进入方格
bool check(int Threshold,int rows,int cols,int row,int col,bool *visitd);



//定义返回函数
int MoveCount(int threshold,int rows,int cols)
{
    int count=0;//记录移动次数
	int i;
    bool *visitd=(bool *)malloc((rows*cols)*sizeof(int));//定义布尔型矩阵，标识格子
   
    
    //先进行判断
    if(threshold<0||rows<=0||cols<=0)
    {
        return 0;
    }
	for(i = 0; i < rows * cols; ++i)
	{
		visitd[i]=False;
	}
	//memset(visitd,0,rows*cols);
    count=MoveCountCore(threshold,rows,cols,0,0,visitd);


    free(visitd);
    return count;
}
//遍历函数
int MoveCountCore(int threshold,int rows,int cols,int row,int col,bool *visitd)
{
    int count1=0;
    if(check(threshold,rows,cols,row,col,visitd))
    {
        visitd[row*cols+col]=True;
        count1=1 + MoveCountCore(threshold,rows,cols,row-1,col,visitd) 
			+ MoveCountCore(threshold,rows,cols,row,col-1,visitd)
            + MoveCountCore(threshold,rows,cols,row+1,col,visitd)
            + MoveCountCore(threshold,rows,cols,row,col+1,visitd);
    }

    return count1;
}
//检查机器人能否进入方格
bool check(int Threshold,int rows,int cols,int row,int col,bool *visitd)
{
    if(row>=0 && row<rows && col>=0 && col<cols
		&& (GetSum(row)+GetSum(col))<=Threshold && !visitd[row*cols+col])
	{
        return True;
	}
    else{

    return False;
	}
    
    
}
//位数求和函数
int GetSum(int number)
{
    int sum=0;
    while(number>0)
    {
        sum+=number%10;
        number/=10;
    }
    return sum;
}

//测试函数
void test(char *testname,int Threshold,int rows,int cols,int expected)
{
	int Mcount=0;
    if(testname != NULL)
        printf("%s begins: ", testname);

	Mcount=MoveCount(Threshold, rows, cols);
	printf("the value is %d\n",Mcount);

    if(MoveCount(Threshold, rows, cols) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");    
}
   
       // 方格多行多列
void test1()
{
    test("Test1", 5, 10, 10, 21);
}

// 方格多行多列
void test2()
{
    test("Test2", 15, 20, 20, 359);
}

// 方格只有一行，机器人只能到达部分方格
void test3()
{
    test("Test3", 10, 1, 100, 29);
} 

// 方格只有一行，机器人能到达所有方格
void test4()
{
    test("Test4", 10, 1, 10, 10);
}

// 方格只有一列，机器人只能到达部分方格
void test5()
{
    test("Test5", 15, 100, 1, 79);
}

// 方格只有一列，机器人能到达所有方格
void test6()
{
    test("Test6", 15, 10, 1, 10);
}

// 方格只有一行一列
void test7()
{
    test("Test7", 15, 1, 1, 1);
}

// 方格只有一行一列
void test8()
{
    test("Test8", 0, 1, 1, 1);
}

// 机器人不能进入任意一个方格
void test9()
{
    test("Test9", -10, 10, 10, 0);
}

int main()
{
//	int num=12;
//	int reeult=0;

//	reeult=GetSum(num);
//	printf("%d",reeult);
    test8();
    return 0;
}
    
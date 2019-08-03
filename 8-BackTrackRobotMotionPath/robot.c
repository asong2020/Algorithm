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
//���������ܷ���뷽��
bool check(int Threshold,int rows,int cols,int row,int col,bool *visitd);



//���巵�غ���
int MoveCount(int threshold,int rows,int cols)
{
    int count=0;//��¼�ƶ�����
	int i;
    bool *visitd=(bool *)malloc((rows*cols)*sizeof(int));//���岼���;��󣬱�ʶ����
   
    
    //�Ƚ����ж�
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
//��������
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
//���������ܷ���뷽��
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
//λ����ͺ���
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

//���Ժ���
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
   
       // ������ж���
void test1()
{
    test("Test1", 5, 10, 10, 21);
}

// ������ж���
void test2()
{
    test("Test2", 15, 20, 20, 359);
}

// ����ֻ��һ�У�������ֻ�ܵ��ﲿ�ַ���
void test3()
{
    test("Test3", 10, 1, 100, 29);
} 

// ����ֻ��һ�У��������ܵ������з���
void test4()
{
    test("Test4", 10, 1, 10, 10);
}

// ����ֻ��һ�У�������ֻ�ܵ��ﲿ�ַ���
void test5()
{
    test("Test5", 15, 100, 1, 79);
}

// ����ֻ��һ�У��������ܵ������з���
void test6()
{
    test("Test6", 15, 10, 1, 10);
}

// ����ֻ��һ��һ��
void test7()
{
    test("Test7", 15, 1, 1, 1);
}

// ����ֻ��һ��һ��
void test8()
{
    test("Test8", 0, 1, 1, 1);
}

// �����˲��ܽ�������һ������
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
    
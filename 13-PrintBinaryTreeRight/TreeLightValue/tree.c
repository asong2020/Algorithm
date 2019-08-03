#include<stdio.h>
#include<stdlib.h>

typedef int bool;
#define False 0
#define True 1
#define MAXSIZE 10
typedef struct
{
	int data[MAXSIZE];
	int front;//指向队列头
	int rear;  // 尾指针，若队列不空，指向队列尾元素的下一个位置
}SqQueue;

int InitQueue(SqQueue* Q);

int main()
{
	return 0;
}
//初始化队列
int InitQueue(SqQueue* Q)
{
	Q->front = 0;
	Q->rear = 0;
	return False;
}
//循环队列求队列长度
int QueueLenggth(SqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

//队列未满，则插入元素e为W新的对尾元素
int EnQueue(SqQueue* Q, int e)
{
	//先判断队列是否为满
	if ((Q->rear + 1) % MAXSIZE == Q->front)
	{
		return False;
	}
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return True;
}

//循环队列删除Q中对头元素
int DeQueue(SqQueue* Q, int* e)
{
	if (Q->front == Q->rear)//为空
	{
		return False;
	}
	e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return e;
}
#include<stdio.h>
#include<stdlib.h>

typedef int bool;
#define False 0
#define True 1
#define MAXSIZE 10
typedef struct
{
	int data[MAXSIZE];
	int front;//ָ�����ͷ
	int rear;  // βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��
}SqQueue;

int InitQueue(SqQueue* Q);

int main()
{
	return 0;
}
//��ʼ������
int InitQueue(SqQueue* Q)
{
	Q->front = 0;
	Q->rear = 0;
	return False;
}
//ѭ����������г���
int QueueLenggth(SqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

//����δ���������Ԫ��eΪW�µĶ�βԪ��
int EnQueue(SqQueue* Q, int e)
{
	//���ж϶����Ƿ�Ϊ��
	if ((Q->rear + 1) % MAXSIZE == Q->front)
	{
		return False;
	}
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return True;
}

//ѭ������ɾ��Q�ж�ͷԪ��
int DeQueue(SqQueue* Q, int* e)
{
	if (Q->front == Q->rear)//Ϊ��
	{
		return False;
	}
	e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return e;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int bool;
#define False 0
#define True 1

//定义链表结构体
typedef struct Node
{
	int data;       //数据域
	struct Node* Next;  //指向下一节点
}ListNode;

ListNode* create();
void PrintList(ListNode* pHead);
ListNode* TailCreate();
ListNode* ListInsert(ListNode* pHead, int i, int value);
ListNode* ListDelete(ListNode* pHead, int i);
ListNode* ListDelete(ListNode* pHead);
int main()
{
	ListNode* pHead;
	pHead = TailCreate();
	PrintList(pHead);
	//pHead=ListInsert(pHead,2,12);
	//ListDelete(pHead,3);
	//PrintList(pHead);
	//ListDelete(pHead);
	PrintList(pHead);
	return 0;
}
/*
// 创建链表头插法
ListNode* create()
{
	ListNode* Head=NULL;   //定义一个头指针
	ListNode* NewNode = NULL;   //定义一个新节点指针
	int newdata;
	printf("please intput :");
	scanf_s("%d", &newdata);
	printf("\n");
	while (newdata!=0)
	{
		NewNode = (ListNode*)malloc(sizeof(ListNode));  //开辟空间
		NewNode->data = newdata;
		NewNode->Next = Head;
		Head = NewNode;  //插入到表头
		printf("please intput :");
		scanf_s("%d", &newdata);
		printf("\n");
	}
	return Head;

}*/

// 创建链表尾插法
ListNode* TailCreate()
{
	ListNode* Head = NULL;
	ListNode* NewNodeTail=NULL,*NewNodeNow=NULL;
	int newdata;
	int iCount = 0;
	printf("please intput :");
	scanf_s("%d", &newdata);
	printf("\n");
	while (newdata != 0)
	{	
		++iCount;
		if (iCount == 1)
		{
			NewNodeTail = (ListNode*)malloc(sizeof(ListNode));
			NewNodeTail->data = newdata;
			NewNodeTail->Next = Head;
			Head = NewNodeTail;
			NewNodeNow = NewNodeTail;
		}
		else
		{
			NewNodeTail = (ListNode*)malloc(sizeof(ListNode));
			NewNodeTail->data = newdata;
			NewNodeTail->Next = NULL;
			NewNodeNow->Next = NewNodeTail;
			NewNodeNow = NewNodeTail;
		}
		printf("please intput :");
		scanf_s("%d", &newdata);
		printf("\n");
	}
	return Head;
}

//链表的插入   第i个位置插入
ListNode* ListInsert(ListNode* pHead,int i,int value)
{
	ListNode* ListIndex = pHead;
	ListNode* NewListNode = NULL;
	int j = 1;
	while (ListIndex && j < i)
	{
		ListIndex = ListIndex->Next;
		++j;
	}
	if (!ListIndex || j > i)  //第i个元素不在
		return False;
	NewListNode = (ListNode*)malloc(sizeof(ListNode));
	NewListNode->data = value;
	NewListNode->Next = ListIndex->Next;
	ListIndex->Next = NewListNode;
	return pHead;
}

//链表的删除   第i个位置删除
ListNode* ListDelete(ListNode* pHead, int i)
{
	ListNode* ListIndex = pHead;
	ListNode* ListDelete=NULL;
	int j = 1;
	while (ListIndex->Next&&j<i)
	{
		ListIndex = ListIndex->Next;
		++j;
	}
	if (!ListIndex || j > i)
	{
		return False;
	}

	ListDelete = ListIndex->Next;
	ListIndex->Next = ListDelete->Next;
	free(ListDelete);

}

//整个链表的删除  
ListNode* ListDelete(ListNode* pHead)
{
	ListNode* pPre = NULL, *pPend = NULL;
	pPend = pHead->Next;
	while (pPend)
	{
		pPre = pPend->Next;
		free(pPend);
		pPend = pPre;
	}
	pHead->Next = NULL;
	return True;

}

void PrintList(ListNode* pHead)
{
	ListNode* pTemp;// 一临时指针
	int Index = 1;//  标识第几个信息
	pTemp = pHead;
	while (pTemp!=NULL)
	{
		printf("第%d个信息:",Index);
		printf("数据为%d\n", pTemp->data);
		pTemp = pTemp->Next;
		++Index;
	}
	

}

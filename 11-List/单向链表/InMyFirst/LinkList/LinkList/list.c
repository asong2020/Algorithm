#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int bool;
#define False 0
#define True 1

//��������ṹ��
typedef struct Node
{
	int data;       //������
	struct Node* Next;  //ָ����һ�ڵ�
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
// ��������ͷ�巨
ListNode* create()
{
	ListNode* Head=NULL;   //����һ��ͷָ��
	ListNode* NewNode = NULL;   //����һ���½ڵ�ָ��
	int newdata;
	printf("please intput :");
	scanf_s("%d", &newdata);
	printf("\n");
	while (newdata!=0)
	{
		NewNode = (ListNode*)malloc(sizeof(ListNode));  //���ٿռ�
		NewNode->data = newdata;
		NewNode->Next = Head;
		Head = NewNode;  //���뵽��ͷ
		printf("please intput :");
		scanf_s("%d", &newdata);
		printf("\n");
	}
	return Head;

}*/

// ��������β�巨
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

//����Ĳ���   ��i��λ�ò���
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
	if (!ListIndex || j > i)  //��i��Ԫ�ز���
		return False;
	NewListNode = (ListNode*)malloc(sizeof(ListNode));
	NewListNode->data = value;
	NewListNode->Next = ListIndex->Next;
	ListIndex->Next = NewListNode;
	return pHead;
}

//�����ɾ��   ��i��λ��ɾ��
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

//���������ɾ��  
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
	ListNode* pTemp;// һ��ʱָ��
	int Index = 1;//  ��ʶ�ڼ�����Ϣ
	pTemp = pHead;
	while (pTemp!=NULL)
	{
		printf("��%d����Ϣ:",Index);
		printf("����Ϊ%d\n", pTemp->data);
		pTemp = pTemp->Next;
		++Index;
	}
	

}

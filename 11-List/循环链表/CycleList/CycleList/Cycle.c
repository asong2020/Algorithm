#include<stdio.h>
#include<stdlib.h>

typedef int bool;
#define Flase 0
#define True 1

typedef struct YuMing
{
	char name[20];
	struct YuMing* LeftNode, * RightNode;
}NameList;

NameList* create();

int main()
{
	NameList* Mhead;
	Mhead = create();
	return 0;
}

NameList* create()
{
	NameList* pHead=NULL, *pPre = NULL, *pNow = NULL;
	int Cout = 0;
	pNow = (NameList*)malloc(sizeof(NameList));
	printf("please input value :");
	scanf_s("%s", pNow->name);
	printf("\n");
	while (pNow->name != '\0')
	{
		++Cout;
		if (Cout == 1)
		{
			pHead->RightNode = pNow;
			pNow->RightNode = NULL;
			pNow->LeftNode = pHead;
			pPre = pNow;
			
		}
		else
		{
			pNow->RightNode = NULL;
			pNow->LeftNode = pPre;
			pPre = pNow;
		}
		
	}
	pHead->LeftNode = pPre;
	pPre->RightNode = pHead;
	return pHead;


}
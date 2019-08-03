#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>



struct ListNode
{
	int m_Value;
    struct ListNode *m_Next;
};

struct ListNode * create();
void print(struct ListNode *pHead);
void RemoveNode(struct ListNode ** pHead,int value);
struct ListNode * AddToTail(struct ListNode * pHead,int value);
int ListLength=0;
int main()
{
	struct ListNode *pHead;
    pHead=create();
   print(pHead);
//	pHead=AddToTail(pHead,"12");
   RemoveNode(pHead,4);
	print(pHead);
	return 0;
}

struct ListNode * create()
{
	struct ListNode * pNew, *pEnd;
	struct ListNode *pHead=NULL;
    pNew=pEnd=(struct ListNode *)malloc(sizeof(struct ListNode));
	printf("please value:");
	scanf("%d",&pNew->m_Value);
    while(pNew->m_Value!=0)
	{
		++ListLength;
		if(ListLength==1)
		{
		  pHead= pNew;
		  pEnd=pNew;
		}
		else{
		  pEnd->m_Next=pNew;
		  pEnd=pNew;

		}
    pNew=(struct ListNode *)malloc(sizeof(struct ListNode));
	printf("please value:");
	scanf("%d",&pNew->m_Value);    
	}
   free(pNew);
   return pHead;
}


struct ListNode * AddToTail(struct ListNode * pHead,int value)
{
     struct ListNode *pNew;
	 struct ListNode *pNode=pHead;
     pNew=(struct ListNode *)malloc(sizeof(struct ListNode));
	 pNew->m_Value=value;
     pNew->m_Next=NULL;
	 if(pHead==NULL)
	 {
	     pHead=pNew;
		
	 }
	 else
	 {

	      while(pNode->m_Next!=NULL)
		  {
		     pNode = pNode->m_Next;
		  }
		  pNode->m_Next=pNew;
		  ++ListLength;
	 }
	 return pHead;


}

void RemoveNode(struct ListNode ** pHead,int value)
{
	struct ListNode *pNew=*pHead;
	//Judge head empty
	if(*pHead==NULL||pHead==NULL)
	{
	     return ;
	}
    
	if((*pHead)->m_Value==value)
	{
	   *pHead=(*pHead)->m_Next;
	}
	else
	{
		while(pNew->m_Next!=NULL&&pNew->m_Value!=value)
		{
			pNew=pNew->m_Next;

		}
		if(pNew->m_Value==value)
		{

                pNew->m_Next=pNew->m_Next->m_Next;
		}
		else
		{
		    printf("no found!\r\n");
		}

	}
	free(pNew);

}


void print(struct ListNode *pHead)
{
    struct ListNode *pTemp;
    int iIndex=1;
    printf("总共%d个学生（信息）：\n",ListLength);
    pTemp=pHead;/*指针得到首结点的地址*/ 
    while(pTemp!=NULL)/*当临时指针不指向NULL时*/ 
    {
        printf("第%d个信息：\n",iIndex); 
        printf("number：%d",pTemp->m_Value); 
 
        pTemp=pTemp->m_Next;/*移动临时指针到下一个结点*/ 
        iIndex++;/*进行自加运算*/ 
    }
}

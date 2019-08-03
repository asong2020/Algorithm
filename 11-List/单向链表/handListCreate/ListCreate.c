#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/*��������*/
struct Student/*����ѧ����Ϣ�ṹ��ģ��*/ 
{
    char cName[20];/*ѧ������*/
    int iNumber;/*ѧ��ѧ��*/
    struct student *next;/*ָ�򱾽ṹ�����͵�ָ������*/
};

int iCount;/*ȫ�ֱ�����ʾ������*/ 

struct Student *Create();/*��������������*/ 
void print(struct Student *);/*�����������������*/
struct Student *Insert(struct Student *pHead,int number);
void Delete(struct Student *pHead,int number);
void Reveseprint(struct Student *pHead);
int main()
{
    int insert_n=2;/*���岢��ʼ��Ҫ����Ľ���*/
    int delete_n=2;/*���岢��ʼ��Ҫɾ���Ľ���*/
    struct Student *pHead;/*����һ��ָ��ѧ����Ϣ�ṹ���ָ����pHeadΪͷ��㴫��*/
    pHead=Create();/*�����������������ͷָ���pHead*/
   // print(pHead);/*��ָ��pHead������������������*/
   // pHead=Insert(pHead,insert_n);/*��ָ��pHead��Ҫ����Ľ�������ݸ����뺯��*/
 //   print(pHead);/*��ָ��pHead������������������*/
   // Delete(pHead,delete_n);/*��ָ��pHead��Ҫɾ���Ľ�������ݸ�ɾ������*/
   // print(pHead);/*��ָ��pHead������������������*/
	Reveseprint(pHead);
    return 0; 
}

struct Student *Create()
{
    struct Student *pHead=NULL;/*��ʼ������ͷָ��Ϊ��*/ 
    struct Student *pEnd,*pNew;
    iCount=0;/*��ʼ��������*/ 
    pEnd=pNew=(struct Student *)malloc(sizeof(struct Student));/*��̬����һ��ѧ����Ϣ�ṹ�����ʹ�С�Ŀռ䣬ʹ��pEnd��pNewͬʱָ��ýṹ��ռ�*/
    scanf("%s",pNew->cName);/*����������ȡ��һ��ѧ������*/ 
    scanf("%d",&pNew->iNumber);/*����������ȡ��һ��ѧ��ѧ��*/ 
    while(pNew->iNumber!=0)/*�趨ѭ��������������ѧ�Ų�Ϊ0ʱ*/ 
    {
        iCount++;/*������+1����ѧ����Ϣ����+1*/ 
        if(iCount==1)/*��������ȸոռ�Ϊ1��ִ��*/ 
        {
            pNew->next=pHead;/*ʹָ��ָ��Ϊ��*/
            pEnd=pNew;/*�����¼���Ľ��*/
            pHead=pNew;/*ͷ���ָ���׽��*/
        }
        else/*��������Ѿ����������ȴ��ڵ���2ʱ��ִ��*/ 
        {
            pNew->next=NULL;/*�½���ָ��Ϊ��*/
            pEnd->next=pNew;/*ԭ���Ľ��ָ���½��*/
            pEnd=pNew;/*pEndָ���½��*/
        }
        pNew=(struct Student *)malloc(sizeof(struct Student));/*�ٴη�������ڴ�ռ�*/
        scanf("%s",pNew->cName);/*����������ȡ��һ��ѧ������*/ 
        scanf("%d",&pNew->iNumber);/*����������ȡ��һ��ѧ��ѧ��*/ 
    }
    free(pNew);/*�ͷŽ��ռ�*/
    return pHead;/*���ش�������ͷָ��*/ 
}

void print(struct Student *pHead)
{
    struct Student *pTemp;/*����ָ��һ��ѧ����Ϣ�ṹ�����͵���ʱָ��*/ 
    int iIndex=1;/*���岢���¹�����iIndex��������ʶ�ڼ���ѧ������Ϣ��*/ 
    printf("�ܹ�%d��ѧ������Ϣ����\n",iCount);
    pTemp=pHead;/*ָ��õ��׽��ĵ�ַ*/ 
    while(pTemp!=NULL)/*����ʱָ�벻ָ��NULLʱ*/ 
    {
        printf("��%d��ѧ����Ϣ��\n",iIndex); 
        printf("������%s",pTemp->cName); /*�������*/
        printf("ѧ�ţ�%d",pTemp->iNumber);/*���ѧ��*/
        pTemp=pTemp->next;/*�ƶ���ʱָ�뵽��һ�����*/ 
        iIndex++;/*�����Լ�����*/ 
    }
}

void Reveseprint(struct Student *pHead)
{
    if(pHead==NULL)
	{
		return ;
	}
	 if(pHead!=NULL)
	{
	     if(pHead->next!=NULL)
		 {
               Reveseprint(pHead->next);
		 }
		 printf("%d\t,%d\t",pHead->cName,pHead->iNumber);
	}
	
}


struct Student *Insert(struct Student *pHead,int number)
{
    struct Student *p=pHead,*pNew;/*����pNewָ���·���Ŀռ�*/ 
    while(p&&p->iNumber!=number)
        p=p->next;/*ʹ��ʱ�����ٵ�Ҫ�����λ�ã���ʵ���������ѧ��Ϊnumber����Ϣ��������󣬷������*/ 
    printf("������ѧ�ţ�\n");
    /*�����ڴ�ռ䣬���ظ��ڴ�ռ�ĵ�ַ*/ 
    pNew=(struct Student *)malloc(sizeof(struct Student));
    scanf("%s",pNew->cName);
    scanf("%d",&pNew->iNumber);
    pNew->next=p->next;/*�½��ָ��ָ��ԭ���Ľ��*/
    p->next=pNew;/*ͷָ��ָ���½��*/
    iCount++;/*��������������*/ 
    return pHead;/*����ͷָ��*/ 
}


void Delete(struct Student *pHead,int number)
{
    int i;
    struct Student *pTemp;/*��ʱָ��*/ 
    struct Student *pPre;/*��ʾҪɾ�����ǰ�Ľ��*/ 
    pTemp=pHead;/*�õ������ͷ���*/ 
    pPre=pTemp;
    for(i=0;i<number;i++)
    {/*ͨ��forѭ��ʹ��Tempָ��Ҫɾ���Ľ��*/ 
        pPre=pTemp;
        pTemp=pTemp->next; 
    }
    pPre->next=pTemp->next;/*����ɾ��������ߵĽ��*/ 
    free(pTemp);/*�ͷ�Ҫɾ�������ڴ�ռ�*/ 
    iCount--;/*���������еĽ�����*/ 
}
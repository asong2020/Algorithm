#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/*单向链表*/
struct Student/*建立学生信息结构体模型*/ 
{
    char cName[20];/*学生姓名*/
    int iNumber;/*学生学号*/
    struct student *next;/*指向本结构体类型的指针类型*/
};

int iCount;/*全局变量表示链表长度*/ 

struct Student *Create();/*创建链表函数声明*/ 
void print(struct Student *);/*遍历输出链表函数声明*/
struct Student *Insert(struct Student *pHead,int number);
void Delete(struct Student *pHead,int number);
void Reveseprint(struct Student *pHead);
int main()
{
    int insert_n=2;/*定义并初始化要插入的结点号*/
    int delete_n=2;/*定义并初始化要删除的结点号*/
    struct Student *pHead;/*声明一个指向学生信息结构体的指针作pHead为头结点传递*/
    pHead=Create();/*创建链表，返回链表的头指针给pHead*/
   // print(pHead);/*将指针pHead传入输出函数遍历输出*/
   // pHead=Insert(pHead,insert_n);/*将指针pHead和要插入的结点数传递给插入函数*/
 //   print(pHead);/*将指针pHead传入输出函数遍历输出*/
   // Delete(pHead,delete_n);/*将指针pHead和要删除的结点数传递给删除函数*/
   // print(pHead);/*将指针pHead传入输出函数遍历输出*/
	Reveseprint(pHead);
    return 0; 
}

struct Student *Create()
{
    struct Student *pHead=NULL;/*初始化链表，头指针为空*/ 
    struct Student *pEnd,*pNew;
    iCount=0;/*初始化链表长度*/ 
    pEnd=pNew=(struct Student *)malloc(sizeof(struct Student));/*动态开辟一个学生信息结构体类型大小的空间，使得pEnd和pNew同时指向该结构体空间*/
    scanf("%s",pNew->cName);/*从输入流获取第一个学生姓名*/ 
    scanf("%d",&pNew->iNumber);/*从输入流获取第一个学生学号*/ 
    while(pNew->iNumber!=0)/*设定循环结束条件——学号不为0时*/ 
    {
        iCount++;/*链表长度+1，即学生信息个数+1*/ 
        if(iCount==1)/*如果链表长度刚刚加为1，执行*/ 
        {
            pNew->next=pHead;/*使指针指向为空*/
            pEnd=pNew;/*跟踪新加入的结点*/
            pHead=pNew;/*头结点指向首结点*/
        }
        else/*如果链表已经建立，长度大于等于2时，执行*/ 
        {
            pNew->next=NULL;/*新结点的指针为空*/
            pEnd->next=pNew;/*原来的结点指向新结点*/
            pEnd=pNew;/*pEnd指向新结点*/
        }
        pNew=(struct Student *)malloc(sizeof(struct Student));/*再次分配结点的内存空间*/
        scanf("%s",pNew->cName);/*从输入流获取第一个学生姓名*/ 
        scanf("%d",&pNew->iNumber);/*从输入流获取第一个学生学号*/ 
    }
    free(pNew);/*释放结点空间*/
    return pHead;/*返回创建出的头指针*/ 
}

void print(struct Student *pHead)
{
    struct Student *pTemp;/*定义指向一个学生信息结构体类型的临时指针*/ 
    int iIndex=1;/*定义并出事哈变量iIndex，用来标识第几个学生（信息）*/ 
    printf("总共%d个学生（信息）：\n",iCount);
    pTemp=pHead;/*指针得到首结点的地址*/ 
    while(pTemp!=NULL)/*当临时指针不指向NULL时*/ 
    {
        printf("第%d个学生信息：\n",iIndex); 
        printf("姓名：%s",pTemp->cName); /*输出姓名*/
        printf("学号：%d",pTemp->iNumber);/*输出学号*/
        pTemp=pTemp->next;/*移动临时指针到下一个结点*/ 
        iIndex++;/*进行自加运算*/ 
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
    struct Student *p=pHead,*pNew;/*定义pNew指向新分配的空间*/ 
    while(p&&p->iNumber!=number)
        p=p->next;/*使临时结点跟踪到要插入的位置（该实例必须存在学号为number的信息，插入其后，否则出错）*/ 
    printf("姓名和学号：\n");
    /*分配内存空间，返回该内存空间的地址*/ 
    pNew=(struct Student *)malloc(sizeof(struct Student));
    scanf("%s",pNew->cName);
    scanf("%d",&pNew->iNumber);
    pNew->next=p->next;/*新结点指针指向原来的结点*/
    p->next=pNew;/*头指针指向新结点*/
    iCount++;/*增加链表结点数量*/ 
    return pHead;/*返回头指针*/ 
}


void Delete(struct Student *pHead,int number)
{
    int i;
    struct Student *pTemp;/*临时指针*/ 
    struct Student *pPre;/*表示要删除结点前的结点*/ 
    pTemp=pHead;/*得到链表的头结点*/ 
    pPre=pTemp;
    for(i=0;i<number;i++)
    {/*通过for循环使得Temp指向要删除的结点*/ 
        pPre=pTemp;
        pTemp=pTemp->next; 
    }
    pPre->next=pTemp->next;/*连接删除结点两边的结点*/ 
    free(pTemp);/*释放要删除结点的内存空间*/ 
    iCount--;/*减少链表中的结点个数*/ 
}
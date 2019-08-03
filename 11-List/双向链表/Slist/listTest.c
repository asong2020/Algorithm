#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define N 10

typedef struct Node
{
    char name[20];
    struct Node *llink,*rlink;
}STUD;

STUD *creat(int);void print(STUD *);
STUD *search(STUD *h,char *x);
int main()
{
    int number;
    char studname[20];
    STUD *head,*searchpoint;
    number=N;
    head=creat(number);
    print(head);
    printf("��������Ҫ���ҵ��˵�������");
    scanf("%s",studname);
    searchpoint=search(head,studname);
    printf("����Ҫ���ҵ��˵������ǣ�%s",*&searchpoint->name); 
    return 0;
}

STUD *creat(int n)
{
    STUD *p,*h,*s;
    int i;
    if((h=(STUD *)malloc(sizeof(STUD)))==NULL)
    {
        printf("���ܷ����ڴ�ռ�");
        exit(0);        
    }
    h->name[0]='\0';
    h->llink=NULL;
    h->rlink=NULL;
    p=h;
    for(i=0;i<n;i++)
    {
        if((s=(STUD *)malloc(sizeof(STUD)))==NULL)
        {
        printf("���ܷ����ڴ�ռ�");
        exit(0);        
        }
        p->rlink=s;
        printf("�������%d���˵�����",i+1);
        scanf("%s",s->name);
        s->llink=p;
        s->rlink=NULL;
        p=s;
    }
    h->llink=s;
    p->rlink=h;
    return(h);
}

void print(STUD *h)
{
    int n;
    STUD *p;
    p=h->rlink;
    printf("������ϢΪ��\n");
    while(p!=h)
    {
        printf("%s ",&*(p->name));
        p=p->rlink;
    }
    printf("\n");
}


STUD *search(STUD *h,char *x)
{
    STUD *p;
    char *y;
    p=h->rlink;
    while(p!=h)
    {
        y=p->name;
        if(strcmp(y,x)==0)
            return(p);
        else
            p=p->rlink;
    }
    printf("û�в鵽�����ݣ�");
}
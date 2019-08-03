#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef enum {false = 0, true = 1} bool;
typedef int Elementtype;    //    ������������

//    ����ڵ�
typedef struct Node {
    Elementtype Element;
    struct Node  * Next;
}NODE, *PNODE;

//    ����ջ�ṹ��
typedef struct Stack {
    PNODE PTOP;        //    ����ջ���ڵ�
    PNODE PBOTTOM;        //    ����ջ�׽ڵ�
}STACK,* PSTACK;

//    ��������
void InitStack(PSTACK Stack);        //    ��ʼ��ջ
void PushStack(PSTACK Stack, int val);        //    ��ջ����
void PopStack(PSTACK Stack,int *val);        //    ��ջ����
void TraverseStack(PSTACK Stack);        //    ����ջ����
bool IsEmpty(PSTACK Stack);       //    �ж�ջ�Ƿ�Ϊ�պ���
void ClearStack(PSTACK Stack);        //    ���ջ����

//    ������

int main() {
    STACK Stack;    //    ����һ��ջ����
    int val = 0;    //    ����һ������
    InitStack(&Stack);        //    ���ó�ʼ��ջ����
    IsEmpty(&Stack);    //    �����ж�ջ�Ƿ�Ϊ�պ���
    PushStack(&Stack, 100);        //    ������ջ��������100����ջ��    
    PushStack(&Stack, 200);
    PushStack(&Stack, 300);
    PushStack(&Stack, 400);
    PushStack(&Stack, 500);
    PushStack(&Stack, 600);
    IsEmpty(&Stack);
    TraverseStack(&Stack);        //    ����ջ��������
    PopStack(&Stack, &val);        //    ���ó�ջ����
    TraverseStack(&Stack);
    ClearStack(&Stack);        //    �������ջ����
    IsEmpty(&Stack);
    return 0;
}

//    �����ʼ��ջ����
void InitStack(PSTACK Stack) {
    PNODE PNew = (PNODE)malloc(sizeof(NODE));    //    �½�һ���ڵ�
    if (PNew == NULL) {        //    �ж��ڴ��Ƿ����ɹ�
        printf("�½ڵ�ռ����ʧ�ܣ�\n");
        exit(-1);
    }
    Stack->PTOP = PNew;        //    ջ��ָ��ָ���½ڵ�
    Stack->PBOTTOM = PNew;        //    ջ��ָ��ָ���½ڵ�
    PNew->Next = NULL;        //    �½ڵ�ָ��ָ��Ϊ��
    printf("ջ�����ɹ���\n");

}

//    ������ջ����
//    ��ջ��������ֵval
void PushStack(PSTACK Stack,int val) {
    PNODE P = (PNODE)malloc(sizeof(NODE));    //    �����µĽڵ����ڴ�ű���
    if (P == NULL) {
        printf("����ռ��ڴ�ʧ�ܣ�");
        exit(-1);
    }
    P->Element = val;    //    ������ֵ���ڵ��������
    P->Next=Stack->PTOP;    //    ���½��Ľڵ�ָ����һ���ڵ�
    Stack->PTOP = P;        //    ���¶����ڵ㣬ʹ��ָ���½��Ľڵ�
    printf("%d ��ջ�ɹ���\n",val);
}

//    �����ջ����
//    ��ջ��������������ַ��ֵ������val
void PopStack(PSTACK Stack, int *val) {
       
    PNODE P = Stack->PTOP;    //    ����һ����ʱ�ڵ�ָ��ջ���ڵ�
	    if (Stack->PBOTTOM == Stack->PTOP) {    //    �ж�ջ�Ƿ�Ϊ��
        printf("��ջʧ�ܣ�ջΪ�գ�\n");    
    }
    *val = P->Element;    //    ��ջ���ڵ�Ԫ�ص�������ַ�ŵ�����val��
    Stack->PTOP = P->Next;    //    ��ջ��ָ��ָ����һ��ջ�ڵ�
    free(P);    //    �ͷŽڵ��ڴ棬��ֹ�ڴ�ռ�й©
    P = NULL;    //    ��ֹ����Ұָ��
    printf("�ѽ�%d��ջ������\n", *val);
}

//    �����ж�ջ�Ƿ�Ϊ�պ���
bool IsEmpty(PSTACK Stack) {
    if (Stack->PBOTTOM == Stack->PTOP)
    {
        printf("ջΪ�գ�\n");
        return true;
    }
    else
    {
        return false;
    }

}

//    ����ջ�ı�������
void TraverseStack(PSTACK Stack) {

    PNODE P = Stack->PTOP;        //    ����һ����ʱ�ڵ�ָ�룬��ʼ��ʱָ��ջ��
       if (IsEmpty(Stack)) {        //    �ж�ջ�Ƿ�Ϊ��
        printf("����ջʧ�ܣ�ջΪ�գ�");
        exit(-1);
    }                                 //ʹ��ʱ�ڵ�ָ���ջ����ʼ����ջ��ֱ��ջ��
    printf("����ջ�Ľ��Ϊ�� ");
    while (P != Stack->PBOTTOM) {
        printf("%d ", P->Element);    //    ��ӡ������
        P = P->Next;
    }
    printf("\n");
    
}

//    ����ջ����պ���

void ClearStack(PSTACK Stack) {

    //    ���������ڵ�ָ�������ͷ�ջ
    PNODE P = Stack->PTOP;
    PNODE Q = NULL;
	    if (IsEmpty(Stack)) {        //    �ж�ջ�Ƿ�Ϊ��
        printf("ջ�Ѿ�Ϊ�գ�������գ�\n");
        exit(-1);
    }
    //    ���ջ
    while (P != Stack->PBOTTOM) {
        Q = P->Next;
        free(P);
        P = Q;
    }
    Stack->PTOP = Stack->PBOTTOM;    //    ջ��ָ��ջ��ָ��ĳ�ʼ�սڵ�
    printf("�����ջ��\n");
}
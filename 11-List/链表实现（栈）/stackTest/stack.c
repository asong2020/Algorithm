#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef enum {false = 0, true = 1} bool;
typedef int Elementtype;    //    定义数据类型

//    定义节点
typedef struct Node {
    Elementtype Element;
    struct Node  * Next;
}NODE, *PNODE;

//    定义栈结构体
typedef struct Stack {
    PNODE PTOP;        //    定义栈顶节点
    PNODE PBOTTOM;        //    定义栈底节点
}STACK,* PSTACK;

//    函数声明
void InitStack(PSTACK Stack);        //    初始化栈
void PushStack(PSTACK Stack, int val);        //    入栈函数
void PopStack(PSTACK Stack,int *val);        //    出栈函数
void TraverseStack(PSTACK Stack);        //    遍历栈函数
bool IsEmpty(PSTACK Stack);       //    判断栈是否为空函数
void ClearStack(PSTACK Stack);        //    清空栈函数

//    主函数

int main() {
    STACK Stack;    //    创建一个栈变量
    int val = 0;    //    定义一个变量
    InitStack(&Stack);        //    调用初始化栈函数
    IsEmpty(&Stack);    //    调用判断栈是否为空函数
    PushStack(&Stack, 100);        //    调用入栈函数，把100推入栈中    
    PushStack(&Stack, 200);
    PushStack(&Stack, 300);
    PushStack(&Stack, 400);
    PushStack(&Stack, 500);
    PushStack(&Stack, 600);
    IsEmpty(&Stack);
    TraverseStack(&Stack);        //    调用栈遍历函数
    PopStack(&Stack, &val);        //    调用出栈函数
    TraverseStack(&Stack);
    ClearStack(&Stack);        //    调用清空栈函数
    IsEmpty(&Stack);
    return 0;
}

//    定义初始化栈函数
void InitStack(PSTACK Stack) {
    PNODE PNew = (PNODE)malloc(sizeof(NODE));    //    新建一个节点
    if (PNew == NULL) {        //    判断内存是否分配成功
        printf("新节点空间分配失败！\n");
        exit(-1);
    }
    Stack->PTOP = PNew;        //    栈顶指针指向新节点
    Stack->PBOTTOM = PNew;        //    栈底指针指向新节点
    PNew->Next = NULL;        //    新节点指针指向为空
    printf("栈创建成功！\n");

}

//    定义入栈函数
//    从栈顶插入数值val
void PushStack(PSTACK Stack,int val) {
    PNODE P = (PNODE)malloc(sizeof(NODE));    //    创建新的节点用于存放变量
    if (P == NULL) {
        printf("分配空间内存失败！");
        exit(-1);
    }
    P->Element = val;    //    变量赋值给节点的数据域
    P->Next=Stack->PTOP;    //    让新建的节点指向上一个节点
    Stack->PTOP = P;        //    更新顶部节点，使其指向新建的节点
    printf("%d 入栈成功！\n",val);
}

//    定义出栈函数
//    从栈顶弹出，并将地址赋值给变量val
void PopStack(PSTACK Stack, int *val) {
       
    PNODE P = Stack->PTOP;    //    建立一个临时节点指向栈顶节点
	    if (Stack->PBOTTOM == Stack->PTOP) {    //    判断栈是否为空
        printf("出栈失败，栈为空！\n");    
    }
    *val = P->Element;    //    把栈顶节点元素弹出，地址放到变量val中
    Stack->PTOP = P->Next;    //    把栈顶指针指向上一个栈节点
    free(P);    //    释放节点内存，防止内存空间泄漏
    P = NULL;    //    防止产生野指针
    printf("已将%d从栈弹出！\n", *val);
}

//    定义判断栈是否为空函数
bool IsEmpty(PSTACK Stack) {
    if (Stack->PBOTTOM == Stack->PTOP)
    {
        printf("栈为空！\n");
        return true;
    }
    else
    {
        return false;
    }

}

//    定义栈的遍历函数
void TraverseStack(PSTACK Stack) {

    PNODE P = Stack->PTOP;        //    建立一个临时节点指针，初始化时指向栈顶
       if (IsEmpty(Stack)) {        //    判断栈是否为空
        printf("遍历栈失败，栈为空！");
        exit(-1);
    }                                 //使临时节点指针从栈顶开始遍历栈，直到栈底
    printf("遍历栈的结果为： ");
    while (P != Stack->PBOTTOM) {
        printf("%d ", P->Element);    //    打印出数据
        P = P->Next;
    }
    printf("\n");
    
}

//    定义栈的清空函数

void ClearStack(PSTACK Stack) {

    //    创建两个节点指针用来释放栈
    PNODE P = Stack->PTOP;
    PNODE Q = NULL;
	    if (IsEmpty(Stack)) {        //    判断栈是否为空
        printf("栈已经为空，无需清空！\n");
        exit(-1);
    }
    //    清空栈
    while (P != Stack->PBOTTOM) {
        Q = P->Next;
        free(P);
        P = Q;
    }
    Stack->PTOP = Stack->PBOTTOM;    //    栈顶指向栈底指向的初始空节点
    printf("已清空栈！\n");
}
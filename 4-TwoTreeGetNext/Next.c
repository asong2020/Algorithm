#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct BinaryTreeNode * GetNext(struct BinaryTreeNode * pNode);
struct BinaryTreeNode
{
    int m_Vaule;
   struct BinaryTreeNode * pLeft;    //左节点指针
   struct BinaryTreeNode * pRight;   // 右节点指针
   struct BinaryTreeNode * pParent;  //父节点指针

};


struct BinaryTreeNode * CreateBinaryTreeNode(int value)
{
    struct BinaryTreeNode *pNode=(struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
    pNode->m_Vaule = value;
    pNode->pLeft = NULL;
    pNode->pRight = NULL;
    pNode->pParent = NULL;  
	
	return pNode;
}

void ConnectTreeNodes(struct BinaryTreeNode *Parent,struct BinaryTreeNode *pLeft,struct BinaryTreeNode *pRight)
{
    if(Parent != NULL)
    {
        Parent->pLeft = pLeft;
        Parent->pRight = pRight;

        if(pLeft != NULL)
            pLeft->pParent = Parent;
        if(pRight != NULL)
            pRight->pParent = Parent;
    }
}

void PrintTreeNode(struct BinaryTreeNode * pNode)
{
    if(pNode != NULL)
    {
        printf("value of this node is: %d\n", pNode->m_Vaule);

        if(pNode->pLeft != NULL)
            printf("value of its left child is: %d.\n", pNode->pLeft->m_Vaule);
        else
            printf("left child is null.\n");

        if(pNode->pRight != NULL)
            printf("value of its right child is: %d.\n", pNode->pRight->m_Vaule);
        else
            printf("right child is null.\n");
    }
    else
    {
        printf("this node is null.\n");
    }

    printf("\n");
}



void PrintTree(struct BinaryTreeNode * pRoot)
{
    PrintTreeNode(pRoot);

    if(pRoot != NULL)
    {
        if(pRoot->pLeft != NULL)
            PrintTree(pRoot->pLeft);

        if(pRoot->pRight != NULL)
            PrintTree(pRoot->pRight);
    }
}

void DestroyTree(struct BinaryTreeNode * pRoot)
{
    if(pRoot != NULL)
    {
        struct BinaryTreeNode * ppLeft = pRoot->pLeft;
        struct BinaryTreeNode * ppRight = pRoot->pRight;

        free(pRoot);
        pRoot = NULL;

        DestroyTree(ppLeft);
        DestroyTree(ppRight);
    }
}



struct BinaryTreeNode * GetNext(struct BinaryTreeNode * pNode)
{
   struct BinaryTreeNode *pNext=NULL;
   struct BinaryTreeNode *Right=NULL;
   struct BinaryTreeNode *Parent=NULL;
   struct BinaryTreeNode *Current=NULL;
    if(pNode==NULL)
    {
        return NULL;
    }
    //先判断节点有没有右子节点
    if(pNode->pRight!=NULL)
    {
        Right=pNode->pRight;
        while(Right->pLeft!=NULL)
        {
            Right=Right->pLeft;
        }
        pNext=Right;
    }   //判断节点的父节点是否为空
    else if(pNode->pParent!=NULL)
    {
        Current=pNode;
        Parent=pNode->pParent;   //先记录下父节点
        while(Parent!=NULL&&pNode==Parent->pRight)
        {
            Current=Parent;
            Parent=Parent->pParent;
        }
        pNext=Parent;
    }
    return pNext;
}






void Test(char* testName, struct BinaryTreeNode * pNode, struct BinaryTreeNode * expected)
{


   struct BinaryTreeNode * pNext = GetNext(pNode);
       if(testName != NULL)
        printf("%s begins: ", testName); 
	   if(pNext == expected)
	   {
        printf("Passed.\n");
	   printf("TreeNext is %\n",pNext);
	   }
    else
        printf("FAILED.\n");
}

//            8
//        6      10
//       5 7    9  11
void Test1_7()
{
    struct BinaryTreeNode * pNode8 = CreateBinaryTreeNode(8);
    struct BinaryTreeNode * pNode6 = CreateBinaryTreeNode(6);
    struct BinaryTreeNode * pNode10 = CreateBinaryTreeNode(10);
    struct BinaryTreeNode * pNode5 = CreateBinaryTreeNode(5);
    struct BinaryTreeNode * pNode7 = CreateBinaryTreeNode(7);
    struct BinaryTreeNode * pNode9 = CreateBinaryTreeNode(9);
    struct BinaryTreeNode * pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    Test("Test1", pNode8, pNode9);
    Test("Test2", pNode6, pNode7);
    Test("Test3", pNode10, pNode11);
    Test("Test4", pNode5, pNode6);
    Test("Test5", pNode7, pNode8);
    Test("Test6", pNode9, pNode10);
    Test("Test7", pNode11, NULL);

    DestroyTree(pNode8);
}



int main()
{
	struct BinaryTreeNode *Getnext=NULL;
    Test1_7();
    return 0;
}
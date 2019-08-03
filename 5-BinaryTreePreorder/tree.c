//ǰ�������һ���ڵ�ȷ�����ڵ㣬Ȼ�������������Ѱ�Ҹ��ڵ㣬�Ӷ�ȷ�����������������������ݹ飨recursive������
#include<stdio.h>
#include<stdlib.h>
#define N 1000

int flag = 1; 		//�Ƿ�Ϊ�������ı�־

typedef struct node						//�ڵ㶨��
{
	int nodevalue;
	struct node *leftchild;
	struct node *rightchild;
}Node,*pNode;							//�ڵ�ṹ����������������������ַ�ʽʹ�ã�ָ��ͷ�ָ�룩

pNode ConstructBinaryTree(int *preTree, int *midTree, int length)  //ע��ǰ�������������ͣ�����pNode
{
	int i = 0;
	int count = 0;
	//�ǳ���Ҫ����ס�ݹ�����Ҫֹͣ�����ģ�������������
	/*��һ����ȷ�����β����ĸ��ڵ�*/
	pNode root = (pNode)malloc(sizeof(Node));		//�ڶ��ڴ���Ϊָ���������ռ�	
		if(length < 1)
		return NULL;
	root->nodevalue = *preTree;						//ǰ������ĵ�һ���ڵ��Ǹ��ڵ�
	root->leftchild = NULL;
	root->rightchild = NULL;
	
	/*�ڶ����������������Ѱ�Ҹ��ڵ㣬ͬʱ��¼�������ĳ��ȣ�����������Ҳ��ͨ�����ܳ���-����������-1���õ���*/

	while(*preTree != *(midTree+i))
	{
		count ++;
		if(count >= length)		//�������Ѱ�ҷ�Χ��û�ҵ����ڵ㣬�Ǿͷ���NULL�ɣ��������������
		{
			flag = 0;			//��־λ��Ϊ0������һ��������
			return NULL;
		}			
		else
			i++;
	}
	
	/*�������ǵݹ�ú�����Ϊʲô���Կ�ʼ�ݹ����أ��۲챾���������������������ǰ����֮��
	����ȷ�������������Ե�ǰ���������������ͳ��ȣ���˿��԰�һ��������ֽ��һ������С�����ˣ� */
	root->leftchild = ConstructBinaryTree(preTree + 1, midTree, count);  //ע��ݹ���ú�Ҫ��ֵ����root�����ҽڵ㣬��ô�ܰ���������أ�������
	root->rightchild = ConstructBinaryTree(preTree + 1 + count, midTree + count + 1, length - count - 1);  //����Ҫ����ǰ�����������������ص���ȷ��
	return root;				//���return������ڵ���Ƕ������ĸ��ڵ㣬����������еݹ���һ������ֵ��Ҳ���ǵ�һ�����ڵ�
}
void TraverseBinaryPostOrder(pNode root)   //����������ʵ�ֻ��������ݹ�
{
	if(root == NULL)
		return;
	TraverseBinaryPostOrder(root->leftchild);
	TraverseBinaryPostOrder(root->rightchild);
	printf("%d ",root->nodevalue);
}

int main(int argc, char* argv[]) //�����linux�����в������Լ������ ��Ϥһ�£����������� 
{
	int TreeLength;
	pNode root;
	freopen("sample.txt","r",stdin);
	/*
	printf("%d",argc);			//just for test
	int j;
	for (j = 0; j < argc; j++)
	{
		printf("%s\n",argv[j]);
	}
	*/
	
	while(scanf("%d",&TreeLength) != EOF)	//ɨ��ĵ�һ�����������ĳ���
	{
		int i;
		int PreOrder[N],InOrder[N];
		
		for(i = 0; i < TreeLength; i++)
		{
			scanf("%d",&PreOrder[i]);
		}
		for(i = 0; i < TreeLength; i++)
		{
			scanf("%d",&InOrder[i]);		//��Ϊscanf�Ĳ�����%d,���white-space���������ˣ�ֻ����%c���ܶ�����
		}
		root = ConstructBinaryTree(PreOrder,InOrder,TreeLength);
		if(flag == 1)
			TraverseBinaryPostOrder(root);
		else
			printf("No");
		printf("\n");
	}
	return 0;
}
    
#include <stdio.h>
#include <string.h>
#define N 1000
int main (int argc, char *argv[])
{
	
	int OperateNum ,stack0[N],stack1[N];		//�����鵱ջ�ã�C����û�취
	int i,top0 = -1 ,top1 = -1;
	char input[5];								//�洢PUSH �� POP������5���ռ�͹���
	freopen("sample.txt","r",stdin);
	while(scanf("%d",&OperateNum) != EOF) 		//�������������ٴ�
	{
		for(i = 0; i < OperateNum; i++)						
		{
			scanf("%s",input);
			if(!strcmp(input,"PUSH"))			//�����PUSH���ٶ���һ���������ݽ�stack0
				scanf("%d",&stack0[++top0]);
			else if(-1 != top1)					//�����POP������stack1��û�գ�����stack1�������Ԫ��
				printf("Queue is %d\n",stack1[top1--]);
			else if(-1 == top1 && -1 == top0)	//��һ���жϿ��Բ�Ҫ����Ϊ�����elseif�Ѿ��ų���-1��top1�����
			{
				printf("-1\n");
				break;							//ע���ʱ������return����Ϊsample����ܻ�����һ�������ݣ���Ҫ�ȵ������while����EOF��return
			}
			else								//��ʱΪstack1���ף�top1����-1����stack0���ж�����top0������-1����Ҫ��stack0�����ݷŵ�stack1
			{
				while(-1 != top0)
					stack1[++top1] = stack0[top0--];
				printf("Queue is %d\n",stack1[top1--]);	//��Ҫ������һ�䣬ת������Ҫ�Ѷ���ͷ�������
			}
		}
		printf("\n");
	}

	return 0;
}
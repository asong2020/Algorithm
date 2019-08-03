#include<stdio.h>
#include<string.h> 
#include<math.h>
/*
//把26进制转成10进制
int index(char *str,char x)
{
    unsigned int i ;
    for(i=0;i<strlen(str);i++)
    {
        if(str[i] == x)
            break; 
    }
    return i+1;
}
int strToNumber(char *str)//////给一个字符串求出它在第几列
{
     int len = strlen(str);
	 int col = 0;
	 int i;
    char *tmp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if(str==NULL || len<=0)
        return 0;


    for(i=0;i<len;i++)
    {
        int pos = index(str,str[i]);
        if(pos <= 0)
            return 0;
        col += pos*(int)pow(26,len-1-i);
    }
    return col;
}
*/
int strToNumber(char *str)
{
	int len=strlen(str);
	int value=0;
	int j=0;
	if(str==NULL || len<=0)
        return 0;
    while(len>0)
	{
       value+=(str[--len]-64)*(int)pow(26,j++);
	   
	}
	return value;
}

int main()
{

	char *str="B";
	int result;
    result=strToNumber(str);
	printf("%d",result);

    return 0;
}

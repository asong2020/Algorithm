#include<stdio.h>

char * InrToString(int num,char *string)
{
	int i=0;
	int j=0;
	if(num<0)
	{
		num=-num;

		string[0]='-';
		i=1;
	}

	while(num)
	{
		string[i++]=num%10+48;
		num/=10;
	}

	string[i]='\0';
	if(string[0]=='-')
	{
		j=1;
		++i;
	}else
	{
		j=0;
	}
	for(;j<i/2;j++)
		{
			string[j]=string[j]+string[i-1-j];
			string[i-1-j]=string[j]-string[i-1-j];
            string[j]=string[j]-string[i-1-j];
	}


	return string;
}

int StringToInt(char *str)
{
	int res=0;
	char flag='+';
	
	if(*str=='-')
	{
		++ str;

		flag='-';
	}
	while(*str>=48&&*str<57)
	{
		res=10*res+*str-48;
        ++ str;
	}
	if(flag=='-')
	{
		res=-res;
	}
	return res;
}

int main()
{
	
	int number = 0;
	char str[16]={0};
    number=StringToInt("-1234");
	printf("%d\n",number);

	return 0;
}
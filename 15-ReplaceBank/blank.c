#include<stdio.h>
/*length Ϊ�ַ�����str�������������ڻ�����ַ���str��ʵ�ʳ���*/
char ReplaceBlank(char str[], int length)
{
 //   if(str == nullptr && length <= 0)
 //       return;

    /*originalLength Ϊ�ַ���str��ʵ�ʳ���*/
    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;
	int indexOfOriginal;
    int newLength;
    int indexOfNew;
    while(str[i] != '\0')
    {
        ++ originalLength;

        if(str[i] == ' ')
            ++ numberOfBlank;

        ++ i;
    }

    /*newLength Ϊ�ѿո��滻��'%20'֮��ĳ���*/

	newLength = originalLength + numberOfBlank * 2;
 //   if(newLength > length)
 //       return;


	indexOfOriginal = originalLength;
	indexOfNew = newLength;
    while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
    {
        if(str[indexOfOriginal] == ' ')
        {
            str[indexOfNew --] = '0';
            str[indexOfNew --] = '2';
            str[indexOfNew --] = '%';
        }
        else
        {
            str[indexOfNew --] = str[indexOfOriginal];
        }

        -- indexOfOriginal;
    }
	return str;
}
int main()
{
    char str1[]="Hello world";
	char str2;
    str2=ReplaceBlank(str1,sizeof(str1));

	  printf("the string is %s\r\n",str1);


}
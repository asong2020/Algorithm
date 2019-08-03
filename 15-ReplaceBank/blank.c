#include<stdio.h>
/*length 为字符数组str的总容量，大于或等于字符串str的实际长度*/
char ReplaceBlank(char str[], int length)
{
 //   if(str == nullptr && length <= 0)
 //       return;

    /*originalLength 为字符串str的实际长度*/
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

    /*newLength 为把空格替换成'%20'之后的长度*/

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
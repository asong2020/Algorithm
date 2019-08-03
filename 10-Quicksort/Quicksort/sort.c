#include <stdio.h>
#include <stdlib.h>

/*
���������㷨ѧϰ
*/

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int arr[] ,int start, int end)
{
    int arrBase, arrMiddle;

    int tempStart = start,
        tempEnd = end;

    //�������ֵݹ�ĺ������ڲ�����Ҫ��һ���������ص�����
    if(tempStart >= tempEnd)
        return;

    //����һ����׼ֵ��Ϊ����ȽϵĲ���
    arrBase = arr[start];
    while(start < end)
    {
        while(start < end && arr[end] > arrBase)
            end--;
        if(start < end)
        {
            swap(&arr[start], &arr[end]);
            start++;
        }

        while(start < end && arr[start] < arrBase)
            start++;
        if(start < end)
        {
            swap(&arr[start], &arr[end]);
            end--;
        }
    }
    arr[start] = arrBase;
    arrMiddle = start;

    //���η������еݹ�
    quickSort(arr,tempStart,arrMiddle-1);
    quickSort(arr,arrMiddle+1,tempEnd);
}

int main()
{
    int myArr[] = {12,13,15,20,0,-1,-10,100};
    int i=0;
    int arrLength = sizeof(myArr)/sizeof(int);
    quickSort(myArr,0,arrLength-1);

    for(i = 0; i<arrLength; i++)
        printf("%5d",myArr[i]);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

/*
快速排序算法学习
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

    //对于这种递归的函数，内部必须要有一个函数返回的条件
    if(tempStart >= tempEnd)
        return;

    //拷贝一个基准值作为后面比较的参数
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

    //分治方法进行递归
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
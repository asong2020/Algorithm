
#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
typedef int bool;
#define FALSE 0
#define TRUE 1


bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int *pathlength, bool* visited);

bool hasPath(const char *matrix,int rows,int cols,const char* str)
{
	
	bool *visited =  (bool *)malloc(rows*cols);
	int row ,col ;
	int pathlength=0;
	memset(visited, 0, rows * cols);
	if(matrix==NULL||rows<1||cols<1||str==NULL)   
	{
		return FALSE;
	}
	
	for(row=0;row<rows;row++)
	{
		for(col=0;col<cols;col++)
		{
			if(hasPathCore(matrix,rows,cols,row,col,str,&pathlength,visited))
			{
				return TRUE;
			}
		}
	}
	free(visited);
	return FALSE;
}


bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int *pathlength, bool* visited)
{
	bool haspath=FALSE;
	if(str[*pathlength]=='\0')
	{
		return TRUE;
	}
	if(row<rows&&row>=0&&col>=0&&col<cols&&matrix[row*cols+col]==str[*pathlength]&&!visited[row*cols+col])
	{
		++pathlength;
		visited[row*cols+col]=TRUE;

		haspath=hasPathCore(matrix, rows, cols, row, col - 1,
            str, pathlength, visited)
            || hasPathCore(matrix, rows, cols, row - 1, col,
                str, pathlength, visited)
            || hasPathCore(matrix, rows, cols, row, col + 1,
                str, pathlength, visited)
            || hasPathCore(matrix, rows, cols, row + 1, col,
                str, pathlength, visited);
		if(!haspath)
		{
			--haspath;
			visited[row*cols+col]=FALSE;

		}

	}
	return haspath;
}

void Test(const char* testName, const char* matrix, int rows, int cols, const char* str, bool expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(hasPath(matrix, rows, cols, str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

void Test1()
{
    const char* matrix = "ABTGCFCSJDEH";
    const char* str = "BFCE";

    Test("Test1", (const char*) matrix, 3, 4, str, TRUE);
}

int main()
{
    Test1();
	return 0;
}
 


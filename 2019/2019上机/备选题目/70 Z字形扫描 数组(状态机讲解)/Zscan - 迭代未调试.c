#include <stdio.h>
// 去下行注释则禁用 assert()
// #define NDEBUG
#include <assert.h>

/***********************************************************
	试题编号	66
	试题名称	期末测试2-题目3-Z字形扫描
	时间限制:	1 秒
	内存限制:	256MB
	问题描述	
	问题描述
	在图像编码的算法中，需要将一个给定的方形矩阵进行Z字形扫描(Zigzag Scan)。给定一个n×n的矩阵，Z字形扫描的过程如下图所示。 
	对于下面给出的4×4的矩阵， 
	　　1 5 3 9 
	　　3 7 5 6 
	　　9 4 6 4 
	　　7 3 1 3 
	　　对其进行Z字形扫描后得到长度为16的序列： 
	　　1 5 3 9 7 3 9 5 4 7 3 6 6 4 1 3 
	　　请实现一个Z字形扫描的程序，给定一个n×n的矩阵，输出对这个矩阵进行Z字形扫描的结果。 
	
	输入说明
	输入的第一行包含一个整数n，表示矩阵的大小。 
	　　输入的第二行到第n+1行每行包含n个正整数，由空格分隔，表示给定的矩阵。 
	1≤n≤100，矩阵元素为不超过1000的正整数 
	输出说明
	输出一行，包含n×n个整数，由空格分隔，表示输入的矩阵经过Z字形扫描后的结果。
	输入样例
	4 
	1 5 3 9 
	3 7 5 6 
	9 4 6 4 
	7 3 1 3 
	输出样例
	1 5 3 9 7 3 9 5 4 7 3 6 6 4 1 3
	提示信息
 ***********************************************************/

// 思路: 根据上一步的单元格确定下一步的目标单元格。迭代的精髓。 
 
#define N 100;

// 奇数方阵 
void go1(int a[][N],int n)
{
	int lastRow=0, lastCol=0, up;
	while(1)
	{
		if(lastRow==0) // 最上行
		{
			// 奇数index列, to leftDown 
			if(lastCol%2) { lastRow--; lastCol++; up=0;} 
			//偶数index列
			else if(lastCol==n-1) lastRow++; // 左上角, to down
			else lastCol++; // to right 
		} 
		else if(lastCol==0) // 最左列
		{
			// 奇数行
			if(lastRow%2)
			{
				if(lastRow==n-1) { lastRow--;lastCol++; up=1; }   // 左下角, to right up 
				else lastRow++; // to down
			}
			// 偶数行
			else
			{
				// to right 
			} 
		} 
    } 
}

void go(int a[][N],int n)
{
	int lastRow=0, lastCol=0, up;
	while(1)
	{   
	    printf("%d ",a[lastRow][lastCol]);
	    if(n==1) break;
		if(lastRow==0 && lastCol==0) lastCol++;
		else if(n%2) // 奇数方阵 
		{
			
		} 
		else // 偶数方阵 
		{
		} 
	} 
}

void go1(int a[][N],int n)
{
	int lastRow=0, lastCol=0;
	while(1)
	{
		printf("%d ",a[lastRow][lastCol]);
		if(lastRow==0 && lastCol==n-1) // 右上角
		{
			if(n%2) lastRow++;              // 奇数, 垂直下 
			else  { lastRow++; lastCol--; }	// 偶数, 左下 
		} 
		else if(lastRow==n-1 && lastCol==0) // 左下角
		{
			if(n%2) { lastRow++; lastCol++; }  // 奇数，左上 
			else  lastCol--; 	               // 偶数, 水平右 
		} 
		// 其它, 最上行 
		else if(lastRow==0)
		{
			if(lastCol%2) { lastRow++; lastCol--; } // 奇数, 左下 
			else lastCol++;                         // 偶数, 水平右 
		}
		// 其它, 最左列 
		else if(lastCol==0)
		{
			if(lastRow%2) lastRow++;       // 奇数, 垂直下 
			else { lastRow--; lastCol++; } // 偶数, 右上  
		} 
		// 其它, 最下行 
		else if(lastRow==n-1)
		{
			if(last%2) lastRow++; // to down 
			else { lastRow--; lastCol--; } // to rightUp
		} 
		// 最右列 
	} 
}

int main()
{
	int a[N][N]= { {1,5,3,9},{3,7,5,6},{9,4,6,4},{7,3,1,3} },n=4,i,j;
	/***
	scanf("%d",&n);
	for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	    scanf("%d",&a[i][j]); ***/
	go(a,n);    
	return 0;
}
 
int main1()
{
	int n, a[100][100];
	//int n = 4, a[4][4] = { {1,5,3,9},{3,7,5,6},{9,4,6,4},{7,3,1,3} };
	
	// Finite State Machine
	// last,next = 1,水平(左-->右)，2竖直(上-->下)，3斜下(右上-->左下)，4斜上(左下-->右上)
	int i = 0, j = 0, last = 1, next = 1;
	
	scanf("%d",&n);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			scanf("%d",&a[i][j]);
	
	i = 0; j = 0; 
	printf("%d ", a[i][j]);
	while (1)
	{
		if (i == n - 1 && j == n - 1) break;
		last = next;
		switch (last)
		{
		case 1: // 水平 
			j++;
			if (i == 0) next = 3; // 转斜下 
			else if (i == n - 1) next = 4; // 转斜上 
			break;
		case 2: // 竖直 
			i++;
			if (j == 0) next = 4; // 转斜上 
			else if (j == n - 1) next = 3; // 转斜下 
			break;
		case 3: // 斜下 
			i++; j--;
			if (i > n - 1) i = n - 1;
			if (j < 0) j = 0;

			if (j == 0)
			{
				if (i == n - 1) next = 1; // 转水平 
				if (i < n - 1) next = 2; // 转竖直
			}
			else if (i == n - 1) next = 1; // 转水平 
			break;
		case 4:	// 斜上 
			i--; j++;
			if (i < 0) i = 0;
			if (j > n - 1) j = n - 1;
			if (i == 0)
			{
				if (j == n - 1) next = 2; // 转竖直 
				if (j < n - 1) next = 1; // 转水平	
			}
			else if(j == n-1) next = 2; // 转竖直 
			break;
		}
		printf("%d ", a[i][j]);  // 输出last状态下的a[i][j] 
	}

	return 0;
}

int main2()
{
	//int n, a[100][100];
	int n = 4, a[4][4] = { {1,5,3,9},{3,7,5,6},{9,4,6,4},{7,3,1,3} };
	
	// Finite State Machine
	// last,next = 1,水平(左-->右)，2竖直(上-->下)，3斜下(右上-->左下)，4斜上(左下-->右上)
	int i = 0, j = 0, last = 1, next = 1; 
	printf("%d ", a[0][0]);
	while (1)
	{
		if (i == n - 1 && j == n - 1) break;
		last = next;
		switch (last)
		{
		case 1: // 水平 
			assert(i == 0 || i == n - 1);
			assert(j < n - 1);
			j++;
			if (i == 0) next = 3; // 转斜下 
			else if (i == n - 1) next = 4; // 转斜上 
			break;
		case 2: // 竖直 
			assert(j == 0 || j == n - 1);
			assert(i < n - 1);
			i++;
			if (j == 0) next = 4; // 转斜上 
			else if (j == n - 1) next = 3; // 转斜下 
			break;
		case 3: // 斜下 
			i++; j--;
			if (i > n - 1) i = n - 1;
			if (j < 0) j = 0;

			if (j == 0)
			{
				if (i == n - 1) next = 1; // 转水平 
				if (i < n - 1) next = 2; // 转竖直
			}
			else if (i == n - 1) next = 1; // 转水平 
			break;
		case 4:	// 斜上 
			i--; j++;
			if (i < 0) i = 0;
			if (j > n - 1) j = n - 1;
			if (i == 0)
			{
				if (j == n - 1) next = 2; // 转竖直 
				if (j < n - 1) next = 1; // 转水平	
			}
			else if(j == n-1) next = 2; // 转竖直 
			break;
		}
		printf("%d ", a[i][j]);  // 输出last状态下的a[i][j] 
	}

	return 0;
}



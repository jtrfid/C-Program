/************************************************************************
试题编号	17
试题名称	矩阵
时间限制:	2 秒
内存限制:	10000MB
问题描述	
问题描述
请写一个程序，对于一个m行m列（2＜m＜20）的方阵，求其每一行、每一列及主、辅对角线元素之和
（注：主对角线是方阵从左上角到右下角的一条斜线，辅对角线是方阵从右上角到左下角的一条斜线），
然后按照从大到小的顺序依次输出这些值。
输入说明
只有一组数据；输入数据的第一行为一个正整数，表示m；接下来为m行、每行m个整数表示方阵的元素。
输出说明
从大到小排列的一行整数，每个整数后跟一个空格，最后换行。
输入样例
4 
15 8 -2 6 
31 24 18 71 
-3 -9 27 13 
17 21 38 69 
输出样例
159 145 144 135 81 60 44 32 28 27
提示信息
 ************************************************************************/
 // 思路：定义功能单一的函数，实现简单功能，主程序调用各个函数。
 // 一维数组a[2*M+2]存储相关函数计算结果，排序数组a即是所求。 
 // 避免过多循环嵌套，不易出错，简化程序设计。 
 // 但是缺点是在各函数中分别循环遍历方阵，效率低。
 // 优化方案是不采用独立函数计算，在主函数中一次遍历方阵，计算各值。 
 
 #include <stdio.h>
 // 估计方阵行列数 
 #define M 20
 
// input, m是实际方阵行列数 
void input(int matrix[][M], int m)
{
 	int i,j; 
	for(i = 0; i < m; i++)
 		for(j = 0; j < m; j++) 
			scanf("%d",&matrix[i][j]);
}

// 计算主对角线之和, m是实际方阵行列数 
int main_diagonal(int matrix[][M], int m)
{	
 	int i,j,sum = 0; 
	for(i = 0; i < m; i++)
 	{
 		for(j = 0; j < m; j++) 
		{
 		    if(i == j) sum += matrix[i][j];   // 主对角线 
		}
    }
    return sum;
}

// 计算副对角线之和, m是实际方阵行列数 
int counter_diagonal(int matrix[][M], int m)
{	
 	int i,j,sum = 0;
	for(i = 0; i < m; i++)
 	{
 		for(j = 0; j < m; j++) 
		{ 
 		    if(j == m-i-1) sum += matrix[i][j]; // 副对角线之和 
		}
    }
    return sum;
}

// 计算第i行之和, m是实际方阵行列数 
int sumI(int matrix[][M], int m, int i)
{ 
	int j,sum = 0; 
 	for(j = 0; j < m; j++) // 遍历列 
	{
 		sum += matrix[i][j];  // 第i行之和
	}
	return sum; 
} 

// 计算第j行之和, m是实际方阵行列数 
int sumJ(int matrix[][M], int m, int j)
{ 
	int i,sum = 0; 
 	for(i = 0; i < m; i++) // 遍历行 
	{
 		sum += matrix[i][j];  // 第j行之和
	}
	return sum;
} 

 // 交换两个元素值 
 void swap(int *p1, int *p2)
 {
 	int temp;
 	temp = *p1; *p1 = *p2; *p2 = temp;
 }
 
 // 选择法排序（降序）
 void sorts(int a[], int n)
 {
 	int i,j,k;
 	for(i = 0; i < n-1; i++)
	{
		k = i;
		for (j = i+1; j < n; j++)
			if(a[j] > a[k])	k = j;
		if (k != i) swap(&a[i],&a[k]);
	} 
 }
 
 int main()
 {
 	int matrix[M][M],a[2*M+2]; // 以估计行列数，定义数组 
	int i,m; 
 	scanf("%d",&m); // 实际方阵行列数 
 	
 	input(matrix,m); // input 
	
	// 调用各函数，装配数组a
	int n = 0; // 记录数组a的实际长度		
 	for(i = 0; i < m; i++)
 	{
 		a[n++] = sumI(matrix,m,i); // 第i行之和
		a[n++] = sumJ(matrix,m,i); // 第i列之和  
    }
    
    a[n++] = main_diagonal(matrix,m);    // 主对角线之和 
    a[n++] = counter_diagonal(matrix,m); // 副对角线之和  
	
	// 排序数组a 
 	sorts(a,n);
 	
 	// 输出 
 	for(i = 0; i < n; i++)
 		printf("%d ",a[i]);
 		
 	printf("\n");
 		
 	return 0;
 }

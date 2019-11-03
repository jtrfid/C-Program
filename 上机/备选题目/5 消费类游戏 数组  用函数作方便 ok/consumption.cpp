#include <stdio.h>
#include <math.h>
#define M 30 

// 扫描curRow行中可删除的元素, F: 删除标志矩阵, m: 列数 
void delRow(int curRow, int checker[][M], int F[][M],int m)
{
	int i,j, current,count;
	for(i=0;i<m;i++) 
	{
		// if(F[curRow][i]==1) continue; // 如果先扫描行，这就不合适了 
		count=1; 
		current=checker[curRow][i];
		for(j=i+1;j<m;j++)
		{
			if(current==checker[curRow][j]) count++;
			else break;
		}
		if(count>=3)
		{
			for(j=i;j<m;j++)
			{
				if(checker[curRow][j]==current) F[curRow][j]=1; // 置删除标志
				else break; 
			}
		}
	} 
}

// 扫描curCol列中可删除的元素, F: 删除标志矩阵, n: 行数 
void delCol(int curCol, int checker[][M], int F[][M],int n)
{
	int i,j, current,count;
	for(i=0;i<n;i++) 
	{
		count=1; 
		current=checker[i][curCol];
		for(j=i+1;j<n;j++)
		{
			if(current==checker[j][curCol]) count++;
			else break;
		}
		if(count>=3)
		{
			for(j=i;j<n;j++)
			{
				if(checker[j][curCol]==current) F[j][curCol]=1; // 置删除标志
				else break; 
			}
		}
	} 
}

// 清除所有可删除的元素, F: 删除标志矩阵, n: 行数, m: 列数 
void del(int checker[][M], int F[][M],int n, int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(F[i][j]==1) checker[i][j]=0;
		}
	}
}
 
int main()
{
	//**********
	int checker[M][M]={{2,2,3,1,2},
	                   {3,4,5,1,4},
					   {2,3,2,1,3},
					   {2,2,2,4,4}};
	int n=4,m=5,i,j; // n行，m列 
	/************
    int checker[M][M]={{2,2,3,1,2},
	                   {3,1,1,1,1},
					   {2,3,2,1,3},
					   {2,2,3,3,3}};
	int n=4,m=5,i,j; // n行，m列 
	*************/
	
    int F[M][M]; // 对应元素为1,则表示删除 
	
	//scanf("%d%d",&n,&m);
	
	// 初始化F 
	for(i=0;i<n;i++)
	  for(j=0;j<m;j++)
	    F[i][j]=0;
		 
	// 扫描行 
	for(i=0;i<n;i++) // 行 
	   delRow(i, checker, F, m);
	
	// 扫描列 
	for(j=0;j<m;j++) // 列 
	   delCol(j, checker, F, n);
	   
	// 清除 
	del(checker, F, n, m);
	 
	// 输出棋盘 
	for(i=0;i<n;i++) // 行 
	{
		for(j=0;j<m;j++) // 列 
		{
			printf("%d ",checker[i][j]); 
		}
		printf("\n");
	} 
	return 0;
} 

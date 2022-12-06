#include <stdio.h>
#include <math.h>
#define M 30 

/* 扫描行: 当一行上有连续三个或更多的相同颜色的棋子时，这些棋子都被消除。
    checker每行中符合删除棋子条件，其对应的F矩阵中的元素置1. 
	checker棋盘, F: 标志矩阵, n: 行数, m: 列数
 ***********************************************/ 
void scanRow1(int checker[][M], int F[][M], int n, int m)
{
	int i,j; 
	for(i=0;i<n;i++) // 行扫描 
	{
		for(j=1;j<m-1;j++) // 列，注意下标  
		{
			// 3个以上同行棋子连续同色，置F删除标志 
			if(checker[i][j-1] == checker[i][j] && checker[i][j] == checker[i][j+1]) 
			{
				F[i][j-1]=F[i][j]=F[i][j+1]=1;
			}
		}
	}	
}

/* 扫描列: 当一列上有连续三个或更多的相同颜色的棋子时，这些棋子都被消除。
    checker每列中符合删除棋子条件，其对应的F矩阵中的元素置1. 
	checker棋盘, F: 标志矩阵, n: 行数, m: 列数
 ***********************************************/ 
void scanCol1(int checker[][M], int F[][M], int n, int m)
{
	int i,j; 
	for(j=0;j<m;j++) // 列扫描 
	{
		for(i=1;i<n-1;i++) // 行，注意下标 
		{
			// 3个以上同列棋子连续同色，置F删除标志 
			if(checker[i-1][j] == checker[i][j] && checker[i][j] == checker[i+1][j]) 
			{
				F[i-1][j]=F[i][j]=F[i+1][j]=1;
			}
		}
	}		
}

/* 扫描行: 当一行上有连续三个或更多的相同颜色的棋子时，这些棋子都被消除。
    checker每行中符合删除棋子条件，其对应的F矩阵中的元素置1. 
	checker棋盘, F: 标志矩阵, n: 行数, m: 列数
 ***********************************************/ 
void scanRow(int checker[][M], int F[][M], int n, int m)
{
	int i,j,k,last,count; // last是最后检查的棋子颜色, count是连续同色棋子个数 
	for(i=0;i<n;i++) // 行扫描 
	{
		last=checker[i][0]; // 每行中第一个元素初始为last
		count=0; 
		for(j=1;j<m;j++) // 列 
		{
			if(last == checker[i][j]) count++;
			else // 不同色
			{
				if(count>=2) // 设置同色棋子的删除标志 
				{
					for(k=j-1;count>=0; k--,count--) F[i][k]=1; // 置删除标志 
				}
				last=checker[i][j]; count=0;  
			} 
		}
		// 直到最后一列，仍同色 
		if(count>=2) // 设置同色棋子的删除标志 
		{
			for(k=j-1;count>=0; k--,count--) F[i][k]=1; // 置删除标志 
		} 
	}	
}

/* 扫描列: 当一列上有连续三个或更多的相同颜色的棋子时，这些棋子都被消除。
    checker每列中符合删除棋子条件，其对应的F矩阵中的元素置1. 
	checker棋盘, F: 标志矩阵, n: 行数, m: 列数
 ***********************************************/ 
void scanCol(int checker[][M], int F[][M], int n, int m)
{
	int i,j,k,last,count; // last是最后检查的棋子颜色, count是连续同色棋子个数 
	for(j=0;j<m;j++) // 列扫描 
	{
		last=checker[0][j]; // 每列中第一个元素初始为last
		count=0; 
		for(i=1;i<n;i++) // 行 
		{
			if(last == checker[i][j]) count++;
			else // 不同色
			{
				if(count>=2) // 设置同色棋子的删除标志 
				{
					for(k=i-1;count>=0; k--,count--) F[k][j]=1; // 置删除标志 
				}
				last=checker[i][j]; count=0;  
			} 
		}
		// 直到最后一行，仍同色 
		if(count>=2) // 设置同色棋子的删除标志 
		{
			for(k=i-1;count>=0; k--,count--) F[k][j]=1; // 置删除标志 
		} 
	}	
}

// 读棋盘, n: 行数, m: 列数
void Read(int checker[][M],int n, int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&checker[i][j]);
		}
	}
}

// 输出棋盘, n: 行数, m: 列数
void output(int checker[][M],int n, int m)
{
	int i,j;
	for(i=0;i<n;i++) // 行 
	{
		for(j=0;j<m;j++) // 列 
		{
			printf("%d ",checker[i][j]); 
		}
		printf("\n");
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
	// 棋盘，初始化是为了便于测试 
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
	// 标志矩阵 
    int F[M][M]; // 对应元素为1,则表示删除 
	
	//scanf("%d%d",&n,&m);
	// 读棋盘 
	//Read(checker,n,m);
	
	// 初始化F 
	for(i=0;i<n;i++)
	  for(j=0;j<m;j++)
	    F[i][j]=0;
		 
	// 扫描行 
	scanRow(checker, F, n, m);
	
	// 扫描列 
	scanCol(checker, F, n, m);
	
	// 测试F   
	//output(F,n,m);
	
	// 清除 
	del(checker, F, n, m);
	 
	// 输出棋盘 
	output(checker,n,m);
	
	return 0;
} 

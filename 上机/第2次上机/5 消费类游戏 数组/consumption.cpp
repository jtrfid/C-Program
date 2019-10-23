#include <stdio.h>
#include <math.h>
#define M 30 
int main()
{
	int checker[M][M]={{2,2,3,1,2},
	                   {3,4,5,1,4},
					   {2,3,2,1,3},
					   {2,2,2,4,4}};
	int m=5,n=4,i,j,k; // n行，m列 
	int countCol,countRow; // 计数
	int current; // 当前检查的数 
	
	//scanf("%d%d",&n,&m);
	
	for(i=0;i<n;i++) // 行 
	{
		for(j=0;j<m;j++) // 列 
		{
		   if(checker[i][j]==0) continue; // 已经消除的数 
		   current=checker[i][j];
		   // 检查current同行数 
		   countRow=0;
		   for(k=0;k<m;k++) // 列检查 
		   {
		   	    if(k==j) continue; // 不能重复计数 
				if(checker[i][k]==current) countRow++;
		   }
		   // 检查current同列数 
		   countCol=0;
		   for(k=0;k<n;k++) // 行检查 
		   {
		   	    if(k==i) continue; // 不能重复计数 
				if(checker[k][j]==current) countCol++;
		   }
		   
		   if(countRow>=3) // 消除检查current同行数 
		   {
		   		for(k=0;k<m;k++) if(checker[i][k]==current) checker[i][k]=0;
		   } 
		   
		   if(countCol>=3) // 消除检查current同列数 
		   {
		   		for(k=0;k<n;k++) if(checker[k][j]==current) checker[k][j]=0;
		   } 
		}
	} 
	
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

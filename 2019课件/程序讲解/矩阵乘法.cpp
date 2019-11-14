#include<stdio.h>
#include<math.h>   // 数学库函数 
#include<string.h>

#define M 100 // 估计的最大值
#define P 50
#define N 100 
int main()                   
{  
	//int c[M][N],a[M][P]={{1,2,4}},b[P][N]={{2,1,3},{7,9,10},{5,7,1}}; // c={36,47,27}
	//int m=1,n=3,p=3; // M,N,P实际大小
	//int c[M][N],a[M][P]={{2,1},{4,3}},b[P][N]={{1,2},{1,0}}; // c={{3,4},{7,8}}
	//int m=2,n=2,p=2; // M,N,P实际大小
	//int c[M][N],a[M][P]={{1,0,2},{-1,3,1}},b[P][N]={{3,1},{2,1},{1,0}}; // c={{5,1},{4,2}}
	//int m=2,n=2,p=3; // M,N,P实际大小
	int c[M][N],a[M][P]={{5,2,4},{3,8,2},{6,0,4},{0,1,6}},b[P][N]={{2,4},{1,3},{3,2}}; // c={{24,34},{20,40},{24,32},{19,15}}
	int m=4,n=2,p=3; // M,N,P实际大小
	int i,j,k; //i,j,k分别是m,n,p的循环变量 
	
	scanf("%d%d%d\n", &m,&n,&p);
	for(i=0;i<m;i++)
	  for(k=0;k<p;k++) scanf("%d",&a[i][k]);
	for(k=0;k<p;k++)
	  for(j=0;j<n;j++) scanf("%d",&b[i][k]);
	  
	for(i=0;i<m;i++) 
	{
	   for(j=0;j<n;j++)
	   {
	   	 c[i][j]=0;
	   	 for(k=0;k<p;k++) 
	     	c[i][j]+=a[i][k]*b[k][j]; // a的第i行各列(k)和b的第j列各行(k)的乘积累加 
	     printf("c[%d][%d]=%d\n",i,j,c[i][j]); // 输出测试 
	   }
	}
   return 0;           
}                   

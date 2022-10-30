/********************************************************************************
	试题编号	41
	试题名称	自然数分解
	时间限制:	2 秒
	内存限制:	10000MB
	问题描述	
	问题描述
	任何一个自然数m的立方均可写成m个连续奇数之和。例如： 
	　1^3=1 
	　2^3=3+5 
	　3^3=7+9+11 
	　4^3=13+15+17+19 
	编程实现：输入一自然数n，求组成n^3的n个连续奇数。 
	输入说明
	一个正整数n
	输出说明
	输出n个连续奇数，数据之间用空格隔开，并换行
	输入样例
	4
	输出样例
	13 15 17 19
	提示信息
 ********************************************************************************/
#include <stdio.h>

int main()
{
	int n,i,j,sum,a1;
	scanf("%d",&n);
	// $a_1=n^2-n+1$
	a1=n*n-n+1;
	for(i=1;i<=n;i++)
	{   
		// $a_i=a_{i-1}+d,i=1,\dots,n,d=2$
		printf("%d ",a1);
		a1=a1+2; 
	}
	return 0;
} 

int main2()
{
	int n,i,j,sum,a1;
	scanf("%d",&n);
	// $a_1=n^2-n+1$
	a1=n*n-n+1;
	for(i=1;i<=n;i++)
	{
		// $a_i=a_1+(i-1)*d,i=1,\dots,n,d=2$
		printf("%d ",a1+(i-1)*2);
	}
	return 0;
} 

int main1() 
{
	int n,i,j,sum,first;
	scanf("%d",&n);
	
	// 第一个可能的奇数：
	if(n%2) first = n;    // n是奇数 
	else first = n + 1;   // n是偶数 
	
	while(1)
	{
		sum = 0; // 每趟内层循环前，必须置0 
		// 从first开始，n个连续奇数, i：表示连续奇数，j：计数。 
		for(i = first,j = 1; j <= n; i += 2,j++ ) 
		{
		    sum += i; // 从first开始连续n个奇数累加 
		}
		if(sum == n*n*n) 
		{
			// 输出 
			for(i = first,j = 1; j <= n; i += 2,j++) 
			{
			  	if (j == n)printf("%d\n",i);
			  	else printf("%d ",i);
			}
			break;  
		}
		else first += 2; // 测试下一个first 
	}
	return 0;
} 



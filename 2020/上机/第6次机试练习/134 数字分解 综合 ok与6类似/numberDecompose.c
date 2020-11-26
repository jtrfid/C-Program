/***********************************************************
	试题编号	42
	试题名称	数字分解排序
	时间限制:	2 秒
	内存限制:	10000MB
	问题描述	
	问题描述
	输入一个9位以内的正整数n，按数值从高到低的顺序输出n的各位数字。
	输入说明
	一个正整数n(0<n<1000000000) 
	输出说明
	按数值从高到低的顺序输出n的各位数字，数字之间用空格隔开
	输入样例
	564391 
	输出样例
	9 6 5 4 3 1 
	提示信息
 ***********************************************************/
#include <stdio.h>

void order(int a[],int n);  // 排序函数说明

int main()
{
	int i = 0,j,k,n,num[9];
	scanf("%d",&n);
	k=0; // 数字个数 
	while(n)
	{
		num[i++] = n%10;
		n /= 10;
		k++;
	} 
	
	// 输出验证 
	//for(j = 0; j < k; j++) printf("%d ",num[j]);
	//printf("\n");
	 
    order(num,k);  // 排序函数
			
	// 输出
	for(j = 0; j < k; j++) printf("%d ",num[j]);
	printf("\n");
	return 0;
} 

// 排序函数 
void order(int a[],int n)
{ 
	int i,j,t,flag;
	// 冒泡排序
	for(j = 1; j <= n-1; j++)
	{ 
		flag=0;
		for(i = 0; i < n - j; i++)
			if (a[i] < a[i+1]) 
			{ 
			  t = a[i]; a[i] = a[i+1]; a[i+1] = t; 
			  flag=1;
			}
	    if(!flag) break;
   }
}

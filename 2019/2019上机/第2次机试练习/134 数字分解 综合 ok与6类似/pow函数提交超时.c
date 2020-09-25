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
#include <math.h>

void order(int a[],int n);  // 排序函数说明

int main()
{
	printf("%d,%d\n",(int)pow(5,3),(int)(pow(5,3)+0.5)); // 125,125
	int i = 0,j,k,n,n1,num[9],num1[9];
	scanf("%d",&n);
	k=0; // 数字个数
	n1=n; 
	while(n)
	{
		num1[i++] = n%10;
		n /= 10;
		k++;
	} 
	
	for(j=0;j<k;j++)
	  num[j]=n1/((int)pow(10,j))%10;  // 验证pow函数，提交可能超时，得到错误，本地是好的。 
	   
	// 输出验证 
	//for(j = 0; j < k; j++) printf("%d,%d ",num[j],num1[j]);
	//printf("aaaaaaaa\n");
	 
    order(num,k);  // 排序函数
			
	// 输出
	for(j = 0; j < k; j++) printf("%d ",num[j]);
	printf("\n");
	return 0;
} 

// 排序函数 
void order1(int a[],int n)
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

// 排序函数 
void order(int a[],int n)
{ 
	int i,j,t,flag;
	// 冒泡排序
	for(j = 0; j < n-1; j++)
	{ 
		flag=0;
		for(i = 0; i < n - j-1; i++)
			if (a[i] < a[i+1]) 
			{ 
			  t = a[i]; a[i] = a[i+1]; a[i+1] = t; 
			  flag=1;
			}
	    if(!flag) break;
   }
}

/********************************************************************************
	34. 试题名称	寻找最大整数
	时间限制:	2 秒
	内存限制:	10000MB
	问题描述	
	问题描述
	从键盘输入四个整数，计算其中的最大值并将其输出。
	输入说明
	输入一行4个整数，用空格分隔
	输出说明
	输出一个整数
	输入样例
	25 99 -46 0
	输出样例
	99
	提示信息
 ********************************************************************************/
#include <stdio.h>
int main() // 不用存储整数序列, 采用一条循环语句，合并输入和计算，减少出错概率。 
{
	int i, num, max;
	// 输入, 并计算 
	for(i = 0; i < 4; i++) 
	{ 
		if (i==0) scanf("%d",&max); // 假定第一个数就是最大的数 
		else
		{
			scanf("%d",&num);
			if(num > max) max=num; 
	    } 
	} 
	printf("%d\n",max);
	return 0;
} 

int main1() // 存储整数序列 
{
	int i, num[4], max;
	// 输入 
	for(i = 0; i < 4; i++) 
		scanf("%d",&num[i]);
	
	max = num[0]; // 假定的最大值必须是实际存在的，不要想当然是0,9999,等等。 
	for(i = 1; i < 4; i++)  
		if(max < num[i]) max = num[i];
	
	printf("%d\n",max);
	return 0;
} 
	

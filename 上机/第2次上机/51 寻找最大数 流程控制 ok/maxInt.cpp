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
int main()
{
	int i, num[4], max;
	// 输入 
	for(i = 0; i < 4; i++) 
		scanf("%d",&num[i]);
	
	max = num[0]; 
	for(i = 0; i < 4; i++)  
		if(max < num[i]) max = num[i];
	
	printf("%d\n",max);
	return 0;
} 
	

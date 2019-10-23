/*****************************************************************
	提试题编号	44
	试题名称	数字处理
	时间限制:	2 秒
	内存限制:	10000MB
	问题描述	
	问题描述
	编写一个程序，从键盘输入n个非零整数（0 < n <= 1000000000），对每个整数n进行如下处理：
	将整数的各位数字取出来相加，如果结果是一位数则输出该数，
	否则重复上述过程，直到得到的结果为一位数，并输出该结果。
	输入说明
	多组数据，每行一个整数，输入为0时表示输入结束。
	输出说明
	输出每个整数的处理结果，然后换行。
	输入样例
	24 
	39 
	0 
	输出样例
	6 
	3 
	提示信息
**********************************************************************/
#include <stdio.h>
#include <math.h>

// 返回bits数组长度,填充bits数组: 个位,十位,百位,... 
int numProcess(int n, int bits[])
{
	int bitsNum = 0;
	while(n) 
	{
		bits[bitsNum++] = n % 10; // 填充bits数组: 个位,十位,百位,... 
		n /= 10; 
	}
	return bitsNum;
}

int main()
{
	int i,j,n[100],bits[10],bitsNum,sum;
	
	// 输入存入n[] 
	for(i = 0; ;i++)
	{
		scanf("%d",&n[i]);
		if(n[i] == 0) break;  // 输入结束
	}
	
	// 处理n[] 
	for(i = 0; n[i] != 0; i++)
	{
		bitsNum = numProcess(n[i],bits);
	    sum = 0;
		for(j = bitsNum - 1; j >= 0; j-- )
		{
			sum += bits[j];
			if(sum > 9) 
			{
				printf("%d\n",sum - bits[j]);
				break;
			}
		}
		if(j < 0) printf("%d\n",sum);
	}
	return 0;
}

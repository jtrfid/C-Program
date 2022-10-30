/***********************************************************
	试题编号	59
	试题名称	期末测试-题目1-气温波动
	时间限制:	1 秒
	内存限制:	256MB
	问题描述	
	问题描述
	最近一段时间气温波动较大。已知连续若干天的气温，请给出这几天气温的最大波动值是多少，即在这几天中某天气温与前一天气温之差的绝对值最大是多少。
	输入说明
	输入数据分为两行。 
	第一行包含了一个整数n，表示给出了连续n天的气温值，2 ≤ n ≤ 30。 
	第二行包含n个整数，依次表示每天的气温，气温为-20到40之间的整数。 
	输出说明
	输出一个整数，表示气温在这n天中的最大波动值。
	输入样例
	6 
	2 5 5 7 -3 5 
	输出样例
	10
	提示信息
 ***********************************************************/
#include <stdio.h>
#include <math.h>

// 不使用数组存储气温值 
int main1()
{
	int i, n, last ,temperature, undulation = 0; // last：前一天的气温值, temperature: 当天的气温值,  undulation波动值 
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		scanf("%d",&temperature);
		if (i != 0 && fabs(temperature - last) > undulation) // 注意i==0时, last无值 
			undulation = fabs(temperature - last);
		last = temperature;
	} 
	printf("%d\n",undulation); 
	return 0;
} 

// 使用数组存储最多30个气温值 
int main()
{
	int i, n,temperature[30], undulation = 0; // temperature数组: 气温值,  undulation波动值 
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		scanf("%d",&temperature[i]);
	} 
	
	undulation= fabs(temperature[0]-temperature[1]); // 初始波动值
	 
	for(i = 2; i < n-1; i++) // 注意数组边界，保证数组不越界 
	{
		if (fabs(temperature[i] - temperature[i+1]) > undulation) 
			undulation = fabs(temperature[i] - temperature[i+1]);
	} 
	
	printf("%d\n",undulation); 
	return 0;
} 


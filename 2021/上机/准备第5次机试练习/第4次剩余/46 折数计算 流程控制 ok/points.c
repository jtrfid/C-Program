/***********************************************************
	试题编号	64
	试题名称	期末测试2-题目1-折点计数
	时间限制:	1 秒
	内存限制:	256MB
	问题描述	
	问题描述
	给定n个整数表示一个商店连续n天的销售量。如果某天之前销售量在增长，而后一天销售量减少，则称这一天为折点，
	反过来如果之前销售量减少而后一天销售量增长，也称这一天为折点。其他的天都不是折点。如图所示，第3天和第6天是折点。 
	给定n个整数a1, a2, …, an表示连续n天中每天的销售量。请计算出这些天总共有多少个折点。
	
	输入说明
	输入的第一行包含一个整数n。 
	第二行包含n个整数，用空格分隔，分别表示a1, a2, …, an。 
	3 ≤ n ≤ 100，每天的销售量是不超过1000的非负整数。为了减少歧义，输入数据保证：在这n天中相邻两天的销售量总是不同的，即ai-1≠ai。 
	输出说明
	输出一个整数，表示折点数量。
	输入样例
	7 
	5 4 1 2 3 6 4 
	输出样例
	2 
	提示信息

 ***********************************************************/
 
#include <stdio.h>
int main()
{
	int i = 0, points = 0, n = 7, a[100] = {5,4,1,2,3,6,4};
	int up; // 标志变量 
	scanf("%d",&n);
	for(i = 0; i < n; i++) scanf("%d",&a[i]);
	up = a[1] > a[0] ? 1 : -1;
	for(i = 2; i < n; i++)
	{
		if((a[i] > a[i-1] && up < 0) || (a[i] < a[i-1] && up > 0)) points++;
		up = a[i] > a[i-1] ? 1 : -1;
	}
	
	printf("%d\n",points);
	return 0;
} 

int main1()
{
	int i = 0, points = 0, n = 7, a[100] = {5,4,1,2,3,6,4};
	int up;
	//scanf("%d",&n);
	if(n < 3 || n > 100) return 0;
	//for(i = 0; i < n; i++) scanf("%d",&a[i]);
	up = a[1] > a[0] ? 1 : -1;
	for(i = 2; i < n; i++)
	{
		if((a[i] > a[i-1] && up < 0) || (a[i] < a[i-1] && up > 0)) points++;
		up = a[i] > a[i-1] ? 1 : -1;
	}
	
	printf("%d\n",points);
	return 0;
} 

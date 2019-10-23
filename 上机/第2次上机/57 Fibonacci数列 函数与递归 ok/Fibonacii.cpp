/*****************************************************************
	试题编号	43
	试题名称	Fibonacci数列
	时间限制:	2 秒
	内存限制:	10000MB
	问题描述	
	问题描述
	有一种形式的Fibonacci数列定义如下： 
	F(0)=7 
	F(1)=11 
	F(n)=F(n-1)+F(n-2)（n>=2） 
	给定n值，判断F(n)是否能被3整除。 
	输入说明
	多组数据，输入数据第一行为正整数t(t<100)，表示数据组数，其后为t行，每行一个整数n（0<=n<=100）。
	输出说明
	对于每组数据，如果F(n)能被3整除输出“yes”否则输出“no”。
	输入样例
	3 
	1 
	2 
	3 
	输出样例
	no 
	yes 
	no 
	提示信息
**********************************************************************/
#include <stdio.h>
#include <math.h>

int Fibonacci(int n)
{
	int f; 
	if(n == 0) f = 7;
	else if(n == 1) f = 11;
	else f = Fibonacci(n-1) + Fibonacci(n-2);
	return f; 
}

int main()
{
	int i,t,n[100];
	scanf("%d",&t);
	for(i = 0; i < t; i++) scanf("%d",&n[i]);
	
	for(i = 0; i < t; i++)
	{
		if(Fibonacci(n[i]) % 3 == 0) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
